#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=5e5+5;
const int MAXM=1e6+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int redge,rhead[MAXN],rtail[MAXM],rnex[MAXM];
int a[MAXN],d[MAXN],scc,s[MAXN],top,cnt;
int n,m,S,p,bar[MAXN],f[MAXN],use[MAXN];
int dfn[MAXN],low[MAXN],bel[MAXN],w[MAXN];
queue<int> q;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void radd(int u,int v){
	redge++,rnex[redge]=rhead[u],rhead[u]=redge,rtail[redge]=v;
}
void tarjan(int u){
	s[++top]=u,use[u]=1; dfn[u]=low[u]=++cnt;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (!dfn[v]){ tarjan(v); low[u]=min(low[u],low[v]); }
		else if (use[v]) low[u]=min(low[u],dfn[v]);
	}
	if (dfn[u]==low[u]){
		int x=s[top]; scc++;
//		cout<<"in"<<endl;
		do{
//			cout<<x<<" ";
			x=s[top--];
			use[x]=0; bel[x]=scc;
			w[scc]+=a[x];
		} while (x!=u);
//		cout<<"out"<<endl;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0,u,v;i<m;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d%d",&S,&p);
	for (int i=1;i<=p;i++) scanf("%d",&bar[i]);
	for (int i=1;i<=n;i++){
		if (!dfn[i]) tarjan(i);
	}
//	tarjan(S);
	for (int u=1;u<=n;u++){
//		cout<<u<<" "<<bel[u]<<endl;
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (bel[u]!=0&&bel[v]!=0&&bel[u]!=bel[v]){
				radd(bel[u],bel[v]);
				d[bel[v]]++;
			}
		}
	}
//	for (int i=1;i<=n;i++) if (d[bel[i]]==0) q.push(bel[i]);
	q.push(bel[S]); f[bel[S]]=w[bel[S]];
	while (!q.empty()){
		int u=q.front(); q.pop();
//		cout<<u<<endl;
		for (int e=rhead[u];e;e=rnex[e]){
			int v=rtail[e];
			f[v]=max(f[v],f[u]+w[v]);
			d[v]--;
			if (d[v]==0) q.push(v);
		}
	}
	int ans=0;
//	cout<<scc<<endl;
//	for (int i=1;i<=scc;i++) cout<<w[i]<<" "<<f[i]<<endl;
	for (int i=1;i<=p;i++) ans=max(ans,f[bel[bar[i]]]);
	printf("%d\n",ans);
	return 0;
}
