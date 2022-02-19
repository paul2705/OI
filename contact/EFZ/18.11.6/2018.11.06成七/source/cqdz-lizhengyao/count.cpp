#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read() {
	int a = 0, c = getchar(), w = 1;
	for(; c < '0' || c > '9'; c = getchar()) if(c == '-') w = -1;
	for(; c >= '0' && c <= '9'; c = getchar()) a = a * 10 + c - '0';
	return a * w;
}

int n, m, p;
int a[100], mx[10];

int main() {
	freopen("count.in", "r", stdin);
	freopen("count.out","w", stdout);
	n =  read();  m = read();
	p = read();
	for(int i = 0; i < n*m; i++) a[i] = i;
	int ans = 0;
	do{
		memset(mx, 0, sizeof(mx));
		for(int i = 0; i < n; i++) {
			int p = -1;
			for(int j = 0; j < m; j++) if(!~p || a[i*m+j] > a[p]) p = i*m+j;
			mx[p]++;
		}
		for(int i = 0; i < m; i++) {
			int p = -1;
			for(int j = 0; j < n; j++) if(!~p || a[j*m+i] > a[p]) p = j*m+i;
			mx[p]++;
		}
		int cnt = 0;
		for(int i = 0; i < n*m; i++) if(mx[i] >= 2) cnt++;
		if(cnt == 1) ans++;
	}while(next_permutation(a, a+n*m));
	printf("%d\n", ans);
	return 0;
}
