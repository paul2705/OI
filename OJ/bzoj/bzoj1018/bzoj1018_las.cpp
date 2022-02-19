#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXT=MAXN*8;
// |a b|a b|
// |d c|d c|
struct cn{
    int ab,ac,ad,bc,bd,cd;
    void clr(int tp){
        if (tp==1) ab=0;
        else if (tp==2) cd=0;
        else ad=ac=ad=bc=bd=cd=0;
    }
    void ful(int tp){
        if (tp==1) ab=1;
        else if (tp==2) cd=1;
        else ad=ac=ad=bc=bd=cd=1;
    }
    void prt(){
		cout<<ab<<" "<<ac<<" "<<ad<<" "<<bc<<" "<<bd<<" "<<cd<<endl;
    }
};
struct tnode{
    int l,r,cl,cr;
    cn dat;
} t[MAXT];
int n,M,root;
bool use[3][MAXN][6];
char op[10];
int newnode(int l,int r,int cl,int cr,cn x){
    t[++M]=(tnode){l,r,cl,cr,x};
    return M;
}
cn merge(cn a,cn b,int mid){
    cn c;
    c.ab=(a.ab&&b.ab&&use[1][mid][2])||(a.ac&&b.bd&&use[2][mid][2]);
    c.ac=(a.ab&&b.ac&&use[1][mid][2])||(a.ac&&b.cd&&use[2][mid][2]);
    c.ad=(a.ab&&a.cd&&b.ad&&use[1][mid][2]&&use[2][mid][2])||a.ad||use[1][mid][3];
    c.bc=(b.ab&&b.cd&&a.bc&&use[1][mid][2]&&use[2][mid][2])||b.bc||use[1][mid][3];
    c.bd=(a.bd&&b.ab&&use[1][mid][2])||(a.cd&&b.bd&&use[2][mid][2]);
    c.cd=(a.bd&&b.ac&&use[1][mid][2])||(a.cd&&b.cd&&use[2][mid][2]);
    return c;
}
int build(int l,int r){
    if (l==r) return newnode(l,r,0,0,(cn){1,0,0,0,0,1});
    int mid=(l+r)>>1;
    int cl=build(l,mid),cr=build(mid+1,r);
    return newnode(l,r,cl,cr,merge(t[cl].dat,t[cr].dat,mid));
}
void update(int id){
    int cl=t[id].cl,cr=t[id].cr;
    int l=t[id].l,r=t[id].r;
    int mid=(l+r)>>1;
    t[id].dat=merge(t[cl].dat,t[cr].dat,mid);
}
void modifyl(int a,int b,int tp,int id,int val){
    int l=t[id].l,r=t[id].r;
    int cl=t[id].cl,cr=t[id].cr;
    if (l>b||r<a) return;
    if (l==r) return;
//    cout<<__func__<<" "<<l<<" "<<r<<endl;
    if (a<=l&&r<=b){
//  cout<<"fuck:: "<<l<<" "<<r<<endl;
        if (val==1) t[id].dat.ful(tp),use[tp][a][2]=use[tp][b][4]=1;
        else t[id].dat.clr(tp),use[tp][a][2]=use[tp][b][4]=0;
        return;
    }
    modifyl(a,b,cl,tp,val); modifyl(a,b,cr,tp,val);
    update(id);
}
void modifyc(int a,int b,int id,int val){
    int l=t[id].l,r=t[id].r;
    int cl=t[id].cl,cr=t[id].cr;
    if (l>b||r<a) return;
//    cout<<__func__<<" "<<l<<" "<<r<<endl;
    if (a<=l&&r<=b){
//  cout<<"fuck:: "<<l<<" "<<r<<endl;
        if (val==1) t[id].dat.ful(3),use[1][a][3]=use[2][a][1]=1;
        else t[id].dat.clr(3),use[1][a][3]=use[2][a][1]=0;
        return;
    }
    modifyc(a,b,cl,val); modifyc(a,b,cr,val);
    update(id);
}
cn query(int a,int b,int id){
    int l=t[id].l,r=t[id].r;
    int cl=t[id].cl,cr=t[id].cr;
//    cout<<__func__<<" "<<id<<" "<<l<<" "<<r<<endl;
    if (a<=l&&r<=b) return t[id].dat;
    int mid=(l+r)>>1;
    if (a>mid) return query(a,b,cr);
    if (b<mid+1) return query(a,b,cl);
    cn qcl=query(a,b,cl);
    cn qcr=query(a,b,cr);
    return merge(qcl,qcr,mid);
}
int main(){
    scanf("%d",&n);
    root=build(1,n);
    while (~scanf("%s",op)){
        if (op[0]=='E') break;
        char c=op[0];
        int sx,sy,tx,ty;
        scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
//  cout<<"(2 2): "<<endl;
//  t[root].dat.prt();
        if (sy>ty) swap(sx,tx),swap(sy,ty);
        int x=(c=='O');
        if (c=='O'||c=='C'){
            if (sx==tx) modifyl(sy,ty,sx,root,x);
            else modifyc(sy,ty,root,x);
        }
        if (c=='A'){
            cn inter=query(sy,ty,root),lout=query(1,sy,root),rout=query(ty,n,root);
//      cout<<inter.ab<<endl;
            bool ans=0;
            if (sx==1&&tx==1){
                ans=lout.bc&&rout.ad&&inter.cd;
                ans|=inter.ab;
                ans|=inter.ac&&rout.ad;
                ans|=inter.bd&&lout.bc;
            }
            if (sx==2&&tx==2){
                ans=lout.bc&&rout.ad&&inter.ab;
                ans|=inter.cd;
                ans|=inter.ac&&lout.bc;
                ans|=inter.bd&&rout.ad;
            }
            if (sx==1&&tx==2){
                ans=lout.bc&&rout.ad&&inter.bd;
                ans|=inter.ac;
                ans|=inter.cd&&lout.bc;
                ans|=inter.ab&&rout.ad;
            }
            if (sx==2&&tx==1){
                ans=lout.bc&&rout.ad&&inter.ac;
                ans|=inter.bd;
                ans|=inter.ab&&lout.bc;
                ans|=inter.cd&&rout.ad;
            }
            if (ans) printf("Y\n");
            else printf("N\n");
        }
    }
    return 0;
}
