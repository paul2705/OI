#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e2+5;
const int MAXM=4e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int n,ans,d[MAXN];
int c[MAXN];
bool fl=0;
int q[MAXM],l,r;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs(int u,int col){
	if (c[u]>0&&c[u]!=col) fl=1;
	if (c[u]) return;
	c[u]=col;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		dfs(v,col^1);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			char c=getchar(); while (c!='0'&&c!='1') c=getchar();
			if (c=='1') add(i,j);
		}
	}
	dfs(1,2);
	for (int i=1;i<=n;i++){
		for (int i=1;i<=n;i++) d[i]=0;
		l=r=0;
		q[++r]=i;
		d[i]=1; int res=1;
		while (l<r){
			int u=q[++l];
			res=max(res,d[u]);
			for (int e=head[u];e;e=nex[e]){
				int v=tail[e];
				if (d[v]) continue;
				d[v]=d[u]+1;
				q[++r]=v;
			}
		}
		ans=max(ans,res);
	}
//	for (int i=1;i<=n;i++) printf("%d %d\n",i,d[i]);
	if (!fl) printf("%d\n",ans);
	else printf("-1\n");
	return 0;
}
