#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e3+5;
const int MAXK=60;
const int inf=1e9;
int n,m,q;
int dis[MAXK][MAXK][MAXN];
int main(){
	scanf("%d%d",&n,&m);
	for (int l=1;l<=m;l++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				dis[i][j][l]=inf;
			}
		}
	}
	for (int i=1;i<=m;i++){
		ll a,b,w;
		scanf("%lld%lld%lld",&a,&b,&w);
		if (dis[a][b][1]>w) dis[a][b][1]=w;
	}
	for (int l=2;l<=m;l++){
		for (int k=1;k<=n;k++){
			for (int i=1;i<=n;i++){
				for (int j=1;j<=n;j++){
					dis[i][j][l]=min(dis[i][j][l],dis[i][k][l-1]+dis[k][j][1]);
				}
			}
		}
	}
	scanf("%d",&q);
	for (int i=1,x,y;i<=q;i++){
		double ans=inf,mn=inf;
		scanf("%d%d",&x,&y);
		for (int l=1;l<=n;l++){
			if (dis[x][y][l]<inf) ans=(double)dis[x][y][l]/(double)l;
			mn=min(mn,ans);
		}
		if (mn==inf) printf("OMG!\n");
		else printf("%.3lf\n",mn);
	}
	return 0;
}
