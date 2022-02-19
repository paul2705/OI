#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
ll a[MAXN],n,ans;
int main(){
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]),a[i]+=a[i-1];
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			ans^=a[j]-a[i-1];
		}
	}
	printf("%lld\n",ans);
	return 0;
}
