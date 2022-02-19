#include <algorithm>
#include <cstdio>
typedef long long ll;
inline int gcd(int x, int y)
{
	while (y)
	{
		int r = x % y;
		x = y;
		y = r;
	}
	return x;
}
char a[1000005], b[1000005];
int *sum[1000005], n1, n2, m1, m2;
inline int calc(int l, int r, int u, int d)
{
	if (l > r || u > d || l < 0 || u < 0 || r >= n1 || d >= m1)
		return 0;
	return sum[r][d] - (l ? sum[l - 1][d] : 0) - (u ? sum[r][u - 1] : 0) + (l && u ? sum[l - 1][u - 1] : 0);
}
int main()
{
	freopen("picture.in", "r", stdin);
	freopen("picture.out", "wt", stdout);
	scanf("%d%d%s%d%d%s", &n1, &m1, a, &n2, &m2, b);
	ll n = (ll)n1 * n2 / gcd(n1, n2), m = (ll)m1 * m2 / gcd(m1, m2);
	ll sn1 = n / n1, sn2 = n / n2, sm1 = m / m1, sm2 = m / m2, ans = 0;
	for (int i = 0; i < n1; i++)
	{
		sum[i] = new int [m1 + 5] {0};
		for (int j = 0; j < m1; j++)
		{
			sum[i][j] = a[i * m1 + j] - '0';
			if (i)
				sum[i][j] += sum[i - 1][j];
			if (j)
				sum[i][j] += sum[i][j - 1];
			if (i && j)
				sum[i][j] -= sum[i - 1][j - 1];
		}
	}
	for (int i = 0; i < n2; i++)
	{
		for (int j = 0; j < m2; j++)
		{
			ll xl = (ll)i * sn2, xr = (ll)(i + 1) * sn2 - 1;
			ll yl = (ll)j * sm2, yr = (ll)(j + 1) * sm2 - 1;
			ll l = xl / sn1 + 1, r = xr / sn1 - 1, u = yl / sm1 + 1, d = yr / sm1 - 1;
			ll res = 0;
			if (xl / sn1 == xr / sn1 && yl / sm1 == yr / sm1)
				res += calc(l - 1, l - 1, u - 1, u - 1) * sn2 * sm2;
			else if (xl / sn1 == xr / sn1)
			{
				res += calc(l - 1, l - 1, u - 1, u - 1) * sn2 * (u * sm1 - yl);
				res += calc(l - 1, l - 1, u, d) * sn2 * sm1;
				res += calc(l - 1, l - 1, d + 1, d + 1) * sn2 * (yr - (d + 1) * sm1 + 1);
			}
			else if (yl / sm1 == yr / sm1)
			{
				res += calc(l - 1, l - 1, u - 1, u - 1) * (l * sn1 - xl) * sm2;
				res += calc(l, r, u - 1, u - 1) * sn1 * sm2;
				res += calc(r + 1, r + 1, u - 1, u - 1) * (xr - (r + 1) * sn1 + 1) * sm2;
			}
			else
			{
				res += calc(l, r, u, d) * sn1 * sm1;
				res += calc(l - 1, l - 1, u, d) * (l * sn1 - xl) * sm1;
				res += calc(r + 1, r + 1, u, d) * (xr - (r + 1) * sn1 + 1) * sm1;
				res += calc(l, r, u - 1, u - 1) * sn1 * (u * sm1 - yl);
				res += calc(l, r, d + 1, d + 1) * sn1 * (yr - (d + 1) * sm1 + 1);
				res += calc(l - 1, l - 1, u - 1, u - 1) * (l * sn1 - xl) * (u * sm1 - yl);
				res += calc(l - 1, l - 1, d + 1, d + 1) * (l * sn1 - xl) * (yr - (d + 1) * sm1 + 1);
				res += calc(r + 1, r + 1, u - 1, u - 1) * (xr - (r + 1) * sn1 + 1) * (u * sm1 - yl);
				res += calc(r + 1, r + 1, d + 1, d + 1) * (xr - (r + 1) * sn1 + 1) * (yr - (d + 1) * sm1 + 1);
			}
			if (b[i * m2 + j] == '0')
				res = sn2 * sm2 - res;
			ans += res;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
