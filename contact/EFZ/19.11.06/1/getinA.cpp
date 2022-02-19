#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
typedef long long ll;
const ll mod=50;
ll a,b,c,d;
int main(){
	freopen("gift.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	a=rand()%mod;
	b=rand()%mod;
	c=rand()%mod;
	d=rand()%mod;
	printf("%lld %lld %lld %lld\n",a,b,c,d);
	fclose(stdout);
	return 0;
}
