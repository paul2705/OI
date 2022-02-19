#include <bits/stdc++.h>
using namespace std;
int ans = 1;
int n , m;

int qpow(int x,int y,int p){
	int res = 1;
    while (y){
    	if (y & 1) res = 1ll * res * x % p;
    	x = 1ll * x * x % p; y >>= 1;
	}
	return res;
}

const int prim[]={2,3,5,7,11,13,17,19};
bool miller_rabin(int x){
	for (int i = 0;i < 8;i++){
		if (x == prim[i]) return 1;
		if (x % prim[i] == 0) return 0;
	}
	
	int p = x - 1 , t = 0;
	while (! (p & 1) ) {p >>= 1;t ++;}
	
	for (int i = 1;i <= 8;i++){
		int a = rand() % (x - 1) + 1 , last;
		a = qpow(a , p , x );	
		for (int d = 1;d <= t;d++){
			last = a;
			a = 1ll * a * a % x;
			if (a == 1 && last != 1 && last != x - 1 ) return false;
		}
		if (a != 1) return false;
	}
	return true;
}

int p[50] , pcnt;
void pollard(int x){
	if (x == 1) return;
	if (miller_rabin(x)){
		p[++pcnt] = x;
		return;
	}
	
	while (1){
		int a = rand() % x , b = a , c = rand() % x , gcd;
		
		b = ( 1ll * b * b % x + c ) % x;
		
		while (a != b){
			gcd = __gcd( abs( a - b ) , x);
			if (gcd != 1 && gcd != x){
				pollard(x / gcd);
				pollard(gcd);
				return;
			}
			
			
			a = ( 1ll * a * a % x + c ) % x;
			b = ( 1ll * b * b % x + c ) % x;
			b = ( 1ll * b * b % x + c ) % x;
		}
	}
}

pair<int,int> pr[20];
void dfs(int cur,int mul){
	
}

int main() {
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
  scanf("%d%d",&m,&n);
  for (int i = 1; i * i <= n; i++)
    if (n % i == 0) {
      if (i <= m) ans = max(ans , i);
      if ( (n / i) <= m ) ans = max(ans , n / i);
    }
	
//  pollard(n);
  cout<<ans;
  return 0;
}
