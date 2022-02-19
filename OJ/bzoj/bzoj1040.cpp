#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e6+6;
const int MAXM=3e6+6;
int edge=1,head[MAXN],tail[MAXM],nex[MAXM];
ll a[MAXN],f[MAXN][2];
int n;
int fa[MAXN],fw[MAXN];
bool use[MAXN];
ll ans=0;
int dfn[MAXN],idx;
struct rec{
	int u,e;
} st[MAXN],lis[MAXN];
int top=0,cnt=0;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
/*void dfs(int u,int p){
	use[u]=1;
//	cout<<u<<" "<<p<<endl;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		if (use[v]&&cnt>0) continue;
		if (use[v]&&cnt==0){
//			cout<<u<<" "<<v<<endl;
			lis[cnt++]=(rec){v,e};
			int las=top;
			while (st[top].u!=v){
//				cout<<st[top].u<<" "<<v<<" "<<top<<" "<<cnt<<endl;
				lis[cnt++]=st[top--];
			}
			top=las;
			continue;
		}
		st[++top]=(rec){v,e};
		dfs(v,u);
		top--;
	}
}*/
void get(int u){
	dfn[u]=++idx;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==fa[u]) continue;
		if (dfn[v]){
			if (dfn[v]<dfn[u]) continue;
			lis[cnt++]=(rec){v,fw[v]};
			for (;v!=u;v=fa[v]){
				lis[cnt++]=(rec){v,fw[v]};
			}
		}
		else fa[v]=u,fw[v]=e,get(v);
	}
}
void dp(int u,int p,int lim){
	f[u][0]=0; f[u][1]=a[u];
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (e==lim||e==(lim^1)) continue;
		if (v==p) continue;
		dp(v,u,lim);
		f[u][0]+=max(f[v][0],f[v][1]);
		f[u][1]+=f[v][0];
	}
}
ll solve(int x){
	cnt=top=0;
	st[++top]=(rec){x,0};
//	dfs(x,0);
	get(x);
	ll ret=0;
	for (int i=0;i<cnt;i++){
		dp(lis[i].u,0,lis[i].e);
		ret=max(ret,f[lis[i].u][0]);
		dp(tail[lis[i].e^1],0,lis[i].e);
		ret=max(ret,f[tail[lis[i].e^1]][0]);
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x; scanf("%lld%d",&a[i],&x);
		add(i,x); add(x,i);
	}
//	cout<<"done"<<endl;
	for (int i=1;i<=n;i++){
		if (!use[i]) ans+=solve(i);
	}
	printf("%lld\n",ans);
	return 0;
}
