#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=4e5+5;
int f[MAXN],g[MAXN];
int n,fa[MAXN],d[MAXN];
int q[MAXN],l,r;
bool use[MAXN];
int find(int x){
	if (fa[x]==x) return x;
//	cout<<__func__<<" "<<x<<" "<<fa[x]<<endl;
	int fx=find(fa[x]);
//	cout<<x<<" "<<fa[x]<<endl;
	d[x]+=d[fa[x]];
	return fa[x]=fx;
}
bool check(int mid){
	for (int i=1;i<=2*n;i++) use[i]=0,fa[i]=i,d[i]=0;
	l=r=0;
	use[1]=use[n+1]=1;
	q[++r]=1; q[++r]=n+1; 
	while (l<r){
		int u=q[++l];
//		cout<<u<<endl;
		if (u<=n) u=f[u];
		else u=g[u];
		for (int v=u;;){
			u=find(u); find(v);
//			cout<<u<<" "<<v<<" "<<d[v]<<endl;
			if (d[v]>=mid) break;
			int x=u,fu;
			if (x<=n) x+=n,fu=f[u];
			else x-=n,fu=g[u];
			if (use[x]) break;
			use[x]=1,q[++r]=x;
			if (find(fu)==u) break;
			fa[u]=fu,d[u]++; 
		}
	}
	return use[n]||use[n+n];
}
int main(){
//	freopen("B.in","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int u,v; scanf("%d%d",&u,&v);
		f[i]=u; g[i+n]=v+n;
	}
	int l=-1,r=n+1,mid;
	while (l+1<r){
		mid=(l+r)>>1;
//		cout<<l<<" "<<r<<" "<<mid<<endl;
		if (check(mid)) r=mid;
		else l=mid;
	}
	if (r==n+1) printf("-1\n");
	else printf("%d\n",r);
	return 0;
}
