#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e3+5;
const int MAXM=6e4+5;
const int inf=1e9;
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int edge=1,head[MAXN],tail[MAXM],nex[MAXM],r[MAXM];
int dis[MAXN],cur[MAXN];
int n,m,D,S,T,ans;
int d[25][25];
int a[25][25],id[25][25],cnt;
queue<int> q;
struct rec{
	int x,y;
};
queue<rec> q1;
void add(int u,int v,int R){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,r[edge]=R;
}
void ins(int u,int v,int R){
	add(u,v,R); add(v,u,0);
}
bool bfs(){
	for (int i=1;i<=T;i++) dis[i]=inf;
	dis[S]=0; q.push(S);
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (dis[v]==inf&&r[e]>0){
				dis[v]=dis[u]+1;
				q.push(v);
			}
		}
	}
	return dis[T]<inf;
}
int dfs(int u,int b){
	if (u==T) return b;
	int ans=0;
	for (int& e=cur[u];e;e=nex[e]){
		int v=tail[e];
		if (dis[v]==dis[u]+1&&r[e]>0){
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
int main(){
	scanf("%d%d%d",&n,&m,&D);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			char c=getchar(); while (c<'0'||c>'3') c=getchar();
			if (c>'0'){
				a[i][j]=c-'0',id[i][j]=++cnt;
				ins(id[i][j]*2,id[i][j]*2+1,a[i][j]);
			}
		}
	}
	cnt++;
	S=cnt*2; T=cnt*2+1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (id[i][j]==0) continue;
			int uid=id[i][j]*2+1;
			q1.push((rec){i,j});
			while (!q1.empty()){
				rec u=q1.front(); q1.pop();
				if (d[u.x][u.y]==D) continue;
				for (int k=0;k<4;k++){
					int nx=u.x+dx[k],ny=u.y+dy[k];
					if (ub(nx,ny)){
						ins(uid,T,inf);
						continue;
					}
					if (d[nx][ny]==0){
						d[nx][ny]=d[u.x][u.y]+1;
						q1.push((rec){nx,ny});
						if (id[nx][ny]>0)
							ins(uid,id[nx][ny]*2,inf);
					}
				}
			}
			q1.push((rec){i,j});
			while (!q1.empty()){
				rec u=q1.front(); q1.pop();
				d[u.x][u.y]=0;
				for (int k=0;k<4;k++){
					int nx=u.x+dx[k],ny=u.y+dy[k];
					if (d[nx][ny]>0){
						q1.push((rec){nx,ny});
					}
				}
			}
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			char c=getchar(); while (c!='.'&&c!='L') c=getchar();
			if (c=='L') ins(S,id[i][j]*2,1),ans++;
		}
	}
//	cout<<"done"<<endl;
	while (bfs()){
		for (int i=1;i<=T;i++) cur[i]=head[i];
//		cout<<"fuck1"<<endl;
		ans-=dfs(S,inf);
//		cout<<"fuck2"<<endl;
	}
	printf("%d\n",ans);
	return 0;
}
