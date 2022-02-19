#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
const int MAXT=MAXN*4;
struct tnode{
	int l,r,cl,cr,dat,tag;
};
struct ttnode{
	int l,r,cl,cr,dat,Mx,tag;
	tnode tx[MAXT];
	int rtx;
} ty[MAXT];
int n,m,q,My,rt;
int a[MAXN][MAXN],s[MAXN][MAXN];
int newnodex(int id,int l,int r,int cl,int cr,int dat){
	ty[id].tx[++ty[id].Mx]=(tnode){l,r,cl,cr,dat};
	return ty[id].Mx;
}
int newnodey(int l,int r,int cl,int cr,int dat){
	ty[++My]=(ttnode){l,r,cl,cr,dat,0};
	return My;
}
int buildx(int id,int l,int r){
	if (l==r){
//		int cl=ty[id].cl,cr=ty[id].cr;
		return newnodex(id,l,r,0,0,s[ty[id].r][l]-s[ty[id].l-1][l]);
	}
	int mid=(l+r)>>1;
	int cl=buildx(id,l,mid),cr=buildx(id,mid+1,r);
	int iid=newnodex(id,l,r,cl,cr,ty[id].tx[cl].dat+ty[id].tx[cr].dat);
	return iid;
}
int buildy(int l,int r){
	if (l==r){
		int id=newnodey(l,r,0,0,0);
		ty[id].rtx=buildx(id,1,m);
		ty[id].dat=ty[id].tx[ty[id].rtx].dat;
		return id;
	}
//	cout<<l<<" "<<r<<endl;
	int mid=(l+r)>>1;
	int cl=buildy(l,mid),cr=buildy(mid+1,r);
	int id=newnodey(l,r,cl,cr,ty[cl].dat+ty[cr].dat);
	ty[id].rtx=buildx(id,1,m);
//	ty[id].dat=ty[id].tx[ty[id].rtx].dat;
	return id;
}
void updatex(int rt,int id){
	int cl=ty[rt].tx[id].cl,cr=ty[rt].tx[id].cr;
	ty[rt].tx[id].dat=ty[rt].tx[cl].dat+ty[rt].tx[cr].dat;
}
void pushdownx(int rt,int id){
	int cl=ty[rt].tx[id].cl,cr=ty[rt].tx[id].cr;
	int l=ty[rt].tx[id].l,r=ty[rt].tx[id].r;
	int tag=ty[rt].tx[id].tag;
	if (tag==0) return;
	ty[rt].tx[cl].tag+=tag;
	ty[rt].tx[cr].tag+=tag;
	ty[rt].tx[id].tag=0;
	ty[rt].tx[id].dat+=tag*(r-l+1);
}
void modifyx(int rt,int a,int b,int id,int val){
//	pushdownx(rt,id);
	int l=ty[rt].tx[id].l,r=ty[rt].tx[id].r;
	int cl=ty[rt].tx[id].cl,cr=ty[rt].tx[id].cr;
	if (r<a||l>b) return;
	if (a<=l&&r<=b){
//		ty[rt].tx[id].tag+=val;
//		pushdownx(rt,id);
		ty[rt].tx[id].dat+=val;
		return;	
	}
	modifyx(rt,a,b,cl,val); modifyx(rt,a,b,cr,val);
	updatex(rt,id);
}
void modifyy(int ay,int by,int ax,int bx,int id,int val){
	int l=ty[id].l,r=ty[id].r;
	int cl=ty[id].cl,cr=ty[id].cr;
	if (r<ay||l>by) return;
	int ub=min(r,by),lb=max(l,ay);
	modifyx(id,ax,bx,ty[id].rtx,val/**(ub-lb+1)*/);
	if (ay<=l&&r<=by){
//		modifyx(id,ax,bx,ty[id].rtx,val);
		return;
	}
	modifyy(ay,by,ax,bx,cl,val);
	modifyy(ay,by,ax,bx,cr,val);
}
int queryx(int rt,int a,int b,int id){
//	pushdownx(rt,id);
	int l=ty[rt].tx[id].l,r=ty[rt].tx[id].r;
	int cl=ty[rt].tx[id].cl,cr=ty[rt].tx[id].cr;
	if (r<a||l>b) return 0;
	if (a<=l&&r<=b) return ty[rt].tx[id].dat;
	return queryx(rt,a,b,cl)+queryx(rt,a,b,cr);
}
int queryy(int ay,int by,int ax,int bx,int id){
	int l=ty[id].l,r=ty[id].r;
//	cout<<l<<" "<<r<<" "<<ay<<" "<<by<<endl;
	int cl=ty[id].cl,cr=ty[id].cr;
	if (r<ay||l>by) return 0;
	if (ay<=l&&r<=by) return queryx(id,ax,bx,ty[id].rtx);
	int qcl=queryy(ay,by,ax,bx,cl);
	int qcr=queryy(ay,by,ax,bx,cr);
	return qcl+qcr;
}
int main(){
//	freopen("seg.in","r",stdin);
//	freopen("seg.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
//		for (int j=1;j<=m;j++) s[i][j]=s[i][j-1]+a[i][j];
	}
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++) s[j][i]=s[j-1][i]+a[j][i];
	}
	rt=buildy(1,n);
//	cout<<ty[rt].tx[ty[rt].rtx].dat<<endl;
	for (int i=1;i<=q;i++){
		int op,sx,sy,tx,ty,val;
		// op==1 modify (one-dot)
		// op==2 query
		scanf("%d%d%d%d%d",&op,&sy,&sx,&ty,&tx);
//		cout<<op<<endl;
		if (sx>tx) swap(sx,tx),swap(sy,ty);
		if (op==1){
			scanf("%d",&val);
			modifyy(sy,ty,sx,tx,rt,val);
		}
		else printf("%d\n",queryy(sy,ty,sx,tx,rt));
//		cout<<"done"<<endl;
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
