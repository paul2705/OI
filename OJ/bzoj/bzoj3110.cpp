#pragma GCC optimze(2)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
struct rec{
    int op,a,b;
	ll c;
	int id;
} a[MAXN],p1[MAXN],p2[MAXN];
int ans[MAXN],tim,cnta;
int n,m,M,rt;
struct tnode{
    int l,r,cl,cr;
	ll dat,tag;
} t[MAXN*8];
int newnode(int l,int r,int cl,int cr,ll dat){
    t[++M]=(tnode){l,r,cl,cr,dat,0};
    return M;
}
int build(int l,int r){
    if (l==r) return newnode(l,r,0,0,0);
    int mid=(l+r)>>1;
    int cl=build(l,mid),cr=build(mid+1,r);
    return newnode(l,r,cl,cr,0);
}
void pushdown(int id){
    int cl=t[id].cl,cr=t[id].cr;
    int l=t[id].l,r=t[id].r;
    if (t[id].tag==0) return;
    t[id].dat+=t[id].tag*(r-l+1);
    t[cl].tag+=t[id].tag;
    t[cr].tag+=t[id].tag;
    t[id].tag=0;
}
void update(int id){
    int cl=t[id].cl,cr=t[id].cr;
    t[id].dat=t[cl].dat+t[cr].dat;
}
void add(int a,int b,int id,int val){
    pushdown(id);
    int l=t[id].l,r=t[id].r;
    int cl=t[id].cl,cr=t[id].cr;
    if (l>b||r<a) return;
    if (a<=l&&r<=b){
        t[id].tag+=val;
        pushdown(id);
        return;
    }
    add(a,b,cl,val); add(a,b,cr,val);
    update(id);
}
ll qry(int a,int b,int id){
    pushdown(id);
    int l=t[id].l,r=t[id].r;
    int cl=t[id].cl,cr=t[id].cr;
    if (l>b||r<a) return 0;
    if (a<=l&&r<=b) return t[id].dat;
    return qry(a,b,cl)+qry(a,b,cr);
}
void divd(int ql,int qr,int l,int r){
    if (l>r||ql>qr) return;
    if (l==r){
        for (int i=ql;i<=qr;i++){
            if (a[i].op==2) ans[a[i].id]=n-l+1;
        }
        return;
    }
    int mid=(l+r)>>1;
    int cnt1=0,cnt2=0;
    for (int i=ql;i<=qr;i++){
        if (a[i].op==1){
            if (a[i].c>mid){
                p2[++cnt2]=a[i];
                continue;
            }
            p1[++cnt1]=a[i];
            add(a[i].a,a[i].b,rt,1);
        }
        else {
            ll tmp=qry(a[i].a,a[i].b,rt);
            if (tmp>=a[i].c) p1[++cnt1]=a[i];
            else a[i].c-=tmp,p2[++cnt2]=a[i];
        }
    }
    for (int i=ql;i<=qr;i++){
        if (a[i].op==1){
            if (a[i].c>mid) continue;
            add(a[i].a,a[i].b,rt,-1);
        }
    }
    for (int i=ql;i<=ql+cnt1-1;i++) a[i]=p1[i-ql+1];
    for (int i=ql+cnt1;i<=qr;i++) a[i]=p2[i-ql-cnt1+1];
    divd(ql,ql+cnt1-1,l,mid); divd(ql+cnt1,qr,mid+1,r);
}
int main(){
    scanf("%d%d",&n,&m);
    rt=build(1,n);
    for (int i=1;i<=m;i++){
        int op,aa,b;ll c;
        scanf("%d%d%d%lld",&op,&aa,&b,&c);
        if (op==1) a[++tim]=(rec){op,aa,b,n-c+1,0};
        else a[++tim]=(rec){op,aa,b,c,++cnta};
    }
    divd(1,tim,1,n);
    for (int i=1;i<=cnta;i++) printf("%d\n",ans[i]);
    return 0;
}
