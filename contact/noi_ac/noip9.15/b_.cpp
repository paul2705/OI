#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100;
ll a[MAXN],n,m,p,ans;
ll num[MAXN];
ll mod_pow(ll x,ll n){
	ll ret=1;
	while (n){
		if (n&1) ret=ret*x%p;
		x=x*x%p;
		n>>=1;
	}
	return ret;
}
void dg(int d,int goal,int cnt){
	if (d==goal+1){
//		cout<<"in"<<endl;
		if (cnt>goal){
			ans++;
			return;
		}
		int ret=0;
//		for (int i=1;i<d;i++) cout<<a[i]<<" ";
//		cout<<endl;
		for (int i=1;i<=cnt;i++) num[i]=0;
		for (int i=1;i<=cnt;i++) num[a[i]]++;
		for (int i=1;i<=cnt;i++) ret+=(num[i]==1);
		if (ret==cnt) return;
//		cout<<"cmp: "<<ret<<" ";
		for (int i=cnt+1;i<d;i++){
			num[a[i-cnt]]--;
			num[a[i]]++; ret=0;
			for (int j=1;j<=cnt;j++) ret+=(num[j]==1);
			if (ret==cnt) return;
//			cout<<ret<<" ";
		}
		ans=(ans+1)%p;
//		cout<<endl<<"lll: "<<ans<<endl;
		return;
	}
	for (int i=1;i<=cnt;i++){
		a[d]=i;
		dg(d+1,goal,cnt);
	}
}
int main(){
	scanf("%lld%lld%lld",&n,&m,&p);
	if (m>n) printf("%lld\n",mod_pow(m,n)%p);
	dg(1,n,m);
	printf("%lld\n",ans);
	return 0;
}
