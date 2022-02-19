#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e5+5;
typedef long long ll;
const ll mod=12345678910;
ll s[MAXN],top,a[MAXN],cnt,ans;
ll n,x[MAXN];
int main(){
	scanf("%lld",&n);
	for (int i=1;i<=n;i++){
		scanf("%lld",&x[i]);
		if (x[i]){
			while(s[top])a[cnt-1]=(a[cnt-1]+a[cnt])%mod,cnt--,top--;
			top--;
			if (x[i-1]) a[cnt]=a[cnt]*2%mod;
			else a[++cnt]=1;
		}
		else{
			if (x[i-1]) s[++top]=1;
			s[++top]=0;
		}
	}
	for (int i=1;i<=cnt;i++) a[i]+=a[i-1],a[i]%=mod;
	printf("%lld\n",(a[cnt]+mod)%mod);
	return 0;
}
