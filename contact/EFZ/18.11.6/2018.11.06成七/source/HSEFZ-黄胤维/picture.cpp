#include <bits/stdc++.h>
using namespace std;
int h1, w1, h2, w2;
int g1, g2;
int p1, p2;
int gcd(int a, int b){
	if (a == 0) return b;
	if (b == 0) return a;
	if (a > b) return gcd(b, a%b);
	return gcd(a, b%a);
}
int lcm(int a, int b){
	int g = gcd(a, b);
	return a * b / g;
}
int main(){
	freopen("picture.in", "r", stdin);
	freopen("picture.out", "w", stdout);
	cin >> h1 >> w1;
	cin >> g1;
	cin >> h2 >> w2;
	cin >> g2;
	int hl = lcm(h1, h2);
	int wl = lcm(w1, w2);
	int hd = gcd(h1, h2);
	int wd = gcd(w1, w2);
	int h1m = hl / h1;
	int w1m = wl / w1;
	int h2m = hl / h2;
	int w2m = wl / w2;
	p1 = 0; p2 = 0;
	for (int i = 0; i < h1 * w1; i++){
		p1 += (g1 % 10) * (1 << i);
		g1 = g1 / 10;
	}
	for (int i = 0; i < h2 * w2; i++){
		p2 += (g2 % 10) * (1 << i);
		g2 = g2 / 10;
	}
	int ans = 0;
	for (int i = 0; i < hl; i++) {
		for (int j = 0; j < wl; j++){
			int g = p1;
			int hw1 = (g >> (w1 * (h1 - i / h1m - 1) + (w1 - j / w1m - 1))) & 1; 
			g = p2;
			int hw2 = (g >> (w2 * (h2 - i / h2m - 1) + (w2 - j / w2m - 1))) & 1;
			if (hw1 == hw2) ans++;
		}
	}
	cout << ans;
	return 0;
}
/*
int getg1(int h, int w){
	cout << "GETG1" << endl;
	int g = p1;
	cout << p1 << endl;
	return (g >> (w1 * (h1 - h - 1) + (w1 - w - 1))) | 1;
}
int getg2(int h, int w){
	int g = p2;
	return (g >> (w2 * (h2 - h - 1) + (w2 - w - 1))) | 1;
}*/
