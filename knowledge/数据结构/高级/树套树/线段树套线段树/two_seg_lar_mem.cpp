#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e4+5;
const int MAXT=MAXN*5;
const int MAXTT=MAXT*MAXT;
struct tnode{
	int l,r,cl,cr,dat,tag;
} t[MAXTT];
int n,m,rty,rtx[MAXT],M;
int newnode(int l,int r,int cl,int cr,int dat){
	t[++M]=(tnode){l,r,cl,cr,dat};
	return M;
}
void updatex(int id){
	int cl=t[id].cl,cr=t[id].cr;
	t[id].dat=t[cl].dat+t[cr].dat;
}
void pushdownx(int id){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	int tag=t[id].tag;
	if (tag==0) return;
	t[id].tag=0; t[cl].tag+=tag; t[cr].tag+=tag;
	t[id].dat+=(r-l+1)*tag;
}
void modifyx(int a,int b,int id,int val){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (r<a||l>b) return;
	if (a<=l&&r<=b){
		t[id].tag+=val;
		pushdownx(id);
		return;
	}
	moidfyx(a,b,cl,val); modifyx(a,b,cr,val);
	updatex(id);
}
int queryx(int a,int b,int id){
	pushdownx(id);
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (r<a||l>b) return 0;
	if (a<=l&&r<=b) return t[id].dat;
	return query(a,b,cl)+query(a,b,cr);
}
void modifyy(int ay,int by,int ax,int bx,int id,int val){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (r<ay||l>by) return;
	if (ay<=l&&r<=by){
		t[id].tag+=val;
		modifyx(ax,bx,rtx[id],val);
		return;
	}
	modifyy(ay,by,ax,bx,cl,val);
	modifyy(ay,by,ax,bx,cr,val);
	modifyx(ax,bx,rtx[id],val*(by-ay+1));
}
int queryy(int ay,int by,int ax,int bx,int id){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (r<ay||l>by) return 0;
	if (ay<=l&&r<=by) return queryx(ax,bx,rtx[id]);
	int qcl=queryy(ay,by,ax,bx,cl);
	int qcr=queryy(ay,by,ax,bx,cr);
	return qcl+qcr+t[id].tag*(by-ay+1)*(bx-ax+1);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int 
