#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
typedef long long ll;
const int mod=1e6;
const int modx=1e4;
const int mod1=2;
ll n,m;
int main(){
	freopen("picture.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=rand()%modx+1,m=mod/n;
	cout<<n<<" "<<m<<endl;
	for (ll i=1;i<=n;i++){
		for (ll j=1;j<=m;j++){
			int x=rand()%mod1;
			cout<<x;
		}
	}
	cout<<endl;
	n=rand()%modx,m=mod/n;
	cout<<n<<" "<<m<<endl;
	for (ll i=1;i<=n;i++){
		for (ll j=1;j<=m;j++){
			int x=rand()%mod1;
			cout<<x;
		}
	}
	cout<<endl;
	fclose(stdout);
	return 0;
}
