#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

const int N = 100005;
const int K = 20000010;
int read(){
	int x = 0;char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) x = (x << 1) + (x << 3) + c - '0' , c = getchar();
	return x; 
}
int add(int x,int y) {
    x += y;
    if (x >= mod)
        x -= mod;
    return x;
}
int fac[K] , inv[K] , facinv[K];
int n , a[N] , b[N];

int qpow(int x,int y,int p = mod) {
    int res = 1;
    while (y) {
        if (y & 1) res = 1ll * res * x % p;
        x = 1ll * x * x % p;
        y >>= 1;
    }
    return res;
}
int C(int m,int n) {
    if (m < n) return 0;
    return 1ll * fac[m] * facinv[m - n] % mod * facinv[n] % mod;
}

int ans , sum[K << 1];
int main() {
    fac[0] = 1;for (int i = 1; i < K; i++) fac[i] = 1ll * fac[i-1] * i % mod;
    inv[1] = 1;for (int i = 2; i < K; i++) inv[i] = 1ll * (mod - (mod / i) ) * inv[mod % i] % mod;
    facinv[0] = facinv[1] = 1;for (int i = 2; i < K; i++) facinv[i] = 1ll * facinv[i-1] * inv[i] % mod;
	scanf("%d" , &n);
	for (int i = 1;i <= n;i++){
		scanf("%d%d",a+i,b+i);
		for (int t = -a[i];t <= b[i];t++){
			ans = add(ans , 1ll * C(a[i] + b[i] , t + a[i] ) * sum[t + K] % mod );
		}
		
		for (int t = -b[i];t <= a[i];t++){
			sum[t + K] = add( sum[t + K] , C(a[i] + b[i] , a[i] - t ) );
		}
	}
	ans = 2ll * ans % mod; 
	printf("%d\n",ans);
    return 0;

}
