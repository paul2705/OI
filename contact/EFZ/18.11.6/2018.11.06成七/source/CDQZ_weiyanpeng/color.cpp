#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=2e5+5;
int hed[N],to[M],nxt[M],cnt=1;
void adde(int u,int v){
	++cnt;to[cnt]=v,nxt[cnt]=hed[u];hed[u]=cnt;
}
int colo[N],p[N];
int dep[N],fa[N];
int pree[N];
bool vis[M];
int n,m;
inline void bld(int x,int pre){
	dep[x]=dep[pre]+1;
	fa[x]=pre;
	for(int i=hed[x];i;i=nxt[i]){
		int v=to[i];if(v==pre)continue;
		pree[v]=x;
		bld(v,x);
	}
}
int anc[N][20];
inline void init(){
	for(int i=1;i<=n;i++)anc[i][0]=fa[i];
	for(int i=1;i<=17;++i){
		for(int x=1;x<=n;x++)anc[x][i]=anc[anc[x][i-1]][i-1];
	}
}
inline int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=17;~i;i--)if(dep[anc[x][i]]>=dep[y])x=anc[x][i];
	if(x==y)return x;
	for(int i=17;~i;i--)if(anc[x][i]!=anc[y][i]){
		x=anc[x][i],y=anc[y][i];
	}
	return fa[x];
}
int uu[N],vv[N];
inline void dfs(int x,int pre){
	int c=p[x];
	if(!uu[c])vv[c]=uu[c]=x;
	else if(lca(vv[c],x)==vv[c])vv[c]=x;
	else uu[c]=x;
	for(int i=hed[x];i;i=nxt[i]){
		int v=to[i];if(v==pre)continue;
		dfs(v,x);
	}
}
namespace graph{
	int hedd[N],too[M*10],nxtt[M*10],cntt;
	int dd[N];
	void addee(int u,int v){
		++cntt;too[cntt]=v,nxtt[cntt]=hedd[u];hedd[u]=cntt;
		dd[v]++;
	}
	queue<int>Q;
	inline void topo(){
		for(int i=1;i<=m;i++)if(dd[i]==0)Q.push(i);
		while(!Q.empty()){
			int x=Q.front();Q.pop();
			if(uu[x])printf("%d %d %d\n",x,uu[x],vv[x]);
			for(int i=hedd[x];i;i=nxtt[i]){
				int v=too[i];
				dd[v]--;
				if(!dd[v])Q.push(v);
			}
		}
	}
}

inline void solve(int x,int y,int c){
	int ca=lca(x,y);
	int pr=x;
	while(pr!=ca){
		if(c!=p[pr]){
			graph::addee(c,p[pr]);
		}
		pr=fa[pr];
	}
	pr=y;
	while(pr!=ca){
		if(c!=p[pr]){
			graph::addee(c,p[pr]);
		}
		pr=fa[pr];
	}
	if(c!=p[ca])graph::addee(c,p[ca]);
}

int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		adde(u,v);adde(v,u);
	}
	bld(1,0);
	init();
	dfs(1,0);
	for(int i=1;i<=m;i++)if(uu[i]){
		solve(uu[i],vv[i],i);
	}
	else printf("%d 1 1\n",i);
	graph::topo();
}
/*
6 3
1 3 2 1 1 2
1 4
2 4
3 4
4 5
5 6
*/
