#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
typedef unsigned uint;
const int N = 3e5 + 10;
int n, q, fa[N], son[N], pos[N], top[N], idx;
vector<int> G[N];
uint val[N], sz[N], sum[N], f[N], cnt[N], cnt2[N], a[N], tg[N];
void dfs(int u) {
	sz[u] = 1; sum[u] = f[u] = val[u];
	for(int v=0;v<G[u].size();v++) {
		dfs(v); sz[u] += sz[v]; sum[u] += sum[v];
		f[u] -= sum[v] * sz[v]; a[u] -= sz[v] * (cnt2[v] + 1);
		if(sz[v] > sz[son[u]]) son[u] = v;
	}
	f[u] += sum[u] * sz[u]; a[u] += (cnt[u] + 1) * sz[u] + 1;
}
void dfs2(int u, int t) {
	top[u] = t; pos[u] = ++ idx;
	if(!son[u]) return ;
	dfs2(son[u], t);
	for(int v=0;v<G[u].size();v++) if(!pos[v]) dfs2(v, v);
}
uint tag[N << 2];
void pushd(int u) {
	if(tag[u]) {
		tag[u << 1] += tag[u];
		tag[u << 1 | 1] += tag[u];
		tag[u] = 0;
	}
}
void modify(int u, int l, int r, int ql, int qr, uint v) {
	if(l == ql && r == qr) { tag[u] += v; return ; }
	int mid = (l + r) >> 1; pushd(u);
	if(qr <= mid) modify(u << 1, l, mid, ql, qr, v);
	else if(ql > mid) modify(u << 1 | 1, mid + 1, r, ql, qr, v);
	else {
		modify(u << 1, l, mid, ql, mid, v);
		modify(u << 1 | 1, mid + 1, r, mid + 1, qr, v);
	}
}
uint query(int u, int l, int r, int v) {
	if(l == r) return tag[u];
	int mid = (l + r) >> 1; pushd(u);
	if(v <= mid) return query(u << 1, l, mid, v);
	return query(u << 1 | 1, mid + 1, r, v);
}
void add(int u, uint v) {
	int x = u; tg[u] += v; v *= cnt[u] + 1;
	while(x) {
		int t = top[x];
		if(x != t) modify(1, 1, n, pos[t], pos[x] - 1, v);
		x = fa[t];
		if(x) f[x] += v * (sz[x] - sz[t]);
	}
}
uint query(int u) {
	uint ans = f[u] + tg[u] * a[u];
	if(son[u]) ans += query(1, 1, n, pos[u]) * (sz[u] - sz[son[u]]);
	if(fa[u]) ans += tg[fa[u]] * (cnt2[u] * sz[u] + 2);
	if(fa[fa[u]]) ans += tg[fa[fa[u]]] * (sz[u] + 1);
	return ans;
}
int main() {
	scanf("%d%d", &n, &q);
	for(int i = 2; i <= n; i ++) {
		scanf("%d", fa + i);
		G[fa[i]].push_back(i);
	}
	for(int i = 1; i <= n; i ++) scanf("%u", val + i);
	for(int i = 1; i <= n; i ++) {
		cnt[fa[i]] ++; cnt[fa[fa[i]]] ++; cnt2[fa[i]] ++;
	}
	int op, u; uint v; dfs(1); dfs2(1, 1);
	for(int i = 1; i <= q; i ++) {
		scanf("%d%d", &op, &u);
		if(op == 1) { scanf("%u", &v); add(u, v); }
		if(op == 2) printf("%u\n", query(u));
	}
	return 0;
}
