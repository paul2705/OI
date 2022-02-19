#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstring>
#include <time.h>
#include <utility>

#pragma warning(disable:4996)
#define INF 2000000//005//2 * 10^9
#define lowbit(a) ((a)&-(a))
inline long long max(long long a, long long b)
{
    return a > b ? a : b;
}
inline long long min(long long a, long long b)
{
    return a < b ? a : b;
}

const int MAXN = 45;
const int MAX = 1000005;

int N, m;
int val[MAXN][MAXN][MAXN];
int sum[MAXN][MAXN][MAXN];

void prepare()
{
    int i, j, k;
    for (i = 1; i <= N; i++)
        for (j = 1; j <= N; j++)
            for (k = 1; k <= N; k++)
                sum[i][j][k] = (sum[i - 1][j][k] + sum[i][j - 1][k]
                - sum[i - 1][j - 1][k] + sum[i][j][k - 1] - (sum[i - 1][j][k - 1]
                + sum[i][j - 1][k - 1] - sum[i - 1][j - 1][k - 1]) + val[i][j][k]) % m;
}

int sumof(int x1, int x2, int y1, int y2, int z1, int z2)
{
    x2--;
    y2--;
    z2--;
    int t = (sum[x1][y1][z1] + sum[x1][y2][z2] + sum[x2][y1][z2] + sum[x2][y2][z1]
        - sum[x2][y1][z1] - sum[x1][y2][z1] - sum[x1][y1][z2] - sum[x2][y2][z2]) % m;
    return t < 0 ? t + m : t;
}

bool judge(int x, int y, int z, int len)
{
    return x + len - 1 <= N&&y + len - 1 <= N&&z + len - 1 <= N;
}

int c[MAX], S[MAX], s;

int main()
{
    int i, j, k;
    int cnt = 0;

    scanf("%d %d", &N, &m);
    for (i = 1; i <= N; i++)
        for (j = 1; j <= N; j++)
            for (k = 1; k <= N; k++)
                scanf("%d", &val[i][j][k]);

    prepare();

    int x1, x2, y1, y2, z;
    for (x1 = 1; x1 <= N; x1++)
        for (x2 = x1; x2 <= N; x2++)
            for (y1 = 1; y1 <= N; y1++)
                for (y2 = y1; y2 <= N; y2++)
                {
                    while (s)
                        c[S[--s]] = 0;
                    for (z = 1; z <= N; z++)
                    {
                        int t = sumof(x2, x1, y2, y1, z, 1);
                        if (!c[t])
                            S[s++] = t;
                        cnt += c[t];
                        c[t]++;
                    }
                    cnt += c[0];
                }

    printf("%d", cnt);

//  system("pause");
    return 0;
}
