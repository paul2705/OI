#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
struct tnode{
	ll l,r,cl,cr,dat;
} t[MAXN*20];
ll n,mod,M,T,root;
ll newnode(int l,int r,int cl,int cr,int dat){
	t[++M]=(tnode){l,r,cl,cr,dat};
	return M;
}
ll ini(ll l,ll r){
	if (l==r) return newnode(l,r,0,0,1);
	ll mid=(l+r)>>1;
	ll cl=ini(l,mid),cr=ini(mid+1,r);
	return newnode(l,r,cl,cr,1);
}
void update(ll id){
	ll cl=t[id].cl,cr=t[id].cr;
	t[id].dat=t[cl].dat*t[cr].dat%mod;
}
void modify(ll a,ll b,ll val,ll id){
	ll l=t[id].l,r=t[id].r;
	ll cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return;
	if (a<=l&&r<=b) return t[id].dat=val%mod,void();
	modify(a,b,val,cl); modify(a,b,val,cr);
	update(id);
}
ll query(ll a,ll b,ll id){
	ll l=t[id].l,r=t[id].r;
	ll cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return 1;
	if (a<=l&&r<=b) return t[id].dat%mod;
	return query(a,b,cl)*query(a,b,cr)%mod;
}
int main(){
	scanf("%lld",&T);
	while (T--){
		scanf("%lld%lld",&n,&mod);
		M=0; root=ini(1,n);
		for (int i=1;i<=n;i++){
			ll op,x; scanf("%lld%lld",&op,&x);
			if (op==1) modify(i,i,x,root);
			else modify(x,x,1,root);
			printf("%lld\n",query(1,i,root)%mod);
		}
	}
	return 0;
}
