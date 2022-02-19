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
struct rec{
	int x1,y1,x2,y2;
} mat[MAXN];
struct chk{
	int x,l,r,v;
} lis[MAXN];
int n,rt,M,a[MAXN],cnt,L,W,H;
int newnode(int l,int r,int cl,int cr,int dat){
	t[++M]=(tnode){l,r,cl,cr,dat,0};
	return M;
}
void update(int id){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	t[id].dat=min(t[cl].dat,t[cr].dat);
}
void pushdown(int id){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	int tag=t[id].tag;
	if (!tag) return;
	t[id].dat+=tag;
	t[id].tag=0;
	t[cl].tag+=tag; t[cr].tag+=tag;
}
int build(int l,int r){
	if (l==r) return newnode(l,r,0,0,0);
	int mid=(l+r)>>1;
	int cl=build(l,mid),cr=build(mid+1,r);
	return newnode(l,r,cl,cr,0);
}
void modify(int a,int b,int id,int val){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	pushdown(id);
	if (l>b||r<a) return;
	if (a<=l&&r<=b){
		t[id].tag+=val;
		pushdown(id);
		return;
	}
	modify(a,b,cl,val); modify(a,b,cr,val);
	update(id);
}
int ext0(){ 
	pushdown(rt);
	return t[rt].dat==0; 
}
bool check(int mid){
	cnt=0; int N=0;
	for (int i=1;i<=mid;i++){
		if (mat[i].x1<=L-W){
			lis[++cnt]=(chk){mat[i].x1,min(mat[i].y2,L-H),min(mat[i].y1,L-H),1};
			a[cnt]=lis[cnt].x;
		}
		if (mat[i].x2+1<=L-W){
			lis[++cnt]=(chk){mat[i].x2+1,min(mat[i].y2,L-H),min(mat[i].y1,L-H),-1};
			a[cnt]=lis[cnt].x;
		}
	} N=cnt;
	sort(a+1,a+cnt+1);
	int nn=unique(a+1,a+cnt+1)-a-1;
	for (int i=1;i<=N;i++){
		lis[i].x=lower_bound(a+1,a+nn+1,lis[i].x)-a;
	}
	cnt=0;
	a[++cnt]=0; a[++cnt]=L-W;
	for (int i=1;i<=N;i++){
		a[++cnt]=lis[i].l; a[++cnt]=lis[i].r;
	}
	sort(a+1,a+cnt+1);
	nn=unique(a+1,a+cnt+1)-a-1;
	int mx=0;
	for (int i=1;i<=N;i++){
		lis[i].l=lower_bound(a+1,a+nn+1,lis[i].l)-a;
		lis[i].r=lower_bound(a+1,a+nn+1,lis[i].r)-a;
		mx=max(mx,lis[i].r);
	}
	M=0;
	rt=build(0,mx);
	for (int l=1,r=1;l<=N;l=r+1,r++){
		while (lis[l].x==lis[r+1].x) r++;
		for (int i=l;i<=r;i++){
			int L=lis[i].l,R=lis[i].r,val=lis[i].v;
			modify(L,R,rt,val);
		}
		cout<<lis[l].l<<" "<<ext0()<<endl;
		if (ext0()) return 0;
	}
	if (lis[1].x>0) return 0;
	if (lis[N].x<L-W) return 0;
	return 1;
}
int main(){
	scanf("%d%d%d%d",&n,&L,&W,&H);
	for (int i=1;i<=n;i++){
		int x,y; scanf("%d%d",&x,&y);
		mat[i]=(rec){max(x-W+1,0),max(y-1,0),max(x-1,0),max(y-H+1,0)};
		cout<<i<<": ("<<mat[i].x1<<","<<mat[i].y1<<") ("<<mat[i].x2<<","<<mat[i].y2<<")"<<endl;
//		a[++cnt]=mat[i].x1; a[++cnt]=mat[i].x2;
	}
/*	sort(a+1,a+cnt+1);
	int nn=unique(a+1,a+cnt+1)-a-1;
	for (int i=1;i<=n;i++){
		mat[i].x1=lower_bound(a+1,a+nn+1,mat[i].x1)-a;
		mat[i].x2=lower_bound(a+1,a+nn+1,mat[i].x2)-a;
	}
	cnt=0;
	for (int i=1;i<=n;i++){
		a[++cnt]=mat[i].y1; a[++cnt]=mat[i].y2;
	}
	sort(a+1,a+cnt+1);
	int nn=unique(a+1,a+cnt+1)-a-1;
	for (int i=1;i<=n;i++){
		mat[i].y1=lower_bound(a+1,a+nn+1,mat[i].y1)-a;
		mat[i].y2=lower_bound(a+1,a+nn+1,mat[i].y2)-a;
	}
*/	int l=0,r=n+1,mid;
	while (l+1<r){
		cout<<l<<" "<<r<<endl;
		mid=(l+r)>>1;
		if (check(mid)) l=mid;
		else r=mid;
	}
	if (check(n)) printf("%d\n",l);
	else printf("-1\n");
	return 0;
}
