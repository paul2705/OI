#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int SG[30],a[30],fz[1000];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int t,n;cin>>t;int a[30],cnt[30];
    while(t--)
    {
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            int len;
            memset(cnt,0,sizeof cnt);
            cin>>len;
            for(int j=1;j<=len;++j)
                cin>>a[j],cnt[a[j]]++;
            int tot=0,x=20,fg=0;
//          for(int j=1;j<=20;++j)printf("cnt=%d\n",cnt[j]);
            while(cnt[x])--x;
            for(;x;--x)
            {
//              printf("tot=%d\n",tot);
                if(!cnt[x])ans^=(fg?tot:0),fg^=1,tot=0;
                else ++tot;
//              printf("ans=%d i=%d tot=%d\n",ans,x,tot);
            }
            ans^=(fg?tot:0);
        }
        cout<<(ans?"YES":"NO")<<endl;
    }
    return 0;
}
