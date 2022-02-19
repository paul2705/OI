#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int mod=5e3;
int main(){
	freopen("P7960.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	int n=rand()%mod;
	printf("%d\n",n);
	for (int i=1;i<=n;i++){
		int x=rand()%mod+2;
		printf("%d\n",x);
	}
	fclose(stdout);
	return 0;
}
