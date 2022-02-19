#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

const int Mod = 1e9 + 7;

const int maxk = 1010;

int n, K;
int dp[maxk + 5][maxk + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &K);
	dp[1][0] = 1;
	for (int i = K; i >= 1; --i)
	{
		for (int j = K - i + 1; j >= 1; --j)
			for (int k = min(j - 1, K - i - j + 1); k >= max(0, j - i - 1); --k)
				if (dp[j][k])
				{
					(dp[j + 1][k] += dp[j][k]) %= Mod;
					(dp[j][k + 1] += dp[j][k]) %= Mod;
					dp[j][k] = (LL)dp[j][k] * (n - 1 - (k > 0)) % Mod;
				}
	}
	int ans = 0;
	REP(i, 0, K) if (dp[i + 1][i])
	{
		(ans += (LL)dp[i + 1][i] * ((LL(n - i) * (n - i + 1) >> 1) % Mod) % Mod) %= Mod;
	}
	ans = (LL)ans * fpm(n, Mod - 1 - K, Mod) % Mod;
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}