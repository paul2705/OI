#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
typedef long long ll;
const int mod=1e3;
ll n,m,p,q;
int main(){
	freopen("matrix.in","w",stdout);
	n=rand()%mod+1,m=rand()%mod+1;
	p=rand()%mod+1,q=rand()%mod+1;
	cout<<n<<" "<<m<<" "<<p<<" "<<q<<endl;
	for (int i=1;i<=p;i++){
		ll x=rand()%n+1,xx=rand()%n+1;
		ll y=rand()%m+1,yy=rand()%m+1;
		printf("%lld %lld %lld %lld\n",min(x,xx),min(y,yy),max(x,xx),max(y,yy));
	}
	fclose(stdout);
	return 0;
}
