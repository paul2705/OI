#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e4+5;
const int MAXM=1e3+5;
const int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
struct rec{
	int x,y,d;
};
deque<rec> q;
bool use[MAXN][MAXM];
int n,m,k,up[MAXN],dn[MAXN];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<n;i++) scanf("%d%d",&up[i],&dn[i]);
	for (int i=1;i<=k;i++){
		int p,l,h;
		scanf("%d%d%d",&p,&l,&h);
		for (int j=0;j<=l;j++) use[p][j]=1;
		for (int j=r;j<=m;j++) use[p][j]=1;
	}
	for (int i=0;i<=m;i++) q.push_back((rec){0,i,0});
	int ans=1e9;
	while (!q.empty()){
		rec x=q.front(); q.pop();
		for (int i=1;up[x.x]*i+x.y<=m;i++){
			int nx=x.x+1,ny=up[x.x]*i+x.y;
			if (use[nx][ny]) continue;

