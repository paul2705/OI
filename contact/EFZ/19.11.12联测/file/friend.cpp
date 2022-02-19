#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll inf=1e15;
const int MAXN=205;
int n,m,q;
struct rec{
	ll g[MAXN][MAXN];
	void clr(){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++) g[i][j]=inf;
		}
	}
	void ins(int u){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (g[i][j]>g[i][u]+g[u][j]){
					g[i][j]=g[i][u]+g[u][j];
				}
			}
		}
	}
	void prt(){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				printf("%d %d %lld\n",i,j,g[i][j]);
			}
		}
	}
} G,f[MAXN];
void solve(rec& G,int l,int r){
	if (l==r) return f[l]=G,void();
	int mid=(l+r)>>1;
	rec tmp=G;
	for (int i=l;i<=mid;i++) G.ins(i);
	solve(G,mid+1,r);
	G=tmp;
	for (int i=mid+1;i<=r;i++) G.ins(i);
	solve(G,l,mid);
	G=tmp;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	G.clr();
	for (int i=1;i<=m;i++){
		int x,y;ll w; scanf("%d%d%lld",&x,&y,&w);
		G.g[x][y]=min(G.g[x][y],w);
		G.g[y][x]=min(G.g[y][x],w);
	}
	solve(G,1,n);
	for (int i=1;i<=q;i++){
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		printf("%lld\n",f[a].g[b][c]>=inf?-1:f[a].g[b][c]);
	}
	return 0;
}
