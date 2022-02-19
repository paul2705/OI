#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
int main(){
	int k; scanf("%d",&k);
	double ans=0,cnt=0;
	while (ans<=k){
		cnt++;
		ans+=1/cnt;
	}
	printf("%lld\n",(ll)cnt);
	return 0;
}
