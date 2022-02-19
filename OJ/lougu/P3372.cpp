#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
const int MAXM=1e5+5;
const int MAXT=4*MAXN;
struct node{
	int l,r,cl,cr;
	ll dat,tag;
} t[MAXT];
int n,m,rt,M;
ll a[MAXN];
int newnode(int l,int r,int cl,int cr,ll dat,ll tag){
	t[++M]=(node){l,r,cl,cr,dat,tag};
	return M;
}
int build(int l,int r){
	int mid=(l+r)/2;
	if (l==r) return newnode(l,r,0,0,a[l],0);
	int cl=build(l,mid),cr=build(mid+1,r);
	return newnode(l,r,cl,cr,t[cl].dat+t[cr].dat,0);
}
void pushdown(int id){
	ll tag=t[id].tag;
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (tag==0) return;
	t[id].dat+=(r-l+1)*tag;
	t[cl].tag+=tag;
	t[cr].tag+=tag;
	t[id].tag=0;
}
void update(int id){
	int cl=t[id].cl,cr=t[id].cr;
	t[id].dat=t[cl].dat+t[cr].dat;
}
void modify(int id,int a,int b,ll val){
	pushdown(id);
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return;
	if (a<=l&&r<=b){
		t[id].tag+=val;
		pushdown(id);
		return;
	}
	modify(cl,a,b,val); modify(cr,a,b,val);
	update(id);
}
ll query(int id,int a,int b){
	pushdown(id);
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return 0;
	if (a<=l&&r<=b) return t[id].dat;
	return query(cl,a,b)+query(cr,a,b);
}
void prt(int id){
	if (id==0) return;
	printf("id:%d,l:%d,r:%d,cl:%d,cr:%d,dat:%lld,tag:%lld\n",id,t[id].l,t[id].r,t[id].cl,t[id].cr,t[id].dat,t[id].tag);
	prt(t[id].cl); prt(t[id].cr);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	rt=build(1,n);
	for (int i=1;i<=m;i++){
		int opt,x,y; scanf("%d%d%d",&opt,&x,&y);
		if (opt==1){
			ll k; scanf("%lld",&k);
			modify(rt,x,y,k);
		}
		else printf("%lld\n",query(rt,x,y));
//		prt(rt);
	}
	return 0;
}
