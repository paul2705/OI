#include<cmath>
#include<cstdio> 
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

const int N=1000100;
int a[N],b[N],c[N],n,m,len;

void up(int x)
{
    while (c[x])
    {
        c[x]=c[x-1]=0;
        c[x+1]++; x+=2;
    }
}

void trans(int x)
{
    int k=x-2;
    if(c[x]<2)
        return;
    if(x==2)
        k=1;
    c[x+1]++;
    if(x!=1)
        c[k]++;
    c[x]-=2;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) 
        cin>>a[i];
    cin>>m;
    for(int i=1;i<=m;i++)
        cin>>b[i];
    len=max(n,m);
    for(int i=len;i>=1;i--)
    {
        c[i]+=a[i]+b[i];
        if(c[i]>=2)
        {
            trans(i);
            trans(i+1);
            if(i==1)
                trans(1);
        }
        if(c[i])
            up(i+1);
        if(c[i+1])
            up(i+2);
        if(c[i+2])
            up(i+3);
    }
    while(c[len+1])
        len++;
    if(c[len+2])
        len+=2;
    while(c[len+1])
        len++;
    cout<<len;
    for(int i=1;i<=len;i++)
        cout<<" "<<c[i];
    cout<<endl;
    return 0; 
}
