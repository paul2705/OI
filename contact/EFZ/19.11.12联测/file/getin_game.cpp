#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int modn=1e6;
const int modm=1e9;
const int mod=1e9;
int n,m;
int main(){
	freopen("game.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=modn; m=modm;
	printf("%d %d\n",n,m);
	for (int i=1;i<=n;i++){
		int x=rand()%mod; printf("%d ",x);
	}
	printf("\n");
	fclose(stdin); fclose(stdout);
	return 0;
}
