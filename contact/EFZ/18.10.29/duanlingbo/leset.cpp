#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int MAXN=1e6+5;
struct rec{
	ll a[3][3];
	void clear(){
		for (int i=1;i<=2;i++){
			for (int j=1;j<=2;j++) a[i][j]=0;
		}
	}
	void print(){
		for (int i=1;i<=2;i++){
			for (int j=1;j<=2;j++) cout<<a[i][j]<<" ";
			cout<<endl;
		}
	}
} l_,r_,l,x,r,c,ret;
ll n,cnt[3];
ll inv,inv_;
char s[MAXN];
ll res,stp;
char in[MAXN];
ll mod_pow_1(ll x,ll n){
	ll ret=1;
	while (n>0){
		if (n&1) ret=ret*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return ret;
}
void mul(rec &a,rec b){
	for (int i=1;i<=2;i++){
		for (int j=1;j<=2;j++) c.a[i][j]=0;
	}
	for (int k=1;k<=2;k++){
		for (int i=1;i<=2;i++){
			for (int j=1;j<=2;j++){
				c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j]%mod)%mod;
			}
		}
	}
	for (int i=1;i<=2;i++){
		for (int j=1;j<=2;j++) a.a[i][j]=c.a[i][j];
	}
}
rec mod_pow(rec a,ll n){
	if (n==0) return ret;
	for (int i=1;i<=2;i++){
		for (int j=1;j<=2;j++) ret.a[i][j]=a.a[i][j];
	}
	n--;
	while (n>0){
		if (n&1) mul(ret,a);
		mul(a,a);
		n>>=1;
	}
	return ret;
}
int main(){
	freopen("leset.in","r",stdin);
	freopen("leset.out","w",stdout);
	scanf("%lld",&n);
	scanf("%s",in);
	l.a[1][1]=l.a[1][2]=l.a[2][2]=1; l.a[2][0]=0;
	r.a[1][1]=r.a[2][1]=r.a[2][2]=1; r.a[1][2]=0;
	x.a[1][1]=x.a[2][2]=1; x.a[1][2]=x.a[2][1]=0;
	for (int i=0;i<n;i++){
		stp=res=0;
		while (in[i]=='L'||in[i]=='R') s[res++]=in[i++];
		while (in[i]>='0'&&in[i]<='9') stp=stp*10+in[i++]-'0';
		i--;
		rec ret; ret.clear();
		if (s[0]=='L') ret=l;
		else ret=r;
		for (int j=1;j<res;j++){
			if (s[j]=='L') mul(ret,l);
			else mul(ret,r);
		}
		l_=mod_pow(ret,stp);
		mul(x,l_);
	}
	ll a=x.a[2][1]+x.a[2][2],b=x.a[1][1]+x.a[1][2];
	inv=mod_pow_1(b,mod-2);
	inv=(mod+inv%mod)%mod;
	printf("%lld\n",(a%mod*inv%mod+mod)%mod);
	fclose(stdin); fclose(stdout);
	return 0;
}
