#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=1e6+5;
const int MAXM=MAXN*7;
ll a[15],n,mx=0,w[MAXM];
int edge,head[MAXN],tail[MAXM],nex[MAXM];
ll dist[MAXN];
struct rec{
	ll dis;
	int u;
	bool operator < (const rec& a) const {
		return dis<a.dis;
	}
	bool operator > (const rec& a) const {
		return dis>a.dis;
	}
};
priority_queue<rec,vector<rec>,greater<rec> > q;
void add(int u,int v,ll W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
int main(){
	freopen("sequences.in","r",stdin);
	freopen("sequences.out","w",stdout);
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	if (n==2){
		mx=a[1]*a[2]-a[1]-a[2];
		printf("%lld\n",mx);
		fclose(stdin); fclose(stdout);
		return 0;
	}
	for (int u=0;u<a[1];u++){
		dist[u]=1e17;
		for (int j=2;j<=n;j++){
			ll v=(u+a[j])%a[1];
			add(u,v,a[j]);
		}
	}
	dist[0]=0; q.push((rec){0,0});
	while (!q.empty()){
		rec u=q.top(); q.pop();
		if (u.dis>dist[u.u]) continue;
		for (int e=head[u.u];e;e=nex[e]){
			int v=tail[e];
			if (dist[v]>dist[u.u]+w[e]){
				dist[v]=dist[u.u]+w[e];
				q.push((rec){dist[v],v});
			}
		}
	}
	for (int i=0;i<a[1];i++) mx=max(mx,dist[i]-a[1]);
//	for (int i=0;i<a[1];i++) printf("%lld\n",dist[i]); cout<<endl;
	printf("%lld\n",mx);
	fclose(stdin); fclose(stdout);
	return 0;
}
