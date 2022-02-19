#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
ll n,m,k;
ll x,y,xx,yy,xxx,yyy;
string s;
int main(){
	freopen("1.out","r",stdin);
	cin>>n>>m>>k;
	cin>>s;
	cin>>x>>y>>xx>>yy>>xxx>>>yyy;
	if (n*m*2/k!=trunc(n*m*2/k)&&s[0]=='N') printf("1\n");
	if (xx*yyy==n*m/k&&s[0]=='Y') printf("1\n");
	else printf("0\n");
	return 0;
}
