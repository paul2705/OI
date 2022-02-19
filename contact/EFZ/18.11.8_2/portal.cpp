#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXT=MAXN*4;
// mx1=-x+y;
// mx2=x+y;
// mx3=-x-y;
// mx4=x-y;
struct tnode{
	int l,r,cl,cr,mx1,mx2,mx3,mx4;
} t1[MAXT],t2[MAXT];
int n,m,M1,M2,root1,root2;
struct rec{
	int x,y;
	int val1(){ return -x+y; }
	int val2(){ return x+y; }
	int val3(){ return -x-y; }
	int val4(){ return x-y; }
} c[MAXN],d[MAXN];
int newnode1(int l,int r,int cl,int cr,int mx1,int mx2,int mx3,int mx4){
	t1[++M1]=(tnode){l,r,cl,cr,mx1,mx2,mx3,mx4};
	return M1;
}
int newnode2(int l,int r,int cl,int cr,int mx1,int mx2,int mx3,int mx4){
	t2[++M2]=(tnode){l,r,cl,cr,mx1,mx2,mx3,mx4}:
	return M2;
}
int build1(int l,int r){
	if (l==r) return newnode1(l,r,0,0,0,0,0,0);
	int mid=(l+r)>>1;
	int cl=build1(l,mid),cr=build1(mid+1,r);
	return newnode(l,r,cl,cr,0,0,0,0);
}
int build2(int l,int r){
	if (l==r) return newnode2(l,r,0,0,0,0,0,0);
	int mid=(l+r)>>1;
	int cl=build2(l,mid),cr=build2(mid+1,r);
	return newnode(l,r,cl,cr,0,0,0,0);
}
void update1(int id){
	int cl=t[id].cl,cr=t[id].cr;
	t[id].mx1=max(t[cl].mx1,t[cr].mx1);
	t[id].mx2=max(t[cl].mx2,t[cr].mx2);
	t[id].mx3=max(t[cl].mx3,t[cr].mx3);
	t[id].mx4=max(
void modify1(int a,int b,int id,int u){
	int l=t1[id].l,r=t1[id].r;
	int cl=t1[id].cl,cr=t1[id].cr;
	if (l>a||r<a) return;
	if (a<=l&&r<=b){
		t[id].mx1=c[a].val1();
		t[id].mx2=c[a].val2();
		t[id].mx3=c[a].val3();
		t[id].mx4=c[a].val4();
		return;
	}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d%d",&c[i].x,&c[i].y);
	for (int i=1;i<=n;i++) scanf("%d%d",&d[i].x,&d[i].y);
	root=build(1,n);
