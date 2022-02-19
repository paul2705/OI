#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
ll f[MAXN];
int n,m,a[MAXN],b[MAXN];
ll dis(int x,int y){
	if (a[x]==b[y]) return 1e18;
	return abs(a[x]-b[y]);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
	sort(a+1,a+n+1); sort(b+1,b+n+1);
	for (int i=1;i<=n;i++){
		ll t=1e18;
		t=min(t,dis(i,i)+f[i-1]);
		if (i>=2) t=min(t,dis(i,i-1)+dis(i-1,i)+f[i-2]);
		if (i>=3){
			t=min(t,dis(i,i-2)+dis(i-1,i)+dis(i-2,i-1)+f[i-3]);
			t=min(t,dis(i-2,i)+dis(i-1,i-2)+dis(i,i-1)+f[i-3]);
		}
		f[i]=t;
	}
	if (f[n]==1e18) printf("-1\n");
	else printf("%lld\n",f[n]);
	return 0;
}
