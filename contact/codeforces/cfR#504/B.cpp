#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
ll n,k;
int main(){
	scanf("%lld%lld",&n,&k);
	if (n>=k) printf("%lld\n",k%2==0?(k/2-1):k/2);
	else {
		if (k-n>=n) printf("0\n");
		else{
			printf("%lld\n",(2*n-k+1)/2);
		}
	}
	return 0;
}
