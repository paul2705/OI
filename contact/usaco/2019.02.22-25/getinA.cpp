#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int MAXN=1e3+5;
int a[MAXN],n;
const int mod=1e6;
int main(){
	freopen("cowdate.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=rand()%MAXN+1;
	for (int i=1;i<=n;i++){
		double x=rand()%mod;
		double y=rand()%mod+x;
		a[i]=x/y*1000000.00;
	}
	cout<<n<<endl;
	for (int i=1;i<=n;i++) printf("%d\n",a[i]);
	fclose(stdout);
	return 0;
}
