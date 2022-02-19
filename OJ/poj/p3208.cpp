#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const int MAXN=1e3+5;
const int MAXS=10;
ll dp[MAXN][5],n;
int g[4][12]={{0},{3,3,3,3,3,3,0,3,3,3},{3,3,3,3,3,3,1,3,3,3},{3,3,3,3,3,3,2,3,3,3}};
int main(){
	dp[0][0]=1;
	for (int i=1;i<=MAXS;i++){
		dp[i][0]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2])*9;
		dp[i][1]=dp[i-1][0];
		dp[i][2]=dp[i-1][1];
		dp[i][3]=dp[i-1][3]*10+dp[i-1][2];
	}
	int T; scanf("%d",&T);
	while (T--){
		scanf("%lld",&n);
		int d=0,u=3;
		while (dp[d][3]<n) d++;
		while (d){
			//cout<<d<<endl;
			ll k=0;
			for (int i=0;i<10;i++){
				ll tmp=0;
				for (int j=3;j>=g[u][i];j--)
					tmp+=dp[d-1][j];
				if (k+tmp>=n){
					printf("%d",i);
					u=g[u][i];
					break;
				}
				k+=tmp;
			}
			n-=k; d--;
		}
		printf("\n");
	}
	return 0;
}
