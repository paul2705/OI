#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int modn=10;
const int modm=1e3;
const int mod=1e9;
int n,m;
int main(){
	freopen("problem2.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=rand()%modn+1,m=rand()%modm+1;
	printf("%d %d\n",n,m);
	for (int i=1;i<=m;i++){
		int op=rand()%6+1;
		int x=rand()%n+1;
		if (op==1){
			int y=rand()%mod;
			printf("%d %d %d\n",op,x,y);
		}
		if (op==2) printf("%d %d\n",op,x);
		if (op==3){
			int y=rand()%mod;
			printf("%d %d %d\n",op,x,y);
		}
		if (op==4) printf("%d %d\n",op,x);
		if (op==5){
			int y=rand()%mod;
			printf("%d %d %d\n",op,x,y);
		}
		if (op==6){
			int y=rand()%n+1;
			while (x==y) y=rand()%n+1;
			printf("%d %d %d\n",op,x,y);
		}
	}
	fclose(stdout);
	return 0;
}
