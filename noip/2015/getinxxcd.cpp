#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int MAXN=2e5+5;
const int mod=1e2+5;
int n,a[MAXN];
int main(){
	freopen("message.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=rand()%mod+1;
	cout<<n<<endl;
	a[1]=2;
	for (int i=2;i<=n;i++) a[i]=i+1;
	int x=rand()%(n-1)+2; a[x]=1; a[n]=x;
	for (int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	fclose(stdout);
	return 0;
}
