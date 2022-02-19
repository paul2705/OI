#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN=3e5+5;
const int MAXM=3e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int fa[MAXN];
ll ans[MAXN];
int n,a[MAXN],rt;
struct rec{
	int u,v;
};
vector<rec> ed[MAXN];
void add(int u,int v){
//	cout<<u<<" "<<v<<endl;
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){ fa[find(x)]=find(y); }
void dfs(int u,int p){
	ans[u]+=ans[p];
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		fa[i]=i;
		scanf("%d",&a[i]);
	}
	for (int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		int mx=max(a[u],a[v]);
		if (a[u]<a[v]) swap(u,v);
		ed[mx].push_back((rec){u,v});
	}
	for (int i=1;i<=n;i++){
		for (int j=0;j<ed[i].size();j++){
			rec x=ed[i][j];
			int u=x.u,v=x.v;
			if (a[u]==a[v]) continue;
			v=find(v); ans[v]+=u;
		}
		for (int j=0;j<ed[i].size();j++){
			rec x=ed[i][j];
			int u=x.u,v=x.v;
			v=find(v); u=find(u);
			add(u,v);
			uion(v,u);
		}
	}
	dfs(find(1),0);
	for (int i=1;i<=n;i++){
		printf("%lld ",ans[i]+i);
	}
	return 0;
}
