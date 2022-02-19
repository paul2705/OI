#include<iostream>
#include<cstdio>
#include<cstring>
#include<alorithm>
using namespace std;
const int MAXN=1e3+5;
int x[2][MAXN],y[2][MAXN];
int f[MAXN][MAXN][2];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d%d",&x[0][i],&y[0][i]);
	for (int i=1;i<=m;i++) scanf("%d%d",&x[1][i],&y[1][i]);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			f[i][j][0]=min(f[i][j-1][1]+dist(j-1,j
