#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e3+5;
const int MAXM=2e4+5;
const int inf=1e7;
int edge,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
int d[MAXN],mx[MAXN];
bool use[MAXN];
int n,m,K;
queue<int> q;
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
bool check(int mid){
	for (int i=1;i<=n;i++) d[i]=inf;
	d[1]=0; q.push(1); 
	while (!q.empty()){
		int u=q.front(); q.pop();
		use[u]=0;
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e],W=w[e]>mid;
			if (d[v]>d[u]+W){
				d[v]=d[u]+W;
				if (!use[v]) q.push(v),use[v]=1;
			}
		}
	}
	return d[n]<=K;
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	int tmp=0;
	for (int i=1;i<=m;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); add(v,u,w);
		tmp=max(tmp,w);
	}
	check(tmp);
	if (d[n]==inf) return printf("-1\n"),0;
	int l=-1,r=tmp,mid;
	while (l+1<r){
		mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid;
	}
	printf("%d\n",r);
	return 0;
}
