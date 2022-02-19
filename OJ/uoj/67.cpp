#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=2e5+5;
int edge=1,head[MAXN],nex[MAXM],tail[MAXM];
int n,m,dfn[MAXN],low[MAXN],tim;
int ans[MAXN],cnt,rd[MAXN];
//map<int,int> mp[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
	rd[v]++;
}
void tarjan(int u,int E){
	dfn[u]=low[u]=++tim;
//	cout<<u<<" "<<E<<endl;
	int son=0;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if ((e^E)==1) continue;
		if (!dfn[v]){
			tarjan(v,e);
			low[u]=min(low[u],low[v]);
			if (low[v]>=dfn[u]) son++;
		}
		else low[u]=min(low[u],low[v]);
	}
//	cout<<u<<" dfn:"<<dfn[u]<<" low:"<<low[u]<<endl;;
	if ((u==1&&son==1)||(u!=1&&son==0)){
//		cout<<"in: "<<u<<" rd:"<<rd[u]<<endl;
		if (rd[u]==m-n+2) ans[cnt++]=u;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
//		if (mp[u].find(v)!=mp[u].end()||mp[v].find(u)!=mp[v].end()) printf("YES\n");
//		else mp[u][v]=1,mp[v][u]=1;
	}
	for (int i=1;i<=n;i++){
		if (rd[i]==0) return printf("1\n%d\n",i),0;
	}
	tarjan(1,0);
	sort(ans,ans+cnt);
	printf("%d\n",cnt);
	for (int i=0;i<cnt;i++) printf("%d ",ans[i]);
	cout<<endl;
}
