#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    int n;cin>>n;
    ll a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    ll ans=0;
    ans+=a[n-1];
    if(n>1) ans-=a[0];
    for(int i=1;i<n-1;i++) ans+=abs(a[i]);
    cout<<ans<<endl;
    return 0;
}
