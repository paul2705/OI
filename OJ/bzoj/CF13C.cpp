#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=5005;
priority_queue<int> q;
int dp[2][MAXN],n,t;
long long ans;
int main(){
	scanf("%d%d",&n,&t); q.push(t);
	for (int i=1;i<n;i++){
		scanf("%d",&t);
		q.push(t);
		if (q.top()>t) ans+=q.top()-t,q.pop(),q.push(t);
	}
	printf("%lld\n",ans);
	return 0;
}
