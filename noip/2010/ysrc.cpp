#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=5e2+5;
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int a[MAXN][MAXN];
int ans,n,m,cnt[MAXN];
bool use[MAXN][MAXN],vis[MAXN];
struct rec{
	int x,y;
} ret[MAXN];
int ub[MAXN][MAXN],lb[MAXN][MAXN];
bool bd(int x,int y){
	return x<1||x>n||y<1||y>m;
}
void dfs(int sx,int sy){
	use[sx][sy]=1;
	for (int k=0;k<4;k++){
		int nx=sx+dx[k],ny=sy+dy[k];
		if (bd(nx,ny)) continue;
		if (a[nx][ny]>=a[sx][sy]) continue;
		if (!use[nx][ny]) dfs(nx,ny);
		lb[sx][sy]=min(lb[sx][sy],lb[nx][ny]);
		ub[sx][sy]=max(ub[sx][sy],ub[nx][ny]);
	}
}
bool cmp(rec a,rec b){ return a.x==b.x?a.y<b.y:a.x<b.x; }
int main(){
//	freopen("ysrc.in","r",stdin);
	scanf("%d%d",&n,&m);
	memset(lb,63,sizeof(lb));
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	}
	for (int i=1;i<=m;i++) lb[n][i]=ub[n][i]=i;
	for (int i=1;i<=m;i++) if (!use[1][i]) dfs(1,i);
	int f=0;
	for (int i=1;i<=m;i++){
		ret[i]=(rec){lb[1][i],ub[1][i]};
		if (!use[n][i]) f++;
	}
	if (f>0){ printf("0\n%d\n",f); return 0; }
	int now=1;
//	sort(ret+1,ret+m+1,cmp);
	for (;now<=m;){
		int mx=0;
		for (int i=1;i<=m;i++)
			if (ret[i].x<=now) mx=max(mx,ret[i].y);
		ans++;
		now=mx+1;
	}
	printf("1\n%d\n",ans);
	return 0;
}
