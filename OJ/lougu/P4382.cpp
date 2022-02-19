#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN=4e2+5;
const int MAXM=8e4+5;
const int inf=1e9;
struct G{
	int edge,head[MAXN],from[MAXM],tail[MAXM],pre[MAXM],nex[MAXM],r[MAXM];
} g[MAXN];
int edge=1,head[MAXN],from[MAXM],tail[MAXM],pre[MAXM],nex[MAXM],r[MAXM];
int n,m,C,t,S,T,s[MAXN];
int ans[MAXN],flow;
int d[MAXN];
vector<int> a[MAXN][MAXN];
queue<int> q;
void add(int u,int v,int R){
	edge++,nex[edge]=head[u],from[edge]=u,tail[edge]=v,r[edge]=R;
	if (head[u]) pre[head[u]]=edge;
	head[u]=edge;
}
void ins(int u,int v,int R){
	add(u,v,R); add(v,u,0);
}
void del(int e){
	if (nex[e]) pre[nex[e]]=pre[e];
	if (pre[e]) nex[pre[e]]=nex[e];
	if (e==head[from[e]]) head[from[e]]=nex[e];
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
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (d[v]==d[u]+1&&r[e]>0){
			int res=dfs(v,min(r[e],b));
			r[e]-=res; r[e^1]+=res;
			ans+=res; b-=res;
		}
		if (!b) break;
	}
	return ans;
}
bool check(int x,int mid){
	edge=g[mid-1].edge;
	for (int i=1;i<=T;i++) head[i]=g[mid-1].head[i];
	for (int e=2;e<=edge;e++){
		nex[e]=g[mid-1].nex[e];
		tail[e]=g[mid-1].tail[e];
		from[e]=g[mid-1].from[e];
		pre[e]=g[mid-1].pre[e];
		r[e]=g[mid-1].r[e];
	}
//	cout<<"yangyining AK IOI!"<<endl;
	ins(S,x,1);
	for (int i=1;i<=s[x];i++){
		for (int j=0;j<a[x][i].size();j++){
			int v=a[x][i][j];
			ins(x,v+n,1);
		}
	}
//	cout<<"fuck"<<endl;
	return bfs()&&dfs(S,inf);
}
int main(){
	scanf("%d%d",&t,&C);
	while (t--){
//		cout<<t<<endl;
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
		for (int i=1;i<=n;i++) scanf("%d",&s[i]);
		g[0].edge=edge;
		for (int i=1;i<=T;i++) g[0].head[i]=head[i];
		for (int e=2;e<=edge;e++){
			g[0].nex[e]=nex[e];
			g[0].tail[e]=tail[e];
			g[0].from[e]=from[e];
			g[0].pre[e]=pre[e];
			g[0].r[e]=r[e];
		}
		for (int i=1;i<=n;i++){
//			cout<<": "<<i<<endl;
			ins(S,i,1);
			for (int j=1;j<=m;j++){
				int pe=edge;
				ans[i]=m+1;
				for (int k=0;k<a[i][j].size();k++){
					int v=a[i][j][k];
					ins(i,v+n,1);
				}
				if (bfs()&&dfs(S,inf)){
					ans[i]=j;
					break;
				}
				else{
					for (int k=pe+1;k<=edge;k++) del(k);
					edge=pe;
				}
			}
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
//			cout<<"zouyicen AK IOI! "<<i<<endl;
			if (ans[i]<=s[i]){
				printf("0 ");
				continue;
			}
			int l=0,r=i,mid;
			while (r-l>1){
//				cout<<l<<" "<<r<<endl;
				mid=(l+r)>>1;
				if (check(i,mid)) l=mid;
				else r=mid;
			}
			printf("%d ",i-l);
		}
		printf("\n");
		edge=1;
		for (int i=1;i<=T;i++) head[i]=0;
		for (int i=1;i<=n;i++){
			ans[i]=0;
			for (int j=1;j<=m;j++) a[i][j].clear();
		}
		flow=0;
	}
	return 0;
}
