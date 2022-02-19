#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<cmath>
using namespace std;
const int MAXN=22;
typedef long long ll;
ll n,K,a[MAXN];
ll w[MAXN],cnt[MAXN];
bitset<21> t;
int main(){
	scanf("%lld%lld",&n,&K);
	for (int i=1;i<=10;i++) scanf("%lld",&a[i]);
	for (int i=0;i<n;i++) scanf("%lld%lld",&w[i],&cnt[i]);
	ll mn=K,pos;
	for (int s=0;s<(1<<n);s++){
		ll ret=K;
		for (int i=0;i<n;i++){
			if (s&(1<<i)) ret-=w[i];
		}
		if (abs(ret)<mn){
			mn=abs(ret);
			pos=s;
		}
	}
	t=pos;
	printf("mn: %lld\n",mn);
	cout<<"state: "<<t<<endl;
	ll ret=K;
	for (int i=0;i<n;i++){
		if (pos&(1<<i)) printf("1\n");
		else printf("0\n");
	}
//	printf("%lld\n",ret);
	return 0;
}
