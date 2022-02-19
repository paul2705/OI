#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=5e5+5;
const int MAXM=1e6+5;
int edge,head[MAXN],nex[MAXM],tail[MAXM],w[MAXM];
int n,m,a[MAXN];
ll pw[MAXN][20],fa[MAXN][20];
int dis,top,acnt,gol[MAXN],tdis[MAXN];
ll q[MAXN];
bool lef[MAXN],use[MAXN];
struct rec{
	ll go,l;
} ary[MAXN];
bool cmpq(int a,int b){ return a>b; }
bool cmpa(rec a,rec b){ return a.l<b.l; }
bool cmpb(rec a,rec b){ return a.l>b.l; }
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void dfs(int u,int p){
	fa[u][0]=p; //d[u]=d[p]+1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		pw[v][0]=w[e]; //wd[v]=wd[u]+w[e];
		dfs(v,u);
	}
}
void dfs1(int u,int p){
	gol[u]=top; tdis[u]=dis;
	bool fl=0;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		fl=1;
		dfs1(v,u);
	}
	if (!fl) lef[u]=1;
}
bool dfs2(int u,int p){
	if (lef[u]) return 1;
	bool fl=0;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p||use[v]) continue;
		fl|=dfs2(v,u);
	}
	return fl;
}
bool check(ll x){
	for (int i=1;i<=n;i++) use[i]=0;
	for (int i=1;i<=m;i++) ary[i]=(rec){0,0};
	top=0; acnt=0;
	for (int i=1;i<=m;i++){
		ll tim=x;
		int u=a[i];
		for (int k=19;k>=0;k--){
			if (u==1) break;
			if (fa[u][k]&&pw[u][k]<=tim){
				tim-=pw[u][k];
				u=fa[u][k];
			}
		}
//		cout<<tim<<" "<<u<<" "<<a[i]<<" "<<x<<endl;
		if (u==1) ary[++acnt]=(rec){gol[a[i]],tim};
		else use[u]=1;
	}
//	cout<<"fuck"<<endl;
	sort(ary+1,ary+m+1,cmpa);
	for (int i=1;i<=m;i++){
		if (ary[i].l<tdis[ary[i].go]){
			if (!use[ary[i].go]&&dfs2(ary[i].go,fa[ary[i].go][0])){
				use[ary[i].go]=1;
				ary[i].l=-1;
			}
		}
	}
//	cout<<"fuck"<<endl;
	sort(ary+1,ary+m+1,cmpb);
	for (int e=head[1];e;e=nex[e]){
		int v=tail[e];
//		cout<<dfs2(v,1)<<endl;
		if (!use[v]&&dfs2(v,1)) q[++top]=w[e];
	}
	sort(q+1,q+top+1,cmpq);
	for (int i=1;i<=top;i++){
		if (ary[i].l<q[i]) return 0;
	}
	return 1;
}
int main(){
	freopen("yqkz.in","r",stdin);
	freopen("yqkz.out","w",stdout);
	scanf("%d",&n);
	for (int i=1,u,v,w;i<n;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	dfs(1,0);
	for (int k=1;k<20;k++){
		for (int i=1;i<=n;i++){
			fa[i][k]=fa[fa[i][k-1]][k-1];
			pw[i][k]=pw[i][k-1]+pw[fa[i][k-1]][k-1];
		}
	}
	for (int e=head[1];e;e=nex[e]){
		int v=tail[e]; dis=w[e]; top=v;
		dfs1(v,1);
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++) scanf("%d",&a[i]);
	int tmp=0;
	for (int e=head[1];e;e=nex[e]) tmp++;
	if (tmp>m) return printf("-1\n"),0;
	ll l=0,r=5e14,mid;
	while (l+1<r){
//		cout<<l<<" "<<r<<endl;
		mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid;
	}
//	cout<<check(r)<<endl;
	if (check(l)) printf("%lld\n",l);
	else printf("%lld\n",r==5e14?0:r);
	fclose(stdin); fclose(stdout);
	return 0;
}
