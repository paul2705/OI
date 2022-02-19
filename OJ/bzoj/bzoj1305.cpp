#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int inf=1e9;
const int MAXN=55*4;
const int MAXK=35;
const int MAXM=MAXN*MAXN;
int edge=1,head[MAXN],tail[MAXM],nex[MAXM],r[MAXM];
int redge=1,rhead[MAXN],rtail[MAXM],rnex[MAXM],rr[MAXM];
int n,m,S,T;
int a[MAXN][MAXN],cur[MAXN],d[MAXN];
queue<int> q;
void add(int u,int v,int R){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,r[edge]=R;
}
void radd(int u,int v,int R){
	redge++,rnex[redge]=rhead[u],rhead[u]=redge,rtail[redge]=v,rr[redge]=R;
}
void ins(int u,int v,int R){
	add(u,v,R); add(v,u,0);
}
void rins(int u,int v,int R){
	radd(u,v,R); radd(v,u,0);
}
bool bfs(){
	for (int i=1;i<=T;i++) d[i]=inf;
	d[S]=0; q.push(S);
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (r[e]>0&&d[v]==inf){
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
	return d[T]<inf;
}
int dfs(int u,int b){
	if (u==T) return b;
	int ans=0;
	for (int& e=cur[u];e;e=nex[e]){
		int v=tail[e];
		if (r[e]>0&&d[v]==d[u]+1){
			int res=dfs(v,min(r[e],b));
			r[e]-=res; r[e^1]+=res;
			b-=res; ans+=res;
		}
		if (!b) return ans;
	}
	return ans;
}
bool check(int mid){
	for (int i=1;i<=T;i++) head[i]=rhead[i];
	for (int e=1;e<=redge;e++){
		nex[e]=rnex[e]; tail[e]=rtail[e];
		r[e]=rr[e];
	}
	edge=redge;
	for (int i=1;i<=n;i++){
		ins(S,2*i-1,mid);
		ins(2*i+2*n,T,mid);
	}
	int flow=0;
	while (bfs()){
		for (int i=1;i<=T;i++) cur[i]=head[i];
		flow+=dfs(S,inf);
	}
	return flow==mid*n;
}
int main(){
	scanf("%d%d",&n,&m);
	S=4*n+1; T=S+1;
	for (int i=1;i<=n;i++){
		ins(2*i-1,2*i,m); rins(2*i-1,2*i,m);
		ins(2*i-1+2*n,2*i+2*n,m); rins(2*i-1+2*n,2*i+2*n,m);
		for (int j=1;j<=n;j++){
			char c=getchar(); while (c!='Y'&&c!='N') c=getchar();
			if (c=='Y') ins(2*i-1,2*j+2*n,1),rins(2*i-1,2*j+2*n,1);
			else ins(2*i,2*j-1+2*n,1),rins(2*i,2*j-1+2*n,1);
		}
	}
	int l=0,r=n+1,mid;
	while (l+1<r){
		mid=(l+r)>>1;
		if (check(mid)) l=mid;
		else r=mid;
	}
	printf("%d\n",l);
	return 0;
}
