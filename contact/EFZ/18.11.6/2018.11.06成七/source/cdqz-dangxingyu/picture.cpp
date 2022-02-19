#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+c-'0';c=getchar();}
	return x*f;
}

const int maxn = 1e6 + 10;
#define idx1(x, y) (((x) - 1) * w1 + (y))
#define idx2(x, y) (((x) - 1) * w2 + (y))
ll H, W, h1, w1, h2, w2, lenh1, lenw1, lenh2, lenw2;
//sumh -> 行 sumh[i][j - 1] -> sumh[i][j], sumw -> 列 sumw[i - 1][j] -> sumw[i][j]
vector< vector<int> > g1, g2, sumw, sumh; char buf[maxn];
inline int query(int pos, int l, int r, int opt, int dir) // dir : 0 列, 1 行 
{
	if(dir)
	{
		if(opt)
			return sumh[pos][r] - sumh[pos][l - 1];
		else return r - l + 1 - (sumh[pos][r] - sumh[pos][l - 1]);
	}
	else
	{
		if(opt)
			return sumw[r][pos] - sumw[l - 1][pos];
		else return r - l + 1 - (sumw[r][pos] - sumw[l - 1][pos]);
	}
}
inline ll get_sum(int pos, int l, int r, int up, int down, int opt)
{
	int len = down - up + 1;
	return (ll)len * query(pos, l, r, opt, 1) * lenw2;
}
int main()
{
	freopen("picture.in", "r", stdin);
	freopen("picture.out", "w", stdout);
	h1 = read(), w1 = read();
	g1.resize(h1 + 2);
	for(int i = 0; i <= h1; i ++)
		g1[i].resize(w1 + 2);
	scanf("%s", buf + 1);
	for(int i = 1; i <= h1; i ++)
		for(int j = 1; j <= w1; j ++)
			g1[i][j] = buf[idx1(i, j)] == '1';
	h2 = read(), w2 = read();
	g2.resize(h2 + 2);
	for(int i = 0; i <= h2; i ++)
		g2[i].resize(w2 + 2);
	scanf("%s", buf + 1);
	for(int i = 1; i <= h2; i ++)
		for(int j = 1; j <= w2; j ++)
			g2[i][j] = buf[idx2(i, j)] == '1';
	H = (ll)h1 / __gcd(h1, h2) * h2;
	W = (ll)w1 / __gcd(w1, w2) * w2;
	lenh1 = H / h1, lenw1 = W / w1;
	lenh2 = H / h2, lenw2 = W / w2;
	if(lenh1 > lenh2)
	{
		swap(lenh1, lenh2);
		swap(lenw1, lenw2);
		swap(h1, h2);
		swap(w1, w2);
		swap(g1, g2);
	}
	sumw.resize(h2 + 2);
	sumh.resize(h2 + 2);
	for(int i = 0; i <= h2; i ++)
		sumw[i].resize(w2 + 2), sumh[i].resize(w2 + 2);
	for(int i = 1; i <= h2; i ++)
		for(int j = 1; j <= w2; j ++)
		{
			int col = g2[i][j];
			sumw[i][j] = sumw[i - 1][j] + col;
			sumh[i][j] = sumh[i][j - 1] + col;
		}
	ll ans = 0;
	for(int i = 1; i <= h1; i ++)
		for(int j = 1; j <= w1; j ++)
		{
			ll sh = (ll)(i - 1) * lenh1 + 1, sw = (ll)(j - 1) * lenw1 + 1;
			ll th = (ll)i * lenh1, tw = (ll)j * lenw1, col = g1[i][j];
			ll lh = sh / lenh2 + (sh % lenh2 > 0), rh = th / lenh2 + (th % lenh2 > 0);
			ll lw = sw / lenw2 + (sw % lenw2 > 0), rw = tw / lenw2 + (tw % lenw2 > 0);
			if(rw > lw + 1)
			{
				if(lh == rh)
					ans += get_sum(lh, lw + 1, rw - 1, sh, th, col);
				else ans += get_sum(lh, lw + 1, rw - 1, sh, lh * lenh2, col) + get_sum(rh, lw + 1, rw - 1, lh * lenh2 + 1, th, col);
			}
			if(g2[lh][lw] == col)
				ans += (ll)(min(th, lh * lenh2) - sh + 1) * (min(lw * lenw2, tw) - sw + 1);
			if(rh > lh && g2[rh][lw] == col)
				ans += (ll)(th - (rh - 1) * lenh2) * (min(tw, lw * lenw2) - sw + 1);
			if(rw > lw && g2[lh][rw] == col)
				ans += (ll)(min(th, lh * lenh2) - sh + 1) * (tw - (rw - 1) * lenw2);
			if(rw > lw && rh > lh && g2[rh][rw] == col)
				ans += (ll)(th - (rh - 1) * lenh2) * (tw - (rw - 1) * lenw2);
		}
	printf("%lld\n", ans);
	return 0;
}
