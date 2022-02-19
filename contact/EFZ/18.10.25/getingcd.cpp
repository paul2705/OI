#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
int n,m;
const int mod=1e3+7;
int main(){
	freopen("gcd.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=rand()%mod+1,m=rand()%mod+1;
	cout<<n<<" "<<m<<endl;
	fclose(stdout);
	return 0;
}
