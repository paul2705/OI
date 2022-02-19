#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a[15],b[15];
bool chk(ll mid){
//	cout<<mid<<": ";
//	for (int i=1;i<=4;i++) cout<<b[i]<<" ";
//	cout<<endl;
	if (mid>b[4]) return 0;
	b[4]-=mid;
	sort(b+1,b+5);
	if (mid>b[4]) return 0;
	b[4]-=mid;
	return 1;
}
ll check(ll mid){
	ll ret=0;
	for (int k1=1;k1<=4;k1++){
		a[k1]-=mid;
		for (int k2=1;k2<=4;k2++){
			a[k2]-=mid;
			bool fl=1;
			for (int i=1;i<=4;i++){
//				cout<<a[i]<<" ";
				if (a[i]<0) fl=0;
				b[i]=a[i];
			}
//			cout<<endl;
			if (!fl){
				a[k2]+=mid;
				continue;
			}
//			cout<<"in: "<<mid<<" "<<k1<<" "<<k2<<endl;
			sort(b+1,b+5);
//			cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<endl;
//			cout<<b[1]<<" "<<b[2]<<" "<<b[3]<<" "<<b[4]<<endl;
			if (!chk(mid)){
				a[k2]+=mid;
				continue;
			}
//			cout<<"ASK"<<endl;
			for (int i=1;i<=4;i++) b[i]=a[i];
			sort(b+1,b+5);
//			cout<<mid<<" "<<b[4]<<endl;
			ll l=mid,r=b[4],midl;
			while (l+1<r){
				midl=(l+r)>>1;
//				cout<<"mid: "<<l<<" "<<r<<" "<<midl<<endl;
				if (chk(midl)) l=midl;
				else r=midl;
			}
			ret=max(ret,l);
//			cout<<"ans: "<<ret<<endl;
			a[k2]+=mid;
		}
		a[k1]+=mid;
	}
	return ret;
}
int main(){
	freopen("gift.in","r",stdin);
	freopen("gift.out","w",stdout);
	scanf("%lld%lld%lld%lld",&a[1],&a[2],&a[3],&a[4]);
	sort(a+1,a+5);
	ll l=0,r=a[4],midl,midr;
	while (l+1<r){
		midr=(l+r)>>1;
		midl=(l+midr)>>1;
//		cout<<l<<" "<<r<<" "<<mid<<endl;
		if (log(midl)+log(check(midl))>=log(midr)+log(check(midr))) l=midl;
		else r=midr;
	}
	printf("%lld %lld\n",l,check(l));
	fclose(stdin); fclose(stdout);
	return 0;
}
