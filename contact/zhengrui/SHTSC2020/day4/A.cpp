#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
const int _=1e2;
const int maxn=1e5+_;
const int fbin=(1<<18)+_;
const LL inf=(1LL<<61);
inline LL mymax(LL x,LL y){return x>y?x:y;}

#define lc (now<<1)
#define rc (now<<1)|1
#define mid (ql+qr)/2
struct CT{
	struct node{LL a,b,c;node(){a=b=c=-inf;}}tr[2*fbin];
	void pushdown(int now){
		if(tr[now].a!=-inf)tr[lc].a=mymax(tr[now].a,tr[lc].a),tr[rc].a=mymax(tr[now].a,tr[rc].a);
		if(tr[now].b!=-inf)tr[lc].b=mymax(tr[now].b,tr[lc].b),tr[rc].b=mymax(tr[now].b,tr[rc].b);
		if(tr[now].c!=-inf)tr[lc].c=mymax(tr[now].c,tr[lc].c),tr[rc].c=mymax(tr[now].c,tr[rc].c);
		tr[now].a=tr[now].b=tr[now].c=-inf;
	}
	void change(int now,int ql,int qr,int l,int r,int op,LL d){
		if(l>r)return ;
		if(ql==l&&qr==r){
				 if(op==0)tr[now].a=mymax(tr[now].a,d);
			else if(op==1)tr[now].b=mymax(tr[now].b,d);
			else if(op==2)tr[now].c=mymax(tr[now].c,d);
			return ;
		}
		pushdown(now);
			 if(r<=mid)  change(lc,ql,mid,l,r,op,d);
		else if(mid+1<=l)change(rc,mid+1,qr,l,r,op,d);
		else change(lc,ql,mid,l,mid,op,d),change(rc,mid+1,qr,mid+1,r,op,d);
	}
	LL getmax(int now,int ql,int qr,int p,int op){
		if(ql==qr)return op?(op==2?tr[now].c:tr[now].b):tr[now].a;
		pushdown(now);
		if(p<=mid)return getmax(lc,ql,mid,p,op);
		else 	  return getmax(rc,mid+1,qr,p,op);
	}
}T[3];
#undef lc
#undef rc
#undef mid

struct node{int l,r,c;}a[maxn];
bool cmp(node n1,node n2){return n1.r<n2.r;}
int lsn,ls[2*maxn];
int main(){
	int QWQ,n;LL X,Y;
	scanf("%d%d%lld%lld",&QWQ,&n,&X,&Y);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].c,&a[i].l,&a[i].r),a[i].c--,a[i].l--;
		ls[++lsn]=a[i].l;
		ls[++lsn]=a[i].r;
	}
	sort(ls+1,ls+lsn+1);
	lsn=unique(ls+1,ls+lsn+1)-ls-1;
	for(int i=1;i<=n;i++)
		a[i].l=lower_bound(ls+1,ls+lsn+1,a[i].l)-ls,
		a[i].r=lower_bound(ls+1,ls+lsn+1,a[i].r)-ls;
	sort(a+1,a+n+1,cmp);
	
	LL ans=0;
	for(int i=1;i<=n;i++){
		int l=a[i].l,r=a[i].r; LL fi=X*(ls[r]-ls[l]);
		for(int j=0;j<=2;j++){
			fi=mymax(fi,T[j].getmax(1,1,lsn,l,0)+X*(ls[r]-ls[l]));
			if(j==a[i].c)fi=mymax(fi,T[j].getmax(1,1,lsn,l,1)+X*ls[r]);
			else 		 fi=mymax(fi,T[j].getmax(1,1,lsn,l,2)+X*ls[r]+(X+Y)*ls[l]);
		}
		ans=max(ans,fi);
		T[a[i].c].change(1,1,lsn,r,a[n].r,0,fi);
		T[a[i].c].change(1,1,lsn,l+1,r-1 ,1,fi-X*ls[r]);
		T[a[i].c].change(1,1,lsn,l+1,r-1 ,2,fi-(X+X+Y)*ls[r]);
	}
	printf("%lld\n",ans);
				
	return 0;
}
