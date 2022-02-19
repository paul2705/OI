#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353,g=3;
const int maxn=1e6+10;
int Pow(int a,long long k){
    int ret=1;
    while(k){
        if(k&1)ret=ret*1LL*a%mod;
        k>>=1,a=a*1LL*a%mod;
    }
    return ret;
}
int fact[maxn],inv[maxn];
int C(int n,int m){return fact[n]*1LL*inv[m]%mod*inv[n-m];}
int n,p,x,y;
int lim,bit=0,rev[maxn];
void init(int len){
    lim=1,bit=0;
    while(lim<=len)lim<<=1,bit++;
    for(int i=0;i<lim;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<bit-1);
}
void NTT(int *a,int type){
    for(int i=0;i<lim;i++)if(rev[i]>i)swap(a[rev[i]],a[i]);
    for(int mid=1;mid<lim;mid<<=1){
        int wn=Pow(g,(mod-1)/(mid<<1));
        if(type==-1)wn=Pow(wn,mod-2);
        for(int j=0;j<lim;j+=mid<<1)
        for(int k=0,w=1;k<mid;k++,w=w*1LL*wn%mod){
            int x=a[j+k],y=a[j+k+mid]*1LL*w%mod;
            a[j+k]=(x+y)%mod;
            a[j+k+mid]=(x-y+mod)%mod;
        }
    }
    if(type==-1){
        int INV=Pow(lim,mod-2);
        for(int i=0;i<lim;i++)a[i]=a[i]*1LL*INV%mod;
    }
}
int dp[maxn];
int A[maxn],B[maxn];
int P[maxn],iP[maxn];
void solve(int l,int r){
    if(l==r){
        long long tmp=1LL-P[l]-iP[l];
        tmp=(tmp%mod+mod)%mod;
        tmp=Pow(tmp,mod-2);
        dp[l]=(1+dp[l]*1LL*fact[l]%mod)%mod*tmp%mod;
        return ;
    }
    int mid=l+r>>1;
    solve(l,mid);
    init((r-l+1)*2);
    for(int i=0;i<lim;i++)A[i]=B[i]=0;
    for(int i=l;i<=mid;i++)A[i-l]=dp[i]*1LL*P[i]%mod*inv[i]%mod;
    for(int i=0;i<=r-l+1;i++)B[i]=iP[i]*1LL*inv[i]%mod;
    NTT(A,1),NTT(B,1);
    for(int i=0;i<lim;i++)A[i]=A[i]*1LL*B[i]%mod;
    NTT(A,-1);
    for(int i=mid+1;i<=r;i++)dp[i]=(dp[i]+A[i-l])%mod;
    solve(mid+1,r);
    return;
}
int main(){
    scanf("%d%d%d",&n,&x,&y),inv[0]=fact[0]=1,P[0]=iP[0]=1;
    p=x*1LL*Pow(y,mod-2)%mod;
    for(int i=1;i<=n;i++)
    fact[i]=fact[i-1]*1LL*i%mod,inv[i]=Pow(fact[i],mod-2),P[i]=P[i-1]*1LL*p%mod,iP[i]=iP[i-1]*1LL*(1+mod-p)%mod;
    solve(1,n);
    printf("%d\n",dp[n]);
    //system("pasue");

}
