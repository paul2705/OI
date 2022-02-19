#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=350;
typedef long long ll;
int t,n,m,M,use[MAXN];
ll s[MAXN],f[MAXN][MAXN],c[MAXN][MAXN];
bool ff=true;
int main(){
	scanf("%d",&t);
	while (t--){
		memset(use,0,sizeof(use)); memset(s,0,sizeof(s));
		memset(f,0,sizeof(f)); memset(c,0,sizeof(c));
		int i,j,x,y,k;
		ff=true;
		scanf("%d%d%d",&n,&m,&M);
		for (int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			use[y]++;
		}
		for (int i=n;i>=1;i--){
			s[i]=s[i+1]+use[i];
			if (s[i]>n-i+1){
				ff=false;
				printf("NO\n");
			}
		}
		if (!ff) continue;
		for (int i=0;i<n;i++){
			c[i][0]=c[i][i]=1;
			for (int j=1;j<i;j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%M;
		}
		f[n+1][0]=1;
		for (int i=1;i<=n;i++) f[n+1][i]=0;
		for (int i=n;i>=1;i--){
			for (int j=0;j<=n-s[i]-i+1;j++){
				for (int k=0;k<=j;k++){
					f[i][j]=(f[i][j]+f[i+1][j])%M;
				}
			}
		}
		printf("YES %lld\n",f[1][n-m]);
	}
	return 0;
}
