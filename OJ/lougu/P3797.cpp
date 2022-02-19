#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1000000+10;
int ls[maxn],rs[maxn],sum[maxn],posl[maxn],posr[maxn];
int n,m,cnt,ans,root;
void add(int &g,int l,int r,int ll,int rr,int opt){
    if(!g){g=++cnt;posl[g]=0;posr[g]=n+1;}
    if(rr<l || r<ll)return;
    if(ll<=l&&r<=rr){
        if(opt==1){posl[g]=l;posr[g]=n+1;return;}
        if(opt==2){posr[g]=l;posl[g]=0;return;}
        if(opt==3){posl[g]=0;posr[g]=n+1;return;}
    }int mid=(l+r)>>1;
    add(ls[g],l,mid,ll,rr,opt);add(rs[g],mid+1,r,ll,rr,opt);
    posl[g]=max(posl[ls[g]],posl[rs[g]]);posr[g]=min(posr[ls[g]],posr[rs[g]]);
    if(sum[rs[g]]!=0)posl[g]=posl[rs[g]];
    if(sum[ls[g]]!=0)posr[g]=posr[ls[g]];
    sum[g]=sum[ls[g]]+sum[rs[g]];
    if(posl[ls[g]]>0 && posr[rs[g]]<n+1){
        sum[g]=sum[ls[g]]+sum[rs[g]]+1;
        posl[g]=posl[rs[g]];posr[g]=posr[ls[g]];
    }
}
void get(int &g,int l,int r,int ll,int rr){
    if(!g){g=++cnt;posl[g]=0;posr[g]=n+1;}
    if(rr<l || r<ll)return;
    if(ll<=l&&r<=rr){ans+=sum[g];return;}
    int mid=(l+r)>>1;
    get(ls[g],l,mid,ll,rr);get(rs[g],mid+1,r,ll,rr);
    if(posl[ls[g]]>=ll && posr[rs[g]]<=rr)ans++;
}
int main(){
    scanf("%d%d",&n,&m);
    add(root,1,n,1,1,1);add(root,1,n,n,n,2);
    for(int i=1;i<=m;i++){
        int opt,x,y;char c;
        scanf("%d%d",&opt,&x);
        if(opt==1){
            cin>>c;
            if(c=='(')add(root,1,n,x,x,1);
            if(c==')')add(root,1,n,x,x,2);
            if(c=='X')add(root,1,n,x,x,3);
        }
        if(opt==2){
            scanf("%d",&y);
            ans=0;get(root,1,n,x,y);printf("%d\n",ans);
        }
    }
    return 0;
}
