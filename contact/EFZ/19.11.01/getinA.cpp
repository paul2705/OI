#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int mod=5e5;
const int mod1=1e5;
int n;
int main(){
	freopen("highway.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=mod; cout<<n<<endl;
	for (int i=2;i<=n;i++){
		int x=rand()%(i-1)+1;
		int w=rand()%mod1;
		cout<<i<<" "<<x<<" "<<w<<endl;
	}
	fclose(stdout);
	return 0;
}
