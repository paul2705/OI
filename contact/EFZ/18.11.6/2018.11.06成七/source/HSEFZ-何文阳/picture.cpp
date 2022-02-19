#include <bits/stdc++.h>

typedef long long int int64;
int64 gcd(int64 a,int64 b)
{
	while(b != 0) {
		int64 c = a % b;
		a = b;
		b = c;
	}
	return a;
}
int64 h1,w1,h2,w2;
int64** cnt1;
int64 gh, gw;
int64 zx, zy;
int64 kx, ky;
int64 scount(int64 x,int64 y)
{
	if(x == 0 || y == 0) return 0;
	return cnt1[x - 1][y - 1];
}
int64 count(int64 x,int64 y)
{
	int64 s1 = scount(x / zx,y / zy);
	int64 s2,s3,s4;
	if(x % zx > 0)
		s2 = scount(x / zx + 1,y / zy) - s1;
	else
		s2 = 0;
	if(y % zy > 0)
		s3 = scount(x / zx,y / zy + 1) - s1;
	else 
		s3 = 0;
	if(x % zx > 0 && y % zy > 0)
		s4 = scount(x / zx + 1,y / zy + 1) - s1 - s2 - s3;
	else
		s4 = 0;
	return s1 * zx * zy + s2 * (x % zx) * zy + s3 * zx * (y % zy) + s4 * (x % zx) * (y % zy);
}
int main()
{
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	scanf("%lld%lld",&h1,&w1);
	cnt1 = new int64*[h1];
	for(int i = 0;i < h1;++i) {
		cnt1[i] = new int64[w1];
		for(int j = 0;j < w1;++j) {
			char c;
			scanf(" %c",&c);
			cnt1[i][j] = c - '0';
		}
		for(int j = 1;j < w1;++j) {
			cnt1[i][j] += cnt1[i][j - 1];
		}
	}
	for(int i = 1;i < h1;++i) {
		for(int j = 0;j < w1;++j) {
			cnt1[i][j] += cnt1[i - 1][j];
		}
	}
	scanf("%lld%lld",&h2,&w2);
	gh = gcd(h1, h2), gw = gcd(w1, w2);
	zx = h2 / gh,zy = w2 / gw;
	kx = h1 / gh,ky = w1 / gw;

	int64 cnt = 0;
	for(int i = 0;i < h2;++i) {
		for(int j = 0;j < w2;++j) {
			char c;
			scanf(" %c",&c);
			int64 x1 = i * kx,x2 = (i + 1) * kx;
			int64 y1 = j * ky,y2 = (j + 1) * ky;
			int64 ans = count(x2,y2) - count(x1,y2) - count(x2,y1) + count(x1,y1);
			if(c == '0') {
				ans = kx * ky - ans;
			}
			cnt += ans;
		}
	}
	printf("%lld\n",cnt);
}
