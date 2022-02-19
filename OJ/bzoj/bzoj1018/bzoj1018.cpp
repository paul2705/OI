#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXT=MAXN*4;
// |a b|a b|
// |d c|d c|
struct cn{
    int ab,ac,ad,bc,bd,cd;
    void prt(){
        cout<<ab<<" "<<ac<<" "<<ad<<" "<<bc<<" "<<bd<<" "<<cd<<endl;
    }
};
struct tnode{
    int l,r,cl,cr;
    cn dat;
} t[MAXT];
int n,M=1,root;
char op[10];
bool use[3][MAXN][5];
int newnode(int l,int r,int cl,int cr,cn dat){
    t[++M]=(tnode){l,r,cl,cr,dat};
    return M;
}
cn merge(cn &a,cn &b,int mid){
    //    cout<<__func__<<endl;
    cn c;
    c.ab=(a.ab&&b.ab&&use[1][mid][2])||(a.ac&&b.bd&&use[2][mid][2]);
    c.ac=(a.ab&&b.ac&&use[1][mid][2])||(a.ac&&b.cd&&use[2][mid][2]);
    c.ad=a.ad||(a.ab&&b.ad&&a.cd&&use[1][mid][2]&&use[2][mid][2]);
    c.bc=b.bc||(b.ab&&a.bc&&b.cd&&use[1][mid][2]&&use[2][mid][2]);
    c.bd=(a.bd&&b.ab&&use[1][mid][2])||(a.cd&&b.bd&&use[2][mid][2]);
    c.cd=(a.bd&&b.ac&&use[1][mid][2])||(a.cd&&b.cd&&use[2][mid][2]);
    return c;
}
// |ab|
// |cd|
int build(int l,int r){
    if (l==r) return newnode(l,r,0,0,(cn){1,0,0,0,0,1});
    int mid=(l+r)>>1;
    int cl=build(l,mid),cr=build(mid+1,r);
    return newnode(l,r,cl,cr,merge(t[cl].dat,t[cr].dat,mid));
}
void update(int id){
    //    cout<<__func__<<endl;
    int cl=t[id].cl,cr=t[id].cr;
    int l=t[id].l,r=t[id].r;
    int mid=(l+r)>>1;
    t[id].dat=merge(t[cl].dat,t[cr].dat,mid);
}
void modifyl(int a,int b,int id,int tp){
    int l=t[id].l,r=t[id].r;
    //    cout<<__func__<<l<<" "<<r<<endl;
    int cl=t[id].cl,cr=t[id].cr;
    if (r<a||l>b) return;
    if (l==r) return;
    if (a<=l&&r<=b){
        //        cout<<"fuckin"<<endl;
        update(id);
        //        cout<<"fu"<<endl;
        return;
    }
    //    cout<<"out"<<endl;
    modifyl(a,b,cl,tp); modifyl(a,b,cr,tp);
    update(id);
}
void modifyc(int a,int b,int id,int val){
    int l=t[id].l,r=t[id].r;
    //    cout<<__func__<<l<<" "<<r<<endl;
    int cl=t[id].cl,cr=t[id].cr;
    if (r<a||l>b) return;
    if (a<=l&&r<=b){
        t[id].dat.ac=t[id].dat.bc=t[id].dat.ad=t[id].dat.bd=val;
        return;
    }
    modifyc(a,b,cl,val); modifyc(a,b,cr,val);
    update(id);
}
// (,mid] [a,b]
// [a,b] [mid+1,)
cn query(int a,int b,int id){
    int l=t[id].l,r=t[id].r;
    //    cout<<__func__<<l<<" "<<r<<endl;
    int cl=t[id].cl,cr=t[id].cr;
    int mid=(l+r)>>1;
    if (r<a||l>b) return (cn){0,0,0,0,0,0};
    if (a<=l&&r<=b) return t[id].dat;
    cn qcl=query(a,b,cl);
    cn qcr=query(a,b,cr);
    if (mid<a) return qcr;
    else if (mid+1>b) return qcl;
    else return merge(qcl,qcr,mid);
}
int main(){
	freopen("bzoj1018.in","r",stdin);
	freopen("bzoj1018.out","w",stdout);
	scanf("%d",&n);
    root=build(1,n);
    while (~scanf("%s",op)){
        //        t[root].dat.prt();
        int sx,sy,tx,ty;
        char c=op[0];
        if (c=='E') break;
        scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
        int x=c=='O';
        if (sy>ty) swap(sx,tx),swap(sy,ty);
//		cout<<sx<<" "<<sy<<" "<<tx<<" "<<ty<<endl;
		if (c=='O'||c=='C'){
            if (sx==tx){
                use[sx][sy][2]=use[tx][ty][4]=x;
                //                cout<<"fuck"<<endl;
                modifyl(sy,ty,root,sx);
            }
            else{
                use[1][sy][3]=use[2][sy][1]=x;
                modifyc(sy,ty,root,x);
            }
        }
        else {
            cn inter=query(sy,ty,root),lout=query(1,sy,root),rout=query(ty,n,root);
//            inter.prt();
  //          lout.prt();
    //        rout.prt();
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
    fclose(stdin); fclose(stdout);
    return 0;
}
