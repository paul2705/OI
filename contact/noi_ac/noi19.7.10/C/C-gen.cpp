#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <ctime>

using namespace std;

const int maxn = 200010;

int fa[maxn], n, m, q;
const int maxw = 200000;

int main() {
	srand(time(0));
	n = maxw;
	m = maxw;
	q = maxw;
	printf("%d %d %d\n", n, m, q);
	for (int i = 2; i <= n; i++) fa[i] = rand()%(i-1) + 1;
	for (int i = 2; i <= n; i++) printf("%d %d\n", fa[i], i);
	for (int i = 1; i <= q; i++) {
		int l = rand()%m+1, r = l + rand()%(m-l+1);
		printf("%d %d %d\n", l, r, rand()%n+1);
	}
	return 0;
}