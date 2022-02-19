#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=1e6+5;
const int MAXM=MAXN*20;
ll edge,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
ll T,n,m,k,d[MAXN];
queue<ll> q;
void add(ll u,ll v,ll W){
//	cout<<u<<" "<<v<<endl;
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
int main(){
	freopen("practice.in","r",stdin);
	freopen("practice1.out","w",stdout);
	scanf("%lld",&T);
	while (T--){
		memset(head,0,sizeof(head)); edge=0;	
		scanf("%lld%lld%lld",&n,&m,&k);
		for (ll i=n;i>=m;i--){
			add(i-1,i,1);
			for (ll j=2;j<=k;j++) add(i-i%j,i,1);
		}
		memset(d,-1,sizeof(d)); d[m]=0;
		q.push(m);
		while (!q.empty()){
			ll u=q.front(); q.pop();
			for (ll e=head[u];e;e=nex[e]){
				ll v=tail[e];
				if (d[v]>=0) continue;
				d[v]=d[u]+1;
				q.push(v);
			}
		}
//		for (int i=m;i<=n;i++) cout<<d[i]<<" "; cout<<endl;
//		int cnt=1;
//		for (int i=m+1;i<=n;i++){
//			if (d[i]==d[i-1]) cnt++;
//			else printf("%d ",cnt),cnt=0;
//		}
		printf("%lld\n",d[n]);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
