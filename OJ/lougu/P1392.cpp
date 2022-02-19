#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
int read(){
    int f=1,x=0;
    char ss=getchar();
    while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
    while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
    return x*f;
}
const int maxn=1010;
int n,m,k;
int a[maxn],b[maxn],c[maxn],cnt;
struct node{int x,y,sum,pre;}mi[maxn];
void swapp(int x,int y){
    node tp=mi[x];
    mi[x]=mi[y]; mi[y]=tp;
}
void ins(int x,int y,int pre){
    mi[++cnt].x=x; mi[cnt].y=y;
    mi[cnt].pre=pre; mi[cnt].sum=a[x]+b[y];
    int p=cnt;
    while(p>1){
        if(mi[p].sum<mi[p>>1].sum){ swapp(p,p>>1); p>>=1;}
        else break;
    }
}
void pop(){
    mi[1]=mi[cnt--];
    int p=1,s=p<<1;
    while(s<=cnt){
        if(s<cnt&&mi[s].sum>mi[s+1].sum) s++;
        if(mi[s].sum<mi[p].sum){ swapp(s,p); p=s; s=p<<1;}
        else break;
    }
}
int main(){
    n=read();m=read();k=read();
    for(int i=1;i<=m;++i) c[i]=read();
    sort(c+1,c+1+m);
    for(int i=1;i<n;++i){
        for(int j=1;j<=m;++j) a[j]=c[j],b[j]=read();
        sort(b+1,b+1+m);
        cnt=0; ins(1,1,0);
        for(int j=1;j<=k;++j){
            node tp=mi[1]; pop();
            int x=tp.x, y=tp.y, sum=tp.sum, pre=tp.pre;
            ins(x,y+1,1);
            if(pre==0) ins(x+1,y,0);
            c[j]=sum;
        }
    }
    for(int i=1;i<=k;++i)
        printf("%d ",c[i]);
    return 0;
}
