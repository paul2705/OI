#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e4+5;
const int MAXE=1e5+5;
int edge,head[MAXN],nex[MAXE],tail[MAXE];
int n,m,puh[MAXN],low[MAXN],dfn[MAXN],cnt,res;
int s[MAXN],top,num[MAXN],cmp[MAXN],ans;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void tarjan(int u){
	dfn[u]=low[u]=++res;
	s[++top]=u; puh[u]=1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (!dfn[v]){
			tarjan(v); low[u]=min(low[u],low[v]);
		}
		else if (puh[v]) low[u]=min(low[u],dfn[v]);
	}
	if (dfn[u]==low[u]){
		cnt++; int v;
		do{
			num[cnt]++; v=s[top--];
			cmp[v]=cnt; puh[v]=0;
		}while (u!=v);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0,u,v;i<m;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	for (int i=1;i<=n;i++){
		if (!dfn[i]) tarjan(i);
	}
	for (int i=1;i<=cnt;i++){
		if (num[i]>1) ans++;
	}
	printf("%d\n",ans);
	return 0;
} 
