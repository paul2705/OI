#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e2+5;
int a[MAXN],n,k;
int f[MAXN][MAXN][MAXN];
int dp(int l,int r,int s){
	if (l>r) return 0;
	if (l==r) return k-1-s;
	if (f[l][r][s]>=0) return f[l][r][s];
	int ans=1e9;
	if (s<k-1) ans=dp(l,r,s+1)+1;
	else ans=dp(l+1,r,0);
	for (int i=l+1;i<=r;i++){
		if (a[l]==a[i]){
			ans=min(ans,dp(l+1,i-1,0)+dp(i,r,min(k-1,s+1)));
		}
	}
	return f[l][r][s]=ans;
} 
int main(){
	memset(f,-1,sizeof(f));
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	printf("%d\n",dp(1,n,0));
	return 0;
}	
