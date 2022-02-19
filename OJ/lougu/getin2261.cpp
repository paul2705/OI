#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int mod=1e3;
int n,k;
int main(){
	freopen("P2261.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=rand()%mod;
	k=rand()%mod;
	printf("%d %d\n",n,k);
	fclose(stdout);
	return 0;
}
