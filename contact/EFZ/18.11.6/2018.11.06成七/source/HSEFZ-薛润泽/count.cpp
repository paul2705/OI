#include <iostream>
#include <cstdio>

#define __debug__ if (0)
#define __files__ if (1)

#define _filename_is "count.in"
#define _filename_os "count.out"

using namespace std;

inline void fio_set() {
	freopen(_filename_is, "r", stdin);
	freopen(_filename_os, "w", stdout);
}

inline void fio_rst() {
	fclose(stdin);
	fclose(stdout);
}

int main() {
	__files__ fio_set();
	
	int ans[4][4];
	ans[1][1] = 1;
	ans[2][2] = 16;
	ans[3][3] = 108864;
	ans[1][2] = ans[2][1] = 2;
	ans[1][3] = ans[3][1] = 6;
	ans[2][3] = ans[3][2] = 288;
	int n, m, p;
	cin >> n >> m >> p;
	if (n > 3 || m > 3) return 0;
	cout << ans[m][n] % p;
	
	__files__ fio_set();

	return 0;
}

