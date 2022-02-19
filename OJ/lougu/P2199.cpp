#include<iostream>
#include<cstring>
using namespace std;
int x[10000001],y[100000001],head,tail=1,d1[4]={0,1,-1,0},d2[4]={1,0,0,-1},n,m,sx,sy,ex,ey,is[1001][1001],ans[1000001];
void search()
{
    for(int i=ex;i<=n;i++)
        if(is[i][ey]==1)
            break;
        else
            is[i][ey]=3;
    for(int i=ex;i>=1;i--)
        if(is[i][ey]==1)
            break;
        else
            is[i][ey]=3;
    for(int i=ey;i<=m;i++)
        if(is[ex][i]==1)
            break;
        else
            is[ex][i]=3;
    for(int i=ey;i>=1;i--)
        if(is[ex][i]==1)
            break;
        else
            is[ex][i]=3;
    for(int i=1;ex+i<=n&&ey+i<=m;i++)
        if(is[ex+i][ey+i]==1)
            break;
        else
            is[ex+i][ey+i]=3;
    for(int i=1;ex-i>=1&&ey+i<=m;i++)
        if(is[ex-i][ey+i]==1)
            break;
        else
            is[ex-i][ey+i]=3;
    for(int i=1;ex+i<=n&&ey-i>=1;i++)
        if(is[ex+i][ey-i]==1)
            break;
        else
            is[ex+i][ey-i]=3;
    for(int i=1;ex-i>=1&&ey-i>=1;i++)
        if(is[ex-i][ey-i]==1)
            break;
        else
            is[ex-i][ey-i]=3;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        char s[10001];
        cin>>s;
        int len=strlen(s);
        for(int j=0;j<len;j++)
            if(s[j]=='X')
                is[i][j+1]=1;
    }
    while(cin>>ex>>ey>>sx>>sy)
    {
        if(ex==0&&ey==0&&sx==0&&sy==0)
            break;
        int minn=0x7fffffff;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(is[i][j]==2||is[i][j]==3)  //将其赋为不同的值，以便区分
                    is[i][j]=0;
        head=0,tail=1;
        x[1]=sx,y[1]=sy;   //初始化（上面都是）
        search();  //记录可视点
        if(is[sx][sy]==3) //注意！！！有0步的情况，即不用走就能看到！！！
        {
            cout<<0<<endl;
            continue;
        }
        while(head<tail)
        {
            head++;
            for(int i=0;i<4;i++)
            {
                int nowx=x[head]+d1[i];
                int nowy=y[head]+d2[i];
                if(nowx<=n&&nowx>0&&nowy<=m&&nowy>0&&is[nowx][nowy]!=1&&is[nowx][nowy]!=2)
                {
                    x[++tail]=nowx;
                    y[tail]=nowy;
                    ans[tail]=ans[head]+1; //用来记录步数
                    if(is[nowx][nowy]==3)  //到达可视点
                        minn=min(minn,ans[tail]);
                    is[nowx][nowy]=2;
                }
            }
        }
        if(minn==0x7fffffff)
            cout<<"Poor Harry"<<endl;
        else
            cout<<minn<<endl;
    }
}
