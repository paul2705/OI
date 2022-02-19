#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int modn=2e5+5e4;
const int mod=2e9;
const int modd=1e5;
int n,L;
int main(){
	freopen("bzoj1171.in","w",stdout);
	struct timezone tz;
	struct timeval tv;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=rand()%(modn-2)+3; L=rand()%modd;
	cout<<n<<" "<<L<<endl;
	int las=0;
	for (int i=2;i<=n;i++){
		int x=rand()%mod+1;
		int y=rand()%(mod-x)+x+1;
		int d=rand()%L;
		int rd=rand()%L;
		int op=rand()%2;
		cout<<x<<" "<<y<<" "<<las+d+rd*op<<endl;
		las+=d+rd*op;
	}
	fclose(stdout);
	return 0;
}
