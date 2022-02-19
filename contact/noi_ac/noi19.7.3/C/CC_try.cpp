#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll ans;
ll a[10000005];
int main(){
	for (int i=1;i<=1e7;i++){
		ans=ans+i;
		a[i]=a[i-10]+1;
	}
	printf("%lld\n",ans);
	for (int i=1e7-10;i<=1e7;i++) printf("%lld\n",a[i]);
	return 0;
}
