#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=5e3+5;
const int MAXM=5e5+5;
const int mod=80112002;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int n,m,id[MAXN],od[MAXN],f[MAXN];
queue<int> q;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
	od[u]++; id[v]++;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v);
	}
	for (int i=1;i<=n;i++){
		if (!id[i]) q.push(i),f[i]=1;
	}
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			id[v]--; f[v]=(f[v]+f[u])%mod;
			if (id[v]==0) q.push(v);
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		if (!od[i]) ans=(ans+f[i])%mod;
	}
	printf("%d\n",ans);
	return 0;
}
