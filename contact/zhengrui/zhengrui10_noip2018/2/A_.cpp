#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MAXN=5e5+5;
struct rec{
	ll a,b;
} f[MAXN];
ll n,m,s1[MAXN][3],cnt1,s2[MAXN][3],cnt2;
bool cmp(rec a,rec b){ return a.a<b.a; }
ll fx(rec q,ll x){ return (ll)q.a*x*x+q.b*x; }
int main(){
	scanf("%lld%lld",&n,&m);
	for (ll i=1;i<=n;i++) scanf("%lld%lld",&f[i].a,&f[i].b);
	sort(f+1,f+n+1,cmp);
	s1[++cnt1][0]=0; s1[cnt1][1]=1;
	for (ll i=2;i<=n;i++){
		rec p1=f[i];
		while (true){
			rec p2=f[s1[cnt1][1]];
			if (p1.a<=p2.a) break;
			ll j=(p2.b-p1.b)/(p1.a-p2.a);
			while (fx(p1,j)<fx(p2,j)) ++j;
			if (j<=s1[cnt1][0]){
				cnt1--;
				if (!cnt1){
					s1[++cnt1][0]=j,s1[cnt1][1]=i;
					break;
				}
			}
			else{
				s1[++cnt1][0]=j,s1[cnt1][1]=i;
				break;
			}
		}
	}
	s2[++cnt2][0]=0,s2[cnt2][1]=n;
	for (ll i=n-1;i;i--){
		rec p1=f[i];
		while (true){
			rec p2=f[s2[cnt2][1]];
			if (p1.a<=p2.a) break;
			ll j=(p2.b-p1.b)/(p1.a-p2.a);
			while (fx(p1,j)<fx(p2,j)) j--;
			if (j>=s2[cnt2][0]){
				cnt2--;
				if (!cnt2){
					s2[++cnt2][0]=j,s2[cnt2][1]=i;
					break;
				}
			}
			else {
				s2[++cnt2][0]=j,s2[cnt2][1]=i;
				break;
			}
		}
	}
	for (ll i=1,x;i<=m;i++){
		scanf("%lld",&x);
		if (x==0){ printf("0\n"); continue; }
		else if (x>0){
			if (x>=s1[cnt1][0]){
				printf("%lld\n",fx(f[s1[cnt1][1]],x));
				continue;
			}
			ll l=1,r=cnt1,mid,ans;
			while (l<=r){
				mid=(l+r)>>1;
				if (s1[mid][0]<=x) ans=mid,l=mid+1;
				else r=mid-1;
			}
			printf("%lld\n",fx(f[s1[ans][1]],x));
		}
		else {
			if (x<=s2[cnt2][0]){
				printf("%lld\n",fx(f[s2[cnt2][1]],x));
				continue;
			}
			ll l=1,r=cnt2,mid,ans;
			while (l<=r){
				mid=(l+r)>>1;
				if (s2[mid][0]>=x) ans=mid,l=mid+1;
				else r=mid-1;
			}
			printf("%lld\n",fx(f[s2[ans][1]],x));
		}
	}
	return 0;
}
