#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e6+6;
ll a[MAXN],b[MAXN],cnt[MAXN],s[MAXN];
int n,m;
bool check(ll mid){
	for (int i=1;i<=n;i++) b[i]=a[i],s[i]=0;
	ll ret=0;
	for (int i=1;i<=n;i++){
//		cout<<"id:"<<i<<" org:"<<b[i]<<" del:"<<ret<<" ans:"<<b[i]-ret<<endl;
		b[i]-=ret;
		if (b[i]<=0){
			cnt[i]=0; s[i]=s[i-1];
			ret-=s[i-1]-s[i-mid<0?0:i-mid];
			ret+=(mid-1)*cnt[i];
		}
		else {
			cnt[i]=ceil((double)b[i]/(double)mid);
			s[i]=s[i-1]+cnt[i];
			ret-=s[i-1]-s[i-mid<0?0:i-mid];
			ret+=(mid-1)*cnt[i];
		}
//		cout<<b[i]<<" "<<cnt[i]<<" "<<s[i]<<endl;
	}
	return s[n]<=m;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&n,&m);
	ll mx=0;
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]),mx=max(mx,a[i]+i-1);
	ll l=0,r=mx,mid;
	while (l+1<r){
//		cout<<l<<" "<<r<<" "<<((l+r)>>1)<<endl;
		mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid;
//		cout<<endl;
	}
	printf("%lld\n",r);
	fclose(stdin); fclose(stdout);
	return 0;
}
