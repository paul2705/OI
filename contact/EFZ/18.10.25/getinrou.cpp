#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
typedef long long ll;
const int MAXN=1e2+6;
const int mod=1e5+7;
int n,m;
int main(){
	freopen("route.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=rand()%MAXN+1,m=rand()%(MAXN*5)+1;
	cout<<n<<" "<<m<<endl;
	for (int i=1;i<=m;i++){
		int u=rand()%n+1,v=rand()%n+1;
		if (u==v){
			v=(v+1)%n;
			if (v==0&&u!=n) v=n;
			else if (v==0) v=1;
		}
		ll w=rand()%mod+1;
		printf("%d %d %lld\n",u,v,w);
	}
	fclose(stdout);
	return 0;
}
