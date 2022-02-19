#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const double eps=1e-9;
const int N=100005;
int in[N],out[N];
int head[N],nxt[N],tail[N];
double x[N];
bool b[N];
int q[N],t,n;
void addto(int x,int y){
    t++;
    in[y]++;
    out[x]++;
    nxt[t]=head[x];
    head[x]=t;
    tail[t]=y;
}
int main(){
    scanf("%d",&n);
    for (int i=1,x,y;i<n;i++){
        scanf("%d%d",&x,&y);
        addto(x,y);
    }
    int l=1,r=0;
    for (int i=1;i<=n;i++){
        if(in[i]==0)r++,q[r]=i,b[i]=true;
    }
    for (int i=1;i<=r;i++) x[q[i]]=1.0/r;
    while (l<=r){
        int xx=q[l];
        for (int k=head[xx];k;k=nxt[k]){
            x[tail[k]]+=x[xx]/out[xx];
            in[tail[k]]--;
            if (in[tail[k]]==0)q[++r]=tail[k];
        }
        l++;
    }
    for (int i=1;i<=n;i++)
        if (!b[i]&&fabs(1-x[i])<=eps)printf("%d\n",i);
    return 0;
}
