#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN=6e5+5;
ll t[MAXN],n,m,qq,mx;
ll pre[MAXN],qx[MAXN],qy[MAXN];
struct rec{
	ll pos,id;
};
vector<ll> num[MAXN];
vector<rec> q[MAXN];
void add(ll x,ll val){
	for (;x<=mx;x+=x&-x) t[x]+=val;
}
ll sum(ll x){
	ll ret=0;
	for (;x>0;x-=x&-x) ret+=t[x];
	return ret;
}
ll qry(ll x){
	ll l=0,r=mx,mid;
	while (l+1<r){
		mid=(l+r)>>1;
		if (sum(mid)<x) l=mid;
		else r=mid;
	}
	return r;
}
int main(){
	scanf("%lld%lld%lld",&n,&m,&qq);
	mx=max(mx,max(n,m))+qq;
	for (int i=1;i<=qq;i++){
		scanf("%lld%lld",&qx[i],&qy[i]);
		if (qy[i]!=m) q[qx[i]].push_back((rec){qy[i],i});
	}
	for (int i=1;i<=mx;i++) add(i,1);
	for (int i=1;i<=n;i++){
		for (int j=0;j<q[i].size();j++){
			rec u=q[i][j];
			ll kth=qry(u.pos);
			pre[u.id]=kth;
			add(kth,-1);
		}
		for (int j=0;j<q[i].size();j++){
			rec u=q[i][j];
			add(pre[u.id],1);
		}
	}
//	cout<<sum(2)<<endl;
	for (int i=1;i<=qq;i++){
		ll kth=qry(qx[i]),ans=0;
		if (kth<=n) ans=kth*m;
		else ans=num[0][kth-n-1];
		add(kth,-1);
//		cout<<kth<<" "<<ans<<endl;
		if (qy[i]!=m){
			num[qx[i]].push_back(ans);
			if (pre[i]<m) ans=(qx[i]-1)*m+pre[i];
			else ans=num[qx[i]][pre[i]-m];
		}
		num[0].push_back(ans);
		printf("%lld\n",ans);
	}
	return 0;
}
