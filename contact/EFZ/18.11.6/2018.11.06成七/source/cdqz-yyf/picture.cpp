#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#ifndef WIN32
#define Auto "%lld"
#else
#define Auto "%I64d"
#endif
using namespace std;
typedef bool boolean;

#define ll long long

template <typename T>
class Matrix {
	public:
		int r, c;
		T* p;

		Matrix() {	}
		Matrix(int r, int c):r(r), c(c) {
			p = new T[(r * c)];
		}

		T* operator [] (int x) {
			return p + x * c;
		}
};

int gcd(int a, int b) {
	return (b) ? (gcd(b, a % b)) : (a);
}

const int N = 1e6 + 5;

FILE* fin = fopen("picture.in", "r");
FILE* fout = fopen("picture.out", "w");

char buf[N];
Matrix<int> s;		// enum the first picture
Matrix<char> a, b;
int w1, h1, w2, h2;
int bw, bh;

inline void init() {
	fscanf(fin, "%d%d", &w1, &h1);
	a = Matrix<char>(w1 + 2, h1 + 1);
	fscanf(fin, "%s", buf);
	char* p = buf;
	for (int i = 1; i <= w1; i++)
		for (int j = 1; j <= h1; j++)
			a[i][j] = *(p++);
	fscanf(fin, "%d%d", &w2, &h2);
	b = Matrix<char>(w2 + 2, h2 + 1);
	fscanf(fin, "%s", buf);
	p = buf;
	for (int i = 1; i <= w2; i++)
		for (int j = 1; j <= h2; j++)	
			b[i][j] = *(p++);
	s = Matrix<int>(w2 + 1, h2 + 1);
	memset(s.p, 0, sizeof(int) * (w2 + 1) * (h2 + 1));
	for (int i = 1; i <= w2; i++)
		for (int j = 1; j <= h2; j++)
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (b[i][j] == '0');
}

int sum(int x1, int y1, int x2, int y2, int col) {
	if (x2 < x1 || y2 < y1)
		return 0;
	int tmp = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
	if (col == 1)
		return (x2 - x1 + 1) * (y2 - y1 + 1) - tmp;
	return tmp;
}

ll calc(ll x, ll y, int col) {
	if (!x || !y)
		return 0;
	ll bx = (x - 1) / bw, by = (y - 1) / bh;
	ll sum1 = sum(1, 1, bx, by, col) * 1ll * bw * bh;
	ll dx = bx * bw, dy = by * bh;
	ll sum2 = sum(bx + 1, 1, bx + 1, by, col) * (x - dx) * bh;
	ll sum3 = sum(1, by + 1, bx, by + 1, col) * (y - dy) * bw;
	ll sum4 = (b[bx + 1][by + 1] - '0' == col) * (x - dx) * (y - dy);
	ll rt = sum1 + sum2 + sum3 + sum4; 
//	cerr << sum1 << " " << sum2 << " " << sum3 << " " << sum4 << '\n';
//	cerr << x << " " << y << " " << col << " " << rt << '\n';
	return rt;
}

ll calc(ll x1, ll y1, ll x2, ll y2, int col) {
	return calc(x2, y2, col) - calc(x1 - 1, y2, col) - calc(x2, y1 - 1, col) + calc(x1 - 1, y1 - 1, col); 
} 

inline void solve() {
	bw = w1 / gcd(w1, w2);
	bh = h1 / gcd(h1, h2);

	ll bx = w2 / gcd(w1, w2), by = h2 / gcd(h1, h2), res = 0;
	for (int i = 1; i <= w1; i++)
		for (int j = 1; j <= h1; j++)
			res += calc((i - 1) * bx + 1, (j - 1) * by + 1, bx * i, by * j, a[i][j] - '0');
	fprintf(fout, Auto"\n", res);
}

int main() {
	init();
	solve();
	return 0;
}
