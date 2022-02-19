#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e4+5;
const int MAXM=1e5+5;
int edge,head[MAXN],nex[MAXM],tail[MAXM],c[MAXM];
int x[MAXN],y[MAXN],v[MAXN];
int n,m,T;

int main(){
	scanf("%d",&T);
	while (T--){
		memset(head,0,sizeof(head)); edge=0;
		scanf("%d%d",&n,&m);
		for (int i=1,u,v,c;i<=n;i++){
			scanf("%d%d%d",&u,&v,&c);
			add(u,v,c); add(v,u,c);
		}
		for (int i=1;i<=m;i++) scanf("%d%d%d",&x[i],&y[i],&v[i]);
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}
