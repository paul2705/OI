#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=MAXN*2;
int edge,head[MAXN],nex[MAXM],tail[MAXM];
int n,m,T;
int dfn[MAXN],cnt,col[MAXN];
int fa[MAXN][20],d[MAXN];
struct rec{
	int dat,id;
} lis[MAXN*2];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs(int u,int p){
	dfn[u]=++cnt; fa[u][0]=p; d[u]=d[p]+1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u);
	}
}
void ini(){
	for (int k=1;k<20;k++){
		for (int i=1;i<=n;i++){
			fa[i][k]=fa[fa[i][k-1]][k-1];
		}
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
		if (fa[u][k]!=fa[v][k]) u=fa[u][k],v=fa[v][k];
	}
	if (u!=v) u=fa[u][0];
	return u;
}
bool cmp(rec a,rec b){ return a.dat<b.dat; }
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		edge=0;
		for (int i=1;i<=n;i++) head[i]=0;
		for (int i=1,u,v;i<n;i++){
			scanf("%d%d",&u,&v);
			add(u,v); add(v,u);
		}
		dfs(1,0); ini();
		for (int i=1,a,b;i<=m;i++){
			scanf("%d",&a);
			int res=0;
			for (int j=1,x;j<=a;j++){
				scanf("%d",&x);
				col[x]+=1; lis[res++]=(rec){dfn[x],x};
			}
			scanf("%d",&b);
			for (int j=1,x;j<=b;j++){
				scanf("%d",&x);
				col[x]+=2; lis[res++]=(rec){dfn[x],x};
			}
			sort(lis,lis+res,cmp);
			int mx=0;
			for (int i=0;i<res-1;i++){
				int u=lis[i].id,v=lis[i+1].id;
				if (col[u]!=3&&col[v]!=3){
					if (col[u]!=col[v]){
						int f=lca(u,v);
//						cout<<u<<" "<<v<<" "<<f<<endl;
						mx=max(mx,d[f]);
					}
				}
				else {
					int f=lca(u,v);
					mx=max(mx,d[f]);
				}
			}
			printf("%d\n",mx);
            for (int i=0;i<res;i++) col[lis[i].id]=0;
		}
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
