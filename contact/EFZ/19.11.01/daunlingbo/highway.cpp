#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e5+5;
const int MAXM=2e6+6;
int edge,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
int fa[MAXN][20],fw[MAXN][20],d[MAXN];
int n,m;
int f[MAXN],st[MAXN],fi[MAXN],len[MAXN];
struct rec{
	int u,v,w;
} ed[MAXM];
int ans1[MAXN],ans2[MAXN];
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void dfs(int u,int p){
	fa[u][0]=p; d[u]=d[p]+1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		fw[v][0]=w[e];
		dfs(v,u);
	}
}
void ini(){
	for (int k=1;k<20;k++){
		for (int u=1;u<=n;u++){
			fa[u][k]=fa[fa[u][k-1]][k-1];
			fw[u][k]=fw[u][k-1]+fw[fa[u][k-1]][k-1];
		}
	}
}
int lca(int x,int y){
	int ans=0;
	if (d[x]<d[y]) swap(x,y);
	for (int k=19;k>=0;k--){
		if (d[fa[x][k]]>d[y]){
			ans+=fw[x][k];
			x=fa[x][k];
		}
	}
	if (d[x]>d[y]){
		ans+=fw[x][0];
		x=fa[x][0];
	}
	if (x==y) return ans;
	for (int k=19;k>=0;k--){
		if (fa[x][k]!=fa[y][k]){
			ans+=fw[x][k]+fw[y][k];
			x=fa[x][k]; y=fa[y][k];
		}
	}
	if (x!=y){
		ans+=fw[x][0]+fw[y][0];
		return ans;
	}
	return ans;
}
int find(int x){ return f[x]==x?x:f[x]=find(f[x]); }
void uion(int x,int y,int W){
	int fx=find(x),fy=find(y);
	int dis1=lca(st[fx],x),L=0;
	int dis2=lca(fi[fx],x),S;
	if (dis1>dis2) S=st[fx],L+=dis1;
	else S=fi[fx],L+=dis2;
	int dis3=lca(st[fy],y);
	int dis4=lca(fi[fy],y),T;
	if (dis3>dis4) T=st[fy],L+=dis3;
	else T=fi[fy],L+=dis4;
	L+=W;
//	cout<<x<<" "<<y<<" "<<W<<endl;
//	cout<<S<<" "<<T<<" "<<L<<endl;
//	cout<<endl;
	int mx=max(len[fx],max(len[fy],L));
	if (mx==len[fx]) f[fy]=fx;
	else if (mx==len[fy]){
		st[fx]=st[fy]; fi[fx]=fi[fy]; len[fx]=len[fy];
		f[fy]=fx;
	}
	else if (mx==L){
		st[fx]=S; fi[fx]=T; len[fx]=L;
		f[fy]=fx;
	}
}
int main(){
	freopen("highway.in","r",stdin);
	freopen("highway.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); add(v,u,w);
		ed[i]=(rec){u,v,w};
	}
	dfs(1,0); ini();
/*	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) cout<<i<<" "<<j<<" "<<lca(i,j)<<endl;
	}
*/	for (int i=1;i<=n;i++) f[i]=i,len[i]=0,st[i]=fi[i]=i;
	for (int i=n-1;i>=1;i--){
		int u=ed[i].u,v=ed[i].v,w=ed[i].w;
		int fu=find(u),fv=find(v);
//		if (len[fu]<len[fv]) printf("%d %d\n",len[fu],len[fv]);
//		else printf("%d %d\n",len[fv],len[fu]);
		if (len[fu]<len[fv]) ans1[i]=len[fu],ans2[i]=len[fv];
		else ans1[i]=len[fv],ans2[i]=len[fu];
		uion(u,v,w);
	}
	for (int i=1;i<n;i++) printf("%d %d\n",ans1[i],ans2[i]);
	fclose(stdin); fclose(stdout);
	return 0;
}

