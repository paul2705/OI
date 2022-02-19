#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
const int MAXM=MAXN*2;
int edge,head[MAXN],nex[MAXM],tail[MAXM];
int low[MAXN],dfn[MAXN],cnt;
int n,m,bel[MAXN],num[MAXN],scc;
int s[MAXN],top;
bool use[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void tarjan(int u){
	low[u]=dfn[u]=++cnt;
	s[++top]=u; use[u]=1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if (use[v]) low[u]=min(low[u],dfn[v]);
	}
	if (low[u]==dfn[u]){
		scc++; num[scc]=1;
		int x=s[top--]; bel[u]=scc; use[u]=0;
		while (x!=u){
			bel[x]=scc; num[scc]++;
			use[x]=0;
			x=s[top--]; 
		}
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1,x;i<=n;i++){
		scanf("%d",&x);
		add(i,x);
	}
	for (int i=1;i<=n;i++){
		if (!dfn[i]) tarjan(i);
	}
	int ans=1e9;
//	for (int i=1;i<=n;i++) cout<<bel[i]<<" "; cout<<endl;
//	for (int i=1;i<=scc;i++) cout<<num[i]<<" ";cout<<endl;
	for (int i=1;i<=scc;i++) 
		if (num[i]>1) ans=min(ans,num[i]);
	printf("%d\n",ans);
	return 0;
}
