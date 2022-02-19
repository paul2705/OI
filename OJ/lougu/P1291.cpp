#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll x,y,a,n;
ll gcd(ll a,ll b){
    if (a%b==0) return b;
    else return gcd(b,a%b);
}
ll f(ll a){
    ll cnt=0; 
    while (a>0) cnt++,a=a/10;
    return cnt;
}
int main(){
    scanf("%lld",&n);x=1;y=1;
    for (ll i=2;i<=n;i++){
        ll gcd_=gcd(y,i);
        x=(x*i+y)/gcd_;
        y*=i/gcd_;
    }
    ll gcd_=gcd(n,y);
    x*=n/gcd_;
    y/=gcd_;
    a=x/y;
    x-=a*y;
    ll g=a,g_=y,cnt=0;
    if (x==0) return printf("%lld",a),0;
    for (ll i=1;i<=f(a);i++) printf(" ");
    cout<<x<<endl<<a;
    for (ll i=1;i<=f(y);i++) printf("-");
    cout<<endl;
    for (ll i=1;i<=f(a);i++) printf(" ");
    cout<<y;
    return 0;
}
