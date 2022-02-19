#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e5+5;
const int MAXM=2e6+6;
int edge,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
int n,m,d[MAXN],ans1[MAXN],ans2[MAXN];
int res=0;
struct rec{
	int u,v,w;
} ed[MAXN];
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void dfs(int u,int p){
//	d[u]=d[p]+w[e];
//	cout<<__func__<<" "<<u<<" "<<p<<endl;
	if (d[res]<=d[u]) res=u;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		d[v]=d[u]+w[e];
		dfs(v,u);
	}
}
int main(){
	freopen("highway.in","r",stdin);
	freopen("highway.ans","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		ed[i]=(rec){u,v,w};
	}
	for (int i=n-1;i>=1;i--){
		int u=ed[i].u,v=ed[i].v,w=ed[i].w;
		res=0; dfs(u,0); 
//		cout<<i<<" "<<res<<endl; 
		d[res]=0;
		dfs(res,0);
		ans1[i]=d[res];
		res=0; dfs(v,0); 
//		cout<<i<<" "<<res<<endl;
		d[res]=0;
		dfs(res,0);
		ans2[i]=d[res];
		if (ans1[i]>ans2[i]) swap(ans1[i],ans2[i]);
		add(u,v,w); add(v,u,w);
	}
	for (int i=1;i<n;i++) printf("%d %d\n",ans1[i],ans2[i]);
	fclose(stdin); fclose(stdout);
	return 0;
}
