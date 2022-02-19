#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
const int MAXM=MAXN*2;
int n,m,u[MAXM],v[MAXM];
int edge,head[MAXN],nex[MAXM],tail[MAXM];
int d[MAXN],fa[MAXN][20];
void dfs(int u,int p){

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&u[i],&v[i]);
		if (i<n) add(u[i],v[i]),add(v[i],u[i]);
	}
	dfs(1,0);
