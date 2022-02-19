#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;

int n, m;
int p[maxn];
int tmp[maxn];

int main() {
	freopen("B.in","r",stdin);
	freopen("B.ans","w",stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	for (int i = 1; i <= m; i++) {
		int opt; scanf("%d", &opt);
		if (opt == 1) {
			int l, m, r; scanf("%d%d%d", &l, &m, &r);
			int s1 = l, s2 = m+1, s = l;
			while (s1 <= m && s2 <= r) {
				if (p[s1] < p[s2]) {
					tmp[s++] = p[s1++];
				} else tmp[s++] = p[s2++];
			}
			while (s1 <= m) tmp[s++] = p[s1++];
			while (s2 <= r) tmp[s++] = p[s2++];
			for (int i = l; i <= r; i++) p[i] = tmp[i];
		} else {
			int x; scanf("%d", &x);
			printf("%d\n", p[x]);
		}
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
