#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
ll dp[12][11],d[12],a,b;
void get_dp(){
	for (int i=0;i<=9;i++) dp[1][i]=1;
	for (int i=2;i<=11;i++)
		for (int j=0;j<=9;j++) 
			for (int k=0;k<=9;k++)
				if (abs(k-j)>=2) dp[i][j]+=dp[i-1][k];
}
ll solve(ll x){
	ll ans=0,cnt=0;
	memset(d,0,sizeof(d));
	while (x>0) d[++cnt]=x%10,x/=10; 
	for (int i=1;i<d[cnt];i++) ans+=dp[cnt][i];
	for (int i=cnt-1;i>0;i--)
		for (int j=1;j<=9;j++) ans+=dp[i][j];
	for (int i=cnt-1;i>0;i--){
		for (int j=0;j<d[i];j++) 
			if (abs(d[i+1]-j)>=2) ans+=dp[i][j];
		if (abs(d[i+1]-d[i])<2) break;
	}
	return ans;
}
int main(){
	scanf("%lld%lld",&a,&b);
	get_dp();
	printf("%lld\n",solve(b+1)-solve(a));
	return 0;
}
