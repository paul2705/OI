#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 1005
#define eps 1e-9
using namespace std;
int f[N];double g[N];
int find(int x){
    if(f[x]==x)return x;
    int temp=find(f[x]);
    g[x]*=g[f[x]];
    return f[x]=temp;
}
bool equal(double a,double b){ return fabs(a-b)<=eps; }
int main(){
    int T,n,m,a,b;
    double x,y;
    bool flag=0;
    scanf("%d",&T);
    for (int t=1;t<=T;++t){
        scanf("%d%d",&n,&m); flag=0;
        for (int i=1;i<=n;i++) f[i]=i;
        for (int i=1;i<=n;i++) g[i]=1;
        for (int i=1;i<=m;i++){
            scanf("%d%d%lf%lf",&a,&b,&x,&y);
            int f1=find(a),f2=find(b);
            if (f1==f2){
                if(!equal(x/y,g[a]/g[b])) flag=true;
            }
            else f[f2]=f1,g[f2]*=g[a]/g[b]*y/x;
        }
        if(flag) printf("Case #%d: No\n",t);
        else printf("Case #%d: Yes\n",t);
    }
    return 0;
}
