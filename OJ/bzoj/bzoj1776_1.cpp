#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
const int MAXM=4e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int n,m,rt,d[MAXN],fa[MAXN][21];
int mxd[MAXN],ans[MAXN],a[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs(int u,int p){
//	cout<<__func__<<" "<<u<<" "<<p<<endl;
	fa[u][0]=p; d[u]=d[p]+1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u);
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
//	cout<<__func__<<" "<<x<<" "<<y<<endl;
	for (int k=20;k>=0;k--){
		if (d[fa[x][k]]>d[y]) x=fa[x][k];
	}
//	cout<<x<<" "<<y<<endl;
	if (d[x]>d[y]) x=fa[x][0];
	if (x==y) return x;
//	cout<<x<<" "<<y<<endl;
	for (int k=20;k>=0;k--){
		if (fa[x][k]!=fa[y][k]){
			x=fa[x][k];
			y=fa[y][k];
		}
	}
	if (x!=y) x=fa[x][0],y=fa[y][0];
//	cout<<x<<" "<<y<<endl;
	return x;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		int p; scanf("%d%d",&a[i],&p);
		if (p) add(p,i);
		else rt=i;
	}
	dfs(rt,0); ini();
//	for (int i=1;i<=n;i++) cout<<i<<" "<<fa[i][0]<<endl;
	for (int i=1;i<=n;i++){
		if (d[i]>d[mxd[a[i]]]) mxd[a[i]]=i;
	}
	for (int i=1;i<=n;i++){
		int lf=lca(i,mxd[a[i]]);
		int dis=d[i]+d[mxd[a[i]]]-d[lf]*2;
//		cout<<a[i]<<" "<<i<<" "<<mxd[a[i]]<<" "<<lf<<" "<<dis<<endl;
		ans[a[i]]=max(ans[a[i]],dis);
	}
	for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}
