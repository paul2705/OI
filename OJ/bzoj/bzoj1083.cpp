#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
const int MAXM=1e6+6;
struct rec{
	int u,v,w;
} ed[MAXM];
int n,m,ans,mx;
int fa[MAXN],cnt=0;
bool cmp(rec a,rec b){ return a.w<b.w; }
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){ fa[find(x)]=find(y); }
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		ed[cnt++]=(rec){u,v,w};
	}
	sort(ed,ed+cnt,cmp);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=0;i<cnt;i++){
		int u=ed[i].u,v=ed[i].v;
		int fu=find(u),fv=find(v);
		if (fu==fv) continue;
		uion(u,v);
		ans++;
		mx=ed[i].w;
	}
	printf("%d %d\n",ans,mx);
	return 0;
}
