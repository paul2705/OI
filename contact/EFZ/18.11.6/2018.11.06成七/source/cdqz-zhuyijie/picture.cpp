#include<bits/stdc++.h>
#define LL long long
#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
using namespace std;
const LL N1=39;
LL h1,w1,h2,w2,H,W,ans=0;
LL a[N1][N1],b[N1][N1],c[910][910],d[910][910];
char s[910];
template<typename T>
inline void read(T &x)
{
	x=0;T w=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')w=-1;	c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+c-'0';	c=getchar();}
	x*=w;
}
LL gcd(LL a,LL b)
{
	if(!b)	return a;
	return gcd(b,a%b);
}
int main()
{
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	read(h1);read(w1);
	scanf("%s",s+1);
	for(LL i=1;i<=h1*w1;++i)
		a[(i-1)/w1+1][(i-1)%w1+1]=s[i];
	read(h2);read(w2);
	scanf("%s",s+1);
	for(LL i=1;i<=h2*w2;++i)
		b[(i-1)/w2+1][(i-1)%w2+1]=s[i];
	H=h1/gcd(h1,h2)*h2;
	W=w1/gcd(w1,w2)*w2;
	for(LL i=1;i<=h1;++i)
		for(LL j=1;j<=w1;++j)
			for(LL x=H/h1*(i-1)+1;x<=H/h1*i;++x)
				for(LL y=W/w1*(j-1)+1;y<=W/w1*j;++y)				
					c[x][y]=a[i][j];
	for(LL i=1;i<=h2;++i)
		for(LL j=1;j<=w2;++j)		
			for(LL x=H/h2*(i-1)+1;x<=H/h2*i;++x)			
				for(LL y=W/w2*(j-1)+1;y<=W/w2*j;++y)				
					d[x][y]=b[i][j];
	for(LL i=1;i<=H;++i)
		for(LL j=1;j<=W;++j)
			ans+=(c[i][j]==d[i][j]);
	printf(LLD,ans);
	return 0;
}
