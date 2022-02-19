#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
const int MAXT=MAXN*8;
ll mod;
int n,m,M,rt,a[MAXN];
struct tnode{
	int l,r,cl,cr;
	ll dat,tag1,tag2;
} t[MAXT];
int newnode(int l,int r,int cl,int cr,int dat){
	t[++M]=(tnode){l,r,cl,cr,dat,1,0};
	return M;
}
int build(int l,int r){
	if (l==r) return newnode(l,r,0,0,a[l]);
	int mid=(l+r)>>1;
	int cl=build(l,mid),cr=build(mid+1,r);
	return newnode(l,r,cl,cr,(t[cl].dat+t[cr].dat)%mod);
}
void pushdown(int id){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	t[id].dat=(t[id].dat*t[id].tag1%mod+t[id].tag2*(r-l+1))%mod;
	t[cl].tag1=(t[cl].tag1*t[id].tag1)%mod;
	t[cl].tag2=(t[cl].tag2*t[id].tag1%mod+t[id].tag2)%mod;
	t[cr].tag1=(t[cr].tag1*t[id].tag1)%mod;
	t[cr].tag2=(t[cr].tag2*t[id].tag1%mod+t[id].tag2)%mod;
	t[id].tag1=1; t[id].tag2=0;
}
void update(int id){
	int cl=t[id].cl,cr=t[id].cr;
//	pushdown(cl); pushdown(cr);
	t[id].dat=(t[cl].dat+t[cr].dat)%mod;
}
void modify_mul(int a,int b,int id,int val){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	pushdown(id);
	if (l>b||r<a) return;
	if (a<=l&&r<=b){
		t[id].tag1=(t[id].tag1*val)%mod;
		pushdown(id);
		return;
	}
	modify_mul(a,b,cl,val);
	modify_mul(a,b,cr,val);
	update(id);
}
void modify_add(int a,int b,int id,int val){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	pushdown(id);
	if (l>b||r<a) return;
	if (a<=l&&r<=b){
		t[id].tag2=(t[id].tag2+val)%mod;
		pushdown(id);
		return;
	}
	modify_add(a,b,cl,val);
	modify_add(a,b,cr,val);
	update(id);
}
ll query(int a,int b,int id){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	pushdown(id);
	if (l>b||r<a) return 0;
	if (a<=l&&r<=b){
//		printf("qry:(%d %d %lld)\n",l,r,t[id].dat);
		return t[id].dat;
	}
	return (query(a,b,cl)+query(a,b,cr))%mod;
}
int main(){
	scanf("%d%lld",&n,&mod);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	rt=build(1,n);
	for (int i=1;i<=m;i++){
		int op,l,r; scanf("%d%d%d",&op,&l,&r);
		if (op==1){
			int x; scanf("%d",&x);
			modify_mul(l,r,rt,x);
		}
		if (op==2){
			int x; scanf("%d",&x);
			modify_add(l,r,rt,x);
		}
		if (op==3) printf("%lld\n",query(l,r,rt));
	}
	return 0;
}
