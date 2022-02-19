#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=3e5+5;
ll a[MAXN],n,m;
ll ans;
ll op[MAXN],l[MAXN],r[MAXN],c[MAXN],b[MAXN];
struct tnode{
	ll l,r,cl,cr,dat,tag;
} t[MAXN*5];
ll M,root;
int newnode(int l,int r,int cl,int cr,int dat){
	t[++M]=(tnode){l,r,cl,cr,dat,0};
	return M;
}
int build(int l,int r){
	if (l==r) return newnode(l,r,0,0,-l);
	int mid=(l+r)>>1;
	int cl=build(l,mid),cr=build(mid+1,r);
	return newnode(l,r,cl,cr,t[cl].dat+t[cr].dat);
}
void update(int id){
	int cl=t[id].cl,cr=t[id].cr;
	t[id].dat=t[cl].dat+t[cr].dat;
}
void pushdown(int id){
	int tag=t[id].tag;
	int cl=t[id].cl,cr=t[id].cr;
	if (tag==0) return;
	t[cl].tag=tag; t[cr].tag=tag;
	t[id].dat=tag;
	t[id].tag=0;
}
void modify(int a,int b,int id,ll val){
	pushdown(id);
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return;
	if (a<=l&&r<=b){
		t[id].tag=val;
		pushdown(id);
		return;
	}
	modify(a,b,cl,val); modify(a,b,cr,val);
	update(id);
}
ll query(int a,int b,int id){
	pushdown(id);
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return 0;
	if (a<=l&&r<=b) return t[id].dat;
	return query(a,b,cl)+query(a,b,cr);
}
void solve1(){
    for (int i=1;i<=m;i++){
        if (op[i]==1){
            for (ll j=l[i];j<=r[i];j++) a[j]=(j-l[i]+1)*c[i]%b[i];
        }
        else {
            ans=0;
            for (ll j=l[i];j<=r[i];j++) ans+=a[j];
            printf("%lld\n",ans);
        }
    }
}
void solve2(){
	for (int i=1;i<=m;i++){
		if (op[i]==1) printf("0\n");
	}
}
void solve3(){
	root=build(1,n);
	for (int i=1;i<=m;i++){
		cout<<query(1,5,root)<<endl;
		if (op[i]==1) modify(l[i],r[i],root,-l[i]+1);
		else printf("%lld\n",(r[i]+l[i])*(r[i]-l[i]+1)/2+query(l[i],r[i],root));
	}
}
int main(){
	freopen("small.in","r",stdin);
	freopen("small.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	bool fla=1,flb=1;
	for (int i=1;i<=m;i++){
		scanf("%lld",&op[i]);
		if (op[i]==1) scanf("%lld%lld%lld%lld",&l[i],&r[i],&c[i],&b[i]);
		else scanf("%lld%lld",&l[i],&r[i]);
		if (op[i]==1) if (c[i]>1) fla=0;
		if (op[i]==1) if (b[i]>1) flb=0;
	}
//	solve3();
	if (n<1e3+5) solve1();
    else if (flb) solve2();
	else if (fla) solve3();
	fclose(stdin); fclose(stdout);
	return 0;
}
