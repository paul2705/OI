#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+5;
const int MAXM=2e6+6;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int n,m,bel[MAXN],use[MAXN],scc,num[MAXN];
int s[MAXN],top,low[MAXN],dfn[MAXN],cnt;
int ans[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void tarjan(int u){
	dfn[u]=low[u]=++cnt;
	s[top++]=u;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (!dfn[v]){
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if (!use[v]) low[u]=min(low[u],dfn[v]);
	}
	if (dfn[u]==low[u]){
		int x=s[top-1]; scc++; top--;
		bel[u]=scc; num[scc]=1;
		while (x!=u){
			bel[x]=scc; num[scc]++;
			use[x]=0;
			x=s[top-1]; top--;
		}
	}
}
int main(){
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	for (int i=1;i<=n;i++){
		if (!dfn[i]) tarjan(i);
	}
	for (int i=1;i<=n;i++){
//		cout<<bel[i]<<" "<<num[bel[i]]<<endl;
		if (num[bel[i]]>1) ans[i]=1;
	}
	for (int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}
