#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2050;
const int MAXE=1e6*4+6;
struct edge{
	int u,v,w;
} ed[MAXE];
int cnt,ans,scc;
int n,c,fa[MAXN];
struct rec{
	int x,y;
} a[MAXN];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void uion(int x,int y){
	fa[find(x)]=find(y); scc--;
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
inline int sq(int x){ return x*x; }
inline int dis(int x,int y){
	return sq(a[x].x-a[y].x)+sq(a[x].y-a[y].y);
}
int main(){
	scanf("%d%d",&n,&c);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (i==j) continue;
			if (dis(i,j)<c) continue;
			cnt++; ed[cnt]=(edge){i,j,dis(i,j)}; 
		}
	}
	sort(ed+1,ed+cnt+1,cmp); scc=n;
	for (int i=1;i<=cnt;i++){
		int u=ed[i].u,v=ed[i].v;
		if (find(u)!=find(v)){
			uion(u,v); ans+=ed[i].w;
		}
	}
	if (scc==1) printf("%d\n",ans);
	else printf("-1\n");
	return 0;
}
	
