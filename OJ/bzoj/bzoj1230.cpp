#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXT=MAXN*4;
struct tnode{
	int l,r,cl,cr,op,ed,tag;
} t[MAXT];
int n,m,M,rt;
int newnode(int l,int r,int cl,int cr,int op,int ed){
	t[++M]=(tnode){l,r,cl,cr,op,ed,0};
	return M;
}
int build(int l,int r){
	if (l==r) return newnode(l,r,0,0,0,1);
	int mid=(l+r)>>1;
	int cl=build(l,mid),cr=build(mid+1,r);
	return newnode(l,r,cl,cr,0,t[cl].ed+t[cr].ed);
}
void update(int id){
	int cl=t[id].cl,cr=t[id].cr;
	t[id].op=t[cl].op+t[cr].op;
	t[id].ed=t[cl].ed+t[cr].ed;
}
void pushdown(int id){
	int cl=t[id].cl,cr=t[id].cr;
	int tag=t[id].tag;
	if (!tag) return;
	swap(t[id].op,t[id].ed);
	t[cl].tag^=1;
	t[cr].tag^=1;
	t[id].tag=0;
}
void modify(int a,int b,int id){
	pushdown(id);
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return;
	if (a<=l&&r<=b){
		t[id].tag^=1;
		pushdown(id);
		return;
	}
	modify(a,b,cl); modify(a,b,cr);
	update(id);
}
int qry(int a,int b,int id){
	pushdown(id);
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return 0;
	if (a<=l&&r<=b) return t[id].op;
	return qry(a,b,cl)+qry(a,b,cr);
}
int main(){
	scanf("%d%d",&n,&m);
	rt=build(1,n);
	for (int i=1;i<=m;i++){
		int op,x,y; scanf("%d%d%d",&op,&x,&y);
		if (op==0) modify(x,y,rt);
		else printf("%d\n",qry(x,y,rt));
	}
	return 0;
}
