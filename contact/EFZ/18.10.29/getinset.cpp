#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int MAXN=1e5+5;
const int mod=1e9+7;
const int mod1=1e3+5;
int n;
int main(){
	freopen("leset.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=rand()%mod1+1;
	for (int i=1;i<=n;i++){
		int x=rand()%2+1;
		if (x==1) printf("L");
		else printf("R");
		int f=rand()%2+1;
		if (f==1){
			int xx=rand()%mod+1;
			cout<<xx;
		}
	}
	cout<<endl;
	fclose(stdin); fclose(stdout);
	return 0;
}
