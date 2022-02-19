#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
const int MAXT=MAXN*30;
int n,m,a[MAXN];
struct tnode{
	int l,r,cl,cr,dat;
} t[MAXT];
int M,rt[MAXN];
int newnode(int l,int r,int cl,int cr,int dat){
	t[++M]=(tnode){l,r,cl,cr,dat};
	return M;
}
int build(int l,int r){
	if (l==r) return newnode(l,r,0,0,a[l]);
	int mid=(l+r)>>1;
	int cl=build(l,mid),cr=build(mid+1,r);
	return newnode(l,r,cl,cr,0);
}
int modify(int pid,int a,int b,int l,int r,int val){
//	cout<<__func__<<" "<<a<<" "<<b<<" "<<l<<" "<<r<<" "<<val<<endl;
	int mid=(l+r)>>1;
	if (l==r) return newnode(l,r,0,0,val);
	if (mid<b){
		int cr=modify(t[pid].cr,a,b,mid+1,r,val);
		return newnode(l,r,t[pid].cl,cr,0);
	}
	else {
		int cl=modify(t[pid].cl,a,b,l,mid,val);
		return newnode(l,r,cl,t[pid].cr,0);
	}
}
int query(int id,int a,int b){
//	cout<<__func__<<" "<<a<<" "<<b<<" ";
	int l=t[id].l,r=t[id].r;
//	cout<<l<<" "<<r<<endl;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return 0;
	if (a<=l&&r<=b) return t[id].dat;
	return query(cl,a,b)+query(cr,a,b);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	rt[0]=build(1,n);
	for (int i=1;i<=m;i++){
		int v,op,x,y;
		scanf("%d%d",&v,&op);
		if (op==1){
			scanf("%d%d",&x,&y);
			rt[i]=modify(rt[v],x,x,1,n,y);
		}
		else {
			scanf("%d",&x);
			printf("%d\n",query(rt[v],x,x));
			rt[i]=rt[v];
		}
	}
	return 0;
}
