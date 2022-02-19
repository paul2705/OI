#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int MAXN=1e5+5;
ll pri[MAXN];
bool use[MAXN];
ll lis[MAXN],cnt;
ll x,n,ans=1;
void dfs(int d,ll res){
//	cout<<d<<endl;
	if (d==cnt+1){
		if (res>n) return;
		cout<<res<<endl;
		ll tmp=n/res;
		res%=mod;
		ans=ans*res%mod;
		return;
	}
	for (ll ret=1;res*ret<=n;ret*=lis[d]) dfs(d+1,res*ret);
}
int main(){
	cin>>x>>n;
	int ub=sqrt(x);
	for (int i=2;i*i<=ub+1;i++){
//		cout<<i<<" "<<i*i<<" "<<x<<endl;
		if (!use[i]) pri[++pri[0]]=i;
		for (int j=1;j<=pri[0]&&(ll)i*pri[j]<=ub+1;j++){
			use[i*pri[j]]=x;
			if (i%pri[j]==0) break;
		}
	}
//	cout<<"done"<<endl;
	for (int i=1;i<=pri[0];i++){
		bool fl=0;
		while (x%pri[i]==0){
			fl=1;
			x/=pri[i];
		}
		if (fl) lis[++cnt]=pri[i];
	}
	if (x!=1) lis[++cnt]=x;
	for (int i=1;i<=cnt;i++) cout<<lis[i]<<endl;
	dfs(1,1);
	printf("%lld\n",ans);
	return 0;
}
