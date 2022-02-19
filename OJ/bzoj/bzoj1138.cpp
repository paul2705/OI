#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int inf=1e9;
const int MAXN=405;
const int MAXM=2e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
int redge,rhead[MAXN],rtail[MAXM],rnex[MAXM],rw[MAXM];
int n,m,Q,f[MAXN][MAXN],g[MAXN][MAXN][30];
struct rec{
	int u,v,c;
};
queue<rec> q;
void add(int u,int v,int c){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=c;
}
void radd(int u,int v,int c){
	redge++,rnex[redge]=rhead[u],rhead[u]=redge,rtail[redge]=v,rw[redge]=c;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			f[i][j]=inf;
			for (int k=1;k<=26;k++) g[i][j][k]=inf;
		}
	}
	for (int i=1;i<=m;i++){
		int u,v; char c;
		scanf("%d%d%c%c",&u,&v,&c,&c);
		add(u,v,c-'a'+1); radd(v,u,c-'a'+1);
		f[u][v]=1;
		q.push((rec){u,v,0});
	}
	for (int i=1;i<=n;i++) f[i][i]=0,q.push((rec){i,i,0});
	while (!q.empty()){
		rec tmp=q.front(); q.pop();
		int x=tmp.u,y=tmp.v,c=tmp.c;
		if (c==0){
			for (int e=head[y];e;e=nex[e]){
				int v=tail[e];
				if (g[x][v][w[e]]>f[x][y]+1){
					g[x][v][w[e]]=f[x][y]+1;
					q.push((rec){x,v,w[e]});
				}
			}
		}
		else {
			for (int e=rhead[x];e;e=rnex[e]){
				int v=rtail[e];
				if (f[v][y]>g[x][y][rw[e]]+1){
					f[v][y]=g[x][y][rw[e]]+1;
					q.push((rec){v,y,0});
				}
			}
		}
	}
	scanf("%d",&Q);
	int las; scanf("%d",&las);
	for (int i=1;i<Q;i++){
		int x; scanf("%d",&x);
		printf("%d\n",f[las][x]>=inf?-1:f[las][x]);
		las=x;
	}
	return 0;
}
