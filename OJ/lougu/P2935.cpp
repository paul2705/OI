#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e2+5;
int f[MAXN][MAXN],g[MAXN][MAXN];
int n,m,t;
int a[MAXN];
int main(){
	scanf("%d%d%d",&n,&m,&t);
	for (int i=1;i<=m;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) f[i][j]=5e8;
		f[i][i]=0;
	}
	for (int i=1;i<=t;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		f[u][v]=w; f[v][u]=w;
	}
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	int ans=0,mn=1e9;
	for (int i=1;i<=n;i++){
		int cnt=0;
		for (int j=1;j<=m;j++) cnt+=f[i][a[j]];
		if (mn>cnt) mn=cnt,ans=i;
	}
	printf("%d\n",ans);
	return 0;
}
