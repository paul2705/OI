#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e2+5;
const int MAXM=MAXN*MAXN;
struct ed{
    int u,v,w;
} e[MAXM];
int n,mx,edge;
int fa[MAXN];
bool cmp(ed a,ed b){ return a.w<b.w; }
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){ fa[find(x)]=find(y); }
int main(){
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n); mx=edge=0;
		for (int i=1;i<=n;i++) fa[i]=i;
		for (int i=1;i<=n;i++){
		 	for (int j=1,w;j<=n;j++){
				scanf("%d",&w);
				e[edge++]=(ed){i,j,w};
			}
		}
	    sort(e,e+edge,cmp);
		for (int i=0;i<edge;i++){
			int u=e[i].u,v=e[i].v;
			if (find(u)==find(v)) continue;
			uion(u,v); mx=max(mx,e[i].w);
		}
		printf("%d\n",mx);
    }
    return 0;
}

