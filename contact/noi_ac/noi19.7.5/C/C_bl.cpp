#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=15;
const ll mod=998244353;
const ll ub=1e9;
int n,m,A,T;
ll P,ans,inv,Cnt=0,PP=0;;
ll mod_pow(ll x,ll n){
	ll ret=1;
	while (n){
		if (n&1) ret=ret*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return ret;
}
void dfs(int c,int d,int s,int x,int y,ll p,ll cnt){
	if (p==0) return;
//	cout<<c<<" "<<d<<" "<<s<<" "<<x<<" "<<y<<" "<<p<<" "<<cnt<<endl;
	if (d==n+m){
		ans=(ans+cnt*p%mod)%mod;
		return;
	}
	if (c==1){
		if (x>y){
			if (s&(1<<d)) dfs(c^1,d+1,s,x-1,y,p,cnt+1);
			else dfs(c^1,d+1,s,x,y-1,p,cnt);
		}
		else if (x<y){
			if (s&(1<<d)) dfs(c^1,d+1,s,x-1,y,p,cnt);
			else dfs(c^1,d+1,s,x,y-1,p,cnt+1);
		}
		else {
			if (s&(1<<d)){
				dfs(c^1,d+1,s,x-1,y,p*(ub/2)%mod*inv%mod,cnt+1);
				dfs(c^1,d+1,s,x-1,y,p*(ub/2)%mod*inv%mod,cnt);
			}
			else {
				dfs(c^1,d+1,s,x,y-1,p*(ub/2)%mod*inv%mod,cnt+1);
				dfs(c^1,d+1,s,x,y-1,p*(ub/2)%mod*inv%mod,cnt);
			}
		}
	}
	else {
		if (s&(1<<d)){
			dfs(c^1,d+1,s,x-1,y,p*P%mod*inv%mod,cnt+1);
			dfs(c^1,d+1,s,x-1,y,p*(ub-P)%mod*inv%mod,cnt);
		}
		else {
			dfs(c^1,d+1,s,x,y-1,p*P%mod*inv%mod,cnt);
			dfs(c^1,d+1,s,x,y-1,p*(ub-P)%mod*inv%mod,cnt+1);
		}
	}
}
int main(){
	scanf("%d",&T);
	while (T--){
		ans=Cnt=PP=0; inv=mod_pow(ub,mod-2);
		scanf("%d%d%lld%d",&n,&m,&P,&A);
		for (int s=0;s<(1<<(n+m));s++){
			int cnt1=0,cnt2=0;
			for (int i=0;i<n+m;i++){
				if (s&(1<<i)) cnt1++;
				else cnt2++;
			}
			if (cnt1!=n||cnt2!=m) continue;
			dfs(A,0,s,n,m,1,0);
			Cnt=(Cnt+1)%mod;
		}
		printf("%lld\n",ans*mod_pow(Cnt,mod-2)%mod);
	}
	return 0;
}
