#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int maxn=100005;
const int INF=0x7fffffff;

struct Interval{
    int l,r;
}inval[maxn];

bool cmp(Interval a,Interval b)
{
    if(a.r!=b.r)return a.r<b.r;
    return a.l>b.l;
}

int cap[maxn];

struct Seg_Tree{
    int l,r,MIN,lazy;
}t[maxn*4];

inline void update(int k1)
{
    t[k1].MIN=min(t[k1*2].MIN,t[k1*2+1].MIN);
}

void build(int k1,int l,int r)
{
    t[k1].l=l;
    t[k1].r=r;
    if(l==r){
        t[k1].MIN=cap[l];
        return;
    }
    int mid=(l+r)>>1;
    build(k1*2,l,mid);
    build(k1*2+1,mid+1,r);
    update(k1);
}

void change_interval(int k1,int L,int R,int k)
{
    if(t[k1].l>R||t[k1].r<L)return;
    if(t[k1].l>=L&&t[k1].r<=R){
        t[k1].MIN+=k;
        t[k1].lazy+=k;
        return;
    }
    change_interval(k1*2,L,R,k);
    change_interval(k1*2+1,L,R,k);
    update(k1);
}

void pushdown(int k1)
{
    t[k1*2].lazy+=t[k1].lazy;
    t[k1*2].MIN+=t[k1].lazy;
    t[k1*2+1].lazy+=t[k1].lazy;
    t[k1*2+1].MIN+=t[k1].lazy;
    t[k1].lazy=0;
}

int find(int k1,int L,int R)
{
    if(t[k1].l>R||t[k1].r<L)return INF;
    if(t[k1].l>=L&&t[k1].r<=R)return t[k1].MIN;
    pushdown(k1);
    return min(find(k1*2,L,R),find(k1*2+1,L,R));
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>cap[i];
    }
    build(1,1,n);
    for(int i=1;i<=m;i++){
        cin>>inval[i].l>>inval[i].r;
    }
    sort(inval+1,inval+m+1,cmp);
    int ans=0;
    for(int i=1;i<=m;i++){
        if(find(1,inval[i].l,inval[i].r)){
            ans++;
            change_interval(1,inval[i].l,inval[i].r,-1);
        }
    }
    cout<<ans<<endl;
    return 0;
}
