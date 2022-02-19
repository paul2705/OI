#include<bits/stdc++.h>
namespace ZDY{
#define ll long long
#define Fur(i,x,y) for(int i=x;i<=y;i++)
#define in2(x,y) in(x);in(y)
}using namespace ZDY;using namespace std;
#define N 5000011
#define ls rt<<1
#define rs ls|1
#define Z int m=(l+r)>>1
#define lson l,m,ls
#define rson m+1,r,rs
ll s[N<<2],sl[N<<2],sr[N<<2];
int n,q;
short add[N];
inline void pu(int rt,int ln,int rn){
    s[rt]=max(max(s[ls],s[rs]),sr[ls]+sl[rs]);
    sl[rt]=sl[ls]+(sl[ls]==ln)*sl[rs];
    sr[rt]=sr[rs]+(sr[rs]==rn)*sr[ls];
}
inline void pd(int rt,int ln,int rn){
    if(!add[rt]||(!ln&&!rn))return;
    s[ls]=sl[ls]=sr[ls]=(add[rt]>0)*ln;
    s[rs]=sl[rs]=sr[rs]=(add[rt]>0)*rn;
    add[ls]=add[rs]=add[rt];add[rt]=0;
}
inline void build(int l,int r,int rt){
    s[rt]=sl[rt]=sr[rt]=r-l+1;if(l==r)return;
    Z;build(lson);build(rson);
}
inline void upd(int L,int R,int l,int r,int rt,int v){
    if(L<=l&&r<=R){s[rt]=sl[rt]=sr[rt]=(v>0)*(r-l+1),add[rt]=v;return;}
    Z;pd(rt,m-l+1,r-m);
    if(L<=m)upd(L,R,lson,v);
    if(R>m)upd(L,R,rson,v);
    pu(rt,m-l+1,r-m);
}
inline int ask(int c,int l,int r,int rt){
    Z;pd(rt,m-l+1,r-m);
    if(s[ls]>=c)return ask(c,lson);
    else if(sr[ls]+sl[rs]>=c)return m-sr[ls]+1;
    else return ask(c,rson);
}
int main(){
     scanf("%d%d",&n,&q);build(1,n,1);
     int x,y,ans=0,pos;
     while(q--)
        if(sc()=='A'){
            scanf("%d",&x);
             if(s[1]<x)ans++;
             else{
                pos=ask(x,1,n,1);
                upd(pos,pos+x-1,1,n,1,-1);
             }
        }
        else{scanf("%d%d",&x,&y);upd(x,y,1,n,1,1);}
    cout<<ans<<endl;
	return 0;
}
