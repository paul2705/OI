#pragma GCC optimize(3)
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2505;
const int MAXS=1e2+5;
int f1[MAXN][MAXS],f2[MAXN][MAXS];
int n,m,s,p;
ll ans=0;
int t[MAXN],t1[MAXN];
int inv[MAXN*MAXN],pow[MAXN*MAXN],fac[MAXN*MAXN],rfac[MAXN*MAXN];
int C(int n,int m){
	if (n<0||m<0||n<m) return 0;
	return 1ll*fac[n]*rfac[m]%p*rfac[n-m]%p;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&p);
	pow[0]=fac[0]=inv[1]=rfac[0]=1;
	for (int i=1;i<=n*m;i++) pow[i]=1ll*pow[i-1]*(s+1)%p;
	for (int i=1;i<=n+m;i++){
//		pow[i]=1ll*pow[i-1]*(s+1)%p;
		fac[i]=1ll*fac[i-1]*i%p;
		if (i!=1) inv[i]=(1ll*-inv[p%i]*(p/i))%p;
		rfac[i]=1ll*rfac[i-1]*(inv[i]+p)%p;
	}
	f1[0][0]=1;
	for (int i=1;i<=n;i++){
		for (int j=0;j<=s;j++){
			for (int k=0;k<=j;k++){
				f1[i][j]=(f1[i][j]+1ll*f1[i-1][j-k]*k)%p;
			}
		}
	}
	f2[0][0]=1;
	for (int i=1;i<=m;i++){
		for (int j=0;j<=s;j++){
			for (int k=0;k<=j;k++){
				f2[i][j]=(f2[i][j]+1ll*f2[i-1][j-k]*(k+1))%p;
			}
		}
	}
	for (int i=1;i<n;i++){
		for (int j=0;j<=s;j++) t[j]=t1[j]=0;
		int x=i-1,y=m-2,c=C(x+y,x);
		for (int j=0;j<=s;j++){
			for (int k=0;k<=j;k++) t[j]=(t[j]+1ll*f1[x][j-k]*f2[y][k])%p;
		}
		for (int j=0;j<=s;j++){
			for (int k=0;k<=j;k++) t1[j]=(t1[j]+1ll*t[j-k]*(k+1))%p;
		}
		for (int j=0;j<=s;j++){
			int a=n*m-i-m-x-y-(n-i);
			ll ret=1ll*t1[j]*c%p*pow[a]%p*C(s-j+n-i-1,n-i-1)%p;
//			cout<<ret<<" "<<t1[j]<<" "<<c<<" "<<pow[a]<<" "<<C(s-j+n-i-1,n-i-1)<<endl;
			ans=(ans+ret)%p;
		}
	}
	for (int i=1;i<m;i++){
		for (int j=0;j<=s;j++) t[j]=t1[j]=0;
		int x=n-2,y=i-1,c=C(x+y,x);
		for (int j=0;j<=s;j++){
			for (int k=0;k<=j;k++) t[j]=(t[j]+1ll*f1[x][j-k]*f2[y][k])%p;
		}
		for (int j=0;j<=s;j++){
			for (int k=0;k<=j;k++) t1[j]=(t1[j]+1ll*t[j-k]*k)%p;
		}
		for (int j=0;j<=s;j++){
			int a=n*m-n-i-x-y-(m-i);
			ll ret=1ll*t1[j]*c%p*pow[a]%p*C(s-j+m-i-1,m-i-1)%p;
			ans=(ans+ret)%p;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
