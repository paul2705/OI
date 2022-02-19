#include<bits/stdc++.h>

#define UPLOAD

typedef long long ll;
int gcd(int a, int b)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int a[10005][10005];

int main()
{
	#ifdef UPLOAD
		freopen("picture.in", "r", stdin);
		freopen("picture.out", "w", stdout);
	#endif

	int h1, w1, h2, w2;
	scanf("%d%d", &h1, &w1);
	char c = getchar();
	memset(a, 0, sizeof(a));
	/*for(int i = 0; i <= h1; i++)
		for(int j = 0; j <= w1; j++)
			a[i].push_back(0);*/
	for(int i = 1; i <= h1; i++)
		for(int j = 1; j <= w1; j++)
		{
			while (c != '0' && c != '1') c = getchar();
			a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
			if (c == '1') a[i][j]++;
			c = getchar();
		}

	scanf("%d%d", &h2, &w2);

	//printf("%d %d\n", h2, w2);
	ll ans = 0;
	ll h = (long long)h1 * h2 / gcd(h1, h2);
	ll w = (long long)w1 * w2 / gcd(w1, w2);
	ll rh1 = h / h1, rh2 = h / h2, rw1 = w / w1, rw2 = w / w2;
	
	printf("%lld %lld %lld %lld %lld %lld\n", h, w, rh1, rh2, rw1, rw2);
	c = getchar();
	for(int i = 1; i <= h2; i++)
		for(int j = 1; j <= w2; j++)
		{
			while (c != '0' && c != '1') c = getchar();
			ll s = c == '0' ? 1ll : 0ll, t = c == '0' ? -1ll : 1ll;
			ll stx = (i - 1) * rh2 + 1, edx = i * rh2, sty = (j - 1) * rw2 + 1, edy = j * rw2;
			ll p1 = (stx - 2) / rh1 + 1, p2 = (sty - 2) / rw1 + 1;
			if (stx == 1) p1 = 0;
			if (sty == 1) p2 = 0;
			int q1 = (stx + rh1 - 1) % rh1 + 1, q2 = (sty + rw1 - 1) % rw1 + 1;
			ll p3 = (edx - 1) / rh1 + 1, p4 = (edy - 1) / rw1 + 1;
			int q3 = edx % rh1 + 1, q4 = edy % rw1 + 1;
			//printf("%d %d %d %d %d %lld %lld %lld\n", p1, q1, p2, q2, p3, q3, p4, q4);
			ans += (p3 - p1) * (p4 - p2) * (s * h1 * w1 + t * a[h1][w1]);
			//printf("%d\n", t * a[i - 1][j - 1]);
			ans += (p4 - p2 + 1) * (s * h1 * w1 + t * a[h1][w1] - s * q3 * w1 - t * a[q3][w1]);
			ans += (p3 - p1 + 1) * (s * h1 * w1 + t * a[h1][w1] - s * q4 * h1 - t * a[h1][q4]);
			ans += (s * q3 * q4 + t * a[q3][q4] - s * h1 * w1 - t * a[h1][w1]);
			ans -= (p4 - p2) * (s * q1 * w1 + t * a[q1][w1]);
			ans -= (p3 - p1) * (w * q2 * h1 + t * a[h1][q2]);
			ans -= (s * q1 * q2 + t * a[q1][q2]);
			c = getchar();
		}
	printf("%lld\n", ans);
	return 0;
}