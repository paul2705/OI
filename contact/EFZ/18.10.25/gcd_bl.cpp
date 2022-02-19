#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
int n,m,mx;
int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }
int main(){
	freopen("gcd.in","r",stdin);
	freopen("gcd1.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		mx=max(mx,gcd(i,m));
	}
	printf("%d\n",mx);
	fclose(stdin); fclose(stdout);
	return 0;
}
