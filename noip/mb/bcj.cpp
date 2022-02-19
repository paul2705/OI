#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int fa[MAXN];
int n,m;
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){ fa[find(x)]=find(y);	}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1,op,x,y;i<=m;i++){
		scanf("%d%d%d",&op,&x,&y);
		if (op==1) uion(x,y);
		else{
			if (find(x)==find(y)) printf("Y\n");
			else printf("N\n");
		}
	}
	return 0;
}
