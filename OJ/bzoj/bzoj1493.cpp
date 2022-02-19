#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e5+5;
const int MAXT=MAXN*4;
struct tnode{
	int l,r,cl,cr,dat,tag;
} t[MAXT];
int n,m,M,rt,a[MAXN];
int del,rev;
char s[10];
int newnode(int l,int r,int cl,int cr,int dat){
	t[++M]=(tnode){l,r,cl,cr,dat};
	return M;
}
void pushdown(int id){
	int cl=t[id].cl,cr=t[id].cr;
	if (!t[id].tag) return;
	t[cl].tag=t[cr].tag=t[id].tag;
	t[id].tag=0;
	t[id].dat=1;
}
void update(int id){
	int cl=t[id].cl,cr=t[id].cr;
	t[id].dat=t[cl].dat+t[cr].dat;
	int r=t[cl].r,l=t[cr].l;
	if (a[l]==a[r]) t[id].dat--;
}
int build(int l,int r){
	if (l==r) return newnode(l,r,0,0,1);
	int mid=(l+r)>>1;
	int cl=build(l,mid),cr=build(mid+1,r);
	return newnode(l,r,cl,cr,t[cl].dat+t[cr].dat-(a[mid]==a[mid+1]));
}
void modify(int a,int b,int id,int c){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	pushdown(id);
	if (l>b||r<a) return;
	if (a<=l&&r<=b){
		t[id].tag=c;
		pushdown(c);
		return;
	}
	modify(a,b,cl,c); modify(a,b,cr,c);
	update(id);
}
int query(int a,int b,int id){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	pushdown(id);
	if (l>b||r<a) return 0;
	if (a<=l&&r<=b) return t[id].dat;
	l=t[cl].r; r=t[cr].l;
	return query(a,b,cl)+query(a,b,cr)-(a[l]==a[r]);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	rt=build(1,n);
	scanf("%d",&m);
	for (int i=1;i<=m;i++){
		scanf("%s",s+1);
		if (s[1]=='R'){
			int x; scanf("%d",&x);
			if (!rev) del-=x;

