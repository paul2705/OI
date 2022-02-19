#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int mod=15;
const int mod1=1e5+5;
int n,m,k;
int a[mod+5],id[mod+5];
int main(){
	freopen("B.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=rand()%mod+1;
	id[1]=1; a[1]=rand()%3; if(a[1]==1) m++;
	if (a[1]==2) k++;
	for (int i=2;i<=n;i++){
		id[i]=rand()%(i-1)+1;
		a[i]=rand()%3;
		if (a[i]==1) m++;
		if (a[i]==2) k++;
	}
	cout<<n<<endl<<m<<endl;
	for (int i=1;i<=n;i++){
		if (a[i]==1) cout<<i<<" ";
	}
	cout<<endl;
	cout<<k<<endl;
	for (int i=1;i<=n;i++){
		if (a[i]==2) cout<<i<<" ";
	}
	cout<<endl;
	for (int i=2;i<=n;i++){
		int w=rand()%mod1+1;
		cout<<i<<" "<<id[i]<<" "<<w<<endl;
	}
	return 0;
}
