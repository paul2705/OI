#include<stdio.h>
#include<iostream>
#include<cstdio>
using namespace std;
int n;int p;int c;
int map[800][805];
int d[805][805];
int mark[805];
const int inf=9999999;
int res=inf;
int main()
{
    scanf("%d%d%d",&n,&p,&c);
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<p;j++)
        {
            if(i==j)
            {
                map[i][j]=0;
                d[i][j]=0;
            }
            else
            {
                map[i][j]=inf;
                d[i][j]=inf;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        mark[t-1]++;
    }
    for(int i=0;i<c;i++)
    {
        int u;int v;int val;
        scanf("%d%d%d",&u,&v,&val);
        map[u-1][v-1]=val;
        map[v-1][u-1]=val;
        d[u-1][v-1]=val;
        d[v-1][u-1]=val;
    }
    for(int k=0;k<p;k++)
    {
        for(int i=0;i<p;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(d[i][j]>d[i][k]+d[k][j])
                {
                    d[i][j]=d[i][k]+d[k][j];
                    d[j][i]=d[i][j];
                }
            }
        }
    }
    for(int i=0;i<p;i++)
    {
        int sum=0;
        for(int j=0;j<p;j++)
        {
            sum+=d[i][j]*mark[j];
        }
        if(res>sum)res=sum;
    }
    printf("%d",res);
    return 0;
}
