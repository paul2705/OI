#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
using ll = long long;
using ii = pair<int, int>;
using pll = pair<ll, ll>;
using uid = uniform_int_distribution<int>;
 
using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
using ordered_multiset = tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define X first
#define Y second
 
void boost() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
}
 
int n;
ll s1, s2;
int x[2507], y[2507];
int origin;
 
bool lt(const ii &a, const ii &b) {
	return (ll)a.X * b.Y - (ll)a.Y * b.X > 0;
}
 
bool comp(const ii &a, const ii &b) {
	if(a.Y < 0 && b.Y > 0)
		return false;
	if(b.Y < 0 && a.Y > 0)
		return true;
		
	return lt(a, b);
}
 
void solve() {
	scanf("%d", &n);
	for(int i = 1 ; i <= n ; i++)
		scanf("%d%d", &x[i], &y[i]);
		
	s1 = (ll)n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 2 / 3 / 4 / 5;
		
	for(origin = 1 ; origin <= n ; origin++) {
		vector<ii> P;
		for(int i = 0 ; i < n ; i++)
			if(i != origin - 1)
				P.push_back({x[i + 1] - x[origin], y[i + 1] - y[origin]});
		
		sort(P.begin(), P.end(), comp);
		
		int j = 0;
		for(int i = 0 ; i < P.size() ; i++) {
			j = max(j, i);
			while(lt(P[i], P[(j + 1) % P.size()]))
				j++;
			ll cnt = j - i;
			s2 += cnt * (cnt - 1) * (cnt - 2) / 2 / 3;
		}
	}
	
	printf("%lld\n", s1 * 5 - s2);
}
 
int main() {
	int t = 1;
	//~ scanf("%d", &t);
	while(t--) {
		solve();
	}
	return 0;
}
 
