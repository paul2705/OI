#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=2e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int st[MAXN];
int n,q,ans=0;
int fa[MAXN],f[MAXN];
int dfa[MAXN],df[MAXN];
bool use[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs1(int u,int p){
	int sz=1; dfa[u]=p;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		if (use[v]) continue;
		dfs1(v,u);
		sz+=f[v];
	}
	f[u]=sz;
}
int sel(int u){
	for (int i=1;i<=n;i++) f[i]=0;
	dfs1(u,0);
	int alsz=f[u],alc=0;
	for (int i=1;i<=n;i++) alc+=f[i]>0;
	for (int i=1;i<=n;i++){
		if (f[i]==0) continue;
		int mx=0,cnt=0;
		for (int e=head[i];e;e=nex[e]){
			int v=tail[e];
			if (v==dfa[i]) continue;
			mx=max(mx,f[v]); cnt+=f[v];
		}
		mx=max(mx,alsz-cnt);
		if (mx<alc/2) return i;
	}
	return u;
}
void dfs2(int u,int p){
	df[u]=0;
	int state=(st[u]==0);
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (use[v]) continue;
		if (v==p) continue;
		dfs2(v,u);
		df[u]=max(df[u],df[v]+state);
	}
}
void dfs(int u,int p){
//	cout<<__func__<<" "<<u<<" "<<p<<" ";
	int wu=sel(u);
	cout<<wu<<endl;
	use[wu]=1;
	fa[u]=p;
	int dep=0;
	for (int e=head[wu];e;e=nex[e]){
		int v=tail[e];
		if (use[v]) continue;
		dfs2(v,0);
		df[v]++;
//		cout<<v<<" "<<df[v]<<endl;
		ans=max(ans,dep+df[v]);
		dep=max(dep,df[v]);
	}
	for (int e=head[wu];e;e=nex[e]){
		int v=tail[e];
		if (use[v]) continue;
		dfs(v,wu);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	dfs(1,0);
	scanf("%d",&q);
	for (int i=1;i<=q;i++){
		char c=getchar();
		while (c!='G'&&c!='C') c=getchar();
		int x; scanf("%d",&x);
		if (c=='G') printf("%d\n",ans);
		else {

		}
	}
	printf("%d\n",ans);
	return 0;
}
