#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include"sys/time.h"
using namespace std;
const int MAXN=2e5+5;
const int mod=2e5;
int a[MAXN],n,m;
int main(){
	freopen("icekingdom.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000 +tv.tv_usec);
	n=rand()%mod+1,m=rand()%mod+1;
	cout<<n<<" "<<m<<endl;
	a[1]=1;
	for (int i=2;i<=n;i++) a[i]=rand()%(i-1)+1;
	for (int i=1;i<n;i++){
		printf("%d %d\n",a[i+1],i+1);
	}
	for (int i=1;i<=m;i++){
		int l=rand()%n+1,len=rand()%(n-l+1);
		printf("%d %d\n",l,l+len);
	}
	fclose(stdout);
	return 0;
}
