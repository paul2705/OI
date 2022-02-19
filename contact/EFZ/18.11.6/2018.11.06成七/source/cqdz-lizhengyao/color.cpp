#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
//#include<iostream>
using namespace std;
inline int read() {
	int a = 0, c = getchar(), w = 1;
	for(; c < '0' || c > '9'; c = getchar()) if(c == '-') w = -1;
	for(; c >= '0' && c <= '9'; c = getchar()) a = a * 10 + c - '0';
	return a * w;
}

const int maxn = 100050;
int n, m;
int a[maxn], b[maxn];
vector<int> G[maxn], F[maxn];
#define foreg(e, g) for(vector<int>::iterator e = g.begin(); e != g.end(); e++)
int q[maxn], head, tail;
int l[maxn], r[maxn], dis[maxn], dpt[maxn], ind[maxn], fa[maxn];
int cl;
int ans[maxn], ansn;

void dfs0(int u, int pa) {
	fa[u] = pa;
	foreg(e, G[u]) {
		int v = *e;
		if(v == pa) continue;
		dpt[v] = dpt[u] + 1;
		dfs0(v, u);
	}
}

void paint(int u, int pa, int col) {
	if(a[u] == col && dis[u] > dis[cl]) cl = u;
	foreg(e, G[u]) {
		int v = *e;
		if(v == pa) continue;
		dis[v] = dis[u] + 1;
		paint(v, u, col);
	}
}

int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	n = read(); m = read();
	for(int i = 0; i < n; i++) {
	    a[i] = read() - 1; 
	    b[a[i]]++;
	    l[i] = r[i] = i;
	}
	for(int i = 0; i < n-1; i++) {
		int from = read() - 1, to = read() - 1;
		G[from].push_back(to);
		G[to].push_back(from);
	}
	dfs0(0, -1);
	memset(l, -1, sizeof(l));
	for(int i = 0; i < n; i++) if(!~l[a[i]]) {
		cl = i; dis[i] = 0;
		paint(i, -1, a[i]);
		int cr = cl; dis[cr] = 0;
		paint(cr, -1, a[i]);
		if(dpt[cl] < dpt[cr]) swap(cl, cr);
		int ocol = a[cl];
		l[ocol] = cl; r[ocol] = cr;
		while(dpt[cl] > dpt[cr]) {
			cl = fa[cl];
			if(a[cl] != ocol) {
//				cout<<a[cl]<<" to "<<ocol<<endl;
				F[a[cl]].push_back(ocol);
				ind[ocol]++;
			}
		}
		while(cl != cr) {
			cl = fa[cl]; cr = fa[cr];
			if(a[cl] != ocol) {
				F[a[cl]].push_back(ocol);
//				cout<<a[cl]<<" to "<<ocol<<endl;
				ind[ocol]++;
			}
			if(a[cr] != ocol) {
				F[a[cr]].push_back(ocol);
//				cout<<a[cr]<<" to "<<ocol<<endl;
				ind[ocol]++;
			}
		}
	}
	for(int i = 0; i < m; i++) if(!ind[i]) q[tail++] = i;
	while(head < tail) {
		int u = q[head++];
		ans[ansn++] = u;
		foreg(e, F[u]) {
			int v = *e;
			ind[v]--;
			if(!ind[v]) q[tail++] = v;
		}
	}
	for(int i = ansn-1; i >= 0; i--) printf("%d %d %d\n", ans[i]+1, l[ans[i]]+1, r[ans[i]]+1);
	return 0;
}
