#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
const int MAXM=4e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int d[MAXN],sz[MAXN],dfn[MAXN],tim,rdfn[MAXN];
int fa[MAXN][22];
int cnt[MAXN];
ll val[MAXN],gt[MAXN];
ll ans,All;
int n,m,q;
set<int> S;
vector<int> ad[MAXN],dl[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs1(int u,int p){
	fa[u][0]=p; d[u]=d[p]+1;
	dfn[u]=++tim; rdfn[tim]=u;
	sz[u]=1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
	}
}
void dfs2(int u,int p){
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		gt[v]=gt[u]+val[v];
		dfs2(v,u);
//		gt[v]=gt[u]+val[v];
	}
}
void ini(){
	for (int k=1;k<=20;k++){
		for (int i=1;i<=n;i++){
			fa[i][k]=fa[fa[i][k-1]][k-1];
		}
	}
}
int lca(int x,int y){
	if (d[x]<d[y]) swap(x,y);
	for (int k=20;k>=0;k--){
		if (d[fa[x][k]]>d[y]) x=fa[x][k];
	}
	if (d[x]>d[y]) x=fa[x][0];
	if (x==y) return x;
	for (int k=20;k>=0;k--){
		if (fa[x][k]!=fa[y][k]){
			x=fa[x][k];
			y=fa[y][k];
		}
	}
	if (x!=y) return fa[x][0];
	return x;
}
int Gpre(int x){
	set<int>::iterator it=S.lower_bound(x);
	if (it==S.begin()) return 0;
	else return *(--it);
}
int Gnxt(int x){
	set<int>::iterator it=S.upper_bound(x);
	if (it==S.end()) return 0;
	else return *it;
}
void chg(int u,int op){
	if (cnt[u]>1&&op<0){
		cnt[u]--;
		return;
	}
	if (cnt[u]>0&&op>0){
		cnt[u]++;
		return;
	}
	cnt[u]+=op;
	if (op<0) S.erase(dfn[u]);
	ans+=op*gt[u];
	int pre=Gpre(dfn[u]); pre=rdfn[pre];
	int nxt=Gnxt(dfn[u]); nxt=rdfn[nxt];
//	cout<<pre<<" "<<nxt<<" "<<lca(pre,nxt)<<endl;
	if (pre&&nxt) ans+=op*gt[lca(pre,nxt)];
	if (pre) ans-=op*gt[lca(pre,u)];
	if (nxt) ans-=op*gt[lca(nxt,u)];
	if (op>0) S.insert(dfn[u]);
//	cout<<ans<<endl;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	d[0]=-1;
	dfs1(1,0);
	for (int i=1;i<=n;i++){
		if (d[i]>1) val[i]=-sz[i];
		All+=d[i];
//		cout<<i<<" "<<val[i]<<endl;
	}
//	cout<<"done"<<endl;
	dfs2(1,0); ini();
//	cout<<"fuck"<<endl;
//	for (int i=1;i<=n;i++) cout<<i<<" "<<gt[i]<<endl;
	for (int i=1;i<=q;i++){
		int l,r,v; scanf("%d%d%d",&l,&r,&v);
		ad[l].push_back(v); dl[r+1].push_back(v);
	}
//	cout<<"done"<<endl;
	for (int i=1;i<=m;i++){
		for (int j=0;j<ad[i].size();j++) chg(ad[i][j],1);
		for (int j=0;j<dl[i].size();j++) chg(dl[i][j],-1);
		printf("%lld ",All+ans);
	}
	return 0;
}
