#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#define MAXN 100005
#define LL long long
#define INF 2147483647
#define MOD 1000000007
#define free(s) freopen("s.txt","r",stdin);
#define lowbit(x) ((x&(-x))) 
#define debug(x) cout<<x<<endl;
using namespace std;
const int L=105;
struct node{
    int x,y;
};
queue<node>que;
LL int n,t,w[L][L],f[L][L][4],to[4][2]={1,0,-1,0,0,1,0,-1};
LL int bfs(){
    memset(f,0x3f,sizeof(f));
    f[1][1][0]=0;
    que.push((node){1,1});
    while(!que.empty()){
        node now=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            int a=now.x+to[i][0],b=now.y+to[i][1];
            bool flag=false;
            if(a<=n&&a>=1&&b<=n&&b>=1){
                if(f[now.x][now.y][0]+t<f[a][b][1]){
                    f[a][b][1]=f[now.x][now.y][0]+t;
                    flag=true;
                }
                if(f[now.x][now.y][1]+t<f[a][b][2]){
                    f[a][b][2]=f[now.x][now.y][1]+t;
                    flag=true;
                }
                if(f[now.x][now.y][2]+t+w[a][b]<f[a][b][0]){
                    f[a][b][0]=f[now.x][now.y][2]+t+w[a][b];
                    flag=true;
                }
                if(flag) que.push((node){a,b});
            }
        }
    }
    return min(min(min(f[n][n][3],f[n][n][0]),f[n][n][1]),f[n][n][2]);
}
int main(){
    scanf("%lld%lld",&n,&t);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%lld",&w[i][j]);
    printf("%lld",bfs());
    return 0;
}
