#include <cstdio>
long long dp[7005][85][85];
int main()
{
	freopen("count.in", "r", stdin);
	freopen("count.out", "wt", stdout);
	int n, m, MOD;
	scanf("%d%d%d", &n, &m, &MOD);
	dp[1][1][1] = n * m;
	for (int i = 1; i < n * m; i++)
	{
		for (int x = 1; x <= n; x++)
		{
			for (int y = 1; y <= m; y++)
			{
				(dp[i + 1][x + 1][y] += dp[i][x][y] * y * (n - x)) %= MOD;
				(dp[i + 1][x][y + 1] += dp[i][x][y] * x * (m - y)) %= MOD;
				(dp[i + 1][x][y] += dp[i][x][y] * (x * y - i)) %= MOD;
			}
		}
	}
	printf("%lld\n", dp[n * m][n][m]);
	return 0;
}
