#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;

const int maxl = 1000010;

ll ans = 0;
ll kh1, kh2, kw1, kw2, H, W;
int h1, w1, h2, w2;
char s1[maxl], s2[maxl];

ll gcd(ll x, ll y) {
	if (!y) return x;
	return gcd(y, x%y);
}

ll lcm(ll x, ll y) {
	return x*y/gcd(x,y);
}

ll nextx(ll x) {
	ll v1 = x/kh1*kh1;
	ll v2 = x/kh2*kh2;
	if (v1 <= x) v1 += kh1;
	if (v2 <= x) v2 += kh2;
	return min(min(v1, v2), H);
}

ll nexty(ll y) {
	ll v1 = y/kw1*kw1;
	ll v2 = y/kw2*kw2;
	if (v1 <= y) v1 += kw1;
	if (v2 <= y) v2 += kw2;
	return min(min(v1, v2), W);
}

int main() {
	freopen("picture.in", "r", stdin);
	freopen("picture.out", "w", stdout);
	scanf("%d%d", &h1, &w1);
	scanf("%s", s1);
	scanf("%d%d", &h2, &w2);
	scanf("%s", s2);
	H = lcm(h1, h2); W = lcm(w1, w2);
	kh1 = H/h1; kh2 = H/h2;
	kw1 = W/w1; kw2 = W/w2;
	for (ll x = 0; x < H; x = nextx(x)) {
		for (ll y = 0; y < W; y = nexty(y)) {
			if (s1[x/kh1*w1+y/kw1] == s2[x/kh2*w2+y/kw2]) {
				ans += (nextx(x)-x)*(nexty(y)-y);
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
