#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int modn=15;
const int mod=2;
int n,k;
int main(){
	freopen("redistricting.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=rand()%modn+1,k=rand()%n+1;
	cout<<n<<" "<<k<<endl;
	for (int i=1;i<=n;i++){
		int x=rand()%mod;
		if (x==0) printf("H");
		else printf("G");
	}
	printf("\n");
	fclose(stdin); fclose(stdout);
	return 0;
}
