#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=250005;
const int MAXM=MAXN*2;
typedef long long ll;
int n,m,k;
int edge,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
int d[MAXN],st[MAXN],dfn[MAXN];
int h[MAXN],fa[MAXN][20],mn[MAXN][20];
int lis[MAXN],cnt;
ll f[MAXN];
bool use[MAXN];
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
bool cmp(int a,int b){ return dfn[a]<dfn[b]; }
void dfs(int u,int p){
	fa[u][0]=p; d[u]=d[p]+1; dfn[u]=++cnt;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		mn[v][0]=w[e];
		dfs(v,u);
	}
}
int lca(int u,int v){
	if (d[u]<d[v]) swap(u,v);
	for (int k=19;k>=0;k--){
		if (d[fa[u][k]]>d[v]) u=fa[u][k];
	}
	if (d[u]>d[v]) u=fa[u][0];
	if (u==v) return u;
	for (int k=19;k>=0;k--){
		if (fa[u][k]!=fa[v][k]){
			u=fa[u][k];
			v=fa[v][k];
		}
	}
	if (u!=v) return fa[u][0];
	else return u;
}
void dfs2(int u,ll W){
	lis[++cnt]=u;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		dfs2(v,w[e]);
		if (!use[u]) f[u]+=f[v];
	}
	if (use[u]) f[u]=W;
	else f[u]=min(f[u],W);
//	cout<<u<<" "<<f[u]<<endl;	
}
int dist(int u,int v){
	int ret=1e9;
	if (d[u]<d[v]) swap(u,v);
	for (int k=19;k>=0;k--){
		if (d[fa[u][k]]>d[v]){
			ret=min(ret,mn[u][k]);
			u=fa[u][k];
		}
	}
	if (d[u]>d[v]){
		ret=min(ret,mn[u][0]);
		u=fa[u][0];
	}
	if (u==v) return ret;
	for (int k=19;k>=0;k--){
		if (fa[u][k]!=fa[v][k]){
			ret=min(ret,mn[u][k]);
			ret=min(ret,mn[v][k]);
			u=fa[u][k],v=fa[v][k];
		}
	}
	if (u!=v){
		ret=min(ret,mn[u][0]);
		return ret;
	}
	else return ret;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	for (int i=1;i<=n;i++){
		for (int k=0;k<20;k++) mn[i][k]=1e9;
	}
	dfs(1,0); 
	for (int i=1;i<=n;i++){
		for (int k=1;k<20;k++){
			fa[i][k]=fa[fa[i][k-1]][k-1];
			mn[i][k]=min(mn[i][k-1],mn[fa[i][k-1]][k-1]);
		}
	}
	for (int i=1;i<=n;i++) head[i]=0;
	scanf("%d",&m);
	while (m--){
		scanf("%d",&k);
		for (int i=1;i<=k;i++) scanf("%d",&h[i]);
		for (int i=1;i<=k;i++) use[h[i]]=1;
		sort(h+1,h+k+1,cmp);
//		int tot=1;
//		for (int i=2;i<=k;i++){
//			if (lca(h[tot],h[i])!=h[tot]) h[++tot]=h[i];
//		}
//		k=tot;
		cnt=edge=0;
		int top=0;
		st[++top]=1;
		for (int i=1;i<=k;i++){
			int u=h[i],pf=lca(st[top],u);
			while (top>0){
				if (top>1&&d[st[top-1]]>d[pf]){
					int d=dist(st[top-1],st[top]);
					add(st[top-1],st[top],d);
					top--;
				}
				else if (d[st[top]]>d[pf]){
					int d=dist(st[top],pf);
					add(pf,st[top],d);
					top--;
					break;
				}
				else break;
			}
			if (st[top]!=pf) st[++top]=pf;
			if (st[top]!=u) st[++top]=u;
		}
		while (top>1){
			int d=dist(st[top-1],st[top]);
			add(st[top-1],st[top],d);
			top--;
		}
		dfs2(1,1e18);
		printf("%lld\n",f[1]);
		for (int i=1;i<=cnt;i++){
			int u=lis[i];
			head[u]=use[u]=0;
			f[u]=0;
		}
	}
	return 0;
}
