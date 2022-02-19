#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
typedef long long ll;
const ll inf=1ll<<62;
int n,cnt,fir[MAXN];
struct edge{
	int to,nxt;
	ll w;
	edge(){}
	edge(int v,int f,ll l){ to=v; nxt=f; w=l; }
} e[MAXN<<1];
void add(int u,int v,int w){
	e[++cnt]=edge(v,fir[u],w),fir[u]=cnt;
	e[++cnt]=edge(u,fir[v],w),fir[v]=cnt;
}
int sta[MAXN],top,cir[MAXN],cntx;
ll len[MAXN],b[MAXN],dis[MAXN],d[MAXN];
bool inst[MAXN],ancir[MAXN],vis[MAXN],flag;
void dfs_cir(int u,int fa,ll l){
	if (flag) return;
	sta[++top]=u; len[top]=l; inst[u]=1;
	for (int i=fir[u];i;i=e[i].nxt){
		if (e[i].to==fa) continue;
		if (inst[e[i].to]){
			int v=e[i].to;
			for (int j=top;j>=1&&sta[j]!=e[i].to;j--){
				cir[++cntx]=sta[j];
				ancir[sta[j]]=1;
				b[cntx]=len[j];
			}
			cir[++cntx]=e[i].to;
			ancir[e[i].to]=1; b[cntx]=e[i].w;
			flag=1;
		}
		else dfs_cir(e[i].to,u,e[i].w);
	}
	top--; inst[u]=0;
}
void dp(int u,int fa){
	for (int i=fir[u];i;i=e[i].nxt){
		if (e[i].to!=fa&&!ancir[e[i].to]){
			int v=e[i].to;
			dp(v,u);
			d[u]=max(d[u],dis[u]+dis[v]+e[i].w);
			dis[u]=max(dis[u],dis[v]+e[i].w);
			d[u]=max(d[u],d[v]);
		}
	}
}
ll ans=0,f1[MAXN],g1[MAXN],f2[MAXN],g2[MAXN];
int main(){
	scanf("%d",&n);
	for (int i=1,u,v,w;i<=n;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	dfs_cir(1,0,0);
	for (int i=1;i<=cntx;i++){
		dp(cir[i],0);
		ans=max(ans,d[cir[i]]);
	}
	ll sum=0,mx=0,mn=inf,tmp=b[cntx];
	b[cntx]=0;
	for (int i=1;i<=cntx;i++){
		sum+=b[i-1];
		f1[i]=max(f1[i-1],sum+dis[cir[i]]);
		g1[i]=max(g1[i-1],sum+dis[cir[i]]+mx);
		mx=max(mx,dis[cir[i]]-sum);
	}
	sum=mx=0;
	for (int i=cntx;i>=1;i--){
		sum+=b[i];
		f2[i]=max(f2[i+1],sum+dis[cir[i]]);
		g2[i]=max(g2[i+1],sum+dis[cir[i]]+mx);
		mx=max(mx,dis[cir[i]]-sum);
	}
	for (int i=1;i<=cntx;i++){
		mn=min(mn,max(f1[i]+f2[i+1]+tmp,max(g1[i],g2[i+1])));
	}
	ans=max(ans,mn);
	printf("%.1lf",(double)ans/2.0);
	return 0;
}
