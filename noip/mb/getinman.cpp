#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int mod=1e7;
const int mod1=26;
int n;
char a[mod+5];
int main(){
	freopen("manacher.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=rand()%mod+1;
//	cout<<n<<endl;
	int l=rand()%n+1;
	int r=rand()%(n-l)+1;
	int x=n-l-r;
	for (int i=1;i<=l;i++){
		char c=rand()%mod1+97;
		cout<<c;
	}
	if (x&1){
		for (int i=1;i<=x/2;i++){
			a[i]=rand()%mod1+97;
			cout<<a[i];
		}
		cout<<rand()%mod1+97;
		for (int i=x/2;i>=1;i--){
			cout<<a[i];
		}
	}
	else {
		for (int i=1;i<=x/2;i++){
			a[i]=rand()%mod1+97;
			cout<<a[i];
		}
		for (int i=x/2;i>=1;i--){
			cout<<a[i];
		}
	}
	for (int i=1;i<=r;i++){
		char c=rand()%mod1+97;
		cout<<c;
	}
	cout<<endl;
	fclose(stdout);
	freopen("1.out","w",stdout);
	cout<<x<<endl;
	fclose(stdout);
	return 0;
}
