#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
const ll inf=1e11;
const int MAXN=1e5+5;
const int MAXM=2e5+5;
int edge=1,head[MAXN],nex[MAXM],tail[MAXM];
ll w[MAXN],cnt[MAXN];
int n,m;
multiset<int> s[MAXN];
int fa[MAXN][20],d[MAXN];
ll ans=inf,mx=0,S,f[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs_fa(int u,int p){
	fa[u][0]=p; d[u]=d[p]+1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs_fa(v,u);
	}
}
void ini(){
	for (int k=1;k<20;k++){
		for (int i=1;i<=n;i++){
			fa[i][k]=fa[fa[i][k-1]][k-1];
		}
	}
}
int lca(int x,int y){
	if (d[x]<d[y]) swap(x,y);
	for (int k=19;k>=0;k--){
		if (d[fa[x][k]]>d[y]) x=fa[x][k];
	}
	if (d[x]>d[y]) x=fa[x][0];
	if (x==y) return x;
	for (int k=19;k>=0;k--){
		if (fa[x][k]!=fa[y][k]) x=fa[x][k],y=fa[y][k];
	}
	if (x!=y) return fa[x][0];
	return x;
}
void dfs_cnt(int u,int p){
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs_cnt(v,u);
		cnt[u]+=cnt[v];
		w[e]=w[e^1]=cnt[v];
	}
}
void dfs1(int u,int p){
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs1(v,u);
		s[u].insert(w[e]);
		S+=w[e];
	}
	multiset<int>::iterator it=s[u].end(); 
	if (s[u].begin()!=s[u].end()){
		it--;
		mx+=(*it);
	}
}
void dfs2(int u,int p){
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		ll rmx=mx;
		multiset<int>::iterator it=s[u].end(); 
		if (s[u].begin()!=s[u].end()) it--,mx-=(*it);
		it=s[u].lower_bound(w[e]);
		s[u].erase(it);
		if (s[u].begin()!=s[u].end()){
			it=s[u].end(); 
			it--;
			mx+=(*it);
		}
		if (s[v].begin()!=s[v].end()){
			it=s[v].end(); 
			it--;
			mx-=(*it);
		}
		s[v].insert(w[e]);
		if (s[v].begin()!=s[v].end()){
			it=s[v].end(); 
			it--;
			mx+=(*it);
		}
		ans=min(ans,S-mx);
		f[v]=S-mx;
		dfs2(v,u);
		mx=rmx;
		s[u].insert(w[e]);
		it=s[v].lower_bound(w[e]);
		s[v].erase(it);
	}
}
int main(){
//	freopen("B.in","r",stdin);
//	freopen("B.ans","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	dfs_fa(1,0); ini();
	for (int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		int f=lca(u,v); 
		cnt[u]++; cnt[v]++; cnt[f]-=2;
	}
	dfs_cnt(1,0);
	dfs1(1,0);
	ans=S-mx; f[1]=S-mx;
	dfs2(1,0);
	printf("%lld\n",ans);
	return 0;
}
