#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=505;
int n,k,x[MAXN],y[MAXN],f[MAXN][MAXN],a[MAXN][MAXN];
inline int dist(int a,int b){
	return abs(x[a]-x[b])+abs(y[a]-y[b]);
}
int main(){
	scanf("%d%d",&n,&k);
	memset(f,63,sizeof(f));
	for (int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	f[1][0]=0;
	for (int i=0;i<=n;i++) f[i][i]=0;
	for (int i=2;i<=n;i++){
		for (int j=0;j<=min(i-1,k);j++){
			for (int l=0;l<=j;l++) f[i][j]=min(f[i][j],f[i-l-1][j-l]+dist(i,i-l-1));
		}
	}
	printf("%d\n",f[n][k]);
	return 0;
}
