#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e3+5;
int f[MAXN][MAXN],a[MAXN],b[MAXN];
int n,cnta,cntb,x,y,z;
int main(){
	scanf("%d%d%d%d",&n,&x,&y,&z); swap(x,y);
	for (int i=1,xx,yy;i<=n;i++){
		scanf("%d%d",&xx,&yy);
		for (int j=1;j<=xx;j++) a[++cnta]=i;
		for (int j=1;j<=yy;j++) b[++cntb]=i;
	}
	for (int i=1;i<=cnta;i++) f[i][0]=i*x;
	for (int i=1;i<=cntb;i++) f[0][i]=i*y;
	for (int i=1;i<=cnta;i++){
		for (int j=1;j<=cntb;j++){
			f[i][j]=min(f[i-1][j]+x,min(f[i][j-1]+y,f[i-1][j-1]+z*abs(a[i]-b[j])));
		}
	}
	printf("%d\n",f[cnta][cntb]);
	return 0;
}
