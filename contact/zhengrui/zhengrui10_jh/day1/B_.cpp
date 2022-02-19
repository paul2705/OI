#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> par;
const int MAXN=1e5+5;
const int MAXM=2e5+5;
const ll inf=1e11;
int edge=1,head[MAXN],nex[MAXM],tail[MAXM];
ll w[MAXM];
ll f[MAXN][3],g[MAXN][3];
int n,m;
vector<par> G;
struct tnode{
	int l,r,cl,cr,dat,tag;
} t[MAXN*8];
int fa[MAXN],son[MAXN],sz[MAXN];
int rt,M,tp[MAXN],dfn[MAXN],tim,id[MAXN],d[MAXN];
int newnode(int l,int r,int cl,int cr,int dat){
	t[++M]=(tnode){l,r,cl,cr,dat,0};
	return M;
}
int build(int l,int r){
	if (l==r) return newnode(l,r,0,0,0);
	int mid=(l+r)>>1;
	int cl=build(l,mid),cr=build(mid+1,r);
	return newnode(l,r,cl,cr,0);
}
void pushdown(int id){
	if (!t[id].tag) return;
	int tag=t[id].tag;
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	t[id].dat+=(r-l+1)*tag;
	t[cl].tag+=tag;
	t[cr].tag+=tag;
	t[id].tag=0;
}
void update(int id){
	int cl=t[id].cl,cr=t[id].cr;
	t[id].dat=t[cl].dat+t[cr].dat;
}
void modify(int a,int b,int id,int val){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	pushdown(id);
	if (l>b||r<a) return;
	if (a<=l&&r<=b){
		t[id].tag+=val;
		pushdown(id);
		return;
	}
	modify(a,b,cl,val); modify(a,b,cr,val);
	update(id);
}
int qry(int a,int b,int id){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	pushdown(id);
	if (l>b||r<a) return 0;
	if (a<=l&&r<=b) return t[id].dat;
	return qry(a,b,cl)+qry(a,b,cr);
}
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs_sz(int u,int p){
	fa[u]=p;
	sz[u]=1; d[u]=d[p]+1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs_sz(v,u);
		sz[u]+=sz[v];
		if (sz[v]>sz[son[u]]) son[u]=v;
	}
}
void dfs_tp(int u,int p,int T){
	tp[u]=T; dfn[u]=++tim; id[tim]=u;
	if (son[u]) dfs_tp(son[u],u,T);
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		if (v==son[u]) continue;
		dfs_tp(v,u,v);
	}
}
void lca(int x,int y){
//	cout<<__func__<<" "<<x<<" "<<y<<endl;
	while (tp[x]!=tp[y]){
		if (d[tp[x]]<d[tp[y]]) swap(x,y);
//		cout<<"mod1: "<<tp[x]<<" "<<x<<" dfn: "<<dfn[tp[x]]<<" "<<dfn[x]<<endl;
		modify(dfn[tp[x]],dfn[x],rt,1);
		x=fa[tp[x]];
	}
	if (dfn[x]>dfn[y]) swap(x,y);
//	cout<<"mod1: "<<x<<" "<<y<<" dfn: "<<dfn[x]<<" "<<dfn[y]<<endl;
	modify(dfn[x],dfn[y],rt,1);
//	cout<<"mod-1: "<<x<<" "<<x<<" dfn: "<<dfn[x]<<" "<<dfn[x]<<endl;
	modify(dfn[x],dfn[x],rt,-1);
}
void dfs_cnt(int u,int p){
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		w[e]=qry(dfn[v],dfn[v],rt);
		w[e^1]=w[e];
//		cout<<u<<"->"<<v<<" "<<w[e]<<endl;
		dfs_cnt(v,u);
	}
}
void dfs(int u,int p){
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u);
	}
	int tmp=0;
	g[0][0]=0; g[0][1]=g[0][2]=inf;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		tmp++;
		g[tmp][0]=g[tmp][1]=g[tmp][2]=inf;
	}
	tmp=0;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		tmp++;
//		g[tmp][0]=g[tmp][1]=g[tmp][2]=0;
		ll x=f[v][0]+w[e],y=f[v][1];
		g[tmp][0]=g[tmp-1][0]+x;
		g[tmp][1]=min(inf,min(g[tmp-1][1]+x,g[tmp-1][0]+y));
//		g[tmp][2]=min(inf,min(g[tmp-1][2]+x,g[tmp-1][1]+y));
	}
	if (tmp!=0) f[u][1]=g[tmp][1];
	else f[u][1]=0;
	if (tmp!=0) f[u][0]=g[tmp][1];
	else f[u][0]=0;
///	f[u][0]=g[tmp][2];
//	cout<<tmp<<" "<<u<<" 1: "<<f[u][1]<<" 0: "<<f[u][0]<<endl;
}
/*void dfs(int u,int p){
	ll mx=-inf,S=0,tmp=0;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u); tmp++;
		mx=max(mx,f[v][1]-f[v][0]-w[e]);
		S+=f[v][0]+w[e];
	}
	if (tmp!=0) f[u][1]=f[u][0]=S-mx;
	else f[u][1]=f[u][0]=0;
//	cout<<tmp<<" "<<u<<" 1: "<<f[u][1]<<" 0: "<<f[u][0]<<endl;
}*/
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	dfs_sz(1,0);
	dfs_tp(1,0,1);
	rt=build(1,tim);
	for (int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
//		G.push_back(make_pair(u,v));
		lca(u,v);
	}
	ll ans=inf;
//	for (int i=1;i<=n;i++){
//		cout<<i<<endl;
/*		tim=0; 
		for (int i=1;i<=n;i++) son[i]=0;
		dfs_sz(1,0); 
		dfs_tp(1,0,1);
		M=0; rt=build(1,tim);
*/		//	for (int i=1;i<=n;i++) cout<<i<<" "<<tp[i]<<endl;
//		for (int i=0;i<m;i++){
//			int u=G[i].first,v=G[i].second;
//			lca(u,v);
//		}
		dfs_cnt(1,0);
	for (int i=1;i<=n;i++){
		dfs(i,0);
//		printf("%lld\n",min(f[1][0],f[1][1]));
		ans=min(ans,min(f[i][0],f[i][1]));
		cout<<i<<" "<<min(f[i][0],f[i][1])<<endl;
	}
	printf("%lld\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
