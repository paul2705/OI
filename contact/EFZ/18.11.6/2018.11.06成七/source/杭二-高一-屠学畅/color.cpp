#include<cstdio>
#include<algorithm>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<vector>

using namespace std;
#define ll long long

inline char read() {
	static const int IN_LEN = 1000000;
	static char buf[IN_LEN], *s, *t;
	return (s==t?t=(s=buf)+fread(buf,1,IN_LEN,stdin),(s==t?-1:*s++):*s++);
}
template<class T>
inline void read(T &x) {
	static bool iosig;
	static char c;
	for (iosig=false, c=read(); !isdigit(c); c=read()) {
		if (c == '-') iosig=true;
		if (c == -1) return;
	}
	for (x=0; isdigit(c); c=read()) x=((x+(x<<2))<<1)+(c^'0');
	if (iosig) x=-x;
}
const int OUT_LEN = 10000000;
char obuf[OUT_LEN], *ooh=obuf;
inline void print(char c) {
	if (ooh==obuf+OUT_LEN) fwrite(obuf, 1, OUT_LEN, stdout), ooh=obuf;
	*ooh++=c;
}
template<class T>
inline void print(T x) {
	static int buf[30], cnt;
	if (x==0) print('0');
	else {
		if (x<0) print('-'), x=-x;
		for (cnt=0; x; x/=10) buf[++cnt]=x%10+48;
		while(cnt) print((char)buf[cnt--]);
	}
}
inline void flush() { fwrite(obuf, 1, ooh - obuf, stdout); }

const int N = 100005;
int num, n, m, cnt, A[N], B[N], d[N], q[N], dfn[N], fa[N], last[N], dep[N], p[N], h[N], e[N<<1], pre[N<<1];
vector<int> f[N], c[N];
inline void add(int x, int y){ e[++num]=y, pre[num]=h[x], h[x]=num;}
void dfs(int u){
	dfn[u]=++cnt;
	for(int i=h[u]; i; i=pre[i]) if(e[i]!=fa[u])
		fa[e[i]]=u, dep[e[i]]=dep[u]+1, dfs(e[i]);
	last[u]=cnt;
}
int main() {
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	read(n), read(m);
	for(int i=1; i<=n; ++i) read(p[i]), c[p[i]].push_back(i);
	for(int i=1; i<n; ++i){
		static int x, y;
		read(x), read(y), add(x, y), add(y, x);
	}
	dep[1]=1, dfs(1);
	for(int i=1; i<=m; ++i){
		int u=0;
		for(auto j:c[i]) if(dep[j]>dep[u]) u=j;
		if(!u) print(i), print(' '), print(1), print(' '), print(1), print('\n');
		else{
			int v=0;
			for(auto j:c[i]) if(dfn[j]>dfn[u] || last[j]<dfn[u])
				if(dep[j]>dep[v]) v=j;
			if(!v){
				v=u;
				for(auto j:c[i]) if(dep[j]<dep[v]) v=j;
			}
			A[i]=u, B[i]=v;

			while(dep[u]>dep[v]){
				u=fa[u];
				if(p[u]!=i) f[i].push_back(p[u]), ++d[p[u]];
			}
			while(u!=v){
				u=fa[u];
				if(p[u]!=i) f[i].push_back(p[u]), ++d[p[u]];
				v=fa[v];
				if(p[v]!=i) f[i].push_back(p[v]), ++d[p[v]];
			}
		}
	}
	int l=0, r=0;
	for(int i=1; i<=m; ++i) if(!d[i] && A[i]) q[++r]=i;
	while(l<r){
		int u=q[++l];
		for(int i:f[u]) if(!--d[i]) q[++r]=i;
	}
	for(int i=1; i<=r; ++i) print(q[i]), print(' '), print(A[q[i]]), print(' '), print(B[q[i]]), print('\n');
	return flush(), 0;
}
