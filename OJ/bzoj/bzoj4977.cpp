#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const ll MAXN=1e6+5;
struct rec{
	ll x,y,tp;
} a[MAXN];
ll n,m,s,lis[MAXN],cnt=0,las=0;
priority_queue<ll> q;
priority_queue<ll,vector<ll>,greater<ll> > p;
bool cmp(rec a,rec b){
	return a.x==b.x?a.tp<b.tp:a.x<b.x;
}
int main(){
	freopen("bzoj4977.in","r",stdin);
	freopen("bzoj4977.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (ll i=1;i<=n;i++) scanf("%lld",&a[i].x),a[i].tp=0;
	for (ll i=1;i<=m;i++){
		scanf("%lld%lld",&a[n+i].x,&a[n+i].y);
		a[n+i].y-=a[n+i].x; a[n+i].tp=1;
	}
	sort(a+1,a+n+m+1,cmp);
	for (ll i=1;i<=n+m;i++){
		if (a[i].tp==1) q.push(a[i].y);
		else {
			if (q.empty()){
				if (las>=cnt) continue;
				ll x=lis[++las];
				s+=a[i].x-a[x].x;
				lis[cnt++]=i;
			}
			else {
				ll x=q.top(); q.pop();
				s+=a[i].x+x;
				cout<<i<<" "<<x<<endl;
				lis[cnt++]=i;
				p.push(x);
			}
		}
	}
	ll ans=s;
	cout<<endl;
	for (ll i=las;i<cnt;i++){
		s-=a[lis[i]].x+p.top();
		cout<<a[lis[i]].x<<endl;
		p.pop();
		ans=max(ans,s);
	}
	printf("%lld\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
