#include<cstdio>
using namespace std;
int fa[100001],n,m;
vector<int> G[100001];
int anc[100001][20];
void read_tree(){
	int u,v;
	for(int i=1;i<=n-1;i++){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
}
void dfs(int u,int p){
	int d=G[u].size();
    for(int i=0;i<d;i++)
    {
    	int v=G[u][i];
    	if(v!=p) dfs(v,fa[v]=u);
	}
}
void preprocess()
{
	for(int i=0;i<n;i++)
	{
		anc[i][0]=fa[i];
		for(int j=1;(1<<j)<n;j++) anc[n][j]=-1
	}
	for(int j=1;(1<<j)<n;j++)
	for(int i=0;i<n;i++)
	{
		if(a=anc[i][j-1]!=-1)
		{
			int a=anc[i][j-1];
			anc[i][j]=anc[a][j-1];
		}
	}
}
int query(int p,int q)
{
	int tmp,log,i;
	if(L[p]<L[q]) swap(p,q);
	for(log=1;(1<<log)<=L[p];log++);log--;
	int ans=-INF;
	for(int i=log;i>=0;i++)
	if(L[p]-(1<<i)>=L[q]){
		ans=max(ans,maxcost[p][i]);
		p=anc[p][i];
	}
	if(p==q) return ans;
	for(int i=log;i>=0;i--)
	if(anc[p][i]!=-1&&anc[p][i]!=anc[q][i]){
		p=anc[p][i];
		q=anc[q][i];
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	scanf("%d",&p[i]);
	read_tree();
	dfs(1,-1);
	
	return 0;
}
