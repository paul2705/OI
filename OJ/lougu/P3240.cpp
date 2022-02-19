#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
const int MAXM=1e3+5;
const int mod=1e9+7;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int fa[MAXN],a[MAXN],b[MAXN];
int n,m,in[MAXN],its[MAXN],cnt[MAXN];
int C[MAXM][MAXM],sz[MAXN];
int f[MAXN][MAXN],g[MAXN];
char c[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
bool uion(int x,int y){
	int fx=find(x),fy=find(y);
	if (fx!=fy) fa[fx]=fy;
	else return 1;
	return 0;
}
void dfs(int u,int p){
	sz[u]=f[u][1]=1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u);
		for (int i=1;i<=n;i++) g[i]=0;
		for (int i=1;i<=sz[u]+sz[v];i++){
			for (int j=1;j<=sz[u];j++){
				for (int k=1;k<=sz[v];k++){
					int x=k-i+j; if (x<0) continue;
	g[i]+=1ll*f[u][j]*f[v][k]%mod*C[i-1][j-1]%mod*C[j-1][x]%mod;
					g[i]%=mod;
				}
			}
		}
		for (int i=1;i<=sz[u]+sz[v];i++) f[u][i]=g[i];
		sz[u]+=sz[v];
	}
}
int main(){
	for (int i=0;i<=120;i++) C[i][0]=1;
	for (int i=1;i<=120;i++){
		for (int j=1;j<=i;j++){
			C[i][j]=C[i-1][j]+C[i-1][j-1];
			C[i][j]%=mod;
		}
	}
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++){
		scanf("%d %c %d",&a[i],&c[i],&b[i]);
		if (c[i]=='=') uion(a[i],b[i]);
	}
	for (int i=1;i<=n;i++) its[in[i]=find(i)]=1;
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++){
		if (c[i]!='='){
			add(in[a[i]],in[b[i]]); cnt[in[b[i]]]++;
			if (uion(in[a[i]],in[b[i]])) return printf("0\n"),0;
		}
	}
	for (int i=1;i<=n;i++) if (its[i]&&!cnt[i]) add(n+1,i);
	int ans=0;
	dfs(n+1,0);
	for (int i=1;i<=sz[n+1];i++) ans=(ans+f[n+1][i])%mod;
	printf("%d\n",ans);
	return 0;
}
