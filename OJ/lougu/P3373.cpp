#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
struct tnode{
	int l,r,cl,cr;
	ll dat,mul,add;
} t[MAXN*20];
ll a[MAXN];
int n,m,p,M,root;
int newnode(int l,int r,int cl,int cr,ll dat){
	M++;
	t[M]=(tnode){l,r,cl,cr,dat%p,1,0};
	return M;
}
int ini(int l,int r){
	if (l==r) return newnode(l,r,0,0,a[l]);
	int mid=(l+r)>>1;
	int cl=ini(l,mid),cr=ini(mid+1,r);
	return newnode(l,r,cl,cr,t[cl].dat+t[cr].dat);
}
void pushdown(int id){
	ll mul=t[id].mul,add=t[id].add;
	int cl=t[id].cl,cr=t[id].cr;
	int l=t[id].l,r=t[id].r;
	t[cl].mul=t[cl].mul*mul%p;
	t[cl].add=(t[cl].add*mul%p+add)%p;
	t[cr].mul=t[cr].mul*mul%p;
	t[cr].add=(t[cr].add*mul%p+add)%p;
	t[id].mul=1,t[id].add=0;
	t[cl].dat=(t[cl].dat*mul%p+add*(t[cl].r-t[cl].l+1)%p)%p;
	t[cr].dat=(t[cr].dat*mul%p+add*(t[cr].r-t[cr].l+1)%p)%p;
}
void update(int id){
	int cl=t[id].cl,cr=t[id].cr;
	pushdown(cl); pushdown(cr);
	t[id].dat=(t[cl].dat+t[cr].dat)%p;
}
void modify(int a,int b,ll val,int x,int id){
	int l=t[id].l,r=t[id].r;
	if (l>b||r<a) return;
	if (a<=l&&r<=b){
		if (x==1){
			t[id].dat=t[id].dat*val%p;
			t[id].mul=t[id].mul*val%p;
			t[id].add=t[id].add*val%p;
		}
		else{
			t[id].dat=(t[id].dat+val*(r-l+1))%p%p;
			t[id].add=(t[id].add+val)%p;
		}
		return;
	}
	pushdown(id);
	modify(a,b,val,x,t[id].cl);
	modify(a,b,val,x,t[id].cr);
	update(id);
}
ll query(int a,int b,int id){
	pushdown(id);
	int l=t[id].l,r=t[id].r;
	if (l>b||r<a) return 0;
	if (a<=l&&r<=b) return t[id].dat%p;
	ll cl=query(a,b,t[id].cl)%p,cr=query(a,b,t[id].cr)%p;
	return (cl+cr)%p;
}
int main(){
	scanf("%d%d%d",&n,&m,&p);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	root=ini(1,n);
	for (int i=1,op,x,y;i<=m;i++){
		scanf("%d",&op); ll k;
		if (op==1) scanf("%d%d%lld",&x,&y,&k),modify(x,y,k,op,root);
		if (op==2) scanf("%d%d%lld",&x,&y,&k),modify(x,y,k,op,root);
		if (op==3) scanf("%d%d",&x,&y),printf("%lld\n",query(x,y,root));
	}
	return 0;
}
