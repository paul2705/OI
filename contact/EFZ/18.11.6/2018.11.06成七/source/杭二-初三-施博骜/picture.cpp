#include<bits/stdc++.h>
#define MAXN 1000010
using namespace std;
struct Point{
	int x,y;
};
int n1,m1,n2,m2,n,m;
char tt[10];
int a[MAXN],b[MAXN];
int A[1010][1010],B[1010][1010];
int gcd (int a,int b){return b==0?a:gcd (b,a%b);}
Point make (int x,int y){Point tmp;tmp.x=x;tmp.y=y;return tmp;}
Point a_id (int i){return make ((i-1)/m1+1,i-(i-1)/m1*n1);}
Point b_id (int i){return make ((i-1)/m2+1,i-(i-1)/m2*n2);}
int main()
{
	scanf ("%d%d",&n1,&m1);gets (tt);
	for (int i=1;i<=n1*m1;i++)
		a[i]=getchar ()-'0';
	gets (tt);
	scanf ("%d%d",&n2,&m2);gets (tt);
	for (int i=1;i<=n2*m2;i++)
		b[i]=getchar ()-'0';
	int kn=gcd (n1,n2);
	int km=gcd (m1,m2);
	n=n1/kn*n2,m=m1/km*m2;
	for (int i=1;i<=n1*m1;i++)
	{
		Point P=a_id (i);
		for (int i=P.x*;i<=P.x+n2/kn;k++)
			for (int i=P.y)
	}
	return 0;
}
