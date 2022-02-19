#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int mod=1e6;
int n=1e3;
int main(){
	freopen("1.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	int k=rand()%(n+1);
//	int k=0;
	cout<<n<<" "<<n-1<<" "<<1<<" "<<n<<" "<<k<<endl;
	for (int i=1;i<n;i++){
		int x=rand()%mod;
		cout<<i<<" "<<i+1<<" "<<x<<endl;
	}
	fclose(stdout);
	return 0;
}
