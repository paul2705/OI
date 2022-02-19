#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<functional>
#include<algorithm>
using namespace std;
const int maxn = 20005;
int  n;
double a[maxn], c;
 
double dfs(int now, double s, int flag)
{
    if (now > n) return s;
    double sum = max(s, a[now] * dfs(now + 1, s * 2, flag)), res = 0;
    if (s > c && flag)
    {
        res += a[now] * dfs(now + 1, (s - c) * 2, 0);
        res += (1 - a[now]) * dfs(now + 1, s - c, 0);
    }
    return max(sum, res);
}
 
int main()
{
//    while (~scanf("%d%lf", &n, &c))
  //  {
	scanf("%d%lf",&n,&c);
	for (int i = 1; i <= n; i++) 
            scanf("%lf", &a[i]), a[i] /= 100;
        printf("%.9lf\n", dfs(1, 100, 1));
//    }
    return 0;
}
