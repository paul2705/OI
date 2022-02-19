#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int MAXN=10;
const int mod=8;
const int mod1=12;
const int mod2=20;
int n;
int main(){
	freopen("gwyx.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=rand()%mod+1;
	cout<<n<<endl;
	for (int i=0;i<=n;i++){
		int x=rand()%mod1+1,y=rand()%mod2+1;
		printf("%d %d\n",x,y);
	}
	return 0;
}
