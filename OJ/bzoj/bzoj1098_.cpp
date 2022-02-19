#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=1e5+5;
vector<int> g[MAXN];
int n,m;
int ans[MAXN],cnt,tmp;
bool use[MAXN];
queue<int> q;
void bfs(int s){
	q.push(s);
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int i=1;i<g[u].size();i++){
			int l=g[u][i-1],r=g[u][i];
			for (int j=l+1;j<r;j++){
				if (!use[j]){
					use[j]=1;
					tmp++;
					q.push(j);
				}
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i=1;i<=n;i++){
		g[i].push_back(0);
		g[i].push_back(n+1);
		sort(g[i].begin(),g[i].end());
	}
	for (int i=1;i<=n;i++){
		if (!use[i]){
			tmp=0;
			bfs(i);
			ans[cnt++]=tmp;
		}
	}
	sort(ans,ans+cnt);
	printf("%d\n",cnt);
	for (int i=0;i<cnt;i++) printf("%d ",ans[i]);
	return 0;
}
