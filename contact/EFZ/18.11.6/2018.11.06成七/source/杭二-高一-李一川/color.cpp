#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<iostream>
#include<cmath>
#include<vector>
#define LL long long
#define N (100005)
using namespace std;
int n,m,tot,t,L,now,x,y,h; 
int son[N<<1],nxt[N<<1],head[N],a[N],fa[19][N],st[N],en[N],q[N],d[N],dep[N];
vector <int> col[N]; 
bool vis[N],kill[N];
template <typename T> void read(T&t) {
	t=0;
	bool fl=true;
	char p=getchar();
	while (!isdigit(p)) {
		if (p=='-') fl=false;
		p=getchar();
	}
	do {
		(t*=10)+=p-48;p=getchar();
	}while (isdigit(p));
	if (!fl) t=-t;
}
inline void add(int x,int y){
	son[++tot]=y,nxt[tot]=head[x],head[x]=tot;
}
void dfs(int u){
	for (int p=head[u];p;p=nxt[p]){
		int v=son[p];
		if (fa[0][u]!=v){
			fa[0][v]=u;
			dep[v]=dep[u]+1;
			dfs(v);
		}
	} 
}
int lca(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	for (int i=17;i>=0;i--){
		if ((1<<i)&tmp) x=fa[i][x];
	}
	if (x==y) return x;
	for (int i=17;i>=0;i--){
		if (fa[i][x]!=fa[i][y]) x=fa[i][x],y=fa[i][y];
	}
	return fa[0][x];
}
inline bool cmp(int a,int b){
	return dep[a]>dep[b];
}
void jump(int x){
	while (x!=fa[0][L]){
		if (a[x]!=now) add(now,a[x]),d[a[x]]++;
		else vis[x]=1;
		x=fa[0][x];
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	read(n),read(m);
	for (int i=1;i<=n;i++) read(a[i]),col[a[i]].push_back(i);
	for (int i=1;i<n;i++){
		read(x),read(y);
		add(x,y),add(y,x);
	}
	dfs(1);
	memset(head,0,sizeof(head));
	tot=0;
	for (int j=1;j<=18;j++){
		for (int i=1;i<=n;i++) fa[j][i]=fa[j-1][fa[j-1][i]];
	}
	for (int i=1;i<=m;i++){
		if (col[i].size()==0){
			q[++t]=i;
			st[i]=en[i]=1; 
			kill[i]=1;
			continue;	
		}
		L=col[i][0];
		for (int j=1;j<col[i].size();j++){
			L=lca(L,col[i][j]);
		}
		sort(col[i].begin(),col[i].end(),cmp);
		now=i;
		int tt=0;
		for (int j=0;j<col[i].size();j++){
			if (!vis[col[i][j]]){
				jump(col[i][j]);
				if (!st[i]) st[i]=col[i][j];
				else en[i]=col[i][j];
			}
		}
		if (!en[i]) en[i]=L;
	}
	for (int i=1;i<=m;i++){
		if (!kill[i]&&d[i]==0){
			q[++t]=i;
		}
	}
	while (h<t){
		int u=q[++h];
		for (int p=head[u];p;p=nxt[p]){
			int v=son[p];
			d[v]--;
			if (d[v]==0) q[++t]=v;
		}
	}
	for (int i=1;i<=t;i++){
		printf("%d %d %d\n",q[i],st[q[i]],en[q[i]]);
	}
	return 0;
}

