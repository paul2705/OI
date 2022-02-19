#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e6+6;
int a[MAXN],b[MAXN];
int c[MAXN],d[MAXN];
ll h1,w1,h2,w2,cnt1=0,cnt2=0;
ll x,y,ans;
ll gcd(ll a,ll b){ return b==0?a:gcd(b,a%b); }
ll lcm(ll a,ll b){ return a*b/gcd(a,b); }
int main(){
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	scanf("%lld%lld",&h1,&w1);
	for (ll i=1;i<=h1;i++){
		for (ll j=1;j<=w1;j++){
			char c=getchar(); while (c!='0'&&c!='1') c=getchar();
			a[++cnt1]=(c=='1');
		}
	}
	scanf("%lld%lld",&h2,&w2);
	for (ll i=1;i<=h2;i++){
		for (ll j=1;j<=w2;j++){
			char c=getchar(); while (c!='0'&&c!='1') c=getchar();
			b[++cnt2]=(c=='1'); 
		}
	}
//	for (ll i=1;i<=cnt1;i++) cout<<a[i]<<" "; cout<<endl;
//	for (ll i=1;i<=cnt2;i++) cout<<b[i]<<" "; cout<<endl;
	x=lcm(h1,h2); y=lcm(w1,w2);
	ll lh1=0,lh2=0;
	ll pos1=1,pos2=1;
	ll cnt1=0,cnt2=0;
	for (;pos1<=h1||pos2<=h2;){
		if (lh1==0){
			cnt1=0;
			ll l1=(pos1-1)*w1+1,r1=pos1*w1;
//			cout<<"1:"<<pos1<<" "<<l1<<" "<<r1<<endl;
			for (ll i=l1;i<=r1;i++){
				for (ll j=1;j<=y/w1;j++) c[cnt1++]=a[i];
			}
			lh1=x/h1; pos1++;
		}
		if (lh2==0){
			cnt2=0;
			ll l2=(pos2-1)*w2+1,r2=pos2*w2;
			for (ll i=l2;i<=r2;i++){
				for (ll j=1;j<=y/w2;j++) d[cnt2++]=b[i];
			}
//			cout<<"2: "<<pos2<<" "<<l2<<" "<<r2<<endl;
			lh2=x/h2; pos2++;
		}
//		for (ll i=0;i<y;i++) cout<<c[i]<<" "; cout<<endl;
//		for (ll i=0;i<y;i++) cout<<d[i]<<" "; cout<<endl;
//		cout<<pos1<<" "<<lh1<<" "<<pos2<<" "<<lh2<<endl;
		ll res=0;
		for (ll i=0;i<y;i++){
			if (c[i]==d[i]) res++;
		}
		if (lh1<lh2){
			ans+=res*lh1;
			lh2-=lh1; lh1=0;
		}
		else {
			ans+=res*lh2;
			lh1-=lh2; lh2=0;
		}
//		cout<<lh1<<" "<<lh2<<endl;
//		cout<<" :" <<res<<" "<<ans<<endl;
	}
//	cout<<lh1<<" "<<lh2<<endl;
	printf("%lld\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
