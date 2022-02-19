#include<bits/stdc++.h>
#define llong long long
using namespace std;

inline int read()
{
	int x = 0,f = 1; char ch = getchar();
	for(;!isdigit(ch);ch=getchar()) {if(ch=='-') f = -1;}
	for(; isdigit(ch);ch=getchar()) {x = x*10+ch-48;}
	return x*f;
}

const int N = 100;
const int P = 1e9+7;
llong inv[N+3];
int n,m;

llong updsum(llong &x,llong y) {x = x+y>=P?x+y-P:x+y;}

llong quickpow(llong x,llong y)
{
	llong cur = x,ret = 1ll;
	for(int i=0; y; i++)
	{
		if(y&(1ll<<i)) {y-=(1ll<<i); ret = ret*cur%P;}
		cur = cur*cur%P;
	}
	return ret;
}

namespace Solve
{
	int a[N+3],c[N+3];
	llong dp[N+3][N+3];
	llong p[N+3][N+3];
	llong solve()
	{
//		printf("Solve "); for(int i=1; i<=n; i++) printf("%d ",a[i]); puts("");
		for(int i=0; i<=n; i++) c[i] = 0;
		c[1] = m; for(int i=m+1; i<=n; i++) c[a[i]]++;
		for(int i=1; i<=n; i++) c[i] += c[i-1];
//		printf("c: "); for(int i=1; i<=n; i++) printf("%d ",c[i]); puts("");
		llong coe = 1ll; for(int i=1; i<=n; i++) coe = coe*(c[i]-i+1ll)%P;
		for(int j=0; j<=n; j++)
		{
			p[0][j] = 1ll;
			for(int i=1; i<=n; i++)
			{
				p[i][j] = p[i-1][j]*(c[i]-j-i+1<=0?0ll:inv[c[i]-j-i+1])%P*(c[i]-j-i)%P;
//				printf("p[%d][%d]=%lld\n",i,j,p[i][j]);
			}
		}
		for(int i=0; i<=m; i++) for(int j=0; j<=i; j++) dp[i][j] = 0ll;
		dp[0][0] = 1ll;
		for(int i=0; i<m; i++)
		{
			for(int j=0; j<=i; j++)
			{
				llong x = dp[i][j];
				if(x)
				{
//					printf("dp[%d][%d]=%lld\n",i,j,dp[i][j]);
					updsum(dp[i+1][j+1],x*p[a[i+1]][j]%P);
					updsum(dp[i+1][j],x);
				}
			}
		}
		llong ret = 0ll;
		for(int j=0; j<=m; j++)
		{
//			printf("dp[%d][%d]=%lld\n",m,j,dp[m][j]);
			if(j&1) {updsum(ret,P-dp[m][j]);}
			else {updsum(ret,dp[m][j]);}
		}
		ret = ret*coe%P;
//		printf("ret%lld\n",ret);
		return ret;
	}
}

int a[N+3],b[N+3];
vector<int> disc;
llong ans;

void solve(int x)
{
//	printf("solve %d\n",x);
	for(int i=1; i<=m; i++)
	{
		Solve::a[i] = n;
		for(int j=1; j<=n; j++) {if(a[i]+b[j]<x) {Solve::a[i] = j-1; break;}}
	}
	for(int i=m+1; i<=n; i++)
	{
		Solve::a[i] = 1;
		for(int j=n; j>=1; j--) {if(a[i]+b[j]>x) {Solve::a[i] = j+1; break;}}
	}
	ans = (ans+Solve::solve())%P;
	for(int i=1; i<=m; i++)
	{
		Solve::a[i] = n;
		for(int j=1; j<=n; j++) {if(a[i]+b[j]<=x) {Solve::a[i] = j-1; break;}}
	}
	for(int i=m+1; i<=n; i++)
	{
		Solve::a[i] = 1;
		for(int j=n; j>=1; j--) {if(a[i]+b[j]>x) {Solve::a[i] = j+1; break;}}
	}
	ans = (ans-Solve::solve()+P)%P;
}

int main()
{
	for(int i=1; i<=N; i++) inv[i] = quickpow(i,P-2);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]); sort(a+1,a+n+1); reverse(a+1,a+n+1);
	for(int i=1; i<=n; i++) scanf("%d",&b[i]); sort(b+1,b+n+1); reverse(b+1,b+n+1);
	for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) disc.push_back(a[i]+b[j]);
	sort(disc.begin(),disc.end()); disc.erase(unique(disc.begin(),disc.end()),disc.end());
	for(int i=0; i<disc.size(); i++)
	{
		solve(disc[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
