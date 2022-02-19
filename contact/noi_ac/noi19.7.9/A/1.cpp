#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN=1e7+7;
const ll mod=1e9+7;
ll n,k1;
ll s[MAXN],num[MAXN],pr[MAXN];
ll pre[MAXN],p[MAXN],cnt=0;
bool isprime[MAXN];
int main(){
	scanf("%lld%lld",&n,&k1);
	ll ans=0;
	s[1]=1; num[1]=1;
	for (ll d=2;d<=n;d++){
		if (!isprime[d]){
			p[cnt++]=d;
    		ll k2=k1;
	    	ll kk=d%mod,x=1;
		    while (k2>0){
			    if (k2%2==1) x=(x*kk)%mod;
			    kk=(kk*kk)%mod;
			    k2/=2;
			}
			s[d]=(x+1)%mod; num[d]=d; pr[d]=pre[d]=x;
//			cout<<d<<" "<<s[d]<<endl;
		}
		for (ll i=0;i<cnt&&p[i]*d<=n;i++){
			isprime[p[i]*d]=1;
			if (d%p[i]==0){
				if (d>num[d]) s[p[i]*d]=s[d/num[d]]*s[num[d]*p[i]]%mod;
				else{
					pr[p[i]*d]=(pr[d]*pre[d]%mod)%mod;
					pre[p[i]*d]=pre[d];
					s[p[i]*d]=(s[d]+pr[p[i]*d])%mod;
				}
				num[p[i]*d]=num[d]*p[i];
				break;
			}
			else{
				s[p[i]*d]=s[p[i]]*s[d]%mod;
				num[p[i]*d]=p[i];
			}
		}
//		cout<<d<<" "<<s[d]<<endl;
		ans=(ans+s[d]%mod)%mod;
	}
	cout<<(ans+1ll)%mod<<endl;
	return 0;
}
