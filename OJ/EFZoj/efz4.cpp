#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=55;
const int MAXE=MAXN*MAXN;
int edge,head[MAXN],nex[MAXE],tail[MAXE],r[MAXE];
int n,m,d[MAXN],cnr[MAXN],ans;
int f[MAXN],x[MAXN][MAXN];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d",&f[i]);
		char c;
		while (scanf("%d
