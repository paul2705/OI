#define FIO "picture"
#include <bits/stdc++.h>
#define MAX_N 1000000
using namespace std;
template <class T> inline void read(T &x) {
	x = 0; int c = getchar(), f = 1;
	for (; !isdigit(c); c = getchar()) if (c == 45) f = -1;
	for (; isdigit(c); c = getchar()) (x *= 10) += f*(c-'0');
}
int na, ma, nb, mb; char ch[MAX_N+5];
vector <bool> a[MAX_N+5], b[MAX_N+5];
int ra, ca, rb, cb; vector <int> s[2][MAX_N+5];
int gcd(int x, int y) {return y ? gcd(y, x%y) : x;}
int sum(int x1, int y1, int x2, int y2, int c) {
	if (x1 > x2 || y1 > y2) return 0;
	int ret = s[c][x2][y2]+s[c][x1-1][y1-1];
	ret -= s[c][x1-1][y2]+s[c][x2][y1-1];
	return ret;
}
int calc(int x, int y, int c) {
	if (!x || !y) return 0;
	int xp = (x-1)/rb, xx = xp*rb;
	int yp = (y-1)/cb, yy = yp*cb;
	int ret = s[c][xp][yp]*rb*cb;
	ret += sum(1, yp+1, xp, yp+1, c)*rb*(y-yy);
	ret += sum(xp+1, 1, xp+1, yp, c)*(x-xx)*cb;
	if (b[xp+1][yp+1] == c) ret += (x-xx)*(y-yy);
	return ret;
}
int main() {
#ifndef LocalHost
	freopen(FIO".in", "r", stdin);
	freopen(FIO".out", "w", stdout);
#endif
	read(na), read(ma), scanf("%s", ch+1);
	for (int i = 0; i <= na; i++) a[i].resize(ma+5);
	for (int i = 1; i <= na; i++)
		for (int j = 1; j <= ma; j++)
			a[i][j] = ch[(i-1)*ma+j]-'0';
	read(nb), read(mb), scanf("%s", ch+1);
	for (int i = 0; i <= nb; i++) b[i].resize(mb+5);
	for (int i = 1; i <= nb; i++)
		for (int j = 1; j <= mb; j++)
			b[i][j] = ch[(i-1)*mb+j]-'0';
	for (int i = 0; i <= nb; i++) s[0][i].resize(mb+5);
	for (int i = 0; i <= nb; i++) s[1][i].resize(mb+5);
	for (int i = 1; i <= nb; i++) for (int j = 1; j <= mb; j++)
		s[0][i][j] = !b[i][j]+s[0][i-1][j]+s[0][i][j-1]-s[0][i-1][j-1], 
		s[1][i][j] = b[i][j]+s[1][i-1][j]+s[1][i][j-1]-s[1][i-1][j-1];
	ra = nb/gcd(na, nb), ca = mb/gcd(ma, mb);
	rb = na/gcd(na, nb), cb = ma/gcd(ma, mb);
	int ans = 0;
	for (int i = 1; i <= na; i++)
		for (int j = 1; j <= ma; j++)
			ans += calc(i*ra, j*ca, a[i][j]), 
			ans -= calc(i*ra, (j-1)*ca, a[i][j]), 
			ans -= calc((i-1)*ra, j*ca, a[i][j]), 
			ans += calc((i-1)*ra, (j-1)*ca, a[i][j]);
	return printf("%d\n", ans), 0;
}
