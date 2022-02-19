#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=3e5+5;
ll a[MAXN],b[MAXN],x[MAXN],y[MAXN];
ll n,m,ans,A,B;
int main(){
	scanf("%lld%lld%lld%lld",&A,&B,&n,&m);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]); a[n+1]=A; sort(a+1,a+n+2);
	for (int i=1;i<=m;i++) scanf("%lld",&b[i]); b[m+1]=B; sort(b+1,b+m+2);
	for (int i=1;i<=n+1;i++) x[i]=a[i]-a[i-1];
	for (int i=1;i<=m+1;i++) y[i]=b[i]-b[i-1];
	sort(x+1,x+n+2); sort(y+1,y+m+2);
	ans=x[1]*m+y[1]*n;
	for (int i=2,j=2;i<=n+1&&j<=m+1;){
		if (x[i]<y[j]) ans+=x[i++]*(m-j+2);
		else ans+=y[j++]*(n-i+2);
	}
	printf("%lld\n",ans);
	return 0;
}
