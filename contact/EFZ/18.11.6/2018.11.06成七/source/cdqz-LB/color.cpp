#include<bits/stdc++.h>
#define FIO "color"
#define INF 0x3f3f3f
#define pb push_back
#define DBUG(...) fprintf(stderr,__VA_ARGS__)
typedef long long ll;
const int MOD=1e9+7,MAXN=1e5+5,MAXM=2e5+5;
using namespace std;
char buf[1<<20];int bufl,bufr;
#define getch ((bufl^bufr||(bufl=0,bufr=fread(buf,1,1<<20,stdin)))?buf[bufl++]:EOF)
template <class T>inline void read(T &x){T f=1;x=0;char ch=getchar();for(;!isdigit(ch)&&ch!='-';ch=getchar());if(ch=='-')f=-1,ch=getchar();for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';x*=f;}
int N,M,t,p[MAXN],u,v,dep[MAXN],f[MAXN][17];
vector<int>col[MAXN],ans[MAXN];
int head[MAXN],to[MAXM],nxt[MAXM],ecnt;
inline void add(int u,int v){nxt[++ecnt]=head[u];head[u]=ecnt;to[ecnt]=v;}
inline void dfs(int u,int fa){
	col[p[u]].pb(u);f[u][0]=fa;
	for(int i=head[u];i;i=nxt[i])if(to[i]^fa)dep[to[i]]=dep[u]+1,dfs(to[i],u);
	if(col[p[u]][col[p[u]].size()-1]==u)	ans[p[u]].pb(u);
}
struct node{
	int a,b,c,l;
	node(int _c=0,int _a=0,int _b=0){a=_a;b=_b;c=_c;}
	bool operator <(const node &t)const{return dep[l]^dep[t.l]?dep[l]<dep[t.l]:(dep[a]>dep[t.a]&&dep[b]>dep[t.b]?1:dep[b]>dep[t.b]);}
}out[MAXN];
inline int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=16;~i;i--)if(dep[f[u][i]]>=dep[v])u=f[u][i];
	if(u==v)return u;
	for(int i=16;~i;i--)if(f[u][i]^f[v][i])u=f[u][i],v=f[v][i];
	return f[u][0];
}
int main(){
	freopen(FIO".in","r",stdin);
	freopen(FIO".out","w",stdout);
	read(N);read(M);
	for(int i=1;i<=N;i++)read(p[i]);
	for(int i=1;i<N;i++)read(u),read(v),add(u,v),add(v,u);
	dfs(1,0);
	for(int i=1;i<=16;i++)
		for (int j=1;j<=N;j++)
			f[j][i]=f[f[j][i-1]][i-1];
	for(int i=1;i<=M;i++)
		switch(ans[i].size()){
			case 0:printf("%d 1 1\n",i);break;
			case 1:out[++t]=node(i,ans[i][0],col[i][0]);break;
			case 2:out[++t]=node(i,ans[i][0],ans[i][1]);if(dep[out[i].a]<dep[out[i].b])swap(out[i].a,out[i].b);break;
		}
	for(int i=1;i<=t;i++)out[i].l=lca(out[i].a,out[i].b);
//	for(int i=1;i<=M;i++){		printf("col%d:",i);		for(unsigned j=0;j<col[i].size();j++)			printf("%d ",col[i][j]);		printf("\n");	}
	sort(out+1,out+t+1);
	for(int i=1;i<=t;i++)printf("%d %d %d\n",out[i].c,out[i].a,out[i].b);
	return 0;
}
