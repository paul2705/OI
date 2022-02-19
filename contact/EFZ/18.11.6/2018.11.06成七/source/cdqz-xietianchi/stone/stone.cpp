#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e5 + 10;

ll a[N] , one , zero;//one: (i + 1) * (i - 1) ^ 2 // zero : (i - 1) * i 
int n , T;
int main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	scanf("%d",&T);
	
	while (T--){
		scanf("%d",&n);
		for (int i = 1;i <= n;i++) {
			scanf("%lld",&a[i]);
		}
		one = 1ll * (n + 1) * (n - 1) * (n - 1);
		zero  = 1ll * (n - 1) * n;
		for (int i = 1;i <= n;i++){
			if (a[i] < n) {
				puts("Win");
				goto wxh;
			}
			a[i] -= n ;
			a[i] %= (one + zero);
			if (a[i] >= zero){
				puts("Win");
				goto wxh;
			}
		}
		puts("Lose");
		
		wxh:;
	}
	return 0;
}
