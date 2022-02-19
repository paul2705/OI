#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=4*1e4+5;
const int MAXE=1e5;
int a[MAXN],b[MAXN];
int n,m,l,ans,f[3][MAXN];
struct edge{
	int u,v;
} ed[MAXE];
bool cmp(edge a,edge b){ return (a.u<b.u)||(a.u==b.u&&a.v<b.v); }
int main(){
	scanf("%d%d%d",&n,&m,&l);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++) scanf("%d",&b[i]);
	for (int i=1;i<=l;i++) scanf("%d%d",&ed[i].u,&ed[i].v);
	sort(ed+1,ed+l+1,cmp);
	f[1][ed[1].u]=f[2][ed[1].v]=a[ed[1].u]+b[ed[1].v];
	for (int i=2;i<=l;i++){
		if (ed[i-1].u==ed[i].u&&ed[i-1].v==ed[i].v) continue;
		int u=ed[i].u,v=ed[i].v;
		if (f[1][u]==0) f[2][v]=max(f[2][v],a[u]+b[v]);
		else f[2][v]=max(f[2][v],f[1][u]+b[v]);
		if (f[2][v]==0) f[1][u]=max(f[1][u],a[u]+b[v]);
		else f[1][u]=max(f[1][u],f[2][v]+a[u]);
	}
	for (int i=1;i<=n;i++) ans=max(ans,max(f[1][i],a[i]));
	for (int i=1;i<=m;i++) ans=max(ans,max(f[2][i],b[i]));
	printf("%d\n",ans);
	return 0;
}
