#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
typedef long long ll;
const ll mod1=1e9+7;
ll mod=1;
int main(){
	freopen("sequences.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	int n=rand()%5+2;
	cout<<n<<endl;
	for (int i=1;i<=6-n;i++) mod*=10;
	int x=rand()%mod+1;
	cout<<x<<" ";
	for (int i=2;i<=n;i++){
		ll x=rand()%mod1+1;
		cout<<x<<" ";
	}
	fclose(stdout);
	return 0;
}
