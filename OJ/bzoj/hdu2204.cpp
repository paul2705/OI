#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int p[19]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
ll n,ans;
int i;
void calc(int d,int a,int cnt){
	if (a>60) return;
	if (cnt==0){
		ll ret=pow(n,1.0/a);
		if (pow(ret,(double)a)>n) ret--; ret--;
		if (ret) ans+=ret*(i&1?1ll:-1ll);
		return;
	}
	if (d>17) return;
	calc(d+1,a,cnt);
	if (a*p[d]<=60) calc(d+1,a*p[d],cnt-1);
}
int main(){
	while (~scanf("%lld",&n)){
		ans=0;
		for (i=1;i<=3;i++) calc(0,1,i);
		printf("%lld\n",ans+1);
	}
	return 0;
}
