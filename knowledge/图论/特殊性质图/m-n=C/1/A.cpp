#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=2*MAXN+50;
int edge,head[MAXN],nex[MAXM],tail[MAXM];
int n,m,rd[MAXN],fa[MAXN];
int ans;
vector<int> g[MAXN];
queue<int> q;
bool use[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
	rd[v]++;
}
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){
	int fx=find(x),fy=find(y);
	fa[fx]=fy;
}
void dfs(int u,int p,int tp){
	for (int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if (v==p||v<tp) continue;
		if (v==tp){
			ans++;
			continue;
		}
		if (!use[v]){
			use[v]=1;
			dfs(v,u,tp);
			use[v]=0;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	for (int i=1;i<=n+1;i++) fa[i]=i;
	for (int i=1;i<=n;i++){
		if (rd[i]==1) q.push(i),fa[i]=n+1;
	}
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			rd[v]--;
			if (rd[v]==1) q.push(v),fa[v]=n+1;
		}
	}
	for (int i=1;i<=n;i++){
		if (rd[i]==2){
			for (int e=head[i];e;e=nex[e]){
				int v=tail[e];
				if (rd[v]==2) uion(i,v);
			}
		}
	}
	for (int i=1;i<=n;i++){
		if (find(i)>n) continue;
		for (int e=head[i];e;e=nex[e]){
			int v=tail[e],fx=find(i),fy=find(v);
			if (fx!=fy){
				g[fx].push_back(fy); 
//				g[fy].push_back(fx);
//				cout<<fx<<" "<<fy<<endl;
			}
		}
	}
/*	int cnt=0;
	for (int i=1;i<=n;i++){
		if (find(i)==i) cnt++;
	}
	printf("%d\n",cnt);
*/
	for (int i=1;i<=n;i++) use[i]=0;
	for (int i=1;i<=n;i++){
//		for (int i=1;i<=n;i++) use[i]=0;
//		if (find(i)!=i) continue;
		dfs(i,0,i);
	}
	printf("%d\n",ans/2);
	return 0;
}
