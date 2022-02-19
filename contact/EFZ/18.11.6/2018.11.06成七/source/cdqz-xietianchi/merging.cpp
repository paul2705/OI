#include <bits/stdc++.h>
const int N = 8e2 + 10;
using namespace std;


int n , m;
int mat[N][N] , pre[N][N];

int ans , res;

int check(int xl,int xr,int y){
	for (int i = xl;i <= xr;i++) if (!mat[xl][y]) return 0;
	return 1;
}

int check2(int yl,int yr,int x){
	for (int i = yl;i <= yr;i++) if (!mat[x][i]) return 0;
	return 1;
}

int main(){
		freopen("merging.in","r",stdin);
	freopen("merging.out","w",stdout);

	scanf("%d%d",&n,&m);
	ans = n * m;
	for (int i = 1;i <= n;i++)
	for (int j = 1;j <= m;j++)
	scanf("%d",&pre[i][j]);
	
	for (int i = 1;i <= n;i++)
	for (int j = 1;j <= m;j++)
	mat[i][j] = pre[i][j];
	res = 0;
	while (1){
		int x = -1 , y = -1;
		for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++){
			if (mat[i][j]){
				x = i;
				y = j;
				goto wxh;
			}
		}
		
		wxh:;
		if (x == -1) break;
		
		int ny = y , nx = x;
		while (nx + 1 <= n && mat[nx + 1][y] == 1) nx++;
		while (ny + 1 <= m && check( x , nx , ny + 1 ) ) ny++;
		
		for (int i = x;i <= nx;i++)
		for (int j = y;j <= ny;j++)
		mat[i][j] = 0;
//		printf("%d %d %d %d\n",x,nx,y,ny);
		res++;
	}
	
	
	ans = res;
	
	for (int i = 1;i <= n;i++)
	for (int j = 1;j <= m;j++)
	mat[i][j] = pre[i][j];
	res = 0;
	while (1){
		int x = -1 , y = -1;
		for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++){
			if (mat[i][j]){
				x = i;
				y = j;
				goto Wxh;
			}
		}
		
		Wxh:;
		if (x == -1) break;
		
		int ny = y , nx = x;
		while (ny + 1 <= m && mat[x][ny + 1] ) ny++;
	
		while (nx + 1 <= n && check(y , ny , nx + 1) ) nx++;
		
		for (int i = x;i <= nx;i++)
		for (int j = y;j <= ny;j++)
		mat[i][j] = 0;
//		printf("%d %d %d %d\n",x,nx,y,ny);
		res++;
	}
	
	ans = min(res , ans);
	
	
	for (int i = 1;i <= n;i++)
	for (int j = 1;j <= m;j++)
	mat[i][j] = pre[i][j];
	res = 0;
	while (1){
		int x = -1 , y = -1;
		for (int i = n;i >= 1;i--)
		for (int j = 1;j <= m;j++){
			if (mat[i][j]){
				x = i;
				y = j;
				goto wXh;
			}
		}
		
		wXh:;
		if (x == -1) break;
		
		int ny = y , nx = x;
		while (nx + 1 <= n && mat[nx + 1][y] == 1) nx++;
		while (ny + 1 <= m && check( x , nx , ny + 1 ) ) ny++;
		
		for (int i = x;i <= nx;i++)
		for (int j = y;j <= ny;j++)
		mat[i][j] = 0;
//		printf("%d %d %d %d\n",x,nx,y,ny);
		res++;
	}
	ans = min(ans , res);
	
	
	for (int i = 1;i <= n;i++)
	for (int j = 1;j <= m;j++)
	mat[i][j] = pre[i][j];
	res = 0;
	while (1){
		int x = -1 , y = -1;
		for (int i = n;i >= 1;i--)
		for (int j = 1;j <= m;j++){
			if (mat[i][j]){
				x = i;
				y = j;
				goto WXh;
			}
		}
		
		WXh:;
		if (x == -1) break;
		
		int ny = y , nx = x;
		while (ny + 1 <= m && mat[x][ny + 1] ) ny++;
	
		while (nx + 1 <= n && check(y , ny , nx + 1) ) nx++;
		
		for (int i = x;i <= nx;i++)
		for (int j = y;j <= ny;j++)
		mat[i][j] = 0;
//		printf("%d %d %d %d\n",x,nx,y,ny);
		res++;
	}
	
	ans = min(res , ans);
	
	
	
	cout<<ans;
	return 0;
}
