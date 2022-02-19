#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
typedef long long ll;
const ll mod=1e5;
const int mod1=1e2;
ll n,m,k,T;
int main(){
	freopen("A.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	T=rand()%mod1+1;
	cout<<T<<endl;
	for (int i=1;i<=T;i++){
		n=rand()%mod+1,m=rand()%(mod-n)+1;
		m=n+m;
		k=rand()%mod+1;
		cout<<k<<" "<<n<<" "<<m<<endl;
	}
	fclose(stdout);
	return 0;
}
