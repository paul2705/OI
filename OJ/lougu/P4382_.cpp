#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=4e2+5;
const int MAXM=4e4+5;
const int inf=1e9;
struct G{
	int edge,head[MAXN],tail[MAXM],from[MAXM],nex[MAXM],pre[MAXM],r[MAXM];
} g[MAXN];
queue<int> q;
int edge=1,head[MAXN],tail[MAXM],from[MAXM],pre[MAXM],nex[MAXM],r[MAXM];
int n,m,C,t,flow,S,T,s[MAXN],ans[MAXN];
int d[MAXN],cur[MAXN];
vector<int> a[MAXN][MAXN];
void add(int u,int v,int R){
	edge++,nex[edge]=head[u],from[edge]=u,tail[edge]=v,r[edge]=R;
	if (head[u]) pre[head[u]]=edge; head[u]=edge;
}
void del(int e){
	if (nex[e]) pre[nex[e]]=pre[e];
	if (pre[e]) nex[pre[e]]=nex[e];
	if (e==head[from[e]]) head[from[e]]=nex[e];
}
void ins(int u,int v,int R){
	add(u,v,R); add(v,u,0);
}
bool bfs(){
	for (int i=1;i<=T;i++) d[i]=inf;
	d[S]=0; q.push(S);
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (d[v]==inf&&r[e]>0){
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
	return d[T]<inf;
}
int dfs(int u,int b){
	if (u==T) return b;
	int ans=0;
	for (int& e=cur[u];e;e=nex[e]){
		int v=tail[e];
		if (d[v]==d[u]+1&&r[e]>0){
			int res=dfs(v,min(r[e],b));
			r[e]-=res;
			r[e^1]+=res;
			ans+=res;
			b-=res;
		}
		if (!b) break;
	}
	return ans;
}
bool check(int x,int mid){
	edge=g[mid-1].edge;
	for (int e=2;e<=edge;e++){
		nex[e]=g[mid-1].nex[e];
		tail[e]=g[mid-1].tail[e];
		from[e]=g[mid-1].from[e];
		r[e]=g[mid-1].r[e];
		pre[e]=g[mid-1].pre[e];
	}
	for (int i=1;i<=T;i++) head[i]=g[mid-1].head[i];
	ins(S,x,1);
	for (int i=1;i<=s[x];i++){
		for (int j=0;j<a[x][i].size();j++){
			int v=a[x][i][j];
			ins(x,n+v,1);
		}
	}
//	for (int i=1;i<=T;i++) cur[i]=head[i];
	return bfs();
}
int main(){
	scanf("%d%d",&t,&C);
	while (t--){
		scanf("%d%d",&n,&m);
		S=n+m+1; T=S+1; edge=1;
		for (int i=1;i<=m;i++){
			int x; scanf("%d",&x);
			ins(n+i,T,x);
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				int x; scanf("%d",&x);
				a[i][x].push_back(j);
			}
		}
		g[0].edge=edge;
		for (int i=1;i<=T;i++) g[0].head[i]=head[i];
		for (int e=2;e<=edge;e++){
			g[0].nex[e]=nex[e];
			g[0].tail[e]=tail[e];
			g[0].r[e]=r[e];
			g[0].from[e]=from[e];
			g[0].pre[e]=pre[e];
		}
		for (int i=1;i<=n;i++) scanf("%d",&s[i]);
		for (int i=1;i<=n;i++){
			ins(S,i,1);
			for (int j=1;j<=m;j++){
				int pe=edge;
				for (int k=0;k<a[i][j].size();k++){
					int v=a[i][j][k];
					ins(i,n+v,1);
				}
				int pre=flow;
				while (bfs()){
					for (int i=1;i<=T;i++) cur[i]=head[i];
					flow+=dfs(S,inf);
				}
				if (flow>pre){
//					cout<<i<<" "<<j<<" "<<flow<<" "<<pre<<endl;
					ans[i]=j;
					break;
				}
				else {
					for (int e=pe+1;e<=edge;e++) del(e);
					edge=pe;
				}
			}
			if (!ans[i]) ans[i]=m+1;
			g[i].edge=edge;
			for (int j=1;j<=T;j++) g[i].head[j]=head[j];
			for (int e=2;e<=edge;e++){
				g[i].nex[e]=nex[e];
				g[i].tail[e]=tail[e];
				g[i].from[e]=from[e];
				g[i].r[e]=r[e];
				g[i].pre[e]=pre[e];
			}
		}
		for (int i=1;i<=n;i++) printf("%d ",ans[i]);
		printf("\n");
		for (int i=1;i<=n;i++){
			if (ans[i]<=s[i]){
//				cout<<": "<<ans[i]<<" "<<s[i]<<endl;
				printf("0 ");
				continue;
			}
			int l=1,r=i-1,as=0,mid;
			while (l<=r){
				mid=(l+r)>>1;
				if (check(i,mid)){
					as=mid;
					l=mid+1;
				}
				else r=mid-1;
			}
			printf("%d ",i-as);
		}
		printf("\n");
		edge=1;
		for (int i=1;i<=T;i++) head[i]=0;
		for (int i=1;i<=n;i++) ans[i]=0;
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++) a[i][j].clear();
		}
		flow=0;
	}
	return 0;
}
