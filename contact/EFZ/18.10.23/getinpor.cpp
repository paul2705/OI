#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int MAXN=1e2+5;
const int mod=3;
int n,m;
int main(){
	freopen("portals.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	cout<<1<<endl;
	n=1; m=rand()%MAXN+1; int t=rand()%m+1,r=rand()%(m/2)+1;
	cout<<n<<" "<<m<<" "<<t<<" "<<r<<endl;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			int x=rand()%mod+1;
			if (x==1) cout<<"*";
			if (x==2) cout<<"O";
			if (x==3) cout<<"X";
		}
		cout<<endl;
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
