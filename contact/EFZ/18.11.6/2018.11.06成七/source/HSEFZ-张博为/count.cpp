#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 4;

int ans = 0;
int n, m, p;
int a[maxn*maxn];
int q[maxn][maxn];

int getmax_x(int x) {
	int mx = 0;
	for (int y = 1; y <= m; y++) {
		mx = max(mx, q[x][y]);
	}
	return mx;
}

int getmax_y(int y) {
	int mx = 0;
	for (int x = 1; x <= n; x++) {
		mx = max(mx, q[x][y]);
	}
	return mx;
}


int main() {
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &p);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			a[i*m-m+j] = i*m-m+j;
		}
	}
	do {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				q[i][j] = a[i*m-m+j];
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cnt += (getmax_x(i)==q[i][j] && getmax_y(j)==q[i][j]);
			}
		}
		if (cnt == 1) ++ ans;
	} while(next_permutation(a+1, a+n*m+1));
	printf("%d\n", ans%p);
	return 0;
}
