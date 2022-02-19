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
int i,j,k,m,n,x,y,z,cnt,p;
ll f[85][85];
int main(){
	file("count")
	n=r;m=r;p=r;
	f[1][1]=n*m;
	for(rt i=2;i<=n*m;i++)
	for(rt j=n;j>=1;j--)
	for(rt k=m;k>=1;k--){
		f[j][k]=(f[j][k]*(j*k-i+1)+f[j-1][k]*k*(n-j+1)+f[j][k-1]*j*(m-k+1))%p;
		if(j==n&&k==m)cout<<i<<' '<<f[j][k]<<endl;
	}
	cout<<f[n][m];
	return 0;
}

