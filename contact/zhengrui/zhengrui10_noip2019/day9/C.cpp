#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	if (flg) x=-x;
	return x;
}
typedef long long ll;
const int Mod=1e9+7;

int n,m,p,q,r;
int dp[2][25][25][25]; bool dpcur=false;
void add(int &x,int y)
{
	x=(x+y)%Mod;
}
int main()
{
	n=read(),m=read(),p=read(),q=read(),r=read();
	dp[dpcur][0][0][0]=1;
	for (int i=1;i<=n;i++)
	{
		dpcur^=1; memset(dp[dpcur],0,sizeof dp[dpcur]);
		for (int a=0;a<m;a++)
			for (int b=0;b<m;b++)
				for (int c=0;c<m;c++)
					add(dp[dpcur][a][b][(c+1)%m],dp[dpcur^1][a][b][c]),
					add(dp[dpcur][a][b][(c+m-1)%m],dp[dpcur^1][a][b][c]),
					
					add(dp[dpcur][a][(b+1)%m][c],dp[dpcur^1][a][b][c]),
					add(dp[dpcur][a][(b+m-1)%m][c],dp[dpcur^1][a][b][c]),
					
					add(dp[dpcur][(a+1)%m][b][c],dp[dpcur^1][a][b][c]),
					add(dp[dpcur][(a+m-1)%m][b][c],dp[dpcur^1][a][b][c]),
					
					add(dp[dpcur][(a+1)%m][(b+1)%m][(c+1)%m],dp[dpcur^1][a][b][c]),
					add(dp[dpcur][(a+m-1)%m][(b+m-1)%m][(c+m-1)%m],dp[dpcur^1][a][b][c]);
	}
	int ans=dp[dpcur][p][q][r];
	printf("%d\n",(ans+Mod)%Mod);
	return 0;
}
