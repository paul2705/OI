#include<iostream>
#include<cstdio>
#include<cstring>
#include<deque>
using namespace std;
const int MAXX=550;
int dis[MAXX][MAXX];
bool vis[MAXX][MAXX],Map[MAXX][MAXX];
int dx[4]={1,-1,1,-1};
int dy[4]={1,-1,-1,1};
int t,r,c;
char s[MAXX];
inline void init(){
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
}
inline bool check(int x,int y){
    if(x>=1&&y>=1&&x<=r+1&&y<=c+1)return true;
    else return false;
}
inline int edge(int x,int xx,int y,int yy){
    if((xx<x&&yy<y)||(xx>x&&yy>y))return !Map[min(x,xx)][min(y,yy)];
    else return Map[min(x,xx)][min(y,yy)];
}
inline void bfs(){
    Map[0][0]=1;
    deque< pair < pair<int ,int> ,pair<int ,int > > >q;
    pair<int ,int > u=make_pair(0,0);
    pair<int ,int > v=make_pair(1,1);
    q.push_back(make_pair(u,v));
    dis[0][0]=0;
    while(!q.empty()){
        pair< pair<int ,int > , pair<int ,int > >t=q.front();
        q.pop_front();
        pair<int ,int >u=t.first;
        pair<int ,int >v=t.second;
        int xx=u.first;
        int yy=u.second;
        int x=v.first;
        int y=v.second;
        if(vis[x][y])continue;
        dis[x][y]=dis[xx][yy]+edge(x,xx,y,yy);
        vis[x][y]=1;
        for(int i=0;i<4;++i){
            int xv=x+dx[i];
            int yv=y+dy[i];
            pair<int ,int >s=make_pair(xv,yv);
            if(check(xv,yv)&&!vis[xv][yv]){
                if(edge(xv,x,yv,y))q.push_back(make_pair(v,s));
                else q.push_front(make_pair(v,s));
            }
        }
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        init();
        scanf("%d%d",&r,&c);
        for(int i=1;i<=r;++i){
            scanf("%s",s+1);
            for(int j=1;j<=c;++j)
            if(s[j]=='\\')Map[i][j]=1;
            else Map[i][j]=0;
        }
        bfs();
        if(vis[r+1][c+1])printf("%d\n",dis[r+1][c+1]);
        else printf("NO SOLUTION\n");
    }
    return 0;
}
