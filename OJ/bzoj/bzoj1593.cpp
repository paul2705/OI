#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e4+5;
struct tnode{
	int l,r,cl,cr,mx,mi,lx,rx,tag;
} t[MAXN*4];
int n,m,M,root;
int newnode(int l,int r,int cl,int cr,int mx,int mi,int lx,int rx){
	t[++M]=(tnode){l,r,cl,cr,mx,mi,lx,rx,-1};
	return M;
}
void update(int id){
	int cl=t[id].cl,cr=t[id].cr;
	int mx=max(t[cl].mx,t[cr].mx);
	int mi,llen=t[cl].r-t[cl].l+1,rlen=t[cr].r-t[cr].l+1;
	if (t[cl].mi==0||t[cr].mi==0) mi=t[cl].mi+t[cr].mi;
	int lx=t[cl].lx==llen?t[cl].lx+t[cr].lx:t[cl].lx;
	int rx=t[cr].rx==rlen?t[cr].rx+t[cl].rx:t[cr].rx;
	mx=max(mx,t[cl].rx+t[cr].lx);
	t[id]=(tnode){t[id].l,t[id].r,cl,cr,mx,mi,lx,rx};
}
void pushdown(int id){
	int cl=t[id].cl,cr=t[id].cr;
	int tag=t[id].tag;
	t[cl].tag=t[cr].tag=tag;
	if (tag==-1) return;
	int llen=t[cl].r-t[cl].l+1,rlen=t[cr].r-t[cr].l+1;
	if (tag==0) llen=rlen=0;
	t[cl]=(tnode){t[cl].l,t[cl].r,t[cl].cl,t[cl].cr,llen,t[cl].l,llen,llen,t[cl].tag};
	t[cr]=(tnode){t[cr].l,t[cr].r,t[cr].cl,t[cr].cr,rlen,t[cr].l,rlen,rlen,t[cr].tag};
	t[id].tag=-1;
}
int ini(int l,int r){
	if (l==r) return newnode(l,r,0,0,1,l,1,1);
	int mid=(l+r)>>1;
	int cl=ini(l,mid),cr=ini(mid+1,r);
	int len=r-l+1;
	return newnode(l,r,cl,cr,len,l,len,len);
}
void modify(int a,int b,int id,int x){
	int cl=t[id].cl,cr=t[id].cr;
	int l=t[id].l,r=t[id].r;
	if (r<a||b<l) return;
	if (a<=l&&r<=b){
		t[id].tag=x;
		return;
	}
	pushdown(id);
	modify(a,b,cl,x); modify(a,b,cr,x);
	update(id);
}
int query(int k,int id){
	int cl=t[id].cl,cr=t[id].cr;
	pushdown(id);
	if (k<=t[cl].mx) return query(k,cl);
	if (k<=t[cr].mx) return query(k,cr);
	if (k<=t[id].mx) return t[id].mi;
	else return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	root=ini(1,n);
	for (int i=1,op,x,k;i<=m;i++){
		scanf("%d",&op);
		if (op==1){
			scanf("%d",&k);
			int pos=query(k,root);
			printf("%d\n",pos);
			modify(pos,pos+k-1,root,1);
		}
		else{
			scanf("%d%d",&x,&k);
			modify(x,x+k-1,root,0);
		}
	}
	return 0;
}
