#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
priority_queue<ll> q;
ll n,m,ans;
int main(){
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++){
		ll x; scanf("%lld",&x);
		q.push(x);
	}
	while (m--){
		ll x=q.top(); q.pop();
		q.push(x/2);
	}
	while (!q.empty()){
		ans+=q.top(); q.pop();
	}
	printf("%lld\n",ans);
	return 0;
}
