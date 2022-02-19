#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e5+5;
int a[MAXN],n,q,M;
struct tnode{
	int l,r,cl,cr,mn,mx;
} t[MAXN*20];
int newnode(int l,int r,int cl,int cr,int mn,int mx){
	M++;
	t[M]=(tnode){l,r,cl,cr,mn,mx};
	return M;
}
int ini(int l,int r){
	if (l==r) return newnode(l,r,0,0,a[l],a[r]);
	int mid=(l+r)>>1;
	int cl=ini(l,mid),cr=ini(mid+1,r);
	return newnode(l,r,cl,cr,min(t[cl].mn,t[cr].mn),max(t[cl].mx,t[cr].mx));
}
int query_mn(int a,int b,int id){
	int l=t[id].l,r=t[id].r;
	if (r<a||l>b) return (int)1e9;
	if (a<=l&&r<=b) return t[id].mn;
	int nl=query_mn(a,b,t[id].cl),nr=query_mn(a,b,t[id].cr);
	return min(nl,nr);
}
int query_mx(int a,int b,int id){
	int l=t[id].l,r=t[id].r;
	if (r<a||l>b) return 0;
	if (a<=l&&r<=b) return t[id].mx;
	int nl=query_mx(a,b,t[id].cl),nr=query_mx(a,b,t[id].cr);
	return max(nl,nr);
}
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int root=ini(1,n);
	for (int i=1,a,b;i<=q;i++){
		scanf("%d%d",&a,&b);
		printf("%d\n",query_mx(a,b,root)-query_mn(a,b,root));
	}
	return 0;
}
