#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=60;
ll p[MAXN],n,x;
void ins(ll x){
	for (int i=50;i>=0;i--){
		if (x&(1<<i)){
			if (p[i]==0){
				p[i]=x;
				break;
			}
			else x^=p[i];
		}
	}
}
ll qmax(){
	ll ret=0;
	for (int i=50;i>=0;i--){
		if ((ret^p[i])>ret) ret^=p[i];
	}
	return ret;
}
int main(){
	scanf("%lld",&n);
	for (int i=1;i<=n;i++){
		scanf("%lld",&x);
		ins(x);
	}
	printf("%lld\n",qmax());
	return 0;
}
