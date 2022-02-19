#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
ll a[MAXN],n,ans;
bool cmp(ll a,ll b){ return a>b; }
int main(){
	scanf("%I64d",&n);
	for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%I64d",&a[i+n]),ans-=a[i+n];
	sort(a+1,a+2*n+1,cmp);
	for (int i=1;i<=2*n;i+=2) ans+=a[i];
	printf("%I64d\n",ans);
	return 0;
}
