#include <bits/stdc++.h>
#define mod 1000000007
#define g 3
#define ginv 332748118
using namespace std;
const int N = 1e5 + 10;

int add(int x,int y) {
    x += y;
    if (x >= mod)
        x -= mod;
    return x;
}

int n , a[N] , f[N];
int main() {
	freopen("safpar.in","r",stdin);
	
	freopen("safpar.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	f[0] = 1;
	
	for (int i = 1;i <= n;i++){
		int maxn = a[i] , minm = a[i];
		for (int j = i;j >= 1;j--){
			maxn = max(maxn , a[j]);
			minm = min(minm , a[j]);	
			if (i - j + 1 >= minm && i - j + 1 <= maxn) f[i] = add(f[i] , f[j-1]);
		}
	}
	printf("%d\n",f[n]);
    return 0;
}
