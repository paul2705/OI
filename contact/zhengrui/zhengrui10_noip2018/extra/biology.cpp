#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
const ll MAXN=1e3+5;
const ll MAXS=1e6+6;
struct rec{
	ll x,y,val;
};
vector<rec> c[MAXS];
set<ll> s;
ll n,m,a[MAXN][MAXN],b[MAXN][MAXN];
ll f[2][MAXS];
int main(){
//	freopen("biology.in","r",stdin);
	scanf("%lld%lld",&n,&m);
	for (ll i=1;i<=n;i++){
		for (ll j=1;j<=m;j++) scanf("%lld",&a[i][j]);
	}
	for (ll i=1;i<=n;i++){
		for (ll j=1;j<=m;j++){
			scanf("%lld",&b[i][j]);
			s.insert(a[i][j]);
			if (a[i][j]>0){
				c[a[i][j]].push_back((rec){i,j,b[i][j]});
			}
		}
	}
	set<ll>::iterator iit=s.begin(),it=s.begin();
	for (ll i=0;i<c[(*it)].size();i++){
		f[1][i]=c[(*it)][i].val;
	}
	ll cur=1,old=0; it++;
	for (;it!=s.end();it++,iit++){
		swap(cur,old);
//		cout<<(*it)<<endl;
		for (ll i=0;i<c[(*it)].size();i++){
//			cout<<(*it)<<" "<<(*iit)<<endl;
			rec u=c[(*it)][i];
			f[cur][i]=0;
			for (ll j=0;j<c[(*(iit))].size();j++){
//				cout<<(*iit)<<endl;
				rec v=c[(*iit)][j];
				f[cur][i]=max(f[cur][i],f[old][j]+abs(u.x-v.x)+abs(u.y-v.y));
			}
			f[cur][i]+=u.val;
		}
	}
	ll ans=0;
	it--;
	for (ll i=0;i<c[(*it)].size();i++){
		ans=max(ans,f[cur][i]);
	}
	printf("%lld\n",ans);
	return 0;
}
