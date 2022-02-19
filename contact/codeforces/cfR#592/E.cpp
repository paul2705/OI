#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long int LL;
vector<LL> lis;
LL dp[100005];
LL dp2[100005];
int main() {
	int n;
	LL k;
	scanf("%d %lld", &n, &k);
	for (int i = 0; i < n; i++) {
		LL x;
		scanf("%lld", &x);
		lis.push_back(x);
	}
	sort(lis.begin(), lis.end());
	for (int i = n-1; i >= 0; i--) {
		if (i == n-1) dp[i] = 0;
		else dp[i] = dp[i+1] + ((LL)n-i-1)*(lis[i+1] - lis[i]);
	}
	for (int i = 0; i < n; i++) {
		if (i == 0) dp2[i] = 0;
		else dp2[i] = dp2[i-1] + ((LL)i)*(lis[i] - lis[i-1]);
	}
	LL l = 0, r = 2000000000;
	LL foun = -1;
	while (l <= r) {
		LL mid = (l + r) / 2;
		LL cost = k + 1;
		for (int i = 0, j = 0; i < n; i++) {
			while (j < n && lis[j] <= lis[i] + mid) j++;
			LL tmp = dp2[i];
			if (j < n) tmp += dp[j] + (n-j)*(lis[j] - (lis[i] + mid));
			cost = min(cost, tmp);
		}
		for (int i = n-1, j = n-1; i >= 0; i--) {
			while (j >= 0 && lis[j] >= lis[i] - mid) j--;
			LL tmp = dp[i];
			if (j >= 0) tmp += dp2[j] + (j+1)*((lis[i] - mid) - lis[j]);
			cost = min(cost, tmp);
		}
		if (cost <= k) {
			foun = mid;
			r = mid - 1;
		} 
		else l = mid + 1;
	}
	printf("%lld\n", foun);
	return 0;
}
