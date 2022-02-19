#include <bits/stdc++.h>
using namespace std;
#define re register int
#define rep(i,a,b) for(re i=a;i<=b;++i)
#define _ 0
#define pii pair<int,int>
#define fi first
#define se second
template <class T>inline void read(T &x) {
	x=0; int f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	x*=f;
}
#define N 100005

int n, m, c[N], ru[N];
vector<int> d[N], mp[N];
int fa[N], ok[N], vis[N];
queue<int> q;
inline void put(int u) {printf("%d %d %d\n",c[u],ok[c[u]],u);}
void dfs(int u,int f=0) {fa[u]=f;for(int v:d[u])if(v!=f)dfs(v,u);}

void sol() {
	while(!q.empty()) {
		int u=q.front(); q.pop();
		ru[u=fa[u]]--; 
		if(ru[u]==1) {
			q.push(u);
			if(vis[c[u]])	continue;
			if(ok[c[u]])	vis[c[u]]=1,put(u);
			else ok[c[u]]=u;
		}
	}
}

int main() {
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	read(n),read(m);
	rep(i,1,n)	read(c[i]), mp[c[i]].push_back(i);
	int u, v;
	rep(i,2,n) {
		read(u),read(v);
		d[u].push_back(v), d[v].push_back(u);
		ru[u]++, ru[v]++;
	}
	dfs(1);
	rep(i,1,n)if(ru[i]==1) {
		if(ok[c[i]])	vis[c[i]]=1,put(i);
		else ok[c[i]]=i;
		q.push(i);
	}
	sol();
	rep(i,1,m)if(mp[i].size()==1)	printf("%d %d %d\n",i,mp[i][0],mp[i][0]);
	return ~~(0^_^0);
}
