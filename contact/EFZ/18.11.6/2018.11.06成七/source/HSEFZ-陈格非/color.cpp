#include <cstdio>
#include <algorithm>
const int maxn = 1e5+10, maxm = 2e5+10;
int tot,cnt[maxm],tmp,depth[maxn],p[maxn],x,y,rt,n,m,ans[maxm][3],last[maxm];
int degree[maxn],head[maxn],to[2*maxn],next[2*maxn],vis[maxm],num[maxn];
void dfs(int u,int f) {
	/*if(p[u]!=p[f]) num[p[u]++];*/
	last[p[u]]=u;
	for (int i=head[u]; i; i=next[i]) {
		if (to[u] == f) continue;
		dfs(to[i],u);
	}
}
bool ok(int u,int f,int c) {
	if (p[u]==c && !--tmp) return 1;
	bool res = 0;
	for (int i=head[u]; i; i=next[i]) {
		if (to[u] == f) continue;
		if (!p[to[i]] || p[to[i]] == c) res|=ok(to[i],u,c);
	}
	return res;
}
void con(int u,int v) {
	++degree[u];
	to[++tot] = v;
	next[tot] = head[u];
	head[u] = tot;
}
void del(int u,int f,int c) {
	if(p[u]) last[c] = u, p[u] = 0;
	for (int i=head[u]; i; i=next[i]) {
		if (to[i] == f) continue;
		if (!p[to[i]] || p[to[i]] == c) del(to[i],u,c);
	}
}
void print() {
	for (int i=1;i<=n;i++)
		printf("%d ",p[i]);
	puts("");
}
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; ++i) {
		scanf("%d",p+i);
		cnt[p[i]]++;
	}
	for (int i=1; i<n; ++i) {
		scanf("%d%d",&x,&y);
		con(x,y);
		con(y,x);
	}
	for (rt=1; rt<=n && degree[rt]!=1; ++rt);
	dfs(rt,0);
	for (int i=1,j; i<=m; ++i) {
		for (j=1; j<=m; ++j) {
			tmp = cnt[j];
			if (!vis[j] && ok(last[j],0,j)) {
				vis[j] = 1;
				ans[m-i][0] = j;
				ans[m-i][1] = last[j];
				del(last[j],0,j);
				ans[m-i][2] = last[j];
//				print();
				break;
			}
		}
	}
	for (int i=0; i<m; ++i) {
		printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
	}
}
