#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
struct node{
	ll p, e;
	node(ll a = 0, ll b = 0){p = a, e = b;}
	node operator + (node b){return node(p + b.p, e + b.e);}
	node operator * (node b){return node(p * b.p, e * b.p + p * b.e);}
}val, ans, f[2][2][2][2][2];
ll a[100], b[100];
ll n, m, k, t;
int tot;
node Calc(ll *a, ll m){
	memset(f, 0, sizeof(f));
	ll now = 0; 
	node ans(0, 0);
	f[0][0][0][0][0] = node(1, 0);
	f[0][0][1][0][0] = node(1, 1);
	for (ll l = 0, r = m - 1; l < r; l++, r--) {
		memset(f[now ^ 1], 0, sizeof(f[now ^ 1]));
		for (ll lj = 0; lj <= 1; lj++)
			for (ll hj = 0; hj <= 1; hj++)
				for (ll lg = 0; lg <= 1; lg++)
					for (ll hl = 0; hl <= 1; hl++){
						if (!f[now][lj][hj][lg][hl].p)
							continue;
						val = f[now][lj][hj][lg][hl];
						for (ll vl = 0; vl <= 1; vl++)
							for (ll vr = 0; vr <= 1; vr++) {
								if (r == m - 1 && !vr)
									continue;
								ll _lg = ((lg & (vl == a[l])) | (vl > a[l]));
								ll _hl = (hl | (vr < a[r]));
								if ((!hl) && (vr > a[r]))
									continue;
								for (ll nd = 0; nd <= 1; nd++){
									if ((vl + vr + nd >= 2) != hj)
										continue;
									ll ee = ((vl + vr + nd) & 1) + ((vl + vr + lj) & 1);
									f[now ^ 1][(vl + vr + lj) >= 2][nd][_lg][_hl] = f[now ^ 1][(vl + vr + lj) >= 2][nd][_lg][_hl] + val * node(1, ee);
								}
							}
					}
		now ^= 1;
	} 
	if ((m & 1)) {
		for (ll s = 0; s <= 1; s++){
			for (ll lj = 0; lj <= 1; lj++)
				for (ll hj = 0; hj <= 1; hj++)
					for (ll lg = 0; lg <= 1; lg++)
						for (ll hl = 0; hl <= 1; hl++){
							if (!f[now][lj][hj][lg][hl].p)
								continue;
							ll _hl = (hl | (s < a[m / 2]));
							if ((!hl) && (s > a[m / 2]))
								continue;
							if ((!_hl) && (lg))
								continue;
							if (s != hj)
								continue;
							ll ee = ((s + s + lj) & 1);
							ans = ans + node(1, ee) * f[now][lj][hj][lg][hl];
						}
		}
	}
	else{
		for (ll lj = 0; lj <= 1; lj++)
			for (ll hj = 0; hj <= 1; hj++)
				for (ll lg = 0; lg <= 1; lg++)
					for (ll hl = 0; hl <= 1; hl++){
						if (!f[now][lj][hj][lg][hl].p)
							continue;
						if ((!hl) & lg)
							continue;
						if (lj != hj)
							continue;
						ans = ans + f[now][lj][hj][lg][hl];
						
					}
	}
	return ans;
}
int main(){
	scanf("%lld", &n);
	while (n){
		a[tot++] = (n & 1);
		n >>= 1;
	}
	for (int i = 0; i < 80; i++)
		b[i] = 1;
	for (int i = 1; i < tot; i++)
		ans = ans + Calc(b, i);
	ans = ans + Calc(a, tot);
	printf("%lld\n", ans.e);
}
