#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=505;
int t[MAXN];
int n,m;
int f[MAXN][MAXN];
int mn[MAXN][MAXN];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&t[i]);
		for (int j=0;j<=m;j++) f[i][j]=mn[i][j]=1e9;
	}
	sort(t+1,t+n+1);
//	for (int i=1;i<=n;i++) printf("%d ",t[i]);
//	printf("\n");
	for (int i=1;i<=n;i++){
		for (int k=0;k<=m;k++){
			int cnt=k;
			for (int j=i-1;j>=0;j--){
				if (j==0||t[i]+k-t[j]>=m) f[i][k]=min(f[i][k],mn[j][min(t[i]+k-t[j]-m,m)]+cnt);
				cnt+=t[i]+k-t[j];
			}
			if (k==0) mn[i][k]=f[i][k];
			else mn[i][k]=min(mn[i][k-1],f[i][k]);
//			cout<<i<<" "<<k<<" "<<mn[i][k]<<endl;
		}
	}
	printf("%d\n",mn[n][m]);
	return 0;
}
