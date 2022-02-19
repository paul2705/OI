#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=55;
typedef long long ll;
ll n,d[MAXN];
int main(){
	scanf("%lld",&n);
	ll t1=0,t2=0;
	for (int i=1;i<=n;i++){
		scanf("%lld",&d[i]);
		t1+=d[i]; t2+=d[i]*d[i];
	}
	printf("%lld\n",(t1*t1-t2)/2);
	return 0;
}
