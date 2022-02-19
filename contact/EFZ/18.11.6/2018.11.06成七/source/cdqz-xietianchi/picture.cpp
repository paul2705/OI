#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;

vector<vector<int> > sum , p1 , p2;

int h1 , w1 , h2 , w2 , W , H , W2 , H2; 
int ans;
char tmp[N];

int query(int x,int y){
	if (!x || !y) return 0; 
//	printf("gg %d %d\n",x,y);
	int _x = (x - 1) / H2 , _y = ( y - 1 ) / W2;
	int ans = sum[_x][_y];
//	printf("ff %d %d\n",_x,_y);
	int X = _x * H2 , Y = _y * W2;
	ans += (x - X) * ( sum[_x+1][_y] - sum[_x][_y]) + (y - Y) * ( sum[_x][_y+1] - sum[_x][_y]);
	if (p2[_x+1][_y+1]){
		ans += (x - X) * (y - Y);
	}
	
	return ans;	
}
int main(){
	
	freopen("picture.in","r",stdin);
	
	freopen("picture.out","w",stdout);
	scanf("%d%d",&h1,&w1);
	p1.resize(h1 + 1);
	for (int i = 1;i <= h1;i++) p1[i].resize(w1+1);
	scanf("%s",tmp + 1);
	
	for (int i = 1;i <= h1;i++)
	for (int j = 1;j <= w1;j++)
	{
		p1[i][j] = tmp[(i - 1) * w1 + j] - '0';
	}

	scanf("%d%d",&h2,&w2);
	p2.resize(h2 + 1);
	sum.resize(h2 + 1);
	for (int i = 0;i <= h2;i++) p2[i].resize(w2 + 1) , sum[i].resize(w2 + 1);
	scanf("%s",tmp + 1);
	
	
	for (int i = 1;i <= h2;i++)
	for (int j = 1;j <= w2;j++)
	{
		p2[i][j] = tmp[(i - 1) * w2 + j] - '0';
		sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + p2[i][j];
	}
		

		H = h1 * h2 / __gcd(h1 , h2);
		W = w1 * w2 / __gcd(w1 , w2);
		
		W2 = W / w2 , H2 = H / h2; 
		int sh = H / h1 , sw = W / w1;
		
	 
	for (int i = 1;i <= h1;i++){
		for (int j = 1;j <= w1;j++){
//			printf("fafa %d %d\n",i,j);
			int xl = (i - 1) * sh + 1, xr = i * sh , yl = (j - 1) * sw + 1  , yr = j * sw;
//			printf("%d %d %d %d\n",xl,xr,yl,yr);
			if (p1[i][j]){
				ans += query(xr , yr) - query(xl - 1 , yr) - query(xr , yl - 1) + query(xl - 1 , yl - 1); 
			}else{
				ans += sh * sw - (query(xr , yr) - query(xl - 1 , yr) - query(xr , yl - 1) + query(xl - 1 , yl - 1));
			}
		}
	}
	
	printf("%d\n",ans);
	return 0;
}
