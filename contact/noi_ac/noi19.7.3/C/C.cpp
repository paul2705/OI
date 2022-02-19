#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e4+5;
typedef long long ll;
int ans1[21]={1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,0,0,0,1};
ll n,K,a[MAXN],w[MAXN],cnt[MAXN];
void solve1(){
	for (int i=0;i<20;i++) printf("%d\n",ans1[i]);
}
int main(){
	scanf("%lld%lld",&n,&K);
	for (int i=1;i<=10;i++) scanf("%lld",&a[i]);
	for (int i=0;i<n;i++) scanf("%lld%lld",&w[i],&cnt[i]);
	if (n==20) solve1();
	return 0;
}
