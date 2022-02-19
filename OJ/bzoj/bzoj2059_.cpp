#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n, k, e;
ll f[2][10001];
ll q[10001], v[10001], head, tail;

int main() {
	scanf("%lld%lld%lld", &n, &k, &e);
	ll b = 0, lastx = 0, old = 0, cur = 1;
	for (int i = 1; i <= k; i++) f[0][i] = f[1][i] = 0x7fffffff;
	while (n--) {
		ll x, c, w; 
		scanf("%lld%lld%lld", &x, &c, &w);
		b = min(k, b + c);
		head = 0, tail = -1;
		for (int j = 0; j <= b; j++) {
			ll val = f[old][j] - j * w + j * j * (x - lastx);
			while (head <= tail && v[tail] >= val) tail--; 
			tail++, v[tail] = val, q[tail] = j; // 入队 
			while (head <= tail && q[head] < j - c) head++; // 出队 
			f[cur][j] = v[head] + j * w;
		}
		cout<<f[cur][k]<<" ";
		swap(old, cur);
		lastx = x;
	}
	cout<<endl;
	printf("%lld\n", f[old][k] + k * k * (e - lastx));
	return 0;
}
