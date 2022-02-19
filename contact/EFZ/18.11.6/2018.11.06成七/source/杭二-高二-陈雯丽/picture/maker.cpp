#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i=(a);i<=(b);i++)
int n,m;
int main()
{
	freopen("picture.in","w",stdout);srand(time(0));
	n=rand()%1000+1,m=rand()%1000+1;printf("%d %d\n",n,m);
	rep(i,1,n) rep(j,1,m) printf("%d",rand()%2);puts("");
	n=rand()%1000+1,m=rand()%1000+1;printf("%d %d\n",n,m);
	rep(i,1,n) rep(j,1,m) printf("%d",rand()%2);puts("");
	return 0;
}
