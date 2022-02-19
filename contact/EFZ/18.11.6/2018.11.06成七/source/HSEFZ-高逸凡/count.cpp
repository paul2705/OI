#include<bits/stdc++.h>
#define UPLOAD
typedef long long ll;

int n, m;
ll MOD;
ll p[1005];
int main()
{
	#ifdef UPLOAD
		freopen("count.in", "r", stdin);
		freopen("count.out", "w", stdout);
	#endif

	scanf("%d%d%lld", &n, &m, &MOD);
	p[1] = 1ll;
	for(int i = 2; i <= 1000; i++)
		p[i] = p[i - 1] * (ll)i % MOD;
	
	//memset(f, 0, sizeof(f));
	//f[1][1] = 1;

	return 0;
}