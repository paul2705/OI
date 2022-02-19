#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
const int MAXT=MAXN*30;
int n,m,M,rt[MAXN];
int a[MAXN],b[MAXN],id[MAXN];
struct tnode{
	int l,r,cl,cr,dat;
} t[MAXT];
int newnode(int l,int r,int cl,int cr,int dat){
	t[++M]=(tnode){l,r,cl,cr,dat};
	return M;
}
int build(int l,int r,int id){
	if (l==r) return newnode(l,r,0,0,l==id);
	int mid=(l+r)>>1;
	int cl=build(l,mid,id),cr=build(mid+1,r,id);
	return newnode(l,r,cl,cr,t[cl].dat+t[cr].dat);
}
// [l,mid] [mid+1,r]
int ins(int x,int l,int r,int rid){
	if (l==r){
//		printf("%d %d\n",x,l);
		return newnode(l,r,0,0,t[rid].dat+1);
	}
	int mid=(l+r)>>1;
	int rcl=t[rid].cl,rcr=t[rid].cr;
	if (x>mid){
		int cr=ins(x,mid+1,r,rcr);
		return newnode(l,r,rcl,cr,t[rcl].dat+t[cr].dat);
	}
	else {
		int cl=ins(x,l,mid,rcl);
		return newnode(l,r,cl,rcr,t[cl].dat+t[rcr].dat);
	}
}
int kth(int id,int rid,int rk){
	int l=t[id].l,r=t[id].r;
//	cout<<": "<<l<<" "<<r<<" "<<rk<<endl;
	int cl=t[id].cl,cr=t[id].cr;
	int rcl=t[rid].cl,rcr=t[rid].cr;
	int sz=t[cl].dat-t[rcl].dat;
//	if (rk==0) return r;
//	cout<<t[cl].dat<<" "<<t[rcl].dat<<" "<<sz<<endl;
	if (l==r) return l;
	if (rk<=sz) return kth(cl,rcl,rk);
	else return kth(cr,rcr,rk-sz);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	int nn=unique(b+1,b+n+1)-b-1;
	for (int i=1;i<=n;i++){
		int x=lower_bound(b+1,b+nn+1,a[i])-b;
		id[x]=a[i]; a[i]=x;
	}
//	for (int i=1;i<=n;i++) printf("%d ",a[i]); cout<<endl;
	rt[1]=build(1,n,a[1]);
	for (int i=2;i<=n;i++){
//		scanf("%d",&x);
		rt[i]=ins(a[i],1,n,rt[i-1]);
//		printf("%d %d\n",rt[i],t[rt[i]].dat);
	}
	for (int i=1,l,r,k;i<=m;i++){
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",id[kth(rt[r],rt[l-1],k)]);
	}	
	return 0;
}
