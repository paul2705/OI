#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
typedef long long ll;
const int mod=1e5+6;
const int modT=10;
const int modk=15;
ll T;
int main(){
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	freopen("practice.in","w",stdout);
	T=rand()%modT+1;
	cout<<T<<endl;
	for (int i=1;i<=T;i++){
		int m=rand()%mod,l=rand()%mod+1,k=rand()%modk+1;
		cout<<l+m<<" "<<m<<" "<<k<<endl;
	}
	fclose(stdout);
	return 0;
}
