#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2050;
int f[MAXN][MAXN],cnt[MAXN][MAXN];
int n,h,d,res[MAXN];
int main(){
	scanf("%d%d%d",&n,&h,&d);
	for (int i=1,T;i<=n;i++){
		scanf("%d",&T);
		for (int j=0,x;j<T;j++) scanf("%d",&x),cnt[i][x]++;
	}
	for (int i=h;i>=1;i--){
		for (int j=1;j<=n;j++){
			if (i+d<=h) f[i][j]=max(f[i+1][j],res[i+d])+cnt[j][i];
			else f[i][j]=f[i+1][j]+cnt[j][i];
			res[i]=max(res[i],f[i][j]);
		}
	}
	printf("%d\n",res[1]);
	return 0;
}
