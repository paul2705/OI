#include<iostream> 
#include<cstdio> 
#include<cstring> 
using namespace std; 
#define MAXN 8020 
#define MAXM 20020 
int n,m; 
struct node 
{ 
    int v; 
    node *next; 
}; 
node edge[MAXM*2]; 
node *cnt=&edge[0]; 
node *adj[MAXN]; 
node edge2[MAXM*2]; 
node *cnt2=&edge2[0]; 
node *adj2[MAXN]; 
int dfn[MAXN],low[MAXN],dcnt; 
int stack[MAXN],top; 
int Belong[MAXN],Num[MAXN],opp[MAXN],scc; 
int In[MAXN],q[MAXN],col[MAXN]; 
bool Instack[MAXN],ans[MAXN]; 
inline void Get_int(int &Ret) 
{ 
    char ch; 
    bool flag=false; 
    for(;ch=getchar(),ch<'0'||ch>'9';) 
        if(ch=='-') 
            flag=true; 
    for(Ret=ch-'0';ch=getchar(),ch>='0'&&ch<='9';Ret=Ret*10+ch-'0'); 
    flag&&(Ret=-Ret); 
} 
inline int Get(int x) 
{ 
    if(x%2) 
        return x+1; 
    return x-1; 
} 
inline void Addedge(int u,int v) 
{ 
    node *p=++cnt; 
    p->v=v; 
    p->next=adj[u]; 
    adj[u]=p; 
} 
inline void Addedge2(int u,int v) 
{ 
    node *p=++cnt2; 
    p->v=v; 
    p->next=adj2[u]; 
    adj2[u]=p; 
} 
void Read() 
{ 
    Get_int(n); 
    n*=2; 
    Get_int(m); 
    int i,j,k; 
    for(i=1;i<=m;i++) 
    { 
        Get_int(j); 
        Get_int(k); 
        Addedge(j,Get(k)); 
        Addedge(k,Get(j)); 
    } 
} 
void Tarjan(int u) 
{ 
    int v; 
    dfn[u]=low[u]=++dcnt; 
    stack[++top]=u; 
    Instack[u]=true; 
    for(node *p=adj[u];p;p=p->next) 
    { 
        v=p->v; 
        if(!dfn[v]) 
        { 
            Tarjan(v); 
            low[u]=min(low[u],low[v]); 
        } 
        else if(Instack[v]) 
            low[u]=min(low[u],dfn[v]); 
    } 
    if(dfn[u]==low[u]) 
    { 
        scc++; 
        do
        { 
            v=stack[top]; 
            top--; 
            Instack[v]=false; 
            Belong[v]=scc; 
            Num[scc]++; 
        }while(v!=u); 
    } 
} 
bool Work() 
{ 
    int i; 
    for(i=1;i<=n;i++) 
        if(!dfn[i]) 
            Tarjan(i); 
    for(i=1;i<=n;i+=2) 
    { 
        if(Belong[i]==Belong[i+1]) 
            return false; 
        opp[Belong[i]]=Belong[i+1]; 
        opp[Belong[i+1]]=Belong[i]; 
    } 
    int u,v; 
    for(i=1;i<=n;i++) 
        for(node *p=adj[i];p;p=p->next) 
        { 
            v=p->v; 
            if(Belong[i]!=Belong[v]) 
            { 
                Addedge2(Belong[v],Belong[i]); 
                In[Belong[i]]++; 
            } 
        } 
    int l=0,r=0; 
    for(i=1;i<=scc;i++) 
        if(!In[i]) 
        { 
            q[r]=i; 
            r++; 
        } 
    while(l<r) 
    { 
        u=q[l]; 
        l++; 
        if(!col[u]) 
        { 
            col[u]=1; 
            col[opp[u]]=-1; 
        } 
        for(node *p=adj2[u];p;p=p->next) 
        { 
            v=p->v; 
            In[v]--; 
            if(!In[v]) 
            { 
                q[r]=v; 
                r++; 
            } 
        } 
    } 
    for(i=1;i<=n;i+=2) 
        if(col[Belong[i]]==1) 
            ans[i]=true; 
    return true; 
} 
void Print() 
{ 
    if(Work()) 
    { 
        int i; 
        for(i=1;i<=n;i+=2) 
            if(ans[i]) 
                printf("%d\n",i); 
            else
                printf("%d\n",i+1); 
    } 
    else
        printf("NIE\n"); 
} 
int main() 
{ 
    Read(); 
    Print(); 
    return 0; 
}
