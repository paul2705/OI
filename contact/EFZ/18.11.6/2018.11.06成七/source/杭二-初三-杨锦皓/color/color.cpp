#include<bits/stdc++.h>
using namespace std;
#define N 100003

int n,m,nedge,tim,top;
int head[N],p[N],deep[N],col[N],F[N],tin[N],tout[N],f[N][30],vis[N],stk[N];
struct Edge{
	int to,next;
}edge[2*N];
struct Color{
	int col,Max,Min,deep;
}s[N];
vector<int>vec[N];

void addedge(int a,int b){
	edge[nedge].to=b;
	edge[nedge].next=head[a];
	head[a]=nedge++;	
}

void dfs(int u,int fa,int d){
	tin[u]=++tim;
	f[u][0]=fa;	
	deep[u]=d;
	for (int i=head[u];i!=-1;i=edge[i].next){
		int v=edge[i].to;
		if (v==fa) continue;
		dfs(v,u,d+1);	
	}
	tout[u]=++tim;
}

bool ancestor(int x,int y){
	if (tin[x]<=tin[y] && tout[x]>=tout[y]) return true;
	return false;	
}

int query(int x,int y){
	if (ancestor(x,y)) return x;
	if (ancestor(y,x)) return y;
	for (int i=20;i>=0;i--)
	  if (!ancestor(f[x][i],y)) x=f[x][i];
	return f[x][0];	
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	  scanf("%d",&p[i]);
	memset(head,-1,sizeof(head));
	for (int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);	
	}
	dfs(1,0,1);
	f[1][0]=1;
	for (int j=1;j<=20;j++)
	  for (int i=1;i<=n;i++)
	    f[i][j]=f[f[i][j-1]][j-1];
	for (int i=1;i<=m;i++)
	  col[i]=0;
	for (int i=1;i<=n;i++){
		if (deep[i]>col[p[i]]){
			col[p[i]]=deep[i];
			F[p[i]]=i;	
		}
	  	vec[p[i]].push_back(i);
	}
	for (int i=1;i<=m;i++){
		int t=F[i],now,h=0;
		s[i].col=i;
		s[i].Max=t;
		s[i].deep=deep[t];
		now=t;
		for (int j=0;j<vec[i].size();j++){
			int lca=query(t,vec[i][j]);
			if (deep[t]+deep[vec[i][j]]-2*deep[lca]>h){
				h=deep[t]+deep[vec[i][j]]-2*deep[lca];
				now=vec[i][j];	
			}
		}
		s[i].Min=now;
	}
	while (top!=m){
		int t;
		for (int i=1;i<=m;i++){
			if (vis[i]) continue;
			int u=s[i].Min,v=s[i].Max,kind,fx,fy;
			fx=u;fy=v;
			int lca=query(u,v);
			kind=1;
			while (u!=lca){
				u=f[u][0];
				if (p[u]!=s[i].col && p[u]!=0){
					kind++;
					break;	
				}
			}
			while (v!=lca){
				v=f[v][0];
				if (p[v]!=s[i].col && p[v]!=0){
					kind++;
					break;
				}
			}
			if (kind==1){
				u=fx;v=fy;
				vis[i]=1;
				t=i;
				p[u]=p[v]=0;
				while (u!=lca){
					u=f[u][0];
					p[u]=0;
				}
				while (v!=lca){
					v=f[v][0];
					p[v]=0;
				}
				break;
			}
		}
		stk[++top]=t;
	}
	for (int i=top;i>=1;i--)
	  printf("%d %d %d\n",s[stk[i]].col,s[stk[i]].Min,s[stk[i]].Max);
	return 0;	
}
