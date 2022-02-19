#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long
#define pa pair<int,int>
using namespace std;
int n,m,cnt;
int last[3005];
int d1[3005],d2[3005],d[3005];
int l[3005],a[3005][3005];
bool vis[3005];
struct edge{
	int to,next,v;
}e[70005];
void insert(int u,int v,int w){
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;e[cnt].v=w;
}
priority_queue<pa,vector<pa>,greater<pa> > q;
void dijkstra(){
	memset(d1,127/3,sizeof(d1));
	q.push(make_pair(0,1));
	d1[1]=0;
	while(!q.empty()){
		int now=q.top().second; q.pop();
		if (vis[now]) continue;
		vis[now]=1;
		int mx=max(d1[now],d2[now]);
	    for (int i=last[now];i;i=e[i].next){
			if (mx+e[i].v<d1[e[i].to]){
				d1[e[i].to]=mx+e[i].v;
				int tmp=max(d1[e[i].to],d2[e[i].to]);
				if (!d[e[i].to]) q.push(make_pair(tmp,e[i].to));
			}
		}
		for (int i=1;i<=l[now];i++){
			int t=a[now][i];
			d[t]--;
			d2[t]=max(d2[t],mx);
			int tmp=max(d1[t],d2[t]);
			if (!d[t]) q.push(make_pair(tmp,t));
		}
	}
	printf("%d\n",max(d1[n],d2[n]));
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		if (u!=v) insert(u,v,w);
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		for (int j=1;j<=d[i];j++){
			int u; scanf("%d",&u);
			a[u][++l[u]]=i;
		}
	}
	dijkstra();
	return 0;
}
