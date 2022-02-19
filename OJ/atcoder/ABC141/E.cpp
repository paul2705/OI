#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e3+5;
int dp[MAXN][MAXN];
int n;
char s[MAXN];
int main(){
	scanf("%d",&n);
	cin>>s;
	for (int i=0;i<n;i++){
		for (int j=0;j<i;j++){
			if (s[i]==s[j]) dp[i][j]=min(i-j,dp[i-1][j-1]+1);
		}
	}
	int ans=0;
	for (int i=0;i<n;i++){
		for (int j=0;j<i;j++){
			ans=max(ans,dp[i][j]);
		}
	}
	printf("%d\n",ans);
	return 0;
}
