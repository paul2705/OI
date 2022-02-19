#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=20;
int a[MAXN][MAXN],f[MAXN][MAXN];
int n,m,r,c,ans=1e9;
int w[MAXN],v[MAXN][MAXN],seat[MAXN];
void dp(){
	memset(v,0,sizeof(v)); memset(w,0,sizeof(w)); memset(f,127,sizeof(f));
	for (int i=1;i<=m;i++){
		for (int j=1;j<r;j++){
			w[i]+=abs(a[seat[j]][i]-a[seat[j+1]][i]);
		}
	}
	for (int i=1;i<=m;i++){
		for (int j=i+1;j<=m;j++){
			for (int k=1;k<=r;k++){
				v[i][j]+=abs(a[seat[k]][i]-a[seat[k]][j]);
			}
		}
	}
	f[0][0]=0;
	for (int i=1;i<=c;i++){
		for (int j=i;j<=m;j++){
			for (int k=0;k<j;k++){
				f[i][j]=min(f[i][j],f[i-1][k]+w[j]+v[k][j]);
			}
		}
	}
	for (int i=c;i<=m;i++) ans=min(ans,f[c][i]);
}
void dfs(int x,int las){
	if (x>r) return dp(),void();
	for (int i=las+1;n-i>=r-x;i++){
		seat[x]=i;
		dfs(x+1,i);
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&r,&c);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	}
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}
