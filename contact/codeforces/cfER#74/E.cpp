#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#define int long long
using namespace std;
const int maxn = 1e5+10;
const int inf = 1e12;
 
int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+c-48;c=getchar();}
	return x*f;
}
 
int k,m,n,num;
char c[maxn];
int a[21][1<<20],dp[1<<20];
signed main(){
	n=read();m=read();
	scanf("%s",c+1);
	for(register int i=2;i<=n;i++){
		if(c[i-1]==c[i])continue;
		int x=c[i-1]-'a',y=c[i]-'a';
		a[x][1<<y]++;
		a[y][1<<x]++;
	}
	num=(1<<m)-1;
	for(register int i=0;i<m;i++){
		for(register int s=0;s<=num;s++){
			if(__builtin_popcount(s)>1){
				a[i][s]=a[i][s & (s-1)]+a[i][s & (-s)];	
			}
		}
	}
	//memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(register int s=1;s<=num;s++){
		dp[s]=inf;
		for(register int i=0;i<m;i++){
			if((1<<i)&s){
				dp[s]=min(dp[s],dp[s^(1<<i)]+(a[i][s]-a[i][num^s])*(__builtin_popcount(s)));
			}
		}
		//printf("%lld %lld\n",s,dp[s]);
	}
	printf("%lld\n",dp[num]);
	return 0;
}
