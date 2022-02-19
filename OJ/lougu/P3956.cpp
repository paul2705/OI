#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXM=1e2+4;
const int MAXN=1e4+5;
const int MAXE=2e6+6;
const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
const int Dx[8]={-2,-1,-1,0,0,1,1,2},Dy[8]={0,-1,1,-2,2,-1,1,0};
int m,n;
int col[MAXM][MAXM];
int edge,head[MAXN],tail[MAXE],nex[MAXE],w[MAXE];
int dis[MAXN];
struct rec{
	int u,dis;
	bool operator < (const rec& b) const {
		return dis>b.dis;
	}
};
priority_queue<rec> q;
int GetID(int x,int y){ return (x-1)*m+y; }
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
int main(){
	scanf("%d%d",&m,&n);
	for (int i=1;i<=n;i++){
		int x,y,c; scanf("%d%d%d",&x,&y,&c);
		if (c==0) col[x][y]=2;
		else col[x][y]=c;
	}
	for (int i=1;i<=m;i++){
		for (int j=1;j<=m;j++){
			if (col[i][j]==0) continue;
			for (int _=0;_<4;_++){
				int nx=i+dx[_],ny=j+dy[_];
				if (col[nx][ny]==0) continue;
				if (nx<=0||nx>m||ny<=0||ny>m) continue;
				if (col[nx][ny]==col[i][j]){
					int u=GetID(i,j),v=GetID(nx,ny);
					add(u,v,0); 
					cout<<i<<" "<<j<<" "<<nx<<" "<<ny<<" "<<0<<endl;
				}
				else {
					int u=GetID(i,j),v=GetID(nx,ny);
					add(u,v,1);
					cout<<i<<" "<<j<<" "<<nx<<" "<<ny<<" "<<1<<endl;
				}
			}
			for (int _=0;_<8;_++){
				int nx=i+Dx[_],ny=j+Dy[_];
				if (col[nx][ny]==0) continue;
				if (nx<=0||nx>m||ny<=0||ny>m) continue;
				if (col[nx][ny]==col[i][j]){
					int u=GetID(i,j),v=GetID(nx,ny);
					add(u,v,2);
					cout<<i<<" "<<j<<" "<<nx<<" "<<ny<<" "<<2<<endl;
				}
				else {
					int u=GetID(i,j),v=GetID(nx,ny);
					add(u,v,3);
					cout<<i<<" "<<j<<" "<<nx<<" "<<ny<<" "<<3<<endl;
				}
			}
			dis[GetID(i,j)]=1e9;
		}
	}
	q.push((rec){GetID(1,1),0}); dis[GetID(1,1)]=0;
	while (!q.empty()){
		rec u=q.top(); q.pop();
		if (u.dis>dis[u.u]) continue;
		for (int e=head[u.u];e;e=nex[e]){
			int v=tail[e];
			if (dis[v]>dis[u.u]+w[e]){
				dis[v]=dis[u.u]+w[e];
				q.push((rec){v,dis[v]});
			}
		}
	}
	if (dis[GetID(m,m)]==1e9) printf("-1\n");
	else printf("%d\n",dis[GetID(m,m)]);
	return 0;
}
