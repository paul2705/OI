#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 4005
#define inf 0x3f3f3f3f
void Read(int &p)
{
	p = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar());
	for (; c >= '0' && c <= '9'; c = getchar())p = p * 10 + c - '0';
}
int t, k, n;
int cst[N][N], sum;
int num[N][26], all[N], mxx[N], C[N][N];
char S[N];
int Check(int x, int y, int l)
{
	if (x + l >= y || y + l > n)
		return inf;
	int v = cst[x][y];
	if (x + l + 1 < y && y + l + 1 <= n)
		v -= cst[x + l + 1][y + l + 1];
	return v;
}
void Add(int l, int x){
	int v = S[x] - 'a';
	int u = x % l;
	sum -= all[u] - mxx[u];
	C[u][num[u][v]]--;
	mxx[u] = max(mxx[u], num[u][v] + 1);
	num[u][v]++;
	all[u]++;
	C[u][num[u][v]]++;
	sum += all[u] - mxx[u];
}
void Del(int l, int x){
	int v = S[x] - 'a';
	int u = x % l;
	sum -= all[u] - mxx[u];
	C[u][num[u][v]]--;
	if (mxx[u] == num[u][v] && !C[u][num[u][v]])
		mxx[u]--;
	num[u][v]--;
	all[u]--;
	C[u][num[u][v]]++;
	sum += all[u] - mxx[u];
}
int main()
{
	Read(t);
	for (; t--; )
	{
		Read(k);
		scanf("%s", S + 1);
		n = strlen(S + 1);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cst[i][j] = 0;
		for (int i = n; i >= 1; i--)
		{
			for (int j = i + 1; j <= n; j++)
			{
				int v = 0;
				if (i + 1 < j && j < n)
					v = cst[i + 1][j + 1];
				cst[i][j] = (S[i] != S[j]) + v;
			}
		}
		int now = 0, ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				while (Check(i, j, now) <= k)
					now++;
		ans = now;
		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j <= n; j++)
				C[i][j] = 0;
			C[i][0] = 26;
		}
		for (int p = 1; p <= n; p++)
		{
			sum = 0;
			int r = 0;
			for (int i = 1; i <= n; i++)
			{
				while (r < n && sum <= k)
				{
					ans = max(ans, r - i + 1 - p);
					Add(p, ++r);
				}
				if (sum <= k)
					ans = max(ans, r - i + 1 - p);
				Del(p, i);
			}
		}
		printf("%d\n", ans);
	}
}
