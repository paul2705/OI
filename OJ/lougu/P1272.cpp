#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=155;
const int MAXE=MAXN*2;
int bro[MAXN],son[MAXN],cnt[MAXN];
int n,m,ans=1e9,root,f[MAXN][MAXN],sz[MAXN];
bool use[MAXN];
void dfs(int u){
	int s=son[u],b=bro[u];
	if (s!=0) dfs(s);
	if (b!=0) dfs(b);
	for (int k=0;k<=m;k++) f[u][k]=f[b][k]+1;
	for (int x=0;x<=sz[s];x++){
		for (int y=0;y<=sz[b];y++){
			f[u][x+y+1]=min(f[u][x+y+1],f[s][x]+f[b][y]);
		}
	}
	sz[u]=sz[s]+sz[b]+1;
	if (u==root) ans=min(ans,f[u][m]);
	else ans=min(ans,f[son[u]][m-1]+1);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		bro[v]=son[u]; son[u]=v;
		use[v]=1;
	}
	for (int i=0;i<=m;i++) f[0][i]=n;
	f[0][0]=0;
	for (int i=1;i<=n;i++){
		if (!use[i]) root=i;
	}
	dfs(root);
	printf("%d\n",ans);
	return 0;
}
