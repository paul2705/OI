#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+6;
const int MAXT=MAXN*20;
struct tnode{
	int l,r,cl,cr,dat;
} t[MAXT];
int n,m,M,rt,ans=1e9;
int a[MAXN];
int newnode(int l,int r,int cl,int cr,int dat){
	t[++M]=(tnode){l,r,cl,cr,dat};
	return M;
}
void update(int id){
	int cl=t[id].cl,cr=t[id].cr;
	t[id].dat=t[cl].dat+t[cr].dat;
}
void insert(int id,int val){
	int l=t[id].l,r=t[id].r;
	int mid=(l+r)>>1;
	int cl=t[id].cl,cr=t[id].cr;
	if (r<val||l>val) return;
	if (l==r&&l==val){
		t[id].dat=1;
		return;
	}
	if (val<=mid){
		if (!cl) t[id].cl=cl=newnode(l,mid,0,0,0);
		insert(cl,val);
	}
	else {
		if (!cr) t[id].cr=cr=newnode(mid+1,r,0,0,0);
		insert(cr,val);
	}
	update(id);
}
void modify(int id,int val){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (r<val||l>val) return;
	if (l==r&&l==val){
		t[id].dat=0;
		return;
	}
	if (cl) modify(cl,val);
	if (cr) modify(cr,val);
	update(id);
}
int query(int id,int rk){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (!cl&&!cr) return l;
	if (t[cl].dat<rk) return query(cr,rk-t[cl].dat);
	if (t[cl].dat>=rk) return query(cl,rk);
}
int main(){
	scanf("%d%d",&n,&m);
	rt=newnode(1,(int)1e6,0,0,0);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++) insert(rt,a[i]);
	ans=min(ans,query(rt,(m+1)/2)
	for (int i=m+1;i<=n;i++){
		insert(rt,a[i]
