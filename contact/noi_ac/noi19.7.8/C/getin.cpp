#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int mod=2e6;
int n=3e6;
int main(){
	freopen("1.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	cout<<n<<endl;
	for (int i=1;i<=n;i++){
//		int x=rand()%mod+1-1e6;
		int x=1e6;
		cout<<x<<" ";
	}
	cout<<endl;
	for (int i=1;i<=n;i++){
//		int x=rand()%mod+1-1e6;
		int x=1e6;
		cout<<x<<" ";
	}
	cout<<endl;
	fclose(stdout);
	return 0;
}
