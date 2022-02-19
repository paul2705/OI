#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=2e5+5;
typedef long long ll;
struct rec{
	ll las,id,nex,len;
	bool operator < (const rec& b) const {
		return len>b.len;
	}
	bool operator > (const rec& b) const {
		return len<b.len;
	}
};
priority_queue<rec> q;
ll n,k,ans=0,a[MAXN];
ll l[MAXN],r[MAXN],dat[MAXN];
bool use[MAXN];
int main(){
	scanf("%lld%lld",&n,&k);
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		l[i]=i-1; r[i]=i+1; dat[i]=a[i]-a[i-1];
//		cout<<i<<" "<<dat[i]<<endl;
		if (i!=1) q.push((rec){i-1,i,i+1,a[i]-a[i-1]});
	}
	ll cnt=n+1;
	dat[1]=dat[n+1]=1e9;
//	cout<<"in"<<endl;
	while (cnt<=n+k){
		rec u=q.top(); q.pop();
		if (use[u.id]) continue;
		ans+=u.len;
//		cout<<dat[u.id]<<" "<<u.id<<endl;
		ll las=l[u.id],nex=r[u.id],id=++cnt; 
		use[las]=use[nex]=use[u.id]=1;
		r[l[las]]=id; l[r[nex]]=id;
		l[id]=l[las]; r[id]=r[nex];
		ll del=dat[las]+dat[nex]-dat[u.id];
		dat[id]=del;
//		cout<<"add: "<<del<<" "<<id<<endl;
		q.push((rec){l[las],id,r[nex],del});
	}
	printf("%lld\n",ans);
	return 0;
}
