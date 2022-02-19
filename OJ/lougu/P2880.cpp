#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=5e5+5;
int a[MAXN],n,m,T;
struct Tnode{
	int cl,cr;
	int l,r;
	int mx,mn;
} t[MAXN*20];
int newnode(int cl,int cr,int l,int r,int mx,int mn){
	T++;
	t[T]=(Tnode){cl,cr,l,r,mx,mn};
	return T;
}
int ini(int l,int r){
	if (l==r) return newnode(-1,-1,l,r,a[l],a[r]);
	int mid=(l+r)>>1;
	int nl=ini(l,mid),nr=ini(mid+1,r);
	return newnode(nl,nr,l,r,max(t[nl].mx,t[nr].mx),min(t[nl].mn,t[nr].mn));
}
int qmx(int id,int l,int r){
	if (t[id].r<l||t[id].l>r) return -1e9;
	if (t[id].cl==-1||t[id].cr==-1) return t[id].mx;
	if (t[id].r<=r&&t[id].l>=l) return t[id].mx;
	return max(qmx(t[id].cl,l,r),qmx(t[id].cr,l,r));
}
int qmn(int id,int l,int r){
	if (t[id].r<l||t[id].l>r) return 1e9;
	if (t[id].cl==-1||t[id].cr==-1) return t[id].mn;
	if (t[id].r<=r&&t[id].l>=l) return t[id].mn;
	return min(qmn(t[id].cl,l,r),qmn(t[id].cr,l,r));
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int root=ini(1,n);
	for (int i=1,l,r;i<=m;i++){
		scanf("%d%d",&l,&r);
//		printf("%d\n",qmx(root,l,r));
		printf("%d\n",qmx(root,l,r)-qmn(root,l,r));
	}
	return 0;
}
