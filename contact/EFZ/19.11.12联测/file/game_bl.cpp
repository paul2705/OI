#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e6+6;
ll cnt[MAXN],s[MAXN],a[MAXN],b[MAXN];
int n,m;
bool check(ll mid){
	for (int i=1;i<=n;i++) b[i]=a[i],s[i]=0;
	for (int i=1;i<=n;i++){
		ll ret=0,now=mid-1;
		for (int j=i-1;j>max(0ll,i-mid);j--){
			ret+=now*cnt[j];
			now--;
		}
		b[i]-=ret;
		if (b[i]<=0){
			cnt[i]=0; s[i]=s[i-1];
		}
		else {
			cnt[i]=ceil((double)b[i]/(double)mid);
			s[i]=s[i-1]+cnt[i];
		}
//		cout<<b[i]<<" "<<cnt[i]<<" "<<s[i]<<endl;
	}
	return s[n]<=m;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.ans","w",stdout);
	scanf("%d%d",&n,&m);
	ll mx=0,mx1=0;
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]),mx=max(mx,a[i]+i-1),mx1=max(mx1,a[i]);
	if (mx1==0) printf("0\n");
	else {
		for (ll i=1;i<=mx;i++){
			if (check(i)){
				printf("%lld\n",i);
				break;
			}
		}
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
