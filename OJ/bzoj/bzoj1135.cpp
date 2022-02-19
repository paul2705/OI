#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
ll n,m,d,k;
ll M,rt;
struct tnode{
	ll l,r,cl,cr,dat,lm,rm,w;
} t[MAXN*8];
ll newnode(ll l,ll r,ll cl,ll cr,ll dat,ll lm,ll rm,ll w){
	t[++M]=(tnode){l,r,cl,cr,dat,lm,rm,w};
	return M;
}
ll build(ll l,ll r){
	if (l==r) return newnode(l,r,0,0,-k,0,0,0);
	ll mid=(l+r)>>1;
	ll cl=build(l,mid),cr=build(mid+1,r);
	ll ndat=t[cl].dat+t[cr].dat;
	ll nlm=max(t[cl].lm,t[cl].dat+t[cr].lm);
	ll nrm=max(t[cr].rm,t[cr].dat+t[cl].rm);
	ll nw=max(t[cl].w,max(t[cr].w,t[cl].rm+t[cr].lm));
	return newnode(l,r,cl,cr,ndat,nlm,nrm,nw);
}
void update(ll id){
	ll cl=t[id].cl,cr=t[id].cr;
	t[id].dat=t[cl].dat+t[cr].dat;
	t[id].lm=max(t[cl].lm,t[cl].dat+t[cr].lm);
	t[id].rm=max(t[cr].rm,t[cr].dat+t[cl].rm);
	t[id].w=max(t[cl].w,max(t[cr].w,t[cl].rm+t[cr].lm));
}
void modify(ll a,ll b,ll id,ll val){
	ll cl=t[id].cl,cr=t[id].cr;
	ll l=t[id].l,r=t[id].r;
	if (a>r||b<l) return;
	if (a<=l&&r<=b){
		t[id].dat+=val;
		t[id].lm=max(0ll,t[id].dat);
		t[id].rm=max(0ll,t[id].dat);
		t[id].w=max(0ll,t[id].dat);
		return;
	}
	modify(a,b,cl,val); modify(a,b,cr,val);
	update(id);
}
int main(){
	scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
	rt=build(1,n);
	for (int i=1;i<=m;i++){
		ll r,x; scanf("%lld%lld",&r,&x);
		modify(r,r,rt,x);
		if (t[rt].w<=d*k) printf("TAK\n");
		else printf("NIE\n");
	}
	return 0;
}
