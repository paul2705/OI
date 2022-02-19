#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int mod=5e5+5;
const int mod1=1e5+5;
int n,m;
int main(){
	freopen("sort.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=10,m=10;
	cout<<n<<" "<<m<<endl;
	for (int i=1;i<=n;i++){
		int x=rand()%mod1+1;
		cout<<x<<" ";
	}
	cout<<endl;
	for (int i=1;i<=m;i++){
		int x=rand()%n+1;
		cout<<x<<" ";
	}
	cout<<endl;
	fclose(stdout);
	return 0;
}
