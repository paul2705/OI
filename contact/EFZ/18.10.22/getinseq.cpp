#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int mod=1e4+6;
int n;
int a[mod*4];
int main(){
	freopen("sequence.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=rand()%mod+1; n*=2;
	cout<<n<<endl;
	int sum=rand()%mod+1;
	int l=rand()%n+1;
//	cout<<l<<" "<<sum<<endl;
	for (int i=1;i<=n/2;i++){
		int x=rand()%(sum/2-1)+1;
		a[i]=x;
	}
	int pos=n/2;
	for (int i=n/2+1;i<=n;i++){
		a[i]=sum-a[pos];
		pos--;
	}
//	for (int i=1;i<=n;i++) printf("%d ",a[i]);
//	cout<<endl;
	for (int i=l;i<=n;i++) printf("%d ",a[i]);
	for (int i=1;i<l;i++) printf("%d ",a[i]);
	fclose(stdout);
	freopen("seq.out","w",stdout);
	cout<<l<<endl;
	return 0;
}
