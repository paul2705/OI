#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
typedef long long ll;
const ll mod=998244353;
ll f[MAXN],F[MAXN];
ll n,ans;
struct mat{
	ll a[6][6];
	mat(){
		for (int i=0;i<=5;i++){
			for (int j=0;j<=5;j++) a[i][j]=0;
		}
	}
	void operator = (const mat& b){
		for (int i=1;i<=5;i++){
			for (int j=1;j<=5;j++) a[i][j]=b.a[i][j];
		}
//		return c;
	}
	mat operator * (const mat& b) const {
		mat c;
		for (int k=1;k<=5;k++){
			for (int i=1;i<=5;i++){
				for (int j=1;j<=5;j++){
					c.a[i][j]=(c.a[i][j]+a[i][k]*b.a[k][j]%mod)%mod;
				}
			}
		}
		return c;
	}
} A;
void solve1(){
	f[0]=f[1]=1;
	for (int i=2;i<=n;i++) f[i]=(f[i-1]+f[i-2])%mod;
	F[0]=1; F[1]=2;
	for (int i=2;i<=n;i++) F[i]=((F[i-1]+F[i-2])%mod+f[i])%mod;
	for (int i=0;i<=n;i++){
//		printf("%lld %lld\n",f[i],F[i]);
		ans=(ans+F[i])%mod;
	}
	printf("%lld\n",(ans%mod+mod)%mod);
}
mat mod_pow(mat x,ll n){
	if (n<=0) return x;
	mat tmp; tmp=x;
	n--;
	while (n){
		if (n&1) tmp=tmp*x;
		x=x*x;
		n>>=1;
	}
	return tmp;
}
void solve2(){
	A.a[1][1]=A.a[1][2]=A.a[1][3]=1;
	A.a[2][1]=1;
	A.a[3][3]=A.a[3][4]=A.a[3][5]=1;
	A.a[4][3]=1;
	A.a[5][5]=1;
//	mat b,c;
//	b=A; c=A;
//	A=b*c*c;
//	for (int i=1;i<=2;i++){
//		for (int j=1;j<=2;j++) cout<<A.a[i][j]<<" ";
//		cout<<endl;
//	}
	A=mod_pow(A,n-1);
//	for (int i=1;i<=5;i++){
//		for (int j=1;j<=5;j++) cout<<A.a[i][j]<<" ";
//		cout<<endl;
//	}
	ll ans=(A.a[1][1]*3ll%mod+A.a[1][2])%mod;
	ans=(((ans+A.a[1][3]*4ll%mod)%mod+A.a[1][4]*2ll%mod)%mod+A.a[1][5])%mod;
	if (n==0) printf("1\n");
	else if (n==1) printf("3\n");
	else printf("%lld\n",(ans%mod+mod)%mod);
}
int main(){
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	scanf("%lld",&n);
//	solve1();
//	solve2();
	if (n<=1e6) solve1();
	else solve2();
	fclose(stdin); fclose(stdout);
	return 0;
}
