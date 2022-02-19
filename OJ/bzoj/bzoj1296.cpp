#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=55;
const int MAXM=2505;
int f[MAXN][MAXN],g[MAXN][MAXM];
int n,m,K;
char s[MAXN];
int sum[MAXN];
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		for (int j=1;j<=m;j++) sum[j]=sum[j-1]+(s[j]=='1');
		for (int j=1;j<=m;j++){
			for (int k=1;k<=m;k++){
				f[k][j]=0;
				for (int l=0;l<k;l++){
					int tmp=sum[k]-sum[l];
					f[k][j]=max(f[k][j],f[l][j-1]+max(tmp,k-l-tmp));
				}
			}
		}
		for (int j=1;j<=K;j++){
			int tmp=min(m,j);
			for (int k=1;k<=tmp;k++){
				g[i][j]=max(g[i][j],g[i-1][j-k]+f[m][k]);
			}
		}
	}
	int ans=0;
	for (int i=1;i<=K;i++){
		ans=max(ans,g[n][i]);
	}
	printf("%d\n",ans);
	return 0;
}
