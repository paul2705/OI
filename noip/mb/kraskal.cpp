#include<iostream>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
const int MAXM=5e5+5;
struct ed{
	int u,v,w;
} e[MAXM];
int n,m;
int fa[MAXN];
bool cmp(ed a,ed b){ return a.w<b.w; }
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){ fa[find(x)]=find(y); }
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	}
	sort(e+1,e+m+1,cmp);
	ll s=0;
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if (find(u)!=find(v)) uion(u,v),s+=(ll)e[i].w;
	}
	printf("%lld\n",s);
	return 0;
}
