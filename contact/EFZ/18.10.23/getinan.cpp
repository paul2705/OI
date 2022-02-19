#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int MAXN=1e4-5;
const int mod=1e9+7;
int n;
int main(){
	freopen("anomalies.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	n=rand()%MAXN+1;
	cout<<n<<endl;
	int lasl=1,lasr=1;
	for (int i=1;i<=n;i++){
		int x=rand()%mod+1,y=rand()%mod+1;
		cout<<x<<" "<<y<<" "<<lasl<<endl;lasl=x,lasr=y;
	}
	//cout<<1<<" "<<lasl<<" "<<lasr<<endl;
	fclose(stdout);
	return 0;
}
