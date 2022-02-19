#include <bits/stdc++.h>
using namespace std;
template <class T> inline void read(T &x) {
	x = 0; int c = getchar(), f = 1;
	for (; !isdigit(c); c = getchar()) if (c == 45) f = -1;
	for (; isdigit(c); c = getchar()) (x *= 10) += f*(c-'0');
}
int n, m, P, ans;
int a[3][3]; bool mrk[9];
bool ismx(int x, int y) {
	for (int i = 0; i < n; i++)
		if (a[i][y] > a[x][y]) return false;
	for (int i = 0; i < m; i++)
		if (a[x][i] > a[x][y]) return false;
	return true;
}
void chk() {
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cnt += ismx(i, j);
	ans += cnt == 1;
}
void DFS(int stp) {
	if (stp >= n*m) {chk(); return;}
	for (int i = 0; i < n*m; i++) if (!mrk[i])
		mrk[i] = true, a[stp/m][stp%m] = i, 
		DFS(stp+1), mrk[i] = false;
}
int main() {
	read(n), read(m), read(P), DFS(0);
	return printf("%d\n", ans), 0;
}
