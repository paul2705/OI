#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long GCD(long long a, long long b) { return b == 0 ? a : GCD(b, a%b); }
const int inf = 1e9;
const long long mod = 1e9 + 7;
double pi = acos(-1.0);
string str;
int  main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	cin >> str;
	long long ans = 1ll * n*(n - 1) / 2;
	int sum = 1;
	for (int i = 1; i < n; i++)
		if (str[i - 1] == str[i])
			sum++;
		else
			ans -= sum,sum = 1;
	sum = 1;
	for (int i = n - 2; i >= 0; i--)
		if (str[i + 1] == str[i])
			sum++;
		else
			ans -= sum, sum = 1;
	for (int i = 0; i < n - 1; i++)
		if (str[i] != str[i + 1])
			ans++;
	cout << ans << endl;
}
