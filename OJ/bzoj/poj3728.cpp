#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=5e4+5;
struct rec{
	int x,id;
};
int s[MAXN],t[MAXN];
int edge,head[MAXN],tail[MAXN*2],nex[MAXN*2];
int n,q,w[MAXN],sum[MAXN];
int fa[MAXN],mx[MAXN],mn[MAXN],up[MAXN],down[MAXN];
vector<rec> A[MAXN],Q[MAXN];
bool use[MAXN];
int find(int x){
	int p=fa[x];
	if (p==x) return x;
	int r=find(p);
	up[x]=max(up[x],max(up[p],mx[p]-mn[x]));
	down[x]=max(down[x],max(down[p],mx[x]-mn[p]));
	mx[x]=max(mx[x],mx[p]); mn[x]=min(mn[x],mn[p]);
	return fa[x]=find(fa[x]);
}
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs(int u,int p){
	fa[u]=u; use[u]=1;
	for (int i=0;i<A[u].size();i++){
		int v=A[u][i].x;
		if (!use[v]) continue;
		int pa=find(v);
		Q[pa].push_back(A[u][i]);
	}
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (use[v]) continue;
		dfs(v,u); fa[v]=u;
	}
	for (int i=0;i<Q[u].size();i++){
		int id=Q[u][i].id,us=s[id],vt=t[id];
		find(us); find(vt);
		sum[id]=max(up[us],max(down[vt],mx[vt]-mn[us]));
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&w[i]);
		fa[i]=i; up[i]=down[i]=0; mx[i]=mn[i]=w[i];
	}
	for (int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	scanf("%d",&q);
	for (int i=1,u,v;i<=q;i++){
		scanf("%d%d",&s[i],&t[i]);
		A[s[i]].push_back((rec){t[i],i});
		A[t[i]].push_back((rec){s[i],i});	
	}
	dfs(1,0);
	for (int i=1;i<=q;i++) printf("%d\n",sum[i]);
	return 0;
}
