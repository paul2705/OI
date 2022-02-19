#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const int MAXN=1e6+6;
const ll inf=1e10;
ll a[MAXN];
int main(){
    ll ans=-1,n=0,m=0;
    scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    ll l=1,r=inf;
    while(l<=r){
        ll mid=(l+r)/2;
        ll su=0,t=0;
        for(ll i=1;i<=n;i++){
            su+=a[i];
            if(su>=mid) t++,su=0;
            if(su<0) su=0;
        }
        if(t<=m){
            r=mid-1;
            if(t==m) ans=mid;
        }
        else l=mid+1;
    }
    if(ans!=-1){
        printf("%lld ",ans);
        ans=-1,l=1,r=inf;
        while(l<=r){
            ll mid=(l+r)/2;
            ll su=0,t=0;
            for(ll i=1;i<=n;i++){
                su+=a[i];
                if(su>=mid) t++,su=0;
                if(su<0) su=0;
            }
            if(t<=m-1) r=mid-1;
            else{
                l=mid+1;
                if(t==m) ans=mid;
            }
        }
        printf("%lld",ans);
    }
    else printf("-1");
    return 0;
}
