#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int mod=1<<30;
int n,m;
int main(){
	freopen("1.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=200000;m=200000; cout<<n<<" "<<m<<endl;
	for (int i=1;i<=n;i++){
		int x=rand()%mod;
		cout<<x<<" ";
	}
	cout<<endl;
	for (int i=1;i<=m;i++){
		int l=rand()%n+1;
		int stp=rand()%(n-l+1);
		cout<<l<<" "<<l+stp<<endl;
	}
	fclose(stdout);
	return 0;
}
