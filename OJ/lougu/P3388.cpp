#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=2e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int n,m;
int tim,dfn[MAXN],low[MAXN];
int st[MAXN],top,use[MAXN];
vector<int> ans;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void tarjan(int u){
	use[u]=1; st[++top]=u;
	dfn[u]=low[u]=++tim;
	int cnt=0,mx=0;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e]; 
		if (!dfn[v]){
			tarjan(v); cnt++;
			low[u]=min(low[u],low[v]);
			mx=max(mx,low[v]);
		}
		else if (use[v]) low[u]=min(low[u],dfn[v]);
	}
//	cout<<u<<" dfn:"<<dfn[u]<<" low:"<<low[u]<<endl;
	if (dfn[u]==low[u]){
		if (cnt>=2) ans.push_back(u);
		use[u]=0;
		while (st[top]!=u) use[st[top--]]=0;
		top--;
	}
	else if (mx>=dfn[u]) ans.push_back(u);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	for (int i=1;i<=n;i++){
		if (!dfn[i]) tarjan(i);
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",int(ans.size()));
	for (int i=0;i<ans.size();i++) printf("%d ",ans[i]);
	return 0;
}
