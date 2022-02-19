#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int modn=1e3;
const int mod=1e6;
int n;
int main(){
	freopen("cowpatibility.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=rand()%modn+1;
	cout<<n<<endl;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=5;j++){
			int x=rand()%mod+1;
			printf("%d ",x);
		}
		printf("\n");
	}
	fclose(stdout);
	return 0;
}
