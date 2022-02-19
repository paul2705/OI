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

const int N = 1005;

int a[N][N], b[N][N], A[N][N], B[N][N];
int n, m, nn, mm, ans = 0;

int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }

int main() {
	freopen("picture.in", "r", stdin);
	freopen("picture.out", "w", stdout);
	read(n); read(m);
	for(register int i = 1; i <= n; i++) {
		for(register int j = 1; j <= m; j++) {
			char c = getchar();
			while(c != '0' && c != '1') c = getchar();
			a[i][j] = c - '0';
		}
	}
	read(nn); read(mm);
	for(register int i = 1; i <= nn; i++) {
		for(register int j = 1; j <= mm; j++) {
			char c = getchar();
			while(c != '0' && c != '1') c = getchar();
			b[i][j] = c - '0';
		}
	}
	int d1 = gcd(n, nn), d2 = gcd(m, mm);
	for(register int i = 1; i <= n; i++) {
		for(register int j = 1; j <= m; j++) {
			int len1 = nn / d1, len2 = mm / d2;
			for(register int x = (i - 1) * len1 + 1; x <= len1 * i; x++) {
				for(register int y = (j - 1) * len2 + 1; y <= len2 * j; y++) {
					A[x][y] = a[i][j];
				}
			}
		}
	}
	for(register int i = 1; i <= nn; i++) {
		for(register int j = 1; j <= mm; j++) {
			int len1 = n / d1, len2 = m / d2;
			for(register int x = (i - 1) * len1 + 1; x <= len1 * i; x++) {
				for(register int y = (j - 1) * len2 + 1; y <= len2 * j; y++) {
					B[x][y] = b[i][j];
				}
			}
		}
	}
	for(register int i = 1; i <= n * nn / d1; i++) {
		for(register int j = 1; j <= m * mm / d2; j++) {
			if(A[i][j] == B[i][j]) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
