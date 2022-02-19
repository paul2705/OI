#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=2e5+5;
int edge,head[MAXN],nex[MAXM],tail[MAXM],w[MAXM];
int n,m,d[MAXN];
double f[MAXN],rd[MAXN];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0,u,v,w;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); 
