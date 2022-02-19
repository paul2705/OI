#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
int mat[N][N] , tmp[N][N];

void rotate(int lx,int rx,int ly,int ry) {
	
//	printf("%d %d %d %d\n",lx,rx,ly,ry);
	
	for (int y = ry;y >= ly;y--){
		for (int x = lx;x <= rx;x++){
			tmp[lx + y - ly][lx + ry - x]= mat[x][y];
		}
	}
	
	for (int x = lx;x <= rx;x++)
	for (int y = ly;y <= ry;y++)
	mat[x][y] = tmp[x][y];
}

void flip(int lx,int rx,int ly,int ry) {
	
	for (int y = ry;y >= ly;y--){
		for (int x = lx;x <= rx;x++){
			tmp[rx - ( y - ly )][ly + ( rx - x ) ] = mat[x][y];
		}
	}
	
	
	for (int x = lx;x <= rx;x++)
	for (int y = ly;y <= ry;y++)
	mat[x][y] = tmp[x][y];


}


int n , q;
void print(){
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= n;j++){
			printf("%d ",mat[i][j]);
		}
		putchar('\n');
	}
}

unsigned int Hash() {
    unsigned int ans=0;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++) {
            ans^=ans<<13;
            ans^=ans>>17;
            ans^=ans<<5;
            ans+=mat[i][j]+1234567;
        }
      return ans;  
}
char opt[20];
int lx , rx  , ly , ry , l;
int main() {
	freopen("matrix.in","r",stdin);
	
	freopen("matrix.out","w",stdout);
    scanf("%d%d",&n,&q);
	for (int i = 1;i <= n;i++)
	for (int j = 1;j <= n;j++)
	mat[i][j] = (i - 1) * n + j;


//	print();putchar('\n');
	
	while (q--){
		scanf("%s",opt);
		scanf("%d%d%d",&lx,&ly,&l);
		rx = lx + l - 1;
		ry = ly + l - 1;
		if (*opt == 'T'){
			rotate(lx , rx , ly , ry);
		}else{
			flip(lx , rx , ly , ry);
		}
		
//		print();putchar('\n');
	}
	unsigned int res = Hash();
	printf("%u",res);
    return 0;
}
