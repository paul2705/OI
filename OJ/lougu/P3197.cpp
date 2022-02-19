#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll mod=1e5+3;
ll n,m;
ll mod_pow(ll n,ll m){ 
    ll ret=1;
    while (m>0){
        if (m&1) (ret*=n)%=mod;
        (n*=n)%=mod;
        m>>=1;
    }
    return ret;
}
int main(){
    scanf("%lld%lld",&m,&n);
    ll ans=mod_pow(m,n)-m*mod_pow(m-1,n-1)%mod; 
    ans%=mod;
    printf("%lld\n",(ans+mod)%mod); 
    return 0;
}
