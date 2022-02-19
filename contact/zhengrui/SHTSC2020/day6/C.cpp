#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include "maze.h"
#define Max 405
#define glb get_label
#define gen get_edge_number
#define gce get_coming_edge
#define slb set_label
using namespace std;
int d[Max][Max],id[Max][Max],n,cnt,e[Max][Max],fa[Max],pt[5]={1,3,9,27,81},du[Max];
void dfs(int u){
	du[u]=gen();
	slb(3);
	for(int i=1;i<=du[u];i++){
		move(i);
		int t=gce(),v;
		if(glb()==1) dfs(v=++n),e[u][i]=v,e[v][t]=u,fa[v]=t,d[u][v]=d[v][u]=1;
		else e[u][i]=glb()-3;
		move(t);
	}
	slb(2);
}
void dfs2(int u,int t){
	slb(u/pt[t]%3+1);
	for(int i=1;i<=du[u];i++){
		if(e[u][i]>u) move(i),dfs2(e[u][i],t),move(fa[e[u][i]]);
		else if(!e[u][i]) move(i),id[u][i]+=(glb()-1)*pt[t],move(gce());
	}
}
vector<int> solve(int k, int lim){
	memset(d,0x3f,sizeof(d));
	n=1;
	dfs(1);
	for(int i=0;i<=4;i++) dfs2(1,i);
	std::vector<int> ans;
	ans.resize(n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=du[i];j++)
			if(!e[i][j]) d[i][id[i][j]]=d[id[i][j]][i]=1;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(d[i][j]<0x3f3f3f3f) ans[d[i][j]-1]++;
		}
	}
	return ans;
}
