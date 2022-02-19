#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=1e5+5;
vector<int> G[MAXN];
void dfs(int u){
	tick++; dfn[u]=tick;
	for (int i=0;i<G[u].size();i++){
		v=G[u][i];
		if (v!=fa[v]){
			if (dfn[v]>dfn[u]){
				k=0;
				for (int x=v;x!=fa[v];x=fa[x]){
					c[k]=x; x[k]=de[v]-de[x];
					k++;
				}
				c[k]=v; x[k]=x[k-1]+w[u][i];
			}
			else{
				fa[v]=v; de[v]=de[u]+w[u][i];
				dfs(v);
			}
		}
	}
}
ll efs(ll u){
	ll ans=0;
	for (int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if (dfn[v]==0) ans=max(ans,w[u][i]+efs(v));
	}
	return ans;
}
int main(){
	
	dfs(1);
	for (int i=1;i<=n;i++) dfn[i]=de[i]=0;
	for (int i=0;i<k;i++) dfn[c[i]]=1;
	for (int i=2;i<k;i++) d[i]=efs(c[i]);
	for (int j=k+1;j<=k*2;j++){
		c[j]=c[j-k]; d[j]=d[j-k]; x[j]=x[j-k]+x[k];
	}
	
