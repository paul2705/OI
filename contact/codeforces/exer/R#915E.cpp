#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXT=1e7+6e6+5;
struct tnode{
    int cl,cr,dat,tag;
} t[MAXT];
int n,m,M=-1,root;
int newnode(int cl,int cr,int dat,int tag){
    t[++M]=(tnode){cl,cr,dat,tag};
    return M;
}
void pushdown(int l,int r,int id){
    int cl=t[id].cl,cr=t[id].cr;
    int mid=(l+r)>>1;
    int tag=t[id].tag;
    if (tag==0||l==r) return;
    if (cl==0) t[id].cl=cl=newnode(0,0,0,0);
    if (cr==0) t[id].cr=cr=newnode(0,0,0,0);
    t[cl].tag=t[cr].tag=tag;
    t[cl].dat=(tag-1)*(mid-l+1);
    t[cr].dat=(tag-1)*(r-(mid+1)+1);
    t[id].tag=0;
}
void update(int id){
    int cl=t[id].cl,cr=t[id].cr;
    t[id].dat=t[cl].dat+t[cr].dat;
}
void modify(int a,int b,int l,int r,int &id,int x){
    if (id==0) id=newnode(0,0,0,0);
    int mid=(l+r)>>1;
    if (l>b||r<a) return;
    if (a<=l&&r<=b){
        t[id].tag=x; t[id].dat=(x-1)*(r-l+1);
    }
    else {
        pushdown(l,r,id);
        if (a<=mid) modify(a,b,l,mid,t[id].cl,x);
        if (b>mid) modify(a,b,mid+1,r,t[id].cr,x);
        update(id);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    newnode(0,0,0,0);
    int cl=newnode(0,0,0,0),cr=newnode(0,0,0,0);
    root=newnode(cl,cr,n,2);
    for (int i=1,l,r,k;i<=m;i++){
        scanf("%d%d%d",&l,&r,&k);
        modify(l,r,1,n,root,k);
        printf("%d\n",t[root].dat);
    }
    return 0;
}
