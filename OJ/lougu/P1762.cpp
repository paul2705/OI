#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=55;
const int mod=1e6+3;
typedef long long ll;
ll n,d,z,ans,a[MAXN],b[MAXN],v,p,t;
int main(){
	scanf("%lld",&v);
	n=v,z=1,d=z<<50,t=50;
	while (n!=0){
		if (n>=d) n-=d,a[++a[0]]=t;
		d/=2; t--;
	}
	b[0]=1;
	for (int i=1;i<=a[1];i++) b[i]=(b[i-1]*3)%mod;
	for (int i=1;i<=a[0];i++) ans+=b[a[i]]*(ll)(z<<(i-1));
	p=(((z+v%mod)*(v%mod))/2);
	p%=mod; ans%=mod;
	printf("%lld\n",(p-ans+mod)%mod);
	return 0;
}
