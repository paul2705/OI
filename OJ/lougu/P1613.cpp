#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=55;
const int MAXK=65;
int dist[MAXN][MAXN];
int n,m;
bool g[MAXN][MAXN][MAXK];
int main(){
	memset(dist,63,sizeof(dist));
	scanf("%d%d",&n,&m);
	for (int i=0,u,v;i<m;i++){
		scanf("%d%d",&u,&v);
		dist[u][v]=1,g[u][v][0]=1;
	}
	for (int k=1;k<=64;k++){
		for (int i=1;i<=n;i++){
			for (int l=1;l<=n;l++){
				for (int j=1;j<=n;j++){
					if (g[i][l][k-1]&&g[l][j][k-1]){
						dist[i][j]=1;
						g[i][j][k]=1;
					}
				}
			}
		}
	}
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	printf("%d\n",dist[1][n]);
	return 0;
}
