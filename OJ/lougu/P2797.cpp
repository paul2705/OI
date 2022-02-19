#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define mid (l+(r-l)/2)
#define ll long long
#define maxn 1000005 
ll s[maxn],a[maxn];
int n;
double ans;
using namespace std;
ll sum(int x,int l){
    return s[n]-s[n-l]+s[x]-s[x-l-1];
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    for (int i=2;i<n;i++){
        int l=1,r=min(n-i,i-1);
        while(l<r){
            ll s1=sum(i,mid)*(2*mid+3);
            ll s2=sum(i,mid+1)*(2*mid+1);
            if (s1>s2){
                r=mid;
            }
            else{
                l=mid+1;
                if (s1==s2) break;
            }
        }
        if (1.0*sum(i,l)/(2*l+1)-a[i]>ans)
            ans=1.0*sum(i,l)/(2*l+1)-a[i];
    }
    printf("%.2f",ans);
    return 0;
}
