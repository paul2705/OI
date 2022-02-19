#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=12,L=30,K=(1<<10)+10;
typedef long long LL;
short l,n,len[N],bin[N],tot,cnt,num;
char s[N][N];
struct node{
    node *ch[26],*f;short id,st,meaning;
    node(){memset(ch,0,sizeof(ch)),st=0,id=++cnt;}
}*null,*root,*q[N*N],*data[N*N];
inline node* newnode()
    {node *o=new node();data[cnt]=o;return o;}
inline void add(int x){
    node *rt=root;register int i,d;
    for(i=0;i<len[x];++i){
        d=s[x][i]-'a';
        if(!rt->ch[d])rt->ch[d]=newnode();
        rt=rt->ch[d],rt->meaning=d;
    }
    rt->st=1;
}
inline void get_fail(){
    register int i,hd=1,tl=0;
    node *rt,*u;
    for(i=0,root->f=root;i<26;++i)
        if(root->ch[i])root->ch[i]->f=root,q[++tl]=root->ch[i];
        else root->ch[i]=root;
    while(hd<=tl)
        for(rt=q[hd++],u=rt->f,i=0;i<26;++i)
            if(rt->ch[i])rt->ch[i]->f=u->ch[i],q[++tl]=rt->ch[i];
            else rt->ch[i]=u->ch[i];
    for(i=1;i<=cnt;++i)for(u=data[i]->f;u&&u!=null&&u!=root;u=u->f)u->st=0;
    for(i=1;i<=cnt;++i)if(data[i]->st)data[i]->st=++num;
    for(i=1;i<=cnt;++i)if(data[i]->st)data[i]->st=bin[num-data[i]->st];
}
LL f[L][N*N][K];
struct sol{
    char s[L];
    sol(){memset(s,0,sizeof(s));}
    inline void print(){puts(s);}
    inline bool operator < (const sol &b) const{
        for(register int i=0;i<l;++i)
            if(s[i]!=b.s[i])return s[i]<b.s[i];
    }
}str[50],stack;
void dfs(int len,int id,int state,int now){
    register int i,j,k,st;
    stack.s[len-1]=now+'a';
    if(len==1){str[++tot]=stack;return;}
    for(j=2;j<=cnt;++j)
        if(f[len-1][j][state]&&data[j]->ch[now]->id==id)
            dfs(len-1,j,state,data[j]->meaning);
    if(data[id]->st)
        for(st=state^data[id]->st,j=2;j<=cnt;++j)
            if(f[len-1][j][st]&&data[j]->ch[now]->id==id)
                dfs(len-1,j,st,data[j]->meaning);
}
inline void get_solution(){
    register int i,j;tot=0;
    for(j=2;j<=cnt;++j)
        if(f[l][j][bin[num]-1])
            dfs(l,j,bin[num]-1,data[j]->meaning);
}
int main(){
    scanf("%d%d",&l,&n);root=newnode();
    register int i,j,k,u,v;node *rt;LL ans=0;
    bin[0]=1;for(i=1;i<=n;++i)bin[i]=bin[i-1]<<1;
    for(i=1;i<=n;++i)scanf("%s",s[i]),len[i]=strlen(s[i]),add(i);
    get_fail();
    for(i=0,f[0][1][0]=1;i<l;++i)
        for(j=0;j<=cnt;++j)
            for(rt=data[j],k=0;k<bin[num];++k)
                if(f[i][j][k])for(u=0;u<26;++u)
                    f[i+1][rt->ch[u]->id][k|rt->ch[u]->st]+=f[i][j][k];
    for(j=1;j<=cnt;++j)ans+=f[l][j][bin[num]-1];
    printf("%lld\n",ans);
    if(ans<=42){
        get_solution();sort(str+1,str+ans+1);
        for(i=1;i<=ans;++i)str[i].print();
    }
}
