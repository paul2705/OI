#include <iostream>
#include <cstdio>
#include <string>

#define __debug__ if (0)
#define __files__ if (1)

#define _filename_is "picture.in"
#define _filename_os "picture.out"

using namespace std;

inline void fio_set() {
	freopen(_filename_is, "r", stdin);
	freopen(_filename_os, "w", stdout);
}

inline void fio_rst() {
	fclose(stdin);
	fclose(stdout);
}

typedef unsigned long long int num_t;

char pic1[0x1000][0x1000], pic2[0x1000][0x1000];

num_t gcd(num_t a, num_t b) {
	return a < b ? gcd(b, a) : b ? gcd(b, a % b) : a;
}

int main() {
	__files__ fio_set();
	
	num_t h1, h2, w1, w2;
	string buf1, buf2;
	cin >> h1 >> w1;
	cin >> buf1;
	cin >> h2 >> w2;
	cin >> buf2;
	
	num_t H = h1 / gcd(h1, h2) * h2;
	num_t W = w1 / gcd(w1, w2) * w2;
	num_t kh1 = H / h1, kh2 = H / h2;
	num_t kw1 = W / w1, kw2 = W / w2;
	for (num_t i = 0, s = h1 * w1; i < s; ++i) {
		num_t _i = i / w1;
		num_t _j = i % w1;
		for (num_t di = 0; di < kh1; ++di) {
			for (num_t dj = 0; dj < kw1; ++dj) {
				pic1[_i * kh1 + di][_j * kw1 + dj] = buf1[i];
			}
		}
	}
	for (num_t i = 0, s = h2 * w2; i < s; ++i) {
		num_t _i = i / w2;
		num_t _j = i % w2;
		for (num_t di = 0; di < kh2; ++di) {
			for (num_t dj = 0; dj < kw2; ++dj) {
				pic2[_i * kh2 + di][_j * kw2 + dj] = buf2[i];
			}
		}
	}
	__debug__ {
		cerr << "PICTURE 1: " << buf1 << endl;
		for (num_t i = 0; i < H; ++i) {
			for (num_t j = 0; j < W; ++j) {
				cerr << pic1[i][j];
			}
			cerr << endl;
		}
		cerr << "PICTURE 2: " << buf2 << endl;
		for (num_t i = 0; i < H; ++i) {
			for (num_t j = 0; j < W; ++j) {
				cerr << pic2[i][j];
			}
			cerr << endl;
		}
		cerr << endl;
	}
	num_t ans = 0;
	for (num_t i = 0; i < H; ++i) {
		for (num_t j = 0; j < W; ++j) {
			ans += pic1[i][j] == pic2[i][j];
		}
	}
	
	cout << ans;
	
	__files__ fio_set();

	return 0;
}

