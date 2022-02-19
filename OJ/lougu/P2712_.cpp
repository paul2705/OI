#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e3+5;
const int MAXM=1e6+6;
int edge,head[MAXN],tail[MAXM],nex[MAXM],d[MAXN];
bool use[MAXN];
int n,cnt,u[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
int main(){
	scanf("%d",&n);
	for (int i=1,x;i<=n;i++){
		scanf("%d%d",&u[i],&x); use[u[i]]=1;
		for (int j=1,v;j<=x;j++){
			scanf("%d",&v);
			add(u[i],v); d[v]++;
		}
	}
	queue<int> q;
	for (int i=1;i<=n;i++) if (d[u[i]]==0) q.push(i);
	while (!q.empty()){
		cnt++;
		int u=q.front(); q.pop();
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (use[v]){
				d[v]--;
				if (d[v]==0) q.push(v);
			}
		}
	}
	if (cnt==n) printf("YES\n");
	else printf("%d\n",n-cnt);
	return 0;
}
