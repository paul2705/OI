#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=1e9;
const int MAXN=21;
int f[(1<<MAXN)];
int n,m;
int a[MAXN][MAXN],b[MAXN][MAXN];
int dfs(int s,int w){
	if (f[s]<inf) return f[s];
	int ans=w?-inf:inf;
	int x=n+1,y=1;
	for (int i=0;i<n+m-1;i++){
		if ((s>>i)&1) x--;
		else y++;
		if (((s>>i)&3)!=1) continue;
		int nxt=s^(3<<i);
		if (w) ans=max(ans,dfs(nxt,w^1)+a[x][y]);
		else ans=min(ans,dfs(nxt,w^1)-b[x][y]);
	}
	return f[s]=ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) scanf("%d",&b[i][j]);
	}
	for (int i=1;i<=(1<<(n+m));i++) f[i]=inf;
	f[((1<<n)-1)<<m]=0;
	printf("%d\n",dfs((1<<n)-1,1));
}
