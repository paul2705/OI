#include<bits/stdc++.h>
using namespace std;
inline void swap(int&x,int&y){int t=x;x=y;y=t;}
const int N=100005,M=N*10;
int n,m,x,y,p[N],u1[N],u2[N],i,j;
vector<int>e[N];
vector<int>a[N];
int sz[N],dad[N],dep[N],ma[N],top[N];
void dfs1(int x,int fa){
	dad[x]=fa;dep[x]=dep[fa]+1;sz[x]=1;
	for(int i=0;i<e[x].size();++i)if(e[x][i]!=fa){
		dfs1(e[x][i],x);sz[x]+=sz[e[x][i]];
		if(sz[e[x][i]]>sz[ma[x]])ma[x]=e[x][i];
	}
}
struct node{
	int l,r;
}t[M];
int rt[N],len[N],xxb,dfn[N],be[N];
int vcnt;
vector<int>g[M];
int B;
int Z;
void build(int&x,int l,int r){
	x=++vcnt;if(l==r){g[x].push_back(p[dfn[B+l-1]]);return;}
	int m=(l+r)>>1;
	build(t[x].l,l,m);build(t[x].r,m+1,r);
	g[x].push_back(t[x].l);g[x].push_back(t[x].r);
}
void adde(int x,int l,int r,int p,int q,int v){
	if(l==p && r==q){g[v].push_back(x);return;}
	int m=(l+r)>>1;
	if(p>m)adde(t[x].r,m+1,r,p,q,v);
		else if(q<=m)adde(t[x].l,l,m,p,q,v);
				else adde(t[x].l,l,m,p,m,v),adde(t[x].r,m+1,r,m+1,q,v);
}
void dfs2(int x,int fa){
	g[x+m].push_back(p[x]);len[x]=1;
	dfn[be[x]=++xxb]=x;
	if(ma[x]){
		top[ma[x]]=top[x],dfs2(ma[x],x);len[x]=len[ma[x]]+1;
		g[ma[x]+m].push_back(x+m);
	}
	if(top[x]==x)
		B=be[x],build(rt[x],1,len[x]);
	for(int i=0;i<e[x].size();++i)if(e[x][i]!=fa && e[x][i]!=ma[x])
		top[e[x][i]]=e[x][i],dfs2(e[x][i],x);
}
inline int lca(int x,int y){
	for(;top[x]!=top[y];x=dad[top[x]])if(dep[top[x]]<dep[top[y]])swap(x,y);
	return dep[x]<dep[y]?x:y;
}
inline int dis(int x,int y){return dep[x]+dep[y]-dep[lca(x,y)]*2;}
int ind[M];
int b[N],xb;
int cd[N];
bool cmp(int x,int y){return cd[x]<cd[y];}
inline void add(int x,int y,int v){
	if(dep[x]>dep[y])swap(x,y);
	if(lca(x,y)==x){
		y=dad[y];
		for(;top[y]!=top[x];y=dad[top[y]])g[v].push_back(y+m);
		if(x!=y)adde(rt[top[x]],1,len[top[x]],be[x]-be[top[x]]+2,be[y]-be[top[x]]+1,v);
	}else{
		x=dad[x];y=dad[y];
		for(;top[y]!=top[x];y=dad[top[y]]){
			if(dep[top[x]]>dep[top[y]])swap(x,y);
			g[v].push_back(y+m);
		}
		if(dep[x]>dep[y])swap(x,y);
		adde(rt[top[x]],1,len[top[x]],be[x]-be[top[x]]+1,be[y]-be[top[x]]+1,v);
	}
}
int main(){
	freopen("color.in","r",stdin);freopen("color.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	vcnt=m+n;
	for(i=1;i<=n;++i)cin>>p[i],a[p[i]].push_back(i);
	for(i=1;i<n;++i){
		cin>>x>>y;
		e[x].push_back(y);e[y].push_back(x);
	}
	dfs1(1,0);top[1]=1;dfs2(1,0);
	for(i=1;i<=m;++i)if(a[i].size()>1){
		x=a[i][0];for(j=1;j<a[i].size();++j)if(dep[a[i][j]]>dep[x])x=a[i][j];
		for(j=0;j<a[i].size();++j)cd[a[i][j]]=dis(x,a[i][j]);
		sort(a[i].begin(),a[i].end(),cmp);u1[i]=x;u2[i]=a[i].back();
		for(j=0;j<a[i].size()-1;++j)if(dad[a[i][j]]!=a[i][j+1] && dad[a[i][j+1]]!=a[i][j])add(a[i][j],a[i][j+1],i);
	}
	static int q[M];int t=0,w=0;
	for(i=1;i<=vcnt;++i)for(j=0;j<g[i].size();++j)++ind[g[i][j]];
	for(i=1;i<=vcnt;++i)if(!ind[i])q[++w]=i;
	for(i=1;i<=m;++i)if(a[i].empty())u1[i]=u2[i]=1;
	for(;t<w;){
		x=q[++t];if(x<=m)b[++xb]=x;
		for(i=0;i<g[x].size();++i)if(!--ind[g[x][i]])q[++w]=g[x][i];
	}
	for(i=1;i<=xb;++i){
		cout<<b[i]<<' ';
		if(a[b[i]].size()==1)cout<<a[b[i]][0]<<' '<<a[b[i]][0];
			else cout<<u1[b[i]]<<' '<<u2[b[i]];
		cout<<'\n';
	}
	return 0;
}
