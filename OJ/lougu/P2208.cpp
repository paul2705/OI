#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxl=510;
const int d[]={-1,1};
int n,m;
char ma[maxl][maxl];
bool vis[maxl][maxl];
struct node{
    int x,y,t;
    bool down;
}S,E;
queue<node> q;
node fall(node P){
    do{
        if(P.x==E.x&&P.y==E.y){
            printf("%d\n",P.t);
            exit(0);
        }
        P.x+=d[P.down];
    }while(ma[P.x][P.y]!='#');
    P.x-=d[P.down];
    return P;
}
void dfs(int x,int y,int t,bool down,bool right){
    if(vis[x][y]==false||ma[x][y]=='#') return;
    if(ma[x+d[down]][y]!='#'){
        node Tmp=fall((node){x,y,t,down});
        x=Tmp.x,y=Tmp.y;
        if((down&&x==n)||(!down&&x==1)||vis[x][y]==false){
            vis[x][y]=false;
            return;
        }
        vis[x][y]=false;
        q.push(Tmp);
        dfs(x,y-1,t,down,0);
        dfs(x,y+1,t,down,1);
    }
    else{
        vis[x][y]=false;
        if(x==E.x&&y==E.y){
            printf("%d\n",t);
            exit(0);
        }
        q.push((node){x,y,t,down});
        dfs(x,y+d[right],t,down,right);
    }
}
void bfs(){
    q.push(S);
    while(!q.empty()){
        node P=q.front();q.pop();
        int x=P.x,y=P.y,t=P.t;
        bool down=P.down;
        dfs(x, y-1, t, down, 0);
        dfs(x, y+1, t, down, 1);
        down=P.down^1;
        x+=d[down];
        if(vis[x][y]==true&&ma[x][y]!='#'){
            node Tmp=fall((node){x,y,t+1,down});
            x=Tmp.x,y=Tmp.y;
            if((down&&x==n)||(!down&&x==1)||vis[x][y]==false){
                vis[x][y]=false;
                continue;
            }
            vis[x][y]=false;
            q.push(Tmp);
            vis[x-d[down]][y]=false;
        }
    }
    printf("-1\n");
}
int main(){
    scanf("%d%d",&n,&m);
//  memset(vis,false,sizeof(vis));
    memset(ma,'#',sizeof(ma));
    for(int i=1;i<=n;i++){
        scanf("%s",ma[i]+1);
        for(int j=1;j<=m;j++){
            if(ma[i][j]=='.') vis[i][j]=true;
            else if(ma[i][j]=='C') S=(node){i,j,0,true},ma[i][j]='.',vis[i][j]=false;
            else if(ma[i][j]=='D') E=(node){i,j,0},ma[i][j]='.',vis[i][j]=true;
        }
    }
    S=fall(S);
    if(S.x==n){
        printf("-1\n");
        exit(0);
    }
    vis[S.x][S.y]=false;
    bfs();
    return 0;
}
