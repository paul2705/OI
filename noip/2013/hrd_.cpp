#include<iostream>
#include<queue> 
#include<cstdio> 
#include<cstring>
#include<algorithm>
using namespace std;
const int N=50,inf=0x3f3f3f3f;
struct a{int x,y;}qs[400000]; 
int mov[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int mapp[N][N],node[N][N][4],inq[4*N*N];
int temp[N][N],dis[N][N][4][4],diss[4*N*N];
int p[4*N*N],noww[16*N*N],goal[16*N*N],val[16*N*N];
int n,m,q,f,b,cnt,num,t1,t2,t3,t4,t5,t6,s,t,tep,p1,p2;
queue<int> qx; 
bool ok(int xx,int yy)
{
    return xx>=1&&xx<=n&&yy>=1&&yy<=m&&mapp[xx][yy];
}
void link(int f,int t,int v)
{
    noww[++cnt]=p[f],p[f]=cnt;
    goal[cnt]=t,val[cnt]=v;
}
int GET_DIS(int sx,int sy,int ex,int ey)
{
    if(sx==ex&&sy==ey) return 0;
    memset(temp,-1,sizeof temp);
    temp[sx][sy]=0,qs[f=b=0]=(a){sx,sy};
    while(f<=b)
    {
        int tx=qs[f].x,ty=qs[f].y;
        for(int i=0;i<4;i++)
        {
            int nx=tx+mov[i][0],ny=ty+mov[i][1];
            if(ok(nx,ny)&&temp[nx][ny]==-1)
            {
                temp[nx][ny]=temp[tx][ty]+1; qs[++b]=(a){nx,ny};
                if(nx==ex&&ny==ey) return temp[nx][ny];
            }
        }
        f++;
    } 
    return inf;
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&mapp[i][j]);
            for(int k=0;k<4;k++)
                node[i][j][k]=++num;
        }
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(mapp[i][j])
            {
                mapp[i][j]=0;
                for(int k=0;k<4;k++)
                    if(ok(t1=i+mov[k][0],t2=j+mov[k][1]))
                        for(int h=0;h<4;h++)
                            if(ok(t3=i+mov[h][0],t4=j+mov[h][1]))
                                dis[i][j][k][h]=GET_DIS(t1,t2,t3,t4)+1,printf("%d %d %d %d %d\n",i,j,k,h,dis[i][j][k][h]);
                mapp[i][j]=1;
            }  
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=0;k<4;k++)
                for(int h=0;h<4;h++)
                    if(dis[i][j][k][h]<inf)
                        link(node[i][j][k],node[i+mov[h][0]][j+mov[h][1]][h^1],dis[i][j][k][h]),printf("%d %d %d\n",node[i][j][k],node[i+mov[h][0]][j+mov[h][1]][h^1],dis[i][j][k][h]);
    while(q--)
    {
        scanf("%d%d%d%d%d%d",&t1,&t2,&t3,&t4,&t5,&t6);
        if(t3==t5&&t4==t6) {printf("0\n");continue;} 
        s=++num; t=++num;
        mapp[t3][t4]=0;
        for(int i=0;i<4;i++)
            if(mapp[p1=t3+mov[i][0]][p2=t4+mov[i][1]])
                if((tep=GET_DIS(t1,t2,p1,p2))<inf) link(s,node[t3][t4][i],tep),printf("%d %d %d\n",s,node[t3][t4][i],tep);
        mapp[t3][t4]=1;
        for(int i=0;i<4;i++)
            if(mapp[t5+mov[i][0]][t6+mov[i][1]]) link(node[t5][t6][i],t,0),printf("%d %d %d\n",node[t5][t6][i],t,0);
        memset(diss,0x3f,sizeof diss),diss[s]=0; qx.push(s),inq[s]=1; 
        while(!qx.empty())
        {
            int tn=qx.front();
            qx.pop(); inq[tn]=0;
            for(int i=p[tn];i;i=noww[i])
                if(diss[goal[i]]>diss[tn]+val[i])
                {
                     diss[goal[i]]=diss[tn]+val[i];
                     if(!inq[goal[i]]) qx.push(goal[i]),inq[goal[i]]=1;
                }
        }
		for (int i=1;i<=cnt;i++) cout<<diss[i]<<" "; cout<<endl;
		diss[t]==inf?printf("-1\n"):printf("%d\n",diss[t]);
    }
    return 0;
} 
