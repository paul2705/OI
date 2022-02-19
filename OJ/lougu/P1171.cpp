#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int f[1<<20][20],w[20][20],n;
int main(){
    memset(f,0x3f,sizeof f);
    f[1][0]=0;
    cin>>n;
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            scanf("%d",&w[i][j]);
    for(int i=1;i<(1<<n);i+=2) {
        for(int j=0;j<n;j++){
            if(!((i >> j) & 1)) continue;
            for(int k=0;k<n;k++){
                if(j==k) continue; 
                if(!(i>>k &1)) continue; 
                f[i][j]=min(f[i][j],f[i^(1<<j)][k]+w[k][j]);
            }
        }
    }
    int minn=8848888;
    for(int i=0;i<=n-1;++i){
        minn=min(minn,f[(1<<n)-1][i]+w[i][0]);
    }
    cout<<minn;
}
