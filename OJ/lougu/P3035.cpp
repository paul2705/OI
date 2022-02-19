#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=10050;
int x[MAXN],f[MAXN],c[MAXN*10];
int n,m;
int main(){
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) scanf("%d",&x[i]),f[i]=1e9;
        sort(x+1,x+n+1);
        for (int i=1;i<=m;i++) scanf("%d",&c[i]);
        for (int i=m-1;i>=1;i--) c[i]=min(c[i+1],c[i]);
        for (int i=1;i<=n;i++)
                for (int j=1;j<=i;j++)
                        f[i]=min(f[i],f[j-1]+c[x[i]-x[j]+1]);
        printf("%d\n",f[n]);
        return 0;
}                    
