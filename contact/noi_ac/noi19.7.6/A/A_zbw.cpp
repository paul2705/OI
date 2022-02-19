#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;

const int maxn = 100010;
const int maxm = 50010;
const ll inf = 6e18;

struct line {
	ll k, b;
	line (ll k_ = 0, ll b_ = 0) : k (k_), b (b_) {}
	inline ll cal(ll x) {
		return k*x+b;
	}
} Q[maxm];

int n, m, p, s, t;
int pos[maxn], d[maxn], tim[maxm];
ll dp[maxm];

void addLine(int i) {
	if (dp[i] >= inf) return;
	line l(-i, dp[i]);
	while (s+1 < t && (Q[t-2].k-l.k)*(Q[t-1].b-Q[t-2].b) >= (l.b-Q[t-2].b)*(Q[t-2].k-Q[t-1].k)) -- t;
	Q[t++] = l;
}

int main() {
	freopen("A.in","r",stdin);
	freopen("A_.out","w",stdout);
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 1; i <= m; i++) dp[i] = inf;
	for (int i = 2; i <= n; i++) {
		scanf("%d", &d[i]);
		pos[i] = pos[i-1] + d[i];
	}
	for (int i = 1; i <= m; i++) {
		int h, t;
		scanf("%d%d", &h, &t);
		tim[i] = t - pos[h];
	}
	sort(tim+1, tim+m+1);
	dp[0] = 0;
	while (p --) {
		s = t = 0;
		addLine(0);
		for (int i = 1; i <= m; i++) {
			while (s+1 < t && Q[s].cal(tim[i]) >= Q[s+1].cal(tim[i])) ++ s;
			addLine(i);
			dp[i] = Q[s].cal(tim[i])+1ll*tim[i]*i;
		}
		//for (int i = 1; i <= m; i++) cout << dp[i] << " ";
		//cout << endl;
	}
	ll ans = dp[m];
	for (int i = 1; i <= m; i++) ans -= tim[i];
	printf("%lld\n", ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
