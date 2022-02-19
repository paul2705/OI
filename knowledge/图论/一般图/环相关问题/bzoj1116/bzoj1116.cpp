#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=1e6+6;
int n,m,fa[MAXN];
int mark[MAXN];
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){ 
	int fx=find(x),fy=find(y);
	fa[fx]=fy;
	mark[fy]|=mark[fx];
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		int fu=find(u),fv=find(v);
		if (fu!=fv) uion(u,v);
		else mark[fu]=1;
	}
	for (int i=1;i<=n;i++){
		int fi=find(i);
		if (!mark[fi]) return printf("NIE\n"),0;
	}
	printf("TAK\n");
	return 0;
}
