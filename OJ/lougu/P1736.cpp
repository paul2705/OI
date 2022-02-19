#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,f[2510][2510],a[2510][2510]= {0},ls[2510][2510],rs[2510][2510],us[2510][2510],ans=0;

int main() {
    while(~scanf("%d%d",&m,&n)) {
        int ans=0;
        memset(f,0,sizeof(f));
        memset(ls,0,sizeof(ls));
        memset(rs,0,sizeof(rs));
        memset(us,0,sizeof(us));
        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++) {
                scanf("%d",&a[i][j]);
                if(!a[i-1][j])
                    us[i][j]=us[i-1][j]+1;
                if(!a[i][j-1])
                    ls[i][j]=ls[i][j-1]+1;
            }
        for(int i=1; i<=m; i++)
            for(int j=n; j>=1; j--)
                if(!a[i][j+1])rs[i][j]=rs[i][j+1]+1;
        for(int i=1; i<=m; i++)
            for(int j=1; j<=n; j++)if(a[i][j]) {
                    f[i][j]=min(f[i-1][j-1],min(ls[i][j],us[i][j]))+1;
                    f[i][j]=max(f[i][j],min(f[i-1][j+1],min(rs[i][j],us[i][j]))+1);
                    ans=max(f[i][j],ans);
                }
        printf("%d\n",ans);
    }
    return 0;
}
