#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=1e5+5;
typedef long long ll;
const ll mod=1e9+7;
const int pri[40]=
{35,2,3,5,7,11,13,17,19,
23,29,31,37,41,43,47,53,
59,61,67,71,73,79,83,89,97,
101,103,107,109,113,127,131,
137,139,149};
int n,m,las[40][50];
ll t[MAXN],a[MAXN],ans[MAXM],inv[300];
struct rec{
	int l,r,id;
} ask[MAXM];
bool cmp(rec a,rec b){ return a.r<b.r; }
void add(int x,ll val){
	for (;x<=n;x+=x&-x) t[x]=t[x]*val%mod;
}
ll sum(int x){
	ll ans=1;
	for (;x;x-=x&-x) ans=ans*t[x]%mod;
	return ans;
}
ll mod_pow(ll x,ll n){
	ll ans=1;
	while (n){
		if (n&1) ans=ans*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return ans;
}
ll Inv(ll x){ return mod_pow(x,mod-2); }
int main(){
	scanf("%d%d",&n,&m);
	inv[1]=1;
	for (int i=2;i<=100;i++) inv[i]=(-inv[mod%i]*(mod/i)%mod+mod)%mod;
//	for (int i=1;i<=10;i++) printf("%d %lld\n",i,inv[i]);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]),t[i]=1;
	for (int i=1;i<=m;i++) scanf("%d%d",&ask[i].l,&ask[i].r),ask[i].id=i;
	sort(ask+1,ask+m+1,cmp);
	int now=1;
	for (int i=1;i<=m;i++){
		int l=ask[i].l,r=ask[i].r;
		for (;now<=r&&now<=n;now++){
			ll x=a[now];
			for (int k=1;k<=pri[0]&&x>1;k++){
				ll pr=pri[k],cnt=0;
				while (x>1){
					if (x%pr==0){
						cnt++;
						add(now,pr);
						if (las[k][cnt]) add(las[k][cnt],inv[pr]);
						las[k][cnt]=now;
						x/=pr;
					}
					else break;
				}
			}
		}
		ans[ask[i].id]=sum(r)*Inv(sum(l-1))%mod;
	}
	for (int i=1;i<=m;i++) printf("%lld\n",ans[i]);
	return 0;
}
