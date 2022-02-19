#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
const int maxn=3001;
struct proj{
    int w,r;
}a[maxn];
bool cmp(const proj &a,const proj &b){
    return a.r>b.r;
}
int f[maxn][maxn];
int n,ans;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].w>>a[i].r;
    sort(a+1,a+1+n,cmp);
    f[1][1]=a[1].w;
    for(int i=1;i<=n;i++) for(int j=1;j<=i;j++)
    f[i][j]=max(f[i-1][j],f[i-1][j-1]+a[i].w-a[i].r*(j-1));
    for(int i=1;i<=n;i++) ans=max(f[n][i],ans);
    cout<<ans;
}
int main(){
    solve();
    return 0;
}
