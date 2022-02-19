#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=7e2+5;
const int mod=1e9+7;
typedef long long ll;
char s[MAXN];
ll f[MAXN][MAXN][5][5],a[MAXN],stk[MAXN],cnt;
ll w[2][4]={{1,2,0,0},{0,0,1,2}};
ll c[MAXN];
ll dfs(ll l,ll r){
	ll ans=0,las,now;
	if (l==r-1){
		if (c[l-1]!=1) ans++;
		if (c[l-1]!=2) ans++;
		if (c[r+1]!=1) ans++;
		if (c[r+1]!=2) ans++;
		return ans;
	}
	if (a[l]==r){
		for (int i=0;i<4;i++){
			if (c[l-1]==w[0][i]&&w[0][i]) continue;
			if (c[r+1]==w[1][i]&&w[1][i]) continue;
			c[l]=w[0][i],c[r]=w[1][i];
			if (!f[l+1][r-1][w[0][i]][w[1][i]]) f[l+1][r-1][w[0][i]][w[1][i]]=dfs(l+1,r-1);
			ans+=f[l+1][r-1][w[0][i]][w[1][i]],ans%=mod;
		}
	}
	else {
		for (int i=0;i<4;i++){
			if (c[l-1]==w[0][i]&&w[0][i]) continue;
			c[l]=w[0][i];
			c[a[l]]=w[1][i];
			if (l==a[l]-1) las=1;
			else{
				if (!f[l+1][a[l]-1][w[0][i]][w[1][i]]) f[l+1][a[l]-1][w[0][i]][w[1][i]]=dfs(l+1,a[l]-1);
				las=f[l+1][a[l]-1][w[0][i]][w[1][i]];
			}
			if (!f[a[l]+1][r][c[a[l]]][c[r+1]]) f[a[l]+1][r][c[a[l]]][c[r+1]]=dfs(a[l]+1,r);
			now=f[a[l]+1][r][c[a[l]]][c[r+1]];
			ans+=las*now; ans%=mod;
		}
	}
	return ans;
}
int main(){
	cin>>s;
	int len=strlen(s);
	for (int i=len-1;i>=0;i--){
		if (s[i]==')') stk[cnt++]=i;
		else a[i]=stk[--cnt];
	}
	printf("%lld\n",dfs(0,len-1));
	return 0;
}
