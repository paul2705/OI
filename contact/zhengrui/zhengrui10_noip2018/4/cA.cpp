#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const ll MAXN=5e4+5;
priority_queue<ll,vector<ll>,greater<ll> > sell,tsell;
ll n,ans,a[MAXN];
ll T;
int main(){
	scanf("%lld",&T);
	while (T--){
		scanf("%lld",&n);
		while (!sell.empty()) sell.pop();
		while (!tsell.empty()) tsell.pop();
		for (ll i=1;i<=n;i++) scanf("%lld",&a[i]);
		for (ll i=1;i<=n;i++){
			ll op=0,bet=0;
			if (!sell.empty())
				if (bet<a[i]-sell.top()){
					bet=a[i]-sell.top();
					op=1;
				}
			if (!tsell.empty())
				if (bet<a[i]-tsell.top()){
					bet=a[i]-tsell.top();
					op=2;
				}
			ans+=bet;
			if (op==0) tsell.push(a[i]);
			else if (op==1) tsell.push(sell.top()),sell.pop(),sell.push(a[i]);
			else tsell.pop(),sell.push(a[i]);
		}
		printf("%lld %lu\n",ans,sell.size()*2);
		ans=0;
	}
	return 0;
}
