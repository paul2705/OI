#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e5+5;
const int MAXT=MAXN*5;
struct tnode{
	int l,r,cl,cr,dat,tag;
} t[MAXT];
int n,q,M,root,a[MAXN];
int newnode(int l,int r,int cl,int cr,int dat){
	t[++M]=(tnode){l,r,cl,cr,dat};
	return M;
}
int merge(int x){
	if (a[x]==1&&a[x+1]==1) return -2;
	if (a[x-1]==1&&a[x]==0&&a[x+1]==1) return -1;
	if (a[x]==1&&a[x+1]==0&&a[x+2]==1) return -1;
	if (a[x]==0&&a[x+1]==0) return 0;
	return 0;
}
int build(int l,int r){
	if (l==r) return newnode(l,r,0,0,a[l]*2);
	int mid=(l+r)>>1;
	int cl=build(l,mid),cr=build(mid+1,r);
	cout<<l<<" "<<r<<" "<<t[cl].dat+t[cr].dat+merge(mid)<<endl;
	return newnode(l,r,cl,cr,t[cl].dat+t[cr].dat+merge(mid));
}
int query(int a,int b,int id){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return 0;
	if (a<=l&&r<=b) return t[id].dat;
	int qcl=query(a,b,cl),qcr=query(a,b,cr);
	int mid=(l+r)>>1;
	if (mid<a) return qcr;
	if (mid>b) return qcl;
	return qcr+qcl+merge(mid);
}
void update(int id){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	int mid=(l+r)>>1;
	t[id].dat=t[cl].dat+t[cr].dat+merge(mid);
}
void modify(int al,int br,int id,int val){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>br||r<al) return;
	if (al<=l&&r<=br){
		a[al]=val; t[al].dat=val*2;
		return;
	}
	modify(al,br,cl,val); modify(al,br,cr,val);
	update(id);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		char c=getchar(); while (c!='1'&&c!='0') c=getchar();
		a[i]=(c=='1');
	}
	root=build(1,n);
	scanf("%d",&q);
	for (int i=1,op,l,r;i<=q;i++){
		scanf("%d%d%d",&op,&l,&r);
		if (op==1) printf("%d\n",query(l,r,root));
		else modify(l,l,root,r);
	}
	return 0;
}
