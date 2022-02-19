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
int main(){
	freopen("picture.in","w",stdout);
	srand(time(0));
	int n1=1000,m1=1000,n2=1001,m2=999;
	cout<<n1<<' '<<m1<<endl;
	for(rt i=1;i<=n1*m1;i++)putchar((rand()&1)+'0');l;
	
	cout<<n2<<' '<<m2<<endl;
	for(rt i=1;i<=n2*m2;i++)putchar((rand()&1)+'0');l;
	return 0;
}

