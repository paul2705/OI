/*
	Author: zxy_hhhh
	data: 2018/11/06
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<cmath>
#define rep(x,a,b) for (int x=int(a);x<=(int)(b);x++)
#define drp(x,a,b) for (int x=int(a);x>=(int)(b);x--)
#define cross(x,a) for (int x=hd[a];x;x=nx[x])
#define ll long long
#define maxn 905
using namespace std;
inline ll rd()
{
	ll _x=0;int _ch=getchar(),_f=1;
	for(;!isdigit(_ch)&&(_ch!='-')&&(_ch!=EOF);_ch=getchar());
	if (_ch=='-'){_f=0;_ch=getchar();}
	for(;isdigit(_ch);_ch=getchar()) _x=_x*10+_ch-'0';
	return _f?_x:-_x;
}
void write(ll _x){if (_x>=10) write(_x/10),putchar(_x%10+'0'); else putchar(_x+'0'); }
inline void wrt(ll _x,char _p){if (_x<0) putchar('-'),_x=-_x; write(_x); if (_p) putchar(_p);}
int n1,m1,n2,m2,lcm1,lcm2,l1,r1,l2,r2;
inline int gcd(int x,int y){return y==0?x:gcd(y,x%y);}
char a[maxn],b[maxn];
char res1[maxn][maxn],res2[maxn][maxn];
int main()
{
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	n1=rd(),m1=rd();
	scanf("%s",a+1);
	n2=rd(),m2=rd();
	scanf("%s",b+1);
	lcm1=n1/gcd(n1,n2)*n2;
	lcm2=m1/gcd(m1,m2)*m2;
	l1=lcm1/n1,r1=lcm2/m1;
	l2=lcm1/n2,r2=lcm2/m2;
	rep(i,1,n1)
		rep(j,1,m1)
			rep(l,(i-1)*l1+1,i*l1)
				rep(r,(j-1)*r1+1,j*r1)
					res1[l][r]=a[(i-1)*m1+j];
	rep(i,1,n2)
		rep(j,1,m2)
			rep(l,(i-1)*l2+1,i*l2)
				rep(r,(j-1)*r2+1,j*r2)
					res2[l][r]=b[(i-1)*m2+j];
	int Ans=0;
	rep(i,1,lcm1)
		rep(j,1,lcm2)
			Ans+=res1[i][j]==res2[i][j];
	wrt(Ans,'\n');
}