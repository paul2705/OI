#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
#define rg register
const int inf=1e7;
const int MAXN=405;
const int MAXM=2e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
int redge,rhead[MAXN][30],rtail[MAXM],rnex[MAXM],rw[MAXM];
int n,m,Q,f[MAXN][MAXN],g[MAXN][MAXN][30];
struct rec{
	int u,v,c;
};
rec q[MAXN*MAXN*30];
int l=1,r=0;
bool use[MAXN][MAXN][30];
inline void qpush(rec x){ use[x.u][x.v][x.c]=1; q[++r]=x; }
inline void qpop(){ l++; }
inline rec qfront(){ return q[l]; }
inline void add(int u,int v,int c){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=c;
}
inline void radd(int u,int v,int c){
	redge++,rnex[redge]=rhead[u][c],rhead[u][c]=redge,rtail[redge]=v,rw[redge]=c;
}
int main(){
	scanf("%d%d",&n,&m);
	for (rg int i=1;i<=n;i++){
		for (rg int j=1;j<=n;j++){
			f[i][j]=inf;
			for (rg int k=1;k<=26;k++) g[i][j][k]=inf;
		}
	}
	for (rg int i=1;i<=n;i++) f[i][i]=0,qpush((rec){i,i,0});
	for (rg int i=1;i<=m;i++){
		int u,v; char c;
		scanf("%d%d%c%c",&u,&v,&c,&c);
//		cout<<u<<" "<<v<<" "<<c<<endl;
		add(u,v,c-'a'+1); radd(v,u,c-'a'+1);
		f[u][v]=1;// g[u][v][c]=1;
		qpush((rec){u,v,0});// qpush((rec){u,v,c});
	}
	while (l<=r){
		rec tmp=qfront(); qpop();
		int x=tmp.u,y=tmp.v,c=tmp.c;
		use[x][y][c]=0;
		if (c==0){
			for (rg int e=head[y];e;e=nex[e]){
				int v=tail[e];
				if (g[x][v][w[e]]>f[x][y]+1){
//				if (g[x][v][w[e]]==inf){
					g[x][v][w[e]]=f[x][y]+1;
					if (!use[x][v][w[e]]) qpush((rec){x,v,w[e]});
//					qpush((rec){x,v,w[e]});
				}
			}
		}
		else {
			for (rg int e=rhead[x][c];e;e=rnex[e]){
				int v=rtail[e];
				if (f[v][y]>g[x][y][rw[e]]+1){
//				if (f[v][y]==inf){
					f[v][y]=g[x][y][rw[e]]+1;
					if (!use[v][y][0]) qpush((rec){v,y,0});
//					qpush((rec){v,y,0});
				}
			}
		}
	}
	scanf("%d",&Q);
	int las; scanf("%d",&las);
	for (rg int i=1;i<Q;i++){
		int x; scanf("%d",&x);
		printf("%d\n",f[las][x]>=inf?-1:f[las][x]);
		las=x;
	}
	return 0;
}
