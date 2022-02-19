#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int mod=1e9+5;
const int mod1=1e5+5;
int n,sa,sb,sc;
int main(){
	freopen("cdq.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=rand()%mod1+1;
	sa=rand()%mod+1;
	sb=rand()%mod+1;
	sc=rand()%mod+1;
	cout<<n<<endl<<sa<<" "<<sb<<" "<<sc<<endl;
	fclose(stdout);
	return 0;
}
