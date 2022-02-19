#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=5e4+5;
const int MAXM=2e5+5;
int edge,head[MAXN],nex[MAXM],tail[MAXM];
int n,m,ans[505][505];
int fa[MAXN],d[MAXN],f[MAXN];
int lis[MAXN],t1[MAXN],t2[MAXN];
vector<int> g[MAXN];
bool use[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){ fa[find(x)]=find(y); }
void dfs(int u,int p){
	d[u]=d[p]+1; f[u]=p;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u);
	}
}
void Get_list(int u,int v){
	if (d[u]<d[v]) swap(u,v);
	t1[0]=t2[0]=lis[0]=0;
	while (d[u]>d[v]){
		t1[++t1[0]]=u;
		u=f[u];
	}
	while (u!=v){
		t1[++t1[0]]=u;
		t2[++t2[0]]=v;
		u=f[u]; v=f[v];
	}
	for (int i=1;i<=t1[0];i++) lis[++lis[0]]=t1[i];
	lis[++lis[0]]=u;
	for (int i=t2[0];i>=1;i--) lis[++lis[0]]=t2[i];
}
void solve1(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) ans[i][j]=-1;
	}
	dfs(1,0);
	for (int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		Get_list(u,v);
		int ret=0;
		for (int j=1;j<=lis[0];j++){
			for (int k=1;k<=n;k++) fa[k]=k,use[k]=0;
			for (int k=j;k<=lis[0];k++){
				int x=lis[j],y=lis[k]; use[y]=1;
				for (int j=0;j<g[y].size();j++){
					int ny=g[y][j]; if (!use[ny]) continue;
					uion(ny,y);
				}
				if (x>y) swap(x,y);
				if (ans[x][y]>-1) ret+=ans[x][y];
				else {
					bool flag=1;
					for (int _=j;_<=k;_++){
						int nu=lis[_];
						if (find(nu)!=find(x)) flag=0;
					}
					ans[x][y]=flag;
//					cout<<x<<" "<<y<<" "<<flag<<endl;
					ret+=flag;
				}
			}
		}
		printf("%d\n",ret);
	}
}
void solve2(){

}
int main(){
//	freopen("ex_x2.in","r",stdin);
//	freopen("C_2.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	for (int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if (n<=500&&m<=500) solve1();
	else solve2();
	fclose(stdin); fclose(stdout);
	return 0;
}
