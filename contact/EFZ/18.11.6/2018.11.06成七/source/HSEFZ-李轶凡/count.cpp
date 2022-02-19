#include<bits/stdc++.h>
#define lint long long
using namespace std;

int n,m,p;
lint dp[1100][1100];		//State: Certained Hang and lie


int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);
//	dp[0][0]=1;
	dp[1][1]=n*m%p;
	for(int i=2; i<=n*m; i++){
		for(int j=min(n,i); j>0; j--)		//Ceratined
			for(int k=min(m,i); k>0; k--){
				if(j*k>=i-1) dp[j][k]=dp[j][k]*(j*k-(i-1))%p;
				if(n>=j-1)dp[j][k]=(dp[j][k]+dp[j-1][k]*(k*n-k*(j-1)))%p;
				if(n>=k-1)dp[j][k]=(dp[j][k]+dp[j][k-1]*(j*m-j*(k-1)))%p;
			}	
	}
	/*
	int st=n*m;
	lint ans=0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
		ans=(ans+dp[i][j])%p;
	for(int i=max(n,m)+1; i<=st; i++)
		ans=ans*(st-i+1)%p;
	//cout<<ans<<endl;
*/
	printf("%lld\n",dp[n][m]);
	return 0;
}
