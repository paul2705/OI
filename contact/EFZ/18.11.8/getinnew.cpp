#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int mod=10;
const int mod1=5;
int n,m,a[mod*3+5];
int main(){
	freopen("new.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=rand()%mod+1,m=rand()%mod1+1;
	cout<<n<<" "<<m<<endl;
	for (int i=1;i<=3*n;i++) a[i]=i;
	random_shuffle(a+1,a+3*n+1);
	for (int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<endl;
	for (int i=1;i<=m;i++){
		for (int i=1;i<=3*n;i++) a[i]=i;
		random_shuffle(a+1,a+3*n+1);
		for (int i=1;i<=n;i++) cout<<a[i]<<" ";
		cout<<endl;
	}
	fclose(stdout);
	return 0;
}
