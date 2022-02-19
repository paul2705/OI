#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXT=MAXN*50;
struct tnode{
	int l,r,cl,cr,dat,rk;
} t[MAXT];
int n,m,M;
int rt[2*MAXN];
int newnode(int l,int r,int cl,int cr,int dat,int rk){
	t[++M]=(tnode){l,r,cl,cr,dat,rk};
	return M;
}
int build(int l,int r){
	if (l==r) return newnode(l,r,0,0,l,1);
	int mid=(l+r)>>1;
	int cl=build(l,mid),cr=build(mid+1,r);
	return newnode(l,r,cl,cr,0,0);
}
int modify(int pid,int a,int b,int l,int r,int val,int rk){
	int mid=(l+r)>>1;
	if (l==r) return newnode(l,r,0,0,val,rk);
	if (mid<b){
		int cr=modify(t[pid].cr,a,b,mid+1,r,val,rk);
		return newnode(l,r,t[pid].cl,cr,0,0);
	}
	else {
		int cl=modify(t[pid].cl,a,b,l,mid,val,rk);
		return newnode(l,r,cl,t[pid].cr,0,0);
	}
}
void add(int id,int a,int b,int val){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return;
	if (a<=l&&r<=b){
		t[id].rk+=val;
		return ;
	}
	add(cl,a,b,val); add(cr,a,b,val);
}
int qryf(int id,int a,int b){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return 0;
	if (a<=l&&r<=b) return t[id].dat;
	return qryf(cl,a,b)+qryf(cr,a,b);
}
int qryrk(int id,int a,int b){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return 0;
	if (a<=l&&r<=b) return t[id].rk;
	return qryrk(cl,a,b)+qryrk(cr,a,b);
}
int find(int rt,int x){
	int fx=qryf(rt,x,x);
	if (fx==x) return x;
	else return find(rt,fx);
}
int main(){
	scanf("%d%d",&n,&m);
	rt[0]=build(1,n);
	for (int i=1;i<=m;i++){
		int op,x,y;
		scanf("%d",&op);
		if (op==1){
			scanf("%d%d",&x,&y);
			int fx=find(rt[i-1],x),fy=find(rt[i-1],y);
//			cout<<"1: "<<fx<<" "<<fy<<endl;
			int rkx=qryrk(rt[i-1],fx,fx),rky=qryrk(rt[i-1],fy,fy);
			if (rkx<rky){
				rt[i]=modify(rt[i-1],fx,fx,1,n,fy,rkx);
				add(rt[i],fy,fy,rkx);
			}
			else{
				rt[i]=modify(rt[i-1],fy,fy,1,n,fx,rky);
				add(rt[i],fy,fy,rkx);
			}
		}
		if (op==2){
			scanf("%d",&x);
			rt[i]=rt[x];
		}
		if (op==3){
			scanf("%d%d",&x,&y);
			int fx=find(rt[i-1],x),fy=find(rt[i-1],y);
			rt[i]=rt[i-1];
//			cout<<fx<<" "<<fy<<endl;
			if (fx==fy) printf("1\n");
			else printf("0\n");
		}
	}
	return 0;
}
