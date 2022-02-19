#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
const ll mod=998244353;
ll n,q,a[MAXN],root,M;
struct tnode{
	ll l,r,cl,cr,dat;
} t[MAXN*16];
ll newnode(ll l,ll r,ll cl,ll cr,ll dat){
	t[++M]=(tnode){l,r,cl,cr,dat};
	return M;
}
ll build(ll l,ll r){
	if (l==r) return newnode(l,r,0,0,a[l]);
	ll mid=(l+r)>>1;
	ll cl=build(l,mid),cr=build(mid+1,r);
	return newnode(l,r,cl,cr,t[cl].dat+t[cr].dat);
}
void update(ll id){
	ll cl=t[id].cl,cr=t[id].cr;
	t[id].dat=t[cl].dat+t[cr].dat;
}
void modify(ll a,ll b,ll id,ll val){
	ll l=t[id].l,r=t[id].r;
	ll cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return;
	if (a<=l&&r<=b){
		t[id].dat+=val;
		return;
	}
	modify(a,b,cl,val); modify(a,b,cr,val);
	update(id);
}
ll query(ll val,ll id){
	ll l=t[id].l,r=t[id].r;
	ll cl=t[id].cl,cr=t[id].cr;
	if (l==r) return l;
	if (t[cl].dat>=val) return query(val,cl);
	return query(val-t[cl].dat,cr);
}
int main(){
	freopen("station.in","r",stdin);
	freopen("station.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	ll s=0;
	for (ll i=1;i<=n;i++) scanf("%lld",&a[i]),s+=a[i];
	root=build(1,n);
	ll x=19260817%mod;
	ll ret=x,ans=0;
	for (ll i=1;i<=q;i++){
		ll sx,sy;
		scanf("%lld%lld",&sx,&sy);
		modify(sx,sx,root,sy);
		s+=sy;
//		cout<<s<<" "<<query(3,root)<<endl;
		ll pos=query((s+1)/2,root);
//		cout<<s<<" "<<(s+1)/2<<" "<<pos<<endl;
//		cout<<pos<<endl;
		ans=(ans+ret*pos%mod)%mod;
//		cout<<ans<<endl;
		ret=ret*x%mod;
	}
	printf("%lld\n",ans%mod);
	fclose(stdin); fclose(stdout);
	return 0;
}
