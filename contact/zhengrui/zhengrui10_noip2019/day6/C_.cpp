#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<assert.h>
#include<set>
#include<cmath>
#include<queue>
#include<cstdlib>
#include<iostream>
#include<bitset>
using namespace std;
 
const int P = 998244353;
const int N = 5500;
 
int a[N], b[N];
int a_last[N], b_last[N];
int C[N], F[N][N], G[N][N], H[N][N], I[N][N];
 
int main() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) {
		int &u = a_last[a[i]];
		C[i] = (C[i - 1] * 2LL + 1 + P - (u ? C[u - 1] + 1: 0)) % P;
		for (int j = 1; j <= m; j++) {
			int &v = b_last[b[j]];
			if (a[i] != b[j]) {
				I[i][j] = I[i][j - 1];
				int w = a_last[b[j]];
				if (w) {
					if (v) {
						I[i][j] = (I[i][j] + P - 1 - I[w - 1][v - 1]) % P;
					}
					I[i][j] = (I[i][j] + I[w - 1][j - 1] + 1) % P;
				}
			} else {
				I[i][j] = (I[i - 1][j - 1] * 2 + 1) % P;
				if (u && v) I[i][j] = (I[i][j] + P - 1 - I[u - 1][v - 1]) % P;
			}
			if (a[i] > b[j]) {
				H[i][j] = (I[i - 1][j - 1] + F[i - 1][j - 1]) % P;
				H[i][j] = (H[i][j] + C[i - 1] + 1) % P;
			} else {
				H[i][j] = (F[i - 1][j - 1] + C[i - 1]) % P;
			}
			G[i][j] = (G[i - 1][j] + P - H[u][j]) % P;
			G[i][j] = (G[i][j] + H[i][j]) % P;
			F[i][j] = (F[i][j - 1] + P - G[i][v]) % P;
			F[i][j] = (F[i][j] + G[i][j]) % P;
			v = j;
		}
		for (int j = 1; j <= m; j++) {
			b_last[b[j]] = 0;
		}
		u = i;
	}
	cout << F[n][m] << endl;
	return 0;
}
