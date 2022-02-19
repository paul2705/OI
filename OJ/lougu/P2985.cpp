#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#define ll long long 
using namespace std;
ll l,r,ans;
int n,d;
int h[50005],a[50005];
bool jud(ll x,bool f){
    ll tmp=0;
    int now=1;
    for(int i=1;i<=d;i++){
        tmp>>=1;
        while(now<=n&&tmp<x){
            tmp+=h[now];
            if(f)a[now]=i;
            now++;
        }
        if(tmp<x)return 0;
    }
    if(f)for(int i=now+1;i<=n;i++)a[now]=d;
    return 1;
}
int main(){
    scanf("%d%d",&n,&d); 
    for(int i=1;i<=n;i++)
        cin>>h[i],r+=h[i];
    while(l<=r){
        ll mid=(l+r)>>1;
        if(jud(mid,0)){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    printf("%lld\n",ans);
    jud(ans,1);
    for(int i=1;i<=n;i++)
        if(!a[i])printf("%d\n",d);
        else printf("%d\n",a[i]);
    return 0;
}
