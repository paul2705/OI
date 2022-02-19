#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include"sys/time.h"
using namespace std;
const int mod1=1e9+7;
const int mod=2e5+5;
int n,m;
int main(){
	freopen("dream.in","w",stdout);
    struct timeval tv;
    struct timezone tz;
    gettimeofday(&tv,&tz);
    srand(tv.tv_sec*1000000 +tv.tv_usec);
	int n=rand()%mod+1,m=rand()%mod+1;
	cout<<n<<" "<<m<<endl;
	for (int i=1;i<=n;i++){
		int x=rand()%mod1+1;
		int l=rand()%mod1+1;
		int y=x+l;
		printf("%d %d\n",x,y);
	}
	for (int i=1;i<=m;i++){
		int x=rand()%mod1+1;
		printf("%d\n",x);
	}
	fclose(stdout);
	return 0;
}
