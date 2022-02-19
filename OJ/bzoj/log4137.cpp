#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Treenode{
	int l,r;
	int s,list[105];
} t[4000005];
int n,m,ql,qr,qk,M,root[1000005];
int a[1000005];
int newnode(int l,int r,int min){
	M++;
	t[M].l=l;
	t[M].r=r;
	t[M].min=min;
	return M;
}
int inc(int p,int pl,int pr,int a){
	int ns=t[p].s+1;
	if (pl==pr) return newnode(t[p].l,t[p].r,ns);
	else {
		int pm=(pl+pr)/2;
		if (a<=pm) 
		return newnode(inc(t[p].l,pl,pm,a),t[p].r,ns);
		return newnode(t[p].l,inc(t[p].r,pm+1,pr,a),ns);
	}
}
int select(int p,int pp,int pl,int pr,int k){
	if (pl==pr) return pl;
	int pm=(pl+pr)/2;
	int sl=t[t[p].l].s-t[t[pp].l].s;
	if (sl>=k) return select(t[p].l,t[pp].l,pl,pm,k);
	else return select(t[p].r,t[pp].r,pm+1,pr,k-sl);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	root[0]=0;
	for (int i=1;i<=n;i++)
		root[i]=inc(root[i-1],1,n,a[i]);
	for (int i=0;i<m;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d",select(
	return 0;
}
