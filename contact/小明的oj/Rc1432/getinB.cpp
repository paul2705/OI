#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int mod=2e2;
const int mod1=1e3+5;
int main(){
	freopen("B.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	int n=rand()%mod+1; cout<<n<<endl;
	for (int i=1;i<=n;i++){
		int x=rand()%mod1+1,y=rand()%mod1+1;
		printf("%d %d\n",x,y);
	}
	fclose(stdout);
	return 0;
}
