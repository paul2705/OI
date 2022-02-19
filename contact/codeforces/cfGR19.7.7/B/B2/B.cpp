#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<queue>
using namespace std;
typedef long long ll;
const int inf=1e7;
const int MAXN=1e2+5;
const int MAXM=1e3+5;
int g[MAXN][MAXN];
int d[2*MAXM],cur[2*MAXM];
int edge=1,head[2*MAXM],tail[2*MAXM*MAXM],nex[2*MAXM*MAXM],r[2*MAXM*MAXM];
int S,T;
int n,m,s,B,k,h,lis[MAXM],lcnt;
struct sp{
	int x,a,f;
	bitset<1005> use;
} a[MAXM];
struct bs{
	int x,d;
} b[MAXM];
queue<int> q;
bool cmp(sp a,sp b){
	int cnt1=a.use.count();
	int cnt2=b.use.count();
	if (cnt1==cnt2){
		for (int i=1;i<=B;i++){
			if (a.use[i]==b.use[i]) continue;
			return a.use[i]<b.use[i];
		}
		return 1;
	}
	return cnt1<cnt2;
}
void add(int u,int v,int R){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,r[edge]=R;
}
void ins(int u,int v,int R){
	add(u,v,R); add(v,u,0);
}
bool bfs(){
	for (int i=1;i<=T;i++) d[i]=inf;
	d[S]=0; q.push(S);
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (d[v]==inf&&r[e]>0){
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
	return d[T]<inf;
}
int dfs(int u,int b){
	if (u==T) return b;
	int ans=0;
	for (int &e=cur[u];e;e=nex[e]){
		int v=tail[e];
		if (d[v]==d[u]+1&&r[e]>0){
			int res=dfs(v,min(r[e],b));
			r[e]-=res; r[e^1]+=res;
			ans+=res; b-=res;
		}
		if (!b) break;
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) g[i][j]=1e6;
		g[i][i]=0;
	}
	for (int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		if (u==v) continue;
		g[u][v]=g[v][u]=1;
	}
	scanf("%d%d%d%d",&s,&B,&k,&h);
	for (int i=1;i<=s;i++) scanf("%d%d%d",&a[i].x,&a[i].a,&a[i].f);
	for (int i=1;i<=B;i++) scanf("%d%d",&b[i].x,&b[i].d);
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	S=s+B+2; T=S+1;
	for (int i=1;i<=s;i++){
		ins(S,i,1);
		for (int j=1;j<=B;j++){
			if (a[i].a>=b[j].d&&g[a[i].x][b[j].x]<=a[i].f){
				ins(i,j+s,1);
			}
//			cout<<i<<" "<<j<<" "<<g[a[i].x][b[j].x]<<endl;
		}
//		cout<<a[i].use<<endl;
	}
	for (int i=1;i<=B;i++){
		ins(i+s,T,1);
	}
/*	sort(a+1,a+s+1,cmp);
	ll ans=0;
	for (int l=1,r=1;l<=s;l=r+1,r++){
		int res=a[l].use.count();
		while (r<s&&a[l].use==a[r+1].use) r++;
//		cout<<l<<" "<<r<<endl;
		if (res==0) continue;
		if (res>=r-l+1) ans+=(ll)k*(ll)(r-l+1);
		else ans+=(ll)k*(ll)res;
	}*/
	ll flow=0;
	while (bfs()){
//		cout<<"in"<<endl;
		for (int i=1;i<=T;i++) cur[i]=head[i];
		flow+=dfs(S,inf);
	}
//	cout<<flow<<endl;
	cout<<min(flow*(ll)k,(ll)s*(ll)h)<<endl;
	return 0;
}
