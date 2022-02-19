

int dp[MAXN] ;
int g[MAXN] ; 

// dp[i] = max (g[j] = 0 + w(i,j))

// k[i]是dp[i]的最优决策点, k[i] <= k[i+1]

void solve(int l, int r, int pl, int pr) { 

	int mid = (l + r) >> 1 ;
	int best = 0 ;  
	for (int j = pl; j <= pr; j ++) {
		......// g[j] + w(mid ,j)
	}
	solve(l, mid - 1, pl, best) ; 
	solve(mid + 1, r, best, pr) ; 
}

int main() {
	solve(1, n, 1, n)
}