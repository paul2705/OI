#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int main(){
	freopen("C.ans","w",stdout);
	ll cnt=1;
	for (int i=1;i<=1e9+7;i++){
		cnt=cnt*i%mod;
		if (i%((int)1e7)==0) printf("%lld,",cnt%mod);
	}
	fclose(stdout);
	return 0;
}
