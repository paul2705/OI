#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int mod=500;
const int mod1=1e9;
int n,m;
int main(){
	freopen("neworld.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=rand()%mod+1,m=rand()%mod+1;
	cout<<n<<" "<<m<<endl;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			int x=rand()%mod1+1;
			cout<<x<<" ";
		}
		cout<<endl;
	}
	int r=rand()%n+1,c=rand()%m+1,l=rand()%mod1+1,p=rand()%n+1,q=rand()%m+1;
	cout<<r<<" "<<c<<" "<<l<<" "<<r-1<<" "<<c-1<<endl;
	fclose(stdout);
	return 0;
}
