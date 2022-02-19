#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e5+5;
const int MAXM=MAXN*2;
int n,m,k;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int d[MAXN],ffa[MAXN],fa[MAXN][20],sz[MAXN],res[MAXN];
int h[MAXN],r[MAXN],st[MAXN],top;
int dfn[MAXN],cnt,lis[MAXN],wson[MAXN],ttop[MAXN];
int bel[MAXN],ans[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
bool cmp(int a,int b){ return dfn[a]<dfn[b]; }
void dfs(int u,int p){
	sz[u]=1;
	ffa[u]=p;
	fa[u][0]=p; d[u]=d[p]+1; dfn[u]=++cnt;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u);
		sz[u]+=sz[v];
		if (wson[u]==0||sz[wson[u]]<sz[v]) wson[u]=v;
	}
}
void dfs3(int u,int p,int tp){
	ttop[u]=tp;
//	cout<<u<<" "<<p<<" "<<tp<<endl;
	if (wson[u]) dfs3(wson[u],u,tp);
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		if (v==wson[u]) continue;
		dfs3(v,u,v);
	}
}
void ini(){
	for (int i=1;i<=n;i++){
		for (int k=1;k<20;k++){
			fa[i][k]=fa[fa[i][k-1]][k-1];
		}
	}
}
/*int lca(int u,int v){
	if (d[u]<d[v]) swap(u,v);
	for (int k=19;k>=0;k--){
		if (d[fa[u][k]]>d[v]) u=fa[u][k];
	}
	if (d[u]>d[v]) u=fa[u][0];
	if (u==v) return u;
	for (int k=19;k>=0;k--){
		if (fa[u][k]!=fa[v][k]){
			u=fa[u][k]; v=fa[v][k];
		}
	}
	if (u!=v) return fa[u][0];
	else return u;
}*/
int lca(int u,int v){
//	cout<<__func__<<" "<<u<<" "<<v<<endl;
	while (ttop[u]!=ttop[v]){
		if (d[ttop[u]]<d[ttop[v]]) swap(u,v);
		u=ffa[ttop[u]];
	}
//	if (d[u]<d[v]) cout<<u<<endl;
//	else cout<<v<<endl;
	if (d[u]<d[v]) return u;
	else return v;
}
int dist(int u,int v){
	int f=lca(u,v);
	return d[u]+d[v]-d[f]*2;
}
void dfs1(int u){
	res[u]=sz[u]; lis[++cnt]=u;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		dfs1(v);
		if (!bel[v]) continue;
		int t1=dist(bel[v],u),t2=dist(bel[u],u);
		if ((t1==t2&&bel[v]<bel[u])||t1<t2||!bel[u]) bel[u]=bel[v];
	}
}
void dfs2(int u){
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		int t1=dist(bel[u],v),t2=dist(bel[v],v);
		if ((t1==t2&&bel[u]<bel[v])||t1<t2||!bel[v]) bel[v]=bel[u];
		dfs2(v);
	}
}
void work(int u,int v){
	int x=v,cut=v;
	for (int k=19;k>=0;k--){
		if (d[fa[x][k]]>d[u]) x=fa[x][k];
	}
	res[u]-=sz[x];
	if (bel[u]==bel[v]){
		ans[bel[u]]+=sz[x]-sz[v];
		return;
	}
	for (int k=19;k>=0;k--){
		int nxt=fa[cut][k];
		if (d[nxt]<=d[u]) continue;
		int t1=dist(bel[u],nxt),t2=dist(nxt,bel[v]);
		if ((t1==t2&&bel[v]<bel[u])||t1>t2) cut=nxt;
	}
	ans[bel[u]]+=sz[x]-sz[cut];
	ans[bel[v]]+=sz[cut]-sz[v];
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	dfs(1,0); dfs3(1,0,1); ini();
	scanf("%d",&m);
	for (int i=1;i<=n;i++) head[i]=0;
	while (m--){
		scanf("%d",&k);
		for (int i=1;i<=k;i++) scanf("%d",&h[i]);
		for (int i=1;i<=k;i++) bel[h[i]]=h[i],r[i]=h[i];
		edge=0;
		sort(h+1,h+k+1,cmp);
		top=0;
		if (bel[1]!=1) st[++top]=1;
		for (int i=1;i<=k;i++){
//			cout<<i<<endl;
			int u=h[i],pf=0;
			while (top>0){
				pf=lca(st[top],u);
				if (top>1&&d[st[top-1]]>d[pf]){
					add(st[top-1],st[top]);
					top--;
				}
				else if (d[st[top]]>d[pf]){
					add(pf,st[top]);
					top--;
					break;
				}
				else break;
			}
			if (st[top]!=pf) st[++top]=pf;
			if (st[top]!=u) st[++top]=u;
		}
		while (top>1){
			add(st[top-1],st[top]);
			top--;
		}
		cnt=0;
//		cout<<"fuck"<<endl;
		dfs1(1); dfs2(1);
		for (int i=1;i<=cnt;i++){
			int u=lis[i];
			for (int e=head[u];e;e=nex[e]){
				int v=tail[e];
				work(u,v);
			}
		}
		for (int i=1;i<=cnt;i++){
			int u=lis[i];
			ans[bel[u]]+=res[u];
		}
		for (int i=1;i<=k;i++) printf("%d ",ans[r[i]]);
		printf("\n");
		for (int i=1;i<=cnt;i++){
			int u=lis[i];
			head[u]=ans[u]=bel[u]=res[u]=0;
		}
	}
	return 0;
}
