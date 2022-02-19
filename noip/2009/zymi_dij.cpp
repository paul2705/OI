#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=1e6+6;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int redge,rhead[MAXN],rtail[MAXM],rnex[MAXM];
int n,m,a[MAXN],mx[MAXN],mn[MAXN];
bool use[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void radd(int u,int v){
	redge++,rnex[redge]=rhead[u],rhead[u]=redge,rtail[redge]=v;
}
void dij(int s){
	memset(use,0,sizeof(use));
	queue<int> q; q.push(s); use[s]=1; mn[s]=a[s];
	while (!q.empty()){
		int u=q.front(); q.pop(); use[u]=0;
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (mn[v]>min(mn[u],a[v])){
				mn[v]=min(mn[u],a[v]);
				if (!use[v]) use[v]=1,q.push(v);
			}
		}
	}
}
void rdij(int s){
	memset(use,0,sizeof(use));
	queue<int> q; q.push(s); use[s]=1; mn[s]=a[s];
	while (!q.empty()){
		int u=q.front(); q.pop(); use[u]=0;
		for (int e=rhead[u];e;e=rnex[e]){
			int v=rtail[e];
			if (mx[v]<max(mx[u],a[v])){
				mx[v]=max(mx[u],a[v]);
				if (!use[v]) use[v]=1,q.push(v);
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),mn[i]=1e9;
	for (int i=1,op,u,v;i<=m;i++){
		scanf("%d%d%d",&u,&v,&op);
		if (op==1) add(u,v),radd(v,u);
		else add(u,v),add(v,u),radd(u,v),radd(v,u);
	}
	dij(1); rdij(n);
	int ans=0;
	for (int i=1;i<=n;i++) ans=max(ans,mx[i]-mn[i]);
	printf("%d\n",ans);
	return 0;
}
