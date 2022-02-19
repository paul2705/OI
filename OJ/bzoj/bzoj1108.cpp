#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=5e4+5;
int n;
ll ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		ll x,y; scanf("%lld%lld",&x,&y);
		ans+=y-x;
	}
	for (int i=1;i<=n;i++){
		ll x,y; scanf("%lld%lld",&x,&y);
		ans+=x-y;
	}
	printf("%lld\n",ans);
	return 0;
}
