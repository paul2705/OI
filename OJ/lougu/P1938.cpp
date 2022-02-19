#include<cstdio>
#include<cstring>
using namespace std;
const int MaxN=99999999;
int d,p,c,f,s;
int first[221],next[501],dis[221];
struct Node{
    int u,v,w;
}mapp[501];
int main()
{
    int i,j,pd,a,minn,x;
    scanf("%d%d%d%d%d",&d,&p,&c,&f,&s);
    for(i=1;i<=p;i++)
    {
        scanf("%d%d",&mapp[i].u,&mapp[i].v);
        mapp[i].w=-d;         //注意存边
    }
    for(i=p+1;i<=p+f;i++)
    {
        scanf("%d%d%d",&mapp[i].u,&mapp[i].v,&a);
        mapp[i].w=a-d;        //注意存边
    }
    for(i=1;i<=c;i++)
        dis[i]=MaxN;
    dis[s]=0;
    for(i=1;i<c;i++)
    {
        pd=false;   //加上pd可以优化bellman-ford，减少无用功
        for(j=1;j<=p+f;j++)
            if(dis[mapp[j].v]>dis[mapp[j].u]+mapp[j].w)
            {
                pd=true;
                dis[mapp[j].v]=dis[mapp[j].u]+mapp[j].w;
            }
        if(pd==false) break;
    }
    //判负环
    pd=false;
    for(j=1;j<=p+f;j++)
            if(dis[mapp[j].v]>dis[mapp[j].u]+mapp[j].w)
            {
                pd=true;
                dis[mapp[j].v]=dis[mapp[j].u]+mapp[j].w;
            }
    if(pd==true) 
    {
        printf("-1\n");
        return 0;
    }
    minn=MaxN;
    for(i=1;i<=c;i++)
        if(dis[i]<minn)
        {
            minn=dis[i];
            x=i;
        }
    printf("%d\n",(-1)*dis[x]+d);//最终的答案还要加上起点的d
    return 0;
}
