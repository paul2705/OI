#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e4+5;
const int MAXM=MAXN*2;
const int inf=1e9;
int edge,head[MAXN],nex[MAXM],tail[MAXM],w[MAXM];
int n,m;
int sz[MAXN],st[MAXN],top;
bool use[MAXN];
int ans[10000005];
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void dfs1(int u,int p){
	sz[u]=1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		if (use[v]) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
	}
}
int sel(int u){
	for (int i=1;i<=n;i++) sz[i]=-1;
	dfs1(u,0);
	int alsz=sz[u],pos=u,mn=inf;
//	cout<<__func__<<" :"<<u<<" "<<alsz<<endl;
	for (int i=1;i<=n;i++){
		if (sz[i]==-1) continue;
		int mx=0;
		for (int e=head[i];e;e=nex[e]){
			int v=tail[e];
			if (sz[v]>sz[i]) continue;
			if (use[v]) continue;
			mx=max(mx,sz[v]);
		}
		mx=max(mx,alsz-sz[i]);
//		cout<<i<<" "<<mx<<" "<<mn<<" "<<pos<<endl;
		if (mx<mn) mn=mx,pos=i;
	}
	return pos;
}
void dfs2(int u,int p,int d){
	st[++top]=d;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		if (use[v]) continue;
		dfs2(v,u,d+w[e]);
	}
}
void work(int u,int d,int t){
	top=0; dfs2(u,0,d);
	for (int i=1;i<top;i++){
		for (int j=i+1;j<=top;j++){
			ans[st[i]+st[j]]+=t;
		}
	}
}
void solve(int u,int p){
//	cout<<__func__<<" "<<u<<" "<<p<<endl;
	use[u]=1;
	work(u,0,1);
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (use[v]) continue;
		work(v,w[e],-1);
		solve(sel(v),u);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	solve(sel(1),0);
	for (int i=1;i<=m;i++){
		int k;
		scanf("%d",&k);
//		cout<<ans[k]<<" ";
		if (ans[k]>0) printf("AYE\n");
		else printf("NAY\n");
	}
	return 0;
}
