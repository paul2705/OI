#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=1010;
int n,m,c[maxn],tot,fa[maxn][20],dep[maxn];
int head[maxn],nxt[maxn],to[maxn],l[maxn];
int vis[maxn],a[maxn],b[maxn],t2,in[maxn];
int head2[maxn],nxt2[maxn],to2[maxn];
queue<int> q;
void add(int u,int v) {
	tot++; to[tot]=v;
	nxt[tot]=head[u];
	head[u]=tot;
}
void add2(int u,int v) {
	t2++; to2[t2]=v;
	nxt2[t2]=head2[u];
	head2[u]=t2;
	in[v]++;
}
int dfs(int u,int p) {
	fa[u][0]=p;
	dep[u]=dep[p]+1;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		if (v!=p)
			dfs(v,u);
	}
}
int lca(int x,int y) {
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=18;i>=0;i--)
		if (dep[fa[x][i]]>=dep[y])
			x=fa[x][i];
	for (int i=18;i>=0;i--)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	if (x==y) return x;
	return fa[x][0];
}
int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	read(n); read(m);
	for (int i=1;i<=n;i++) read(c[i]);
	for (int i=1,x,y;i<n;i++) {
		read(x); read(y);
		add(x,y); add(y,x);
	}
	dfs(1,0);
	for (int j=1;j<=18;j++)
		for (int i=1;i<=n;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
	for (int i=1;i<=n;i++) {
		if (!l[c[i]]) l[c[i]]=i;
		else l[c[i]]=lca(l[c[i]],i);
	}
	int flag;
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		if (c[i]==c[j]&&lca(i,j)==l[c[i]]) {
			memset(vis,0,sizeof(vis));
			vis[l[c[i]]]=1;
			for (int x=i;x!=l[c[i]];x=fa[x][0])
				vis[x]=1;
			for (int x=j;x!=l[c[i]];x=fa[x][0])
				vis[x]=1;
			flag=1;
			for (int k=1;k<=n;k++)
				if (c[i]==c[k]&&!vis[k]) {
					flag=0; break;
				}
			if (flag) {
				a[c[i]]=i; b[c[i]]=j;
			}
		}
	for (int k=1;k<=m;k++) {
		if (c[l[k]]!=k) add2(k,c[l[k]]);
		for (int x=a[k];x!=l[k];x=fa[x][0])
			if (k!=c[x]) add2(k,c[x]);
		for (int x=b[k];x!=l[k];x=fa[x][0])
			if (k!=c[x]) add2(k,c[x]);
	}
	for (int i=1;i<=m;i++)
		if (in[i]==0) q.push(i);
	while (!q.empty()) {
		int u=q.front(); q.pop();
		printf("%d %d %d\n",u,a[u],b[u]);
		for (int i=head2[u],v;i;i=nxt2[i]) {
			v=to2[i];
			in[v]--;
			if (in[v]==0) q.push(v);
		}
	}
	return 0;
}
