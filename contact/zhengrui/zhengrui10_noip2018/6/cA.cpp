#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
ll n,m,a[100010],b[100010],treeshuju[100010],ans;
ll min_1_i[100010],max_1_i[100010],min_i_n[100010],max_i_n[100010],sum;
ll lowbit(ll x){
	return x&(-x);
}
void updata(ll x){
	while(x<=m){
		treeshuju[x]++;
		x+=lowbit(x);
	}
}
ll query(ll x){
	ll ans=0;
	while(x){
		ans+=treeshuju[x];
		x-=lowbit(x);
	}
	return ans;
}
int main(){
	cin>>n;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&b[i]);
		a[i]=b[i];
	}
	sort(b+1,b+n+1);
	m=unique(b+1,b+n+1)-(b+1);
	for(ll i=1;i<=n;i++)
		a[i]=lower_bound(b+1,b+m+1,a[i])-b;
	memset(treeshuju,0,sizeof(treeshuju));
	for(ll i=1;i<=n;i++){
		min_1_i[i]=query(a[i]-1);
		max_1_i[i]=query(m)-query(a[i]);
		updata(a[i]);
	}
	for(ll i=1;i<=n;i++)
		sum+=min_1_i[i];
	memset(treeshuju,0,sizeof(treeshuju));
	for(ll i=n;i;i--){
		min_i_n[i]=query(a[i]-1);
		max_i_n[i]=query(m)-query(a[i]);
		updata(a[i]);
	}
	for(ll i=1;i<=n;i++){
		ans=(ans+max_1_i[i]*sum-min_i_n[i]*max_i_n[i]-max_1_i[i]*max_i_n[i]-min_1_i[i]*min_i_n[i]-max_1_i[i]*min_1_i[i]);
	}
	cout<<ans;
	return 0;
}
