#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int mod=5;
const int mod1=2;
int n,m;
int main(){
	freopen("merging.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=rand()%mod+1,m=rand()%mod+1;
	cout<<n<<" "<<m<<endl;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			int x=rand()%mod1;
			cout<<x<<" ";
		}
		cout<<endl;
	}
	fclose(stdout);
	return 0;
}
