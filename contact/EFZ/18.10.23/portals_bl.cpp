#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=5e2+5;
int a[MAXN][MAXN],b[MAXN][MAXN];
int T,n,m,t,r,ans;
priority_queue<int> q;
int main(){
	freopen("portals.in","r",stdin);
	freopen("portals1.out","w",stdout);
	scanf("%d",&T);
    while (T--){
        ans=0; while (!q.empty()) q.pop();
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++) b[i][j]=0;
        }
        scanf("%d%d%d%d",&n,&m,&t,&r);
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                char c=getchar(); while (c!='*'&&c!='O'&&c!='X')c=getchar();
                if (c=='*') a[i][j]=1;
                if (c=='O') a[i][j]=2;
                if (c=='X') a[i][j]=3;
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if (a[i][j]!=2) continue;
                for (int x=max(i-r,1);x<=min(n,i+r);x++){
                    for (int y=max(j-r,1);y<=min(m,j+r);y++){
                        if (abs(x-i)+abs(y-j)<=r) b[x][y]++;
                    }
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++)
                if (a[i][j]==1) q.push(b[i][j]);
        }
        for (int i=1;i<=t&&!q.empty();i++){
            ans+=q.top(); q.pop();
        }
        printf("%d\n",ans);
    }
    fclose(stdin); fclose(stdout);
    return 0;
}

