#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
const int MAXM=MAXN*MAXN;
struct ed{
	int u,v,w;
} e[MAXM];
int n,sum,edge;
int fa[MAXN];
bool cmp(ed a,ed b){ return a.w<b.w; }
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){ fa[find(x)]=find(y); }
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1,u,v,w;i<=n*(n-1)/2;i++){
		scanf("%d%d%d",&u,&v,&w);
		e[edge++]=(ed){u,v,w};
	}
	sort(e,e+edge,cmp);
	for (int i=0;i<edge;i++){
		int u=e[i].u,v=e[i].v;
		if (find(u)==find(v)) continue;
		uion(u,v); sum+=e[i].w;
	}
	printf("%d\n",sum);
	return 0;
}
