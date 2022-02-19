#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int mod=20;
int n;
int main(){
	freopen("bzoj1109.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=20;
	printf("%d\n",n);
	for (int i=1;i<=n;i++){
		int x=rand()%n+1;
		printf("%d ",x);
	}
	printf("\n");
	fclose(stdout);
	return 0;
}
