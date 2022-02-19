#include <bits/stdc++.h>
#define CIOS ios::sync_with_stdio(false);
#define For(i, a, b) for(register int i = a; i <= b; i++)
#define Rof(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> ";
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

template <typename T>
inline void read(T &f) {
	f = 0; T fu = 1; char c = getchar();
	while(c < '0' || c > '9') {if(c == '-') fu = -1; c = getchar();}
	while(c >= '0' && c <= '9') {f = (f << 3) + (f << 1) + (c & 15); c = getchar();}
	f *= fu;
}

template <typename T>
void print(T x) {
	if(x < 0) putchar('-'), x = -x;
	if(x < 10) putchar(x + 48);
	else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
	print(x); putchar(t);
}

const int N = 85;

int f[N * N][N][N];
int n, m, p, ans;

inline int mul(int x, int y) { return (int)(1ll * x * y % (ll)p); }

int main() {
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	read(n); read(m); read(p);
	f[1][1][1] = n * m % p;
	for(register int i = 1; i < n * m; i++) {
		for(register int j = 1; j <= n; j++) {
			for(register int k = 1; k <= m; k++) {
				if(f[i][j][k] == 0) continue;
				int t = j * k - i;
				if(t > 0) f[i + 1][j][k] = (f[i + 1][j][k] + mul(f[i][j][k], t)) % p;
				if(k * n - t > 0) f[i + 1][j + 1][k] = (f[i + 1][j + 1][k] + mul(mul(f[i][j][k], k), n - j)) % p; 
				if(j * m - t > 0) f[i + 1][j][k + 1] = (f[i + 1][j][k + 1] + mul(mul(f[i][j][k], j), m - k)) % p;
			}
		}
	}
	cout << f[n * m][n][m] << endl;
	return 0;
}
