#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=105;
const int MAXK=105;
int n,m,k,d[MAXN],t[MAXN];
int u[MAXN],v[MAXN];
int mx[MAXN];
int g[MAXN][MAXK],f[MAXN][MAXK];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=2;i<=n;i++) scanf("%d",&d[i]);
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&t[i],&u[i],&v[i]);
		mx[u[i]]=max(mx[u[i]],t[i]);
	}

