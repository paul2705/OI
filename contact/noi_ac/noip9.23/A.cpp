#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define x first
#define y second
#define x1 X1 
#define x2 X2
#define y1 Y1
#define y2 Y2
#define mp make_pair
#define pb push_back
#define read() Read<int>()

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

template <typename T> inline int Chkmax (T &a, T b) { return a < b ? a = b, 1 : 0; }
template <typename T> inline int Chkmin (T &a, T b) { return a > b ? a = b, 1 : 0; }
const int Maxn = 1e5 + 100;

int N, M;
int Min[4][Maxn << 1], Max[4][Maxn << 1];
pii A[Maxn];
int ans[10];
int main(){
	scanf("%d%d",&N,&M);
	memset(Min, 0x3f, sizeof Min);
	for (int i = 1,x,y; i <= M; ++i)
	{
		scanf("%d%d",&x,&y);
		A[i].x = x, A[i].y = y;
		Chkmin(Min[0][x], y); Chkmin(Min[1][y], x);
		Chkmin(Min[2][x - y + Maxn], x); Chkmin(Min[3][x + y], x);
		Chkmax(Max[0][x], y); Chkmax(Max[1][y], x);
		Chkmax(Max[2][x - y + Maxn], x); Chkmax(Max[3][x + y], x);
	}
	for (int i = 1; i <= M; ++i)
	{
		int sum = 0, x = A[i].x, y = A[i].y;
		sum += (Min[0][x] < y); sum += (Min[1][y] < x);
		sum += (Min[2][x - y + Maxn] < x); sum += (Min[3][x + y] < x);
		sum += (Max[0][x] > y); sum += (Max[1][y] > x);
		sum += (Max[2][x - y + Maxn] > x); sum += (Max[3][x + y] > x);
		ans[sum]++;
	}
	for (int i = 0; i <= 8; ++i) printf("%d ", ans[i]);
	puts("");
	return 0;
}
