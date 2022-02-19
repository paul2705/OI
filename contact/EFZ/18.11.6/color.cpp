#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=MAXN*40;
int edge,head[MAXN],nex[MAXM],tail[MAXM];
int ed,he[MAXN],ne[MAXM],ta[MAXM];
int n,m,a[MAXN],d[MAXN],rd[MAXN];
int fa[MAXN][20],id[MAXN][20],cnt;
struct rec{
	int u,v;
} ans[MAXN];
queue<int> q;
vector<int> col[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void ad(int u,int v){
	if (u==v) return;
	rd[v]++;
	ed++,ne[ed]=he[u],he[u]=ed,ta[ed]=v;
}
void dfs(int u,int p){
	fa[u][0]=p; d[u]=d[p]+1; id[u][0]=a[u];
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u);
	}
}
void ini(){
	for (int k=1;k<20;k++){
		for (int u=1;u<=n;u++){
			fa[u][k]=fa[fa[u][k-1]][k-1];
			id[u][k]=cnt++;
			ad(id[u][k],id[u][k-1]);
			ad(id[u][k],id[fa[u][k-1]][k-1]);
		}
	}
}
int lca(int u,int v){
	if (d[u]<d[v]) swap(u,v);
	for (int k=19;k>=0;k--){
		if (d[fa[u][k]]>d[v]) u=fa[u][k];
	}
	if (d[u]>d[v]) u=fa[u][0];
	for (int k=19;k>=0;k--){
		if (fa[u][k]!=fa[v][k]) u=fa[u][k],v=fa[v][k];
	}
	if (u!=v) return fa[u][0];
	return u;
}
bool isanc(int u,int v){
	if (d[u]>d[v]) return 0;
	for (int k=19;k>=0;k--){
		if (d[fa[u][k]]>d[v]) u=fa[u][k];
	}
	if (v!=u) u=fa[u][0];
	return u==v;
}
void cod(int u,int v){
	int x=a[u];
	u=fa[u][0];
	for (int k=19;k>=0;k--){
		if (d[fa[u][k]]>=d[v]){
			ad(x,id[u][k]);
			u=fa[u][k];
		}
	}
}
bool cmp(int a,int b){ return d[a]>d[b]; }
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d%d",&n,&m); cnt=m+1;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		col[a[i]].push_back(i);
	}
	for (int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	dfs(1,0); ini();
	for (int i=1;i<=m;i++){
		if (col[i].empty()){
			printf("%d 1 1\n",i);
			continue;
		}
		sort(col[i].begin(),col[i].end(),cmp);
		int l=lca(col[i][0],col[i].back());
		int x=l,y=l;
		for (int j=0;j<col[i].size();j++){
			int v=col[i][j];
			if (v==l) continue;
			int p=l;
			if (j&&isanc(col[i][j-1],v)) p=col[i][j-1];
			cod(v,p);
			(x==p?x:y)=v;
		}
		ad(i,a[l]);
		ans[i]=(rec){x,y};
	}
	for (int i=1;i<=cnt;i++){
		if (rd[i]==0) q.push(i);
	}
	while (!q.empty()){
		int u=q.front(); q.pop();
		if (u<=m&&!col[u].empty()){
			printf("%d %d %d\n",u,ans[u].u,ans[u].v);
		}
		for (int e=he[u];e;e=ne[e]){
			int v=ta[e];
			rd[v]--;
			if (rd[v]==0) q.push(v);
		}
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
