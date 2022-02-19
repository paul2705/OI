#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e6+6;
struct tnode{
	int l,r,cr,cl,dat,tag;
} t[MAXN];
int n,m,k,M,root;
int newnode(int l,int r,int cl,int cr,int dat){
	t[++M]=(tnode){l,r,cl,cr,dat,0};
	return M;
}
void pushdown(int x){
	if (!t[x].tag) return;
	int cl=t[x].cl,cr=t[x].cr,tag=t[x].tag;
	t[cl].tag=t[cr].tag=tag;
	t[cl].dat=t[cr].tag=tag;
	t[x].tag=0;
}
void update(int x){
	int cl=t[x].cl,cr=t[x].cr;
	t[x].dat=t[cl].dat|t[cr].dat;
}
int ini(int l,int r){
	if (l==r) return newnode(l,r,0,0,1);
	int mid=(l+r)>>1;
	int cl=ini(l,mid),cr=ini(mid+1,r);
	return newnode(l,r,cl,cr,1);
}
void modify(int a,int b,int c,int id){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return;
	if (a<=l&&r<=b){
		pushdown(id);
		t[id].dat=t[id].tag=1<<(c-1);
		return;
	}
	pushdown(id);
	modify(a,b,c,cl); modify(a,b,c,cr);
	update(id);
}
ll query(int a,int b,int id){
	pushdown(id);
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return 0;
	if (a<=l&&r<=b) return t[id].dat;
	int ql=query(a,b,cl),qr=query(a,b,cr);
//	cout<<ql<<" "<<qr<<endl;
	return ql|qr;
}
int prf(ll x){
	int res=0;
	while (x){
//		cout<<(x&1);
		if (x&1) res++;
		x>>=1;
	}
//	cout<<endl;
	return res;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	root=ini(1,n);
	for (int i=0,a,b,c;i<k;i++){
		char op=getchar(); while (op!='C'&&op!='P') op=getchar();
//		cout<<op<<endl;
		if (op=='C'){
			scanf("%d%d%d",&a,&b,&c);
			if (a>b) swap(a,b);
			modify(a,b,c,root);
		}
		else{
			scanf("%d%d",&a,&b);
			if (a>b) swap(a,b);
			printf("%d\n",prf(query(a,b,root)));
		}
	}
	return 0;
}
