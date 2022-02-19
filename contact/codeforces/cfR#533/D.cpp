#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=1e3+5;
const int MAXM=15;
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
int a[MAXN][MAXN],n,m,p;
int s[MAXM],sz[MAXM];
struct rec{
	int x,y,l;
};
vector<rec> st[MAXM];
deque<rec> q;
bool ub(int x,int y){
	return x<1||x>n||y<1||y>m;
}
int main(){
	scanf("%d%d%d",&n,&m,&p);
	for (int i=1;i<=p;i++) scanf("%d",&s[i]);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			char c=getchar(); while ((c<'1'||c>'9')&&c!='.'&&c!='#') c=getchar();
			if (c=='.') a[i][j]=0;
			else if (c=='#') a[i][j]=11;
			else a[i][j]=c-'0',st[c-'0'].push_back((rec){i,j,0}),sz[a[i][j]]++;
		}
	}
	for (int i=1;i<=p;i++){
		for (int j=0;j<st[i].size();j++){
			q.push_back(st[i][j]);
		}
	}
//	q.push_front(st[1]);
	while (!q.empty()){
		rec u=q.front(); q.pop_front();
//		cout<<u.x<<" "<<u.y<<endl;
		for (int i=0;i<4;i++){
			int nx=u.x+dx[i],ny=u.y+dy[i],nl=u.l+1;
			if (a[nx][ny]>0||ub(nx,ny)) continue;
			a[nx][ny]=a[u.x][u.y];
			sz[a[nx][ny]]++;
			if (nl==s[a[u.x][u.y]]) q.push_back((rec){nx,ny,0});
			else q.push_front((rec){nx,ny,nl});
		}
	}
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=m;j++) printf("%d ",a[i][j]);
//		cout<<endl;
//	}
	for (int i=1;i<=p;i++) printf("%d ",sz[i]);
	return 0;
}
