#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+c-'0';c=getchar();}
	return x*f;
}

const int maxn = 85;
int n, m, mod, f[2][maxn][maxn];
template<typename t1, typename t2> inline int inc(t1 x, t2 y) {int t = x + y; return t >= mod ? t - mod : t;}
template<typename t1, typename t2, typename t3> inline int inc(t1 a, t2 b, t3 c) {return inc(inc(a, b), c);}
template<typename t1, typename t2> inline int mul(t1 x, t2 y) {ll t = (ll)x * y; return t >= mod ? t % mod : t;}
int main()
{
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	n = read(), m = read(), mod = read();
	f[1][1][1] = mul(n, m);
	int all = n * m;
	for(int i = 1; i < all; i ++)
	{
		int np = i & 1, p = np ^ 1;
		memset(f[p], 0, sizeof f[p]);
		for(int j = 0; j <= n; j ++)
			for(int k = 0; k <= m; k ++) if(f[np][j][k])
			{
				int now = f[np][j][k], cross = j * k - i;
				if(cross)
					f[p][j][k] = inc(f[p][j][k], mul(now, cross));
				int nh = j * m - cross - i;
				f[p][j][k + 1] = inc(f[p][j][k + 1], mul(now, nh));
				int nl = k * n - cross - i;
				f[p][j + 1][k] = inc(f[p][j + 1][k], mul(now, nl));
			}
	}
	int np = all & 1;
	printf("%d\n", f[np][n][m]);
	return 0;
}
