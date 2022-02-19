#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=2e5+6;
int edge,head[MAXN],nex[MAXM],tail[MAXM],w[MAXM];
int n,m,cnt,d[MAXN];
int q[MAXN],l,r;
double f[MAXN],rd[MAXN];
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0,u,v,w;i<m;i++){
		scanf("%d%d%d",&u,&v,&w); u--;v--;
		add(u,v,w); d[v]++; rd[u]++;
	}
	q[r++]=0;
	while (r-l>=1){
		int u=q[l++];
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (--d[v]==0) q[r++]=v;
		}
	}
	f[n-1]=0;
	for (int i=n-2;i>=0;i--){
		int u=q[i]; f[u]=0;
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			f[u]+=(f[v]+w[e])/rd[u];
		}
	}
	printf("%.2lf\n",f[0]);
	return 0;
}
