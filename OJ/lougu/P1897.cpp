#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=15;
const int mod=1e9;
int f[MAXN][(1<<MAXN)];
int a[MAXN][MAXN],F[MAXN];
int n,m,ans,s[(1<<MAXN)];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) F[i]=(F[i]<<1)+a[i][j];
	}
	for (int i=0;i<(1<<m);i++) s[i]=((i&(i<<1))==0)&&((i&(i>>1))==0);
	f[0][0]=1;
	for (int i=1;i<=n;i++){
		for (int j=0;j<(1<<m);j++){
			if (s[j]&&((j&F[i])==j)){
				for (int k=0;k<(1<<m);k++){
					if ((k&j)==0) f[i][j]=(f[i][j]+f[i-1][k])%mod;
				}
			}
		}
	}
	int ans=0;
	for (int i=0;i<(1<<m);i++) ans+=f[n][i],ans%=mod;
	printf("%d\n",ans);
	return 0;
}
