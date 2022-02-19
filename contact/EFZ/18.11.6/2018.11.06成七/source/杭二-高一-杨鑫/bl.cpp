#include<ctime>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#define file(x)freopen(x".in","r",stdin);freopen(x".out","w",stdout)
#define rt register int
#define l putchar('\n')
#define ll long long
#define r read()
using namespace std;
inline ll read(){
    ll x = 0; char zf = 1; char ch = getchar();
    while (ch != '-' && !isdigit(ch)) ch = getchar();
    if (ch == '-') zf = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar(); return x * zf;
}
void write(ll y){if(y<0)putchar('-'),y=-y;if(y>9)write(y/10);putchar(y%10+48);}
void writeln(const ll y){write(y);putchar('\n');}
int i,j,k,m,n,x,y,z,cnt;
char c[1000010];
int a[1010][1010],b[1010][1010];
int bb[3010][3010],aa[3010][3010];
int main(){
	freopen("picture.in","r",stdin);
	int n1=r,m1=r;
	scanf("%s",c+1);
	for(rt i=1;i<=n1;i++)
	for(rt j=1;j<=m1;j++)
	a[i][j]=c[i*m1-m1+j]-'0';
	int n2=r,m2=r;
	scanf("%s",c+1);
	for(rt i=1;i<=n2;i++)
	for(rt j=1;j<=m2;j++)
	b[i][j]=c[i*m2-m2+j]-'0';
	int lcmn=n1*n2/__gcd(n1,n2);
	int lcmm=m1*m2/__gcd(m1,m2);
	int sizen1=lcmn/n1,sizen2=lcmn/n2;
	int sizem1=lcmm/m1,sizem2=lcmm/m2;
	for(rt i=1;i<=lcmn;i++)
	for(rt j=1;j<=lcmm;j++)
	aa[i][j]=a[(i+sizen1-1)/sizen1][(j+sizem1-1)/sizem1];
	
	for(rt i=1;i<=lcmn;i++)
	for(rt j=1;j<=lcmm;j++)
	bb[i][j]=b[(i+sizen2-1)/sizen2][(j+sizem2-1)/sizem2];
	
	for(rt i=1;i<=lcmn;i++)
		for(rt j=1;j<=lcmm;j++)
		if(aa[i][j]==bb[i][j])cnt++;
		
		cout<<cnt;
	return 0;
}

