#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include"sys/time.h"
using namespace std;
const int mod=1<<30;
const int lim=3e5;
int n,m;
int main(){
	freopen("C.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=lim,m=lim;
	cout<<n<<" "<<m<<endl;
	for (int i=1;i<=n;i++){
		int x=rand()%mod;
		cout<<x<<" ";
	}
	cout<<endl;
	for (int i=1;i<=m;i++){
		int op=rand()%4+1,x=rand()%mod;
		if (op==3) cout<<3<<endl;
		else cout<<op<<" "<<x<<endl;
	}
	fclose(stdout);
	return 0;
}
