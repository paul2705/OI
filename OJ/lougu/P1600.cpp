#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=3e5+5;
const int MAXM=6e5+5;
int edge,head[MAXN],nex[MAXM],tail[MAXM];
int dfn[MAXN],tim,out[MAXN];
struct qy{
	int val,pos;
	bool operator < (const qy& b) const {
		return pos<b.pos;
	}
};
vector<qy> lis[3][MAXN*3];
int d[MAXN],fa[MAXN],tp[MAXN],son[MAXN],sz[MAXN];
int n,m,w[MAXN];
struct rec{
	int dat,val;
};
vector<rec> cnt[3][MAXN*3];
// up: d[s]-d[u]=w[u] -> d[s]=d[u]+w[u];
// down: d[s]+d[t]-2*d[lca(s,t)]-(d[t]-d[u])=w[u] -> d[s]-2*d[lca(s,t)]=w[u]-d[u]
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs_sz(int u,int p){
	sz[u]=1; d[u]=d[p]+1; fa[u]=p;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs_sz(v,u);
		sz[u]+=sz[v];
		if (sz[v]>sz[son[u]]) son[u]=v;
	}
}
void dfs_tp(int u,int p,int T){
	tp[u]=T; dfn[u]=++tim;
	if (son[u]) dfs_tp(son[u],u,T);
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p||v==son[u]) continue;
		dfs_tp(v,u,v);
	}
	out[u]=tim;
}
int lca(int x,int y){
	while (tp[x]!=tp[y]){
		if (d[tp[x]]<d[tp[y]]) swap(x,y);
		x=fa[tp[x]];
	}
	return d[x]<d[y]?x:y;
}
void dfs_cnt(int u,int p){
//	cout<<__func__<<" "<<u<<" "<<p<<endl;
	for (int i=0;i<cnt[0][u].size();i++){
		rec tmp=cnt[0][u][i];
		lis[0][tmp.dat].push_back((qy){tmp.val,dfn[u]});
	}
	for (int i=0;i<cnt[1][u].size();i++){
		rec tmp=cnt[1][u][i];
		lis[1][tmp.dat].push_back((qy){tmp.val,dfn[u]});
	}
	if (son[u]) dfs_cnt(son[u],u);
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p||v==son[u]) continue;
		dfs_cnt(v,u);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	dfs_sz(1,0); dfs_tp(1,0,1);
	for (int i=1;i<=n;i++) scanf("%d",&w[i]);
	for (int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		int f=lca(u,v);
//		cout<<u<<" "<<v<<" lca: "<<f<<endl;
//		cout<<0<<" "<<u<<" "<<d[u]<<" 1"<<endl;
//		cout<<1<<" "<<v<<" "<<d[u]-2*d[f]+2*n<<" 1"<<endl;
//		cout<<0<<" "<<fa[f]<<" "<<d[u]<<" -1"<<endl;
//		cout<<1<<" "<<fa[f]<<" "<<d[u]-2*d[f]+2*n<<" -1"<<endl;
		cnt[0][u].push_back((rec){d[u],1});
		cnt[1][v].push_back((rec){d[u]-2*d[f]+2*n,1});
		cnt[0][f].push_back((rec){d[u],-1});
		cnt[1][fa[f]].push_back((rec){d[u]-2*d[f]+2*n,-1});
	}
	dfs_cnt(1,0);
//	for (int i=1;i<=n;i++) cout<<i<<" dfn: "<<dfn[i]<<endl;
	for (int i=0;i<=3*n;i++){
//		cout<<i<<" "<<3*n<<endl;
		for (int j=0;j<=1;j++){
//			cout<<"   "<<j<<endl;
//			for (int k=lis[j][i].size()-1;k>=0;k--){
//				cout<<"       "<<k<<endl;
//				cout<<" val: "<<lis[j][i][k].val<<" pos: "<<lis[j][i][k].pos<<endl;
//			}
			lis[j][i].push_back((qy){0,n+1});
			for (int k=lis[j][i].size()-2;k>=0;k--){
				lis[j][i][k].val+=lis[j][i][k+1].val;
			}
		}
	}
//	cout<<"done"<<endl;
	for (int i=1;i<=n;i++){
//		cout<<i<<endl;;
		int l1=lower_bound(lis[0][d[i]+w[i]].begin(),lis[0][d[i]+w[i]].end(),(qy){0,dfn[i]})-lis[0][d[i]+w[i]].begin();
		while (lis[0][d[i]+w[i]][l1].pos<dfn[i]) l1++; 
//		cout<<l1<<endl;
		int r1=lower_bound(lis[0][d[i]+w[i]].begin(),lis[0][d[i]+w[i]].end(),(qy){0,out[i]})-lis[0][d[i]+w[i]].begin();
		while (lis[0][d[i]+w[i]][r1].pos<=out[i]) r1++;
//		cout<<r1<<endl;
//		cout<<w[i]-d[i]+2*n<<endl;
		int l2=lower_bound(lis[1][w[i]-d[i]+2*n].begin(),lis[1][w[i]-d[i]+2*n].end(),(qy){0,dfn[i]})-lis[1][w[i]-d[i]+2*n].begin();
		while (lis[1][w[i]-d[i]+2*n][l2].pos<dfn[i]) l2++;
//		cout<<l2<<endl;
		int r2=lower_bound(lis[1][w[i]-d[i]+2*n].begin(),lis[1][w[i]-d[i]+2*n].end(),(qy){0,out[i]})-lis[1][w[i]-d[i]+2*n].begin();
		while (lis[1][w[i]-d[i]+2*n][r2].pos<=out[i]) r2++;
//		cout<<r2<<endl;
		printf("%d ",lis[0][d[i]+w[i]][l1].val-lis[0][d[i]+w[i]][r1].val+lis[1][w[i]-d[i]+2*n][l2].val-lis[1][w[i]-d[i]+2*n][r2].val);
	}
	printf("\n");
	return 0;
}
