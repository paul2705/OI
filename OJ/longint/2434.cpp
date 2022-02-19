#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=5050;
ll x[MAXN],y[MAXN],b[MAXN],q[MAXN];
int n,cnt=0;
ll f[MAXN];
int main(){
	scanf("%d",&n);
	for (int i=1;i<5050;i++) f[i]=1e18;
	for (int i=0;i<n;i++){
		scanf("%lld%lld",&x[i],&y[i]);
		x[i]=abs(x[i]); y[i]=abs(y[i]);
		b[cnt++]=x[i];
	}
	sort(b,b+cnt); cnt=unique(b,b+cnt)-b;
	for (int i=0;i<n;i++){
		int pos=lower_bound(b,b+cnt,x[i])-b+1;
		q[pos]=max(q[pos],y[i]);
	}
	for (int i=1;i<=cnt;i++){
		ll dy=0;
		for (int j=i;j>=1;j--){
			dy=max(dy,q[j]);
			f[i]=min(f[i],f[j-1]+dy*b[i-1]);
		}
	}
	printf("%lld\n",f[cnt]*4);
	return 0;
}
