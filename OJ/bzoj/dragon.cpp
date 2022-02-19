#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
ll n,m,T,p[MAXN],a[MAXN],at[MAXN],t[MAXN];
void solve1(){
	bool f=false;
	for (ll i=0;i<=t[1];i++){
		ll x=i*p[1]+a[1];
		if (x%t[1]==0){
			f=true;
			printf("%lld\n",(ll)x/t[1]);
			break;
		}
	}
	if (!f) printf("-1\n");
}
ll gcd(ll a,ll b){ return b==0?a:gcd(b,a%b); }
void solve2(){
	ll atk=t[1],ans=a[1]/t[1]+1;
	for (int i=2;i<=n;i++,atk=at[i-1]){
		ll res=a[i]/atk;;
		if (a[i]%atk!=0) res++;
		ans=max(ans,res);
	}
	printf("%lld\n",ans);
}
void solve3(){
	
}
void solve4(){
	
}
int main(){
	freopen("dragon.in","r",stdin);
	freopen("dragon.out","w",stdout);
	scanf("%lld",&T);
	while (T--){
		scanf("%lld%lld",&n,&m);
		for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for (int i=1;i<=n;i++) scanf("%lld",&p[i]);
		for (int i=1;i<=n;i++) scanf("%lld",&at[i]);
		for (int i=1;i<=m;i++) scanf("%lld",&t[i]);
		if (n==1&&m==1) solve1();
		else if (m==1) solve2();
		else if (n<=1e3&&m<=1e3) solve3();
		else solve4();
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
