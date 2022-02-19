#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=150;
const int MAXE=MAXN*MAXN;
int edge,head[MAXN],tail[MAXE],nex[MAXE],w[MAXE];
int n,m,c[MAXN],u[MAXN],use[MAXN];
queue<int> q;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1,x;i<=n;i++){
		scanf("%d%d",&x,&u[i]);
		if (x) q.push(i);
	}
	for (int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	while (!q.empty()){
		int u=q.front(); q.pop();
		if (c[u]<=0) continue;
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			
