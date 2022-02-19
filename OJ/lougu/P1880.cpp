#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;
const int MAXN=1005;
int dp[3][MAXN][MAXN];
int n,a[MAXN],ansi=INT_MAX,ansa;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),a[n+i]=a[i];
	for (int i=1;i<=n<<1;i++) a[i]+=a[i-1];
	for (int i=(n<<1)-1;i>0;i--){
		for (int j=i+1;j<i+n;j++){
			dp[1][i][j]=INT_MAX;
			for (int k=i;k<j;k++){
				dp[1][i][j]=min(dp[1][i][j],dp[1][i][k]+dp[1][k+1][j]+a[j]-a[i-1]);
				dp[2][i][j]=max(dp[2][i][j],dp[2][i][k]+dp[2][k+1][j]+a[j]-a[i-1]);
			}
		}
	}
	for (int i=1;i<=n;i++){
		ansi=min(ansi,dp[1][i][i+n-1]);
		ansa=max(ansa,dp[2][i][i+n-1]);
	}
	printf("%d\n%d\n",ansi,ansa);
	return 0;
}
