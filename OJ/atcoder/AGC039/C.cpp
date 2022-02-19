#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int MAXN=4e5+5;
char x[MAXN];
int a[MAXN],b[MAXN];
int n;
ll cnt[MAXN],ans;
int calc(int len){
	ll res=0,cnt=0;
	for (int i=1;i<=len;i++){
		res=(res*2ll%mod+a[i])%mod;
	}
	for (int i=0;i<2*n;i+=len*2){
		for (int j=1;j<=len;j++) b[i+j]=a[j];
		for (int j=len+1;j<=2*len;j++) b[i+j]=!a[j-len];
	}
	cnt=1;
	while (cnt<=2*n&&a[cnt]==b[cnt]) cnt++;
	res=(res+(cnt>2*n||a[cnt]>b[cnt]))%mod;
	return res;
}
int main(){
	scanf("%d",&n);
	scanf("%s",x+1);
	for (int i=1;i<=n;i++){
		a[i]=(x[i]=='1');
		a[i+n]=(x[i]!='1');
	}
	for (int i=1;i<=n;i++){
		if (n%i==0&&(n/i)&1) cnt[i]=calc(i);
	}
	for (int i=1;i<=n;i++){
		for (int j=2*i;j<=n;j+=i){
			if (n%j==0&&(n/j)&1) cnt[j]=((cnt[j]-cnt[i])%mod+mod)%mod;
		}
	}
	for (int i=1;i<=n;i++) ans=(ans+2ll*i%mod*cnt[i]%mod)%mod;
	printf("%lld\n",ans);
	return 0;
}
