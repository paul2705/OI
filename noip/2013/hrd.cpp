#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int inf=1e9;
const int MAXN=35;
const int MAXM=5e5+5;
const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int edge,head[MAXN],nex[MAXM],tail[MAXM],w[MAXM];
int node[MAXN][MAXN][5],cnt;
int dist[MAXN*MAXN*5*5],d[MAXN][MAXN];
int n,m,qq;
int mp[MAXN][MAXN];
int dis[MAXN][MAXN][5][5];
struct rec{
	int x,y;
};
struct di{
	int dis,u;
	bool operator > (const di& a)const{
		return dis>a.dis;
	}
	bool operator < (const di& a)const{
		return dis<a.dis;
	}
};
queue<rec> q;
priority_queue<di,vector<di>,greater<di> > qd;
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
bool bd(int x,int y){
	return !mp[x][y]||x<1||x>n||y<1||y>m;
}
int bfs(int sx,int sy,int tx,int ty){
	if (sx==tx&&sy==ty) return 0;
	while (!q.empty()) q.pop();
	memset(d,-1,sizeof(d));
	q.push((rec){sx,sy}); d[sx][sy]=0;
	while (!q.empty()){
		rec u=q.front(); q.pop();
		for (int k=0;k<4;k++){
			int nx=u.x+dx[k],ny=u.y+dy[k];
			if (!mp[nx][ny]||d[nx][ny]>=0||bd(nx,ny)) continue;
			d[nx][ny]=d[u.x][u.y]+1; q.push((rec){nx,ny});
			if (nx==tx&&ny==ty) return d[tx][ty];
		}
	}
	return inf;
}
int main(){
	scanf("%d%d%d",&n,&m,&qq);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			scanf("%d",&mp[i][j]);
			for (int k=0;k<4;k++){
				node[i][j][k]=++cnt;
				for (int l=0;l<4;l++) dis[i][j][k][l]=inf;
			}
		}
	}
//	cout<<"fuck"<<endl;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
//			cout<<i<<" "<<j<<endl;
			if (!mp[i][j]) continue;
			mp[i][j]=0;
			for (int k=0;k<4;k++){
				int ni=i+dx[k],nj=j+dy[k];
				if (!mp[ni][nj]||bd(ni,nj)) continue;
				for (int l=0;l<4;l++){
					int nni=i+dx[l],nnj=j+dy[l];
					if (!mp[nni][nnj]||bd(nni,nnj)) continue;
					dis[i][j][k][l]=bfs(ni,nj,nni,nnj)+1;
					cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<dis[i][j][k][l]<<endl;
				}
			}
			mp[i][j]=1;
		}
	}
//	cout<<"fuck"<<endl;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			for (int k=0;k<4;k++){
				for (int l=0;l<4;l++){
					if (dis[i][j][k][l]<inf){
						add(node[i][j][k],node[i+dx[l]][j+dy[l]][l^1],dis[i][j][k][l]);
						printf("%d %d %d\n",node[i][j][k],node[i+dx[l]][j+dy[l]][l^1],dis[i][j][k][l]);
					}
				}
			}
		}
	}
	while (qq--){
		int s,t,bx,by,sx,sy,tx,ty;
		scanf("%d%d%d%d%d%d",&bx,&by,&sx,&sy,&tx,&ty);
		if (sx==tx&&sy==ty){ printf("0\n"); continue; }
		s=++cnt; t=++cnt; mp[sx][sy]=0;
		for (int k=0;k<4;k++){
			int nx=sx+dx[k],ny=sy+dy[k];
			if (!mp[nx][ny]||bd(nx,ny)) continue;
			int tmp=bfs(bx,by,nx,ny);
			if (tmp<inf) add(s,node[sx][sy][k],tmp),printf("%d %d %d\n",s,node[sx][sy][k],tmp);
		}
		mp[sx][sy]=1;
		for (int k=0;k<4;k++){
			int nx=tx+dx[k],ny=ty+dy[k];
			if (mp[nx][ny]||!bd(nx,ny)) add(node[tx][ty][k],t,0),printf("%d %d %d\n",node[tx][ty][k],t,0);
		}
//		memset(dist,63,sizeof(dist));
		for (int i=1;i<=2*cnt;i++) dist[i]=inf;
		dist[s]=0; qd.push((di){0,s});
//		cout<<dist[s]<<" "<<dist[t]<<endl;
		while (!qd.empty()){
			di u=qd.top(); qd.pop();
			if (u.dis>dist[u.u]) continue;
			for (int e=head[u.u];e;e=nex[e]){
				int v=tail[e];
				if (dist[v]>dist[u.u]+w[e]){
					dist[v]=dist[u.u]+w[e];
					qd.push((di){dist[v],v});
				}
			}
		}
		for (int i=1;i<=cnt;i++) cout<<dist[i]<<" "; cout<<endl;
		if (dist[t]>=inf) printf("-1\n");
		else printf("%d\n",dist[t]);
	}
	return 0;
}
