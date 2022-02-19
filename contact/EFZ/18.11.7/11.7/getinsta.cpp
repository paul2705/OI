#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include"sys/time.h"
using namespace std;
typedef long long ll;
const int MAXN=1e4+4;
const int mod=1e9+7;
ll a[MAXN];
ll n,m;
int main(){
	freopen("station.in","r",stdin);
	freopen("station.out","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=rand()%MAXN+1,m=rand()%MAXN+1;
	cout<<n<<" "<<m<<endl;
	for (int i=1;i<=n;i++){
		a[i]=rand()%mod+1;
		cout<<a[i]<<endl;
	}
	for (int i=1;i<=m;i++){
		ll x=rand()%n+1;
		ll y=rand()%a[x]+1;
		a[x]+=y;
		cout<<x<<" "<<y<<endl;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
