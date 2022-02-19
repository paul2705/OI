#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const ll mod=998244353;
template<typename T>void read(T &a){
    T x=0,f=1;char ch=getchar();
    while(!isdigit(ch)){
        if(ch=='-')f=0;ch=getchar();
    }
    while(isdigit(ch)){
        x=((x<<1)%mod+(x<<3)%mod+ch-'0')%mod;ch=getchar();
    }
    a=f?x:-x;
}
bool ok;
ll n,m,cnt;
ll num[105],ans[105];
bool judge(ll now){
    ll sum=0;
    for(ll i=n;i;--i){
        sum=((num[i]+sum)*now)%mod;
    }
    sum=(sum+num[0])%mod;
    return !sum;
}
int main(){
	read(n);read(m);
    for(ll i=0;i<=n;++i) read(num[i]);
    for(ll i=1;i<=m;++i){
        if(judge(i)){ans[++cnt]=i; ok=1; }
    }
    printf("%lld\n",cnt);
    for(ll i=1;i<=cnt;++i) printf("%lld\n",ans[i]);
	return 0;
}
