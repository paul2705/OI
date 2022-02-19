#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e6+6;
ll tag[MAXN];
ll n,ans;
int main(){
	scanf("%lld",&n);
	for (int i=2;i<=n;i++){
		for (int j=i;j<=n;j+=i){
			tag[j]+=i;
		}
	}
	for (int i=1;i<=n;i++){
		ans+=n-tag[i]-1;
		printf("%lld ",ans);
	}
	return 0;
}
