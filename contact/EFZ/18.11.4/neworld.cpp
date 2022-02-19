#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=5e2+5;
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int ans[MAXN][MAXN],a[MAXN][MAXN],n,m;
int r,p,l,c,qq;
bool use[MAXN][MAXN];
struct rec{
	int x,y;
};
queue<rec> q;
bool bound(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m;
}
int main(){
	freopen("neworld.in","r",stdin);
	freopen("neworld.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	}
	scanf("%d%d%d%d%d",&r,&c,&l,&p,&qq);
	ans[r][c]=l; use[r][c]=1;
	q.push((rec){r,c});
	while (!q.empty()){
//		cout<<ans[r][c]<<endl;
		rec u=q.front(); q.pop();
		for (int i=0;i<4;i++){
			int x=u.x+dx[i],y=u.y+dy[i];
			if (x==r&&y==c) continue;
//			if (!bound(x,y)||use[x][y]) continue;
			if (!bound(x,y)) continue;
//			cout<<"in: "<<x<<" "<<y<<endl;
			int mx=a[x][y];
//			cout<<a[x][y]<<endl;
			for (int j=0;j<4;j++){
				int nx=x+dx[j],ny=y+dy[j];
				if (!bound(nx,ny)) continue;
				mx=max(mx,ans[nx][ny]);
//				cout<<mx<<endl;
			}
			if (mx-a[x][y]==ans[x][y]) continue;
			ans[x][y]=mx-a[x][y];
//			cout<<x<<" "<<y<<" "<<ans[x][y]<<endl;
//			use[x][y]=1;
			q.push((rec){x,y});
		}
	}
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=m;j++) cout<<ans[i][j]<<" ";
//		cout<<endl;
//	}
	printf("%d\n",ans[p][qq]);
	fclose(stdin); fclose(stdout);
	return 0;
}
