#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef bool boolean;

FILE* fin = fopen("count.in", "r");
FILE* fout = fopen("count.out", "w");

int n, m, P, V;
boolean vis[10];
int a[4][4];

inline void init() {
	fscanf(fin, "%d%d%d", &n, &m, &P);
	V = n * m;
}

int res = 0;
void dfs(int x, int y) {
	if (x == n) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int mv = -1, p = -1;
			for (int j = 0; j < m; j++)
				if (a[i][j] > mv)
					mv = a[i][j], p = j;
			cnt++;
			for (int j = 0; j < n; j++)
				if (a[j][p] > mv) {
					cnt--;
					break;
				}
		}

/*		if (cnt == 1 && 300 <= res && res <= 310) {
			for (int i = 0; i < n; i++, cerr << '\n')
				for (int j = 0; j < m; j++)
					cerr << a[i][j] + 1 << ' ';
			cerr << '\n';
		}*/
		res += (cnt == 1);
	}
	if (y == m)
		dfs(x + 1, 0);
	else {
		for (int i = 0; i < V; i++)
			if (!vis[i]) {
				vis[i] = true, a[x][y] = i;
				dfs(x, y + 1);
				vis[i] = false;
			}
	}
}

inline void solve() {
	dfs(0, 0);
	fprintf(fout, "%d\n", res);
}

int main() {
	init();
	solve();
	return 0;
}
