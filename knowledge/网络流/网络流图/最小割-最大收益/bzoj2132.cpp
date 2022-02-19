#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXG=1e2+5;
const int MAXN=4e4+5;
const int MAXM=2e6+6;
const int inf=1e9;
const int dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
int edge=1,head[MAXN],nex[MAXM],tail[MAXM],r[MAXM];
int d[MAXN],cur[MAXN];
int n,m,S,T,ans,c[MAXG][MAXG];
queue<int> q;
void add(int u,int v,int R){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,r[edge]=R;
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
	for (int &e=cur[u];e;e=nex[e]){
		int v=tail[e];
		if (d[v]==d[u]+1&&r[e]>0){
			int res=dfs(v,min(b,r[e]));
			r[e]-=res; r[e^1]+=res;
			ans+=res; b-=res;
			if (!b) break;
		}
	}
	return ans;
}
bool ub(int x,int y){
	return x<1||x>n||y<1||y>m;
}
// (i+j)%2=0 A:id*2 B:id*2+1
// (i+j)%2=1 A:id*2+1 B:id*2
int main(){
	scanf("%d%d",&n,&m);
	S=(n*m+1);
	T=S+1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			int x; scanf("%d",&x);
			int id=(i-1)*m+j;
			ans+=x;
//			ins(id*2,id*2+1,inf);
			if ((i+j)%2==0) ins(id,T,x);
			else ins(S,id,x);
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			int x; scanf("%d",&x);
			int id=(i-1)*m+j;
			ans+=x;
			if ((i+j)%2==0) ins(S,id,x);
			else ins(id,T,x);
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) scanf("%d",&c[i][j]);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
//			ans+=2*c[i][j];
			if ((i+j)%2==1) continue;
			for (int k=0;k<4;k++){
				int nx=i+dx[k],ny=j+dy[k];
				if (ub(nx,ny)) continue;
				int id=(i-1)*m+j,nid=(nx-1)*m+ny;
				add(id,nid,c[i][j]+c[nx][ny]);
				add(nid,id,c[i][j]+c[nx][ny]);
				ans+=(c[i][j]+c[nx][ny]);
			}
		}
	}
	while (bfs()){
		for (int i=1;i<=T;i++) cur[i]=head[i];
		ans-=dfs(S,inf);
//		cout<<ans<<endl;
	}
	printf("%d\n",ans);
	return 0;
}
