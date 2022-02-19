#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <ctime>

using namespace std;

int n = 1000, m = 1000;
int p[100010];

int main() {
	freopen("B.in","w",stdout);
	srand(time(0));
	printf("%d %d\n", n, m);
	for (int i = 1; i <= n; i++) p[i] = i;
	random_shuffle(p+1, p+n+1);
	for (int i = 1; i <= n; i++) printf("%d ", p[i]);
	puts("");
	for (int i = 1; i <= m; i++) {
		int opt = rand()%2+1;
		printf("%d ", opt);
		if (opt == 1) {
			int l = 1, m = rand()%(n-1)+1; int r = rand()%(n-m)+1+m;
			printf("%d %d %d\n", l, m, r);
		} else {
			printf("%d\n", rand()%n+1);
		}
	}
	fclose(stdout);
	return 0;
}
