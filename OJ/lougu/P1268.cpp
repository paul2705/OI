#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#define MAXN 35
using namespace std;
int d[MAXN][MAXN];
int n;
int main(){
    while(1){
        scanf("%d",&n);
        if(!n){
            break;
        }
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                scanf("%d",&d[i][j]);
            }
        }
        int ans=d[1][2];
        for(int i=3;i<=n;i++){
            int t=0x7fffffff;
            for(int j=2;j<i;j++){
                t=min(t,d[1][i]-(d[1][j]+d[1][i]-d[j][i])/2);
            }
            ans+=t;
        }
        printf("%d\n",ans);
    }
    return 0;
}
