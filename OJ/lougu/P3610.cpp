#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 25
const int px[4]={-1,0,1,0},py[4]={0,1,0,-1};
bool blk[N][N],mrk[N][N][4][N][N][4];
int n,dst[N][N][4][N][N][4],head,tail=1;
struct P{
    int x,y,d;
    bool IsnInBound(){return x<1||x>n||y<1||y>n||blk[x][y];}
};
struct S{
    P p1,p2;
    int& get(){return dst[p1.x][p1.y][p1.d][p2.x][p2.y][p2.d];}
    bool IsMrked(){return mrk[p1.x][p1.y][p1.d][p2.x][p2.y][p2.d];}
    void Mark(){mrk[p1.x][p1.y][p1.d][p2.x][p2.y][p2.d]=true;}
};
void move(P& d,P f,int w){
    d=f;
    if(w==0){
        if(d.x==1&&d.y==n)return;
        d.x+=px[d.d],d.y+=py[d.d];
        if(d.IsnInBound())d=f;
    }else if(w==1){
        d.d++;
        if(d.d==4)d.d=0;
    }else if(w==2){
        d.d--;
        if(d.d==-1)d.d=3;
    }
}
S q[N*N*N*N*16];
int main(){
    memset(dst,0x7f,sizeof(dst));
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        getchar();
        for(int j=1;j<=n;j++){
            blk[i][j]='H'==getchar();
        }
    }
    q[0].p1.x=q[0].p2.x=n,q[0].p1.y=q[0].p2.y=q[0].p2.d=1;
    q[0].get()=0;
    S p,nx;
    while(head<tail){
        S p=q[head++],nx;
        int w=p.get();
        for(int i=0;i<3;i++){
            move(nx.p1,p.p1,i),move(nx.p2,p.p2,i);
            int &nd=nx.get();
            if(nd>w+1){
                nd=w+1;
                if(!nx.IsMrked())q[tail++]=nx,nx.Mark();
            }
        }
    }
    int ans=0x7f7f7f7f;
    for(int i=0;i<4;i++)for(int j=0;j<4;j++)ans=std::min(ans,dst[1][n][i][1][n][j]);
    printf("%d\n",ans);
    return 0;
}
