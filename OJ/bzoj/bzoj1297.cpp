#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=2009;
const int MAXN=105;
struct rec{
	int a[MAXN][MAXN];
	rec(){
		for (int i=0;i<105;i++){
			for (int j=0;j<105;j++) a[i][j]=0;
		}
	}
} A;
int n,m;
rec mul(rec a,rec b){
	rec c;
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j]%mod)%mod;
			}
		}
	}
	return c;
}
rec mod_pow(rec a,int n){
	rec res; res=a; n--;
	while (n){
		if (n&1) res=mul(res,a);
		a=mul(a,a);
		n>>=1;
	}
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<9;j++){
			A.a[(i-1)*9+j][(i-1)*9+j+1]=1;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			char c=getchar(); while (c<'0'||c>'9') c=getchar();
			int tmp=c-'0';
			if (tmp==0) continue;
			A.a[(i-1)*9+tmp][(j-1)*9+1]=1;
		}
	}
	n*=9; A=mod_pow(A,m);
	printf("%d\n",A.a[1][n-8]);
	return 0;
}
