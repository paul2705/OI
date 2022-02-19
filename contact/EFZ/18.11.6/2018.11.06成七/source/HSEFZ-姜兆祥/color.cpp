#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n,m;
int p[MAXN];
vector<int> c[MAXN];
vector<int> G[MAXN];

int d[MAXN];
int fa[18][MAXN];

void dfs(int u,int p){
	d[u]=d[p]+1;
	fa[0][u]=p;
	for(int i=0;i<(int)G[u].size();i++){
		int v=G[u][i];
		if(v==p)
			continue;
		dfs(v,u);
	}
}

int lca(int u,int v){
	if(d[u]<d[v])
		swap(u,v);
	for(int i=17;i>=0;i--)
		if(d[fa[i][u]]>=d[v])
			u=fa[i][u];
	if(u==v)
		return u;
	for(int i=17;i>=0;i--)
		if(fa[i][u]!=fa[i][v]){
			u=fa[i][u];
			v=fa[i][v];
		}
	return fa[0][u];
}

struct node{
	int l,r,col;
}num[MAXN];

int deg[MAXN];
int mapp[1005][1005];

queue<int> q;

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);

	scanf("%d%d",&n,&m);

	for(int i=1;i<=n;i++){
		scanf("%d",p+i);
		c[p[i]].push_back(i);
	}

	for(int i=0;i<n-1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}

	dfs(1,0);

	for(int i=1;i<18;i++)
		for(int u=1;u<=n;u++)
				fa[i][u]=fa[i-1][fa[i-1][u]];

	for(int i=1;i<=m;i++){
		if(!c[i].size())
			continue;
		int mx=c[i][0];
		for(int j=1;j<c[i].size();j++)
			if(d[c[i][j]]>d[mx])
				mx=c[i][j];
		int mi=mx;
		for(int j=0;j<c[i].size();j++){
			int k=lca(mx,c[i][j]);
			if(d[k]<=d[mi])
				mi=k;
		}
		int an=mi;
		for(int j=0;j<c[i].size();j++)
			if(lca(mx,c[i][j])==mi){
				if(d[c[i][j]]>=d[an])
					an=c[i][j];
			}
		num[i]=(node){mx,an,i};

//		cout<<i<<"  "<<mx<<" "<<an<<endl;

		while(d[mx]>d[an]){
			mx=fa[0][mx];
			if(p[mx]!=i){
				mapp[i][p[mx]]=1;
			}
		}
		while(mx!=an){
			mx=fa[0][mx];
			if(p[mx]!=i){
				mapp[i][p[mx]]=1;
			}
			an=fa[0][an];
			if(p[an]!=i){
				mapp[i][p[an]]=1;
			}
		}
	}

	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++)
			if(mapp[i][j])
				deg[j]++;
	}

	for(int i=1;i<=m;i++){
		if((int)c[i].size()==0){
			printf("%d 1 1\n",i);
		}
		else{
			if(deg[i]==0)
				q.push(i);
		}
	}

	while(!q.empty()){
		int u=q.front();
		q.pop();
		printf("%d %d %d\n",num[u].col,num[u].l,num[u].r);
		for(int i=1;i<=m;i++){
			if(mapp[u][i]){
				deg[i]--;
				if(deg[i]==0)
					q.push(i);
			}
		}
	}

	return 0;
}
