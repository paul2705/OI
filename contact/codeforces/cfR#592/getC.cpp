#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
typedef long long ll;
const ll mod1=1e11;
const ll mod2=1e17;
const ll mod3=1e5;
int main(){
	freopen("1.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	ll d=rand()%mod3+1;
	ll w=rand()%mod3+d;
	ll x=rand()%mod1;
	ll y=rand()%mod1;
	ll z=rand()%mod1;
	ll n=x+y+z,p=x*w+y*d;
	cout<<n<<" "<<p<<" "<<w<<" "<<d<<endl;
//	fclose(stdout);
	cout<<x<<" "<<y<<" "<<z<<endl;
	fclose(stdout);
	return 0;
}
