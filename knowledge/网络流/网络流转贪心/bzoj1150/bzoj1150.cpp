#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=2e5+5;
typedef long long ll;
struct rec{
	ll id,val;
	bool operator < (const rec& b) const {
		return val>b.val;
	}
	bool operator > (const rec& b) const {
		return val<b.val;
	}
};
ll n,k,ans,l[MAXN],r[MAXN],dat[MAXN];
ll a[MAXN],b[MAXN];
bool use[MAXN];
priority_queue<rec> q;
int main(){
	scanf("%lld%lld",&n,&k);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<n;i++) b[i]=a[i+1]-a[i];
	n--;
	for (int i=1;i<=n;i++){
		l[i]=i-1; r[i]=i+1; dat[i]=b[i];
		q.push((rec){i,b[i]});
	}
	ll cnt=n+1;
	dat[0]=dat[n+1]=1e9;
	while (cnt<=n+k){
		rec u=q.top(); q.pop();
		if (use[u.id]) continue;
//		cout<<u.id<<" "<<u.val<<endl;
		ans+=u.val;
		ll las=l[u.id],nex=r[u.id],id=++cnt;
		use[las]=use[nex]=use[u.id]=1;
		r[l[las]]=id; l[r[nex]]=id;
		l[id]=l[las]; r[id]=r[nex];
		ll del=dat[las]+dat[nex]-u.val;
		dat[id]=del;
//		if (las==0||nex==n+1) del=1e9;
//		cout<<id<<" "<<del<<endl;
		q.push((rec){id,del});
	}
	printf("%lld\n",ans);
	return 0;
}
