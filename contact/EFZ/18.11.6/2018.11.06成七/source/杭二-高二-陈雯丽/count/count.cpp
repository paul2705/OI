#include<cstdio>

using namespace std;

#define rep(i,a,b) for (int i=(a);i<=(b);i++)
#define LL long long

const int N=85;

int n,m,p,f[N*N][N][N];

void Inc(int &x,int y) {x+=y;if (x>=p) x-=p;}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);f[1][1][1]=n*m%p;
	rep(_,1,n*m-1) rep(i,1,n) rep(j,1,m) if (f[_][i][j])
	{
		if (i*j>_) Inc(f[_+1][i][j],(LL)f[_][i][j]*(i*j-_)%p);
		if (i<n) Inc(f[_+1][i+1][j],(LL)f[_][i][j]*j%p*(n-i)%p);
		if (j<m) Inc(f[_+1][i][j+1],(LL)f[_][i][j]*i%p*(m-j)%p);
	}
	printf("%d\n",f[n*m][n][m]);
	return 0;
}
