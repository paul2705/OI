#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll f[16][16][16][16][16][6];
bool use[16][16][16][16][16][6];
int n;
int cnt[6];
ll dp(int a,int b,int c,int d,int e,int x){
	if (use[a][b][c][d][e][x]) return f[a][b][c][d][e][x];
	if (a+b+c+d+e==0) return 1;
	ll ret=0;
	if (a>0) ret=(ret+(a-(x==2))*dp(a-1,b,c,d,e,1)%mod)%mod;
	if (b>0) ret=(ret+(b-(x==3))*dp(a+1,b-1,c,d,e,2)%mod)%mod;
	if (c>0) ret=(ret+(c-(x==4))*dp(a,b+1,c-1,d,e,3)%mod)%mod;
	if (d>0) ret=(ret+(d-(x==5))*dp(a,b,c+1,d-1,e,4)%mod)%mod;
	if (e>0) ret=(ret+e*dp(a,b,c,d+1,e-1,5)%mod)%mod;
	use[a][b][c][d][e][x]=1;
	return f[a][b][c][d][e][x]=ret%mod;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x; scanf("%d",&x);
		cnt[x]++;
	}
//	memset(f,-1,sizeof(f));
	printf("%lld\n",dp(cnt[1],cnt[2],cnt[3],cnt[4],cnt[5],0));
	return 0;
}
