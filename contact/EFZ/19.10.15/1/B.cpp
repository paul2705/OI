#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=5e4+5;
vector<int> g[MAXN];
int id1[MAXN],id2[MAXN],id3[MAXN];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) id1[i]=id2[i]=id3[i]=-1;
	for (int i=1;i<=n;i++){
		id1[i]=i/42;
		id2[i]=(i-id1[i]*42)/42;
	}
	for (int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		if (id1[u]!=id1[v]) printf("B\n");
		else if (id2[u]!=id2[v]) printf("R\n");
		else printf("G\n");
	}
	return 0;
}
