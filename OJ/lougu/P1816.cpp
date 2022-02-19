#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n,m,x[MAXN];
int T;
struct rec{
	int l,r,dat;
} d[MAXN*20];
int newnode(int l,int r,int val){
	T++;
	d[T]=(rec){l,r,val};
	return T;
}
int gen(int a,int b){
	if (a==b) return newnode(-1,-1,x[a]);
	int mid=(a+b)>>1;
	int l=gen(a,mid),r=gen(mid+1,b);
	return newnode(l,r,min(d[l].dat,d[r].dat));
}
int query(int l,int r,int a,int b){
	if (l>b||r<a) return 1e9;
	int mid=(l+r)>>1;
	if (l==r) return d[l].dat;
	int res=min(query(l,mid,a,b),query(mid+1,r,a,b));
	return res;
}
void dfs(int x){
	printf("%d %d %d\n",d[x].l,d[x].r,d[x].dat;
	
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&x[i]);
	gen(1,n);
	dfs(1);
//	for (int i=1;i<=T;i++) cout<<d[i].l<<" "<<d[i].r<<" "<<d[i].dat<<endl;
	for (int i=0,x,y;i<m;i++){
		scanf("%d%d",&x,&y);
		printf("%d\n",query(1,n,x,y));
	}
	return 0;
}
