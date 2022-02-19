#include <bits/stdc++.h>


using namespace std;
const int N = 1100;

int n , m , p;
int add(int x,int y){
	x += y;
	if (x >= p)
		x -= p;
	return x;
}
	
int f[2][N][N];	


int main(){
	freopen("count.in","r",stdin);
	
	freopen("count.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);
	f[1][1][1] = n * m;
	
	for (int now = 1;now <= n * m;now++){
//		memset(f[(now&1)^1] , 0 , sizeof f[(now&1)^1]);
		for (int x = 1;x <= n;x++)
		memset(f[(now&1)^1][x] , 0 , sizeof (int) * (m + 10));
		
		for (int x = 1;x <= n;x++)
		for (int y = 1;y <= m;y++){
			if (!f[now&1][x][y]) continue;
			f[(now^1)&1][x][y] 	 = add(f[(now^1)&1][x][y] , 1ll * (x * y - now) * f[now&1][x][y] % p);
			f[(now^1)&1][x+1][y] = add(f[(now^1)&1][x+1][y] , 1ll * y * (n - x) % p * f[now&1][x][y] % p);
			f[(now^1)&1][x][y+1] = add(f[(now^1)&1][x][y+1] , 1ll * x * (m - y) % p * f[now&1][x][y] % p);
		
		}
	}
	
	cout<<f[(n*m)&1][n][m];
	return 0;
}
