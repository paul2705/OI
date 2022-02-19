#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e3+5;
const int MAXM=5e5+5;
struct rec{
	int u,v,w;
} e[MAXM];
int fa[MAXN];
int n,m,ed;
bool cmp(rec a,rec b){ return a.w<b.w; }
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){ fa[find(x)]=find(y); }
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		e[ed++]=(rec){u,v,w};
	}
	sort(e,e+ed,cmp);
	int ans=0;
	for (int i=0;i<ed;i++){
		int u=e[i].u,v=e[i].v;
		if (find(u)==find(v)) continue;
		uion(u,v); ans+=e[i].w;
	}
	printf("%d\n",ans);
	return 0;
}
