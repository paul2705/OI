#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
const int MAXT=MAXN*5;
struct tnode{
	int l,r,cl,cr;
	ll dat,mul,add;
} t[MAXT];
int n,m,M,root;
ll a[MAXN],p;
int newnode(int l,int r,int cl,int cr,ll dat){
	t[++M]=(tnode){l,r,cl,cr,dat,1,0};
	return M;
}
int build(int l,int r){
	if (l==r) return newnode(l,r,0,0,a[l]%p);
	int mid=(l+r)>>1;
	int cl=build(l,mid),cr=build(mid+1,r);
	return newnode(l,r,cl,cr,(t[cl].dat+t[cr].dat)%p);
}
void update(int id){
	int cl=t[id].cl,cr=t[id].cr;
	t[id].dat=(t[cl].dat+t[cr].dat)%p;
}
void pushdown(int id){
	ll mul=t[id].mul,add=t[id].add;
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	t[id].dat=(t[id].dat*mul%p+add*(r-l+1)%p)%p;
	t[cl].mul=(t[cl].mul*mul)%p;t[cl].add=(t[cl].add*mul%p+add)%p;
	t[cr].mul=(t[cr].mul*mul)%p;t[cr].add=(t[cr].add*mul%p+add)%p;
	t[id].mul=1; t[id].add=0;
}
void modify(int a,int b,int id,int x,ll val){
	pushdown(id);
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return;
	if (a<=l&&r<=b){
		if (x==1){
			t[id].mul=t[id].mul*val%p;
			t[id].add=t[id].add*val%p;
			pushdown(id);
		}
		else {
			t[id].add=(t[id].add+val)%p;
			pushdown(id);
		}
		return;
	}
	modify(a,b,cl,x,val); modify(a,b,cr,x,val);
	update(id);
}
ll query(int a,int b,int id){
	pushdown(id);
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return 0;
	if (a<=l&&r<=b) return t[id].dat%p;
	return (query(a,b,cl)+query(a,b,cr))%p;
}
int main(){
	scanf("%d%d%lld",&n,&m,&p);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	root=build(1,n);
	for (int i=1,op;i<=m;i++){
		scanf("%d",&op);
		if (op==1){
			int x,y; ll k;
			scanf("%d%d%lld",&x,&y,&k);
			modify(x,y,root,op,k);
		}
		if (op==2){
			int x,y; ll k;
			scanf("%d%d%lld",&x,&y,&k);
			modify(x,y,root,op,k);
		}
		if (op==3){
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%lld\n",query(x,y,root)%p);
		}
	}
	return 0;
}
