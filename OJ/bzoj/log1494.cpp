#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MAXN=1e4*5+5;
struct entry{ ll l,r,id,key; };
entry q[MAXN];
ll ans1[MAXN],ans2[MAXN],a[MAXN],s[MAXN],sum,n,m,l,r;
void update(ll i,ll sign){
	ll c=a[i];
	sum-=s[c]*s[c];
	s[c]+=sign;
	sum+=s[c]*s[c];
}
bool cmp(entry a,entry b){ return a.key==b.key?a.r<b.r:a.key<b.key; }
ll gcd(ll a,ll b){ return b==0?a:gcd(b,a%b); }
int main(){
	freopen("log1494.in","r",stdin);
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	ll bs=sqrt(n);
	for (int i=0;i<m;i++) scanf("%lld%lld",&q[i].l,&q[i].r),q[i].id=i,q[i].key=q[i].l/bs;
	sort(q,q+m,cmp);
	l=1; r=0;
	for (int i=0;i<m;i++){
		if (q[i].l==q[i].r){ ans2[q[i].id]=1;continue; }
		while (l<q[i].l) update(l++,-1);
		while (l>q[i].l) update(--l,1);
		while (r<q[i].r) update(++r,1);
		while (r>q[i].r) update(r--,-1);
		ans1[q[i].id]=sum-(r-l+1),ans2[q[i].id]=(r-l+1)*(r-l);
		if (ans1[q[i].id]==0){ ans2[q[i].id]=1;continue; }
		ll d=gcd(ans1[q[i].id],ans2[q[i].id]);
		ans1[q[i].id]/=d,ans2[q[i].id]/=d;
	}
	for (int i=0;i<m;i++) printf("%lld/%lld\n",ans1[i],ans2[i]);
	return 0;
}
