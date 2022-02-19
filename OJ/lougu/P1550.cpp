#include<cmath>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int ML=305;
int f[ML];
struct Node{
    int l,r;
    int num;
}a[ML*ML/2];
bool comp(Node a,Node b){
    return a.num<b.num;
}
int found(int x){
    if(f[x]==-1) return x;
    return f[x]=found(f[x]);
}
void merged(int x,int y){
    f[x]=y;
    return;
}
int n;
int ans;
int main(){
    scanf("%d",&n);
    int i,j;
    int t=0;
    for(i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        a[++t].num=x;
        a[t].l=0;
        a[t].r=i;
    }
    memset(f,-1,sizeof(f));
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            int x;
            scanf("%d",&x);
            if(i>j){
                a[++t].num=x;
                a[t].l=i;
                a[t].r=j;
            }
        }
    }
    sort(a+1,a+1+t,comp);
    int x=0;
    for(i=1;i<=t;i++){
        int t1,t2;
        t1=found(a[i].l);
        t2=found(a[i].r);
        if(t1!=t2){
            merged(t1,t2);
            ++x;
            ans+=a[i].num;
        }
        if(x==n) break;
    }
    printf("%d",ans);
    return 0;
}
