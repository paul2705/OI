#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=4e5+5;
const int MAXM=MAXN*20;
ll d[MAXN];
ll edge,head[MAXN],nex[MAXM],tail[MAXM];
ll n,m,k,T;
queue<ll> q;
void add(int u,int v){
	if (u<0||v<0) return;
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
ll gcd(ll a,ll b){ return b==0?a:gcd(b,a%b); }
ll lcm(ll a,ll b){ return a*b/gcd(a,b); }
int main(){
	freopen("practice.in","r",stdin);
	freopen("practice.out","w",stdout);
	scanf("%lld",&T);
	while (T--){
		edge=0;
		scanf("%lld%lld%lld",&n,&m,&k);
		ll lm=1,ans=0;
		for (ll i=2;i<=k;i++) lm=lcm(lm,i);
        //cout<<lm<<endl;
		for (ll i=0;i<=lm+1;i++) head[i]=0,d[i]=-1;
        int l=0,r=lm;
		for (ll i=r;i>=l;i--){
			add(i-1,i);
			for (ll j=2;j<=k;j++) add(i-i%j,i);
		}
		d[0]=0; q.push(0);
		while (!q.empty()){
			ll u=q.front(); q.pop();
			for (ll e=head[u];e;e=nex[e]){
				ll v=tail[e];
				if (d[v]>=0) continue;
				d[v]=d[u]+1;
				q.push(v);
			}
		}
        ans=(n/lm-(m/lm+1))*d[lm];
        r=(m/lm+1)*lm,l=m;
        edge=0;
        for (ll i=0;i<=lm+1;i++) head[i]=0,d[i]=-1;
        for (ll i=r;i>=l;i--){
            add(i-1-l,i-l);
            for (ll j=2;j<=k;j++) add(i-i%j-l,i-l);
        }
        d[0]=0; q.push(0);
        while (!q.empty()){
            ll u=q.front(); q.pop();
            for (ll e=head[u];e;e=nex[e]){
                ll v=tail[e];
                if (d[v]>=0) continue;
                d[v]=d[u]+1;
                q.push(v);
            }
        }
        ans+=d[r-l];
		r=n,l=(n/lm)*lm;
		edge=0;
		for (ll i=0;i<=lm+1;i++) head[i]=0,d[i]=-1;
        for (ll i=r;i>=l;i--){
            add(i-1-l,i-l);
            for (ll j=2;j<=k;j++) add(i-i%j-l,i-l);
        }
        d[0]=0; q.push(0);
        while (!q.empty()){
            ll u=q.front(); q.pop();
            for (ll e=head[u];e;e=nex[e]){
                ll v=tail[e];
                if (d[v]>=0) continue;
                d[v]=d[u]+1;
                q.push(v);
            }
        }
		ans+=d[r-l];
		//cout<<(n-m)/lm<<" "<<d[lm]<<" "<<(n-m)%lm<<" "<<d[(n-m)%lm]<<endl;
        printf("%lld\n",ans);
	}
	return 0;
}
