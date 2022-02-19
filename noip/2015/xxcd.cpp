#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=2e5+5;
const int MAXM=MAXN*2;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int n,m,a[MAXN],d[MAXN],rd[MAXN];
int ans=1e9;
int use[MAXN],top;
queue<int> q;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void bfs(int u,int top){
	q.push(u);
	while (!q.empty()){
	int u=q.front(); q.pop();
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
			if (use[v]==top) ans=min(ans,d[u]+1-d[v]);
			else d[v]=d[u]+1,use[v]=top,q.push(v);
		}
	}
}
int main(){
	freopen("message.in","r",stdin);
	freopen("message.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		add(i,a[i]);
	}
	for (int i=1;i<=n;i++){
		if (!use[i]) bfs(i,top++);
	}
	printf("%d\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
