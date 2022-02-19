#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
typedef long long ll;
ll a[MAXN],n,x;
int main(){
	scanf("%lld",&n);
	for (int i=0;i<n;i++){
		scanf("%lld",&x);
		for (int j=50;j>=0;j--){
			if (x&(1ll<<j)){
				if (!a[j]){ a[j]=x; break; }
				else x^=a[j];
			}
		}
	}
	ll ans=0;
	for (int i=50;i>=0;i--){
		if (ans<(ans^a[i])) ans^=a[i];
	}
	printf("%lld\n",ans);
	return 0;
}
