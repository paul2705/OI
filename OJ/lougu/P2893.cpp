#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e3+5;
int n,m,mf[MAXN][MAXN],f[MAXN][MAXN],a[MAXN],b[MAXN],t[MAXN],ans;
void dp(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			f[i][j]=mf[i-1][j]+abs(a[i]-b[j]);
			if (j!=1) mf[i][j]=min(mf[i][j-1],f[i][j]);
			else mf[i][j]=f[i][j];
		}
	}
}
int main(){
	memset(mf,0,sizeof(mf)); memset(f,0,sizeof(f));
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),t[i]=a[i];
	sort(t+1,t+1+n); int now=-1;
	for (int i=1;i<=n;i++){
		if (now!=t[i]) b[++m]=t[i],now=t[i];	
	}
	dp(); ans=mf[n][m];
	for (int i=1;i<=m/2;i++) swap(b[i],b[m-i+1]);
	memset(mf,0,sizeof(mf)); memset(f,0,sizeof(f));
	dp(); ans=min(ans,mf[n][m]);
	printf("%d\n",ans);
	return 0;
}
