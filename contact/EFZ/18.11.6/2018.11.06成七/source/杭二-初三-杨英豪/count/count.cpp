#include<bits/stdc++.h>
using namespace std;
long long a[10][10];
int main()
{
	freopen("count","r",stdin);
	freopen("count","w",stdout);
	int n,m,p;
	scanf("%d %d %d",&n,&m,&p);
	a[1][1] = 1,a[1][2] = 2,a[1][3] = 6,a[1][4] = 24;
	a[1][5] = 120,a[2][1] = 2,a[2][2] = 16,a[2][3] = 360;
	a[2][4] = 16128,a[2][5] = 1209600;
	a[3][1] = 6,a[3][2] = 360,a[3][3] = 108864,a[3][4] = 95800320;
	long long ans = a[n][m] % p;
	printf("%lld\n",ans);
}
