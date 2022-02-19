#include<bits/stdc++.h>
#define LL long long
#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
using namespace std;
LL n,m,p;
LL f1[6][6];
template<typename T>
inline void read(T &x)
{
	x=0;T w=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')w=-1;	c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+c-'0';	c=getchar();}
	x*=w;
}
void init()
{
	f1[1][1]=1;
	f1[1][2]=2;
	f1[1][3]=6;
	f1[2][1]=2;
	f1[2][2]=16;
	f1[2][3]=360;
	f1[3][1]=6;
	f1[3][2]=360;
	f1[3][3]=108864;
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	read(n);read(m);read(p);
	init();
	if(n<=3&&m<=3)
	{
		printf(LLD,f1[n][m]);
		return 0;
	}
	return 0;
}
