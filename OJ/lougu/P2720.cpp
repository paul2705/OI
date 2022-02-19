#include<bits/stdc++.h>
#define N 100005
using namespace std;
vector<int> E[100005];
struct question
{
    int l,r;
    int s;
}ques[N];
struct orz
{
    int l,r;
}sec[N];
int size;
bool cmp(question a , question b)
{
    int x = (a.l-1)/size,y = (b.l-1)/size;
    if(x != y) return x < y;
    return a.r < b.r;
}
int n;
int a[N],w[N];
long long ans[N];
long long last[N];
long long lastsum;
inline void asks(int lastl,int lastr,int left,int right,int k)
{
 //   printf("%d %d %d %d %d\n",lastl,lastr,left,right,k);
    if(lastr < right)
        for(int i = lastr + 1;i <= right;i++)
        {
            if(last[a[i]] == 0) lastsum++;
            last[a[i]]++;
        }
    else if(lastr > right)
        for(int i = right + 1;i <= lastr;i++)
        {
            last[a[i]]--;
            if(last[a[i]] == 0) lastsum--;
        }
   // printf("lastsum = %d\n",lastsum);
    if(lastl < left)
        for(int i = lastl;i <= left - 1;i++)
        {
            last[a[i]]--;
            if(last[a[i]] == 0) lastsum--;
        }
    else if(lastl > left)
        for(int i = left;i <= lastl - 1;i++)
        {
            if(last[a[i]] == 0) lastsum++;
            last[a[i]]++;
        }
    int cnt=0;
    // printf("lastsum = %d\n",lastsum);
    ans[k]= lastsum;
    return;
}
inline void add(int u,int v)
{
    E[u].push_back(v);
}
int dfst = 0;
bool flag;
void dfs(int u)
{
    dfst++;a[dfst]=w[u];
    sec[u].l = dfst;
    for(int i = 0;i < E[u].size();i++)
        dfs(E[u][i]);
    sec[u].r = dfst;
    return;
}
int main()
{
    int q;
    memset(last,0,sizeof(last));
    scanf("%d",&n);
    for(int i = 2;i <= n;i++)
    {
        int s;
        scanf("%d",&s);
        add(s,i);
    }
    int l,r;
    size = (int)sqrt(n)+1;
    for(int i = 1;i <= n;i++){
        scanf("%d",&w[i]);
    }
    dfs(1);
    scanf("%d",&q);
    for(int i = 0;i < q;i++){
        int p;
        scanf("%d",&p);
        ques[i].l = sec[p].l;
        ques[i].r = sec[p].r;
        ques[i].s = i;
    }
    sort(ques,ques+q,cmp);
    l = 1,r = 1;
    lastsum = 1;
    last[a[1]] = 1;
    for(int i = 0;i < q;i++){
        asks(l,r,ques[i].l,ques[i].r,ques[i].s);
        l = ques[i].l,r = ques[i].r;
    }
    for(int i = 0;i < q;i++)
        printf("%d\n",ans[i]);
    return 0;
}
