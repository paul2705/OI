#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int MAXN=1e2+5;
const int mod=1e3+7;
int a[MAXN],n,m;
int main(){
	freopen("yqkz.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=rand()%MAXN+1;
	a[1]=1;
	cout<<n<<endl;
	for (int i=2;i<=n;i++) a[i]=rand()%(i-1)+1;
	for (int i=2;i<=n;i++) printf("%d %d %d\n",i,a[i],rand()%mod+1);
	m=rand()%MAXN+1;
	for (int i=1;i<=m;i++){
		int x=rand()%(n-1)+2;
		printf("%d\n",x);
	}
	fclose(stdout);
	return 0;
}
