#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const ll MAXN=2e5+5;
const ll inf=1e18;
vector<ll> linker[MAXN],via[MAXN];
ll c[MAXN],vis[MAXN],d[MAXN],m,n,k,s,p,qq,x,y,i,inq[MAXN];
void add(ll u,ll v,ll w){
	linker[u].push_back(v);
	via[u].push_back(w);
}
void bfs(){
	queue<ll> q;
	for (ll i=1;i<=n*2;i++) d[i]=0;
	for (ll i=1;i<=k;i++){ q.push(c[i]); vis[c[i]]=1; d[c[i]]=0; add(c[i],c[i]+n,inf); }
	while (!q.empty()){
		ll e=q.front(); q.pop();
		if (d[e]==s) return;
		for (ll i=0;i<linker[e+n].size();i++){
			if (!vis[linker[e+n][i]]){
				d[linker[e+n][i]]=d[e]+1;
				q.push(linker[e+n][i]);
				add(linker[e+n][i],linker[e+n][i]+n,qq);
				vis[linker[e+n][i]]=1;
			}
		}
	}
}
void xpfa(){
	queue<ll> q;
	for (ll i=1;i<=n*2;i++) d[i]=inf;
	d[1+n]=0;inq[1+n]=1;q.push(1+n);
	while (!q.empty()){
		int u=q.front();q.pop();inq[u]=0;
		for (int i=0;i<linker[u].size();i++){
			int v=linker[u][i],w=via[u][i];
			if (d[v]>d[u]+w){
				d[v]=d[u]+w;
				if (!inq[v]){inq[v]=1;q.push(v);}
			}
		}
	}
	printf("%lld\n",d[n]);
}
int main(){
	scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&k,&s,&p,&qq);
	for (int i=1;i<=k;i++) scanf("%lld",&c[i]);
	for (int i=1;i<=m;i++){
		scanf("%lld%lld",&x,&y);
		add(x+n,y,0); add(y+n,x,0);
	}
	bfs();
	for (int i=2;i<=n-1;i++) if (!vis[i]) add(i,i+n,p);
	xpfa();
	return 0;
}
