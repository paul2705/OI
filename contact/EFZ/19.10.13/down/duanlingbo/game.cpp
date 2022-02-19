#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=1e8;
const int MAXN=2e3+5;
const int MAXM=4e6+6;
int edge=1,head[MAXN],tail[MAXM],nex[MAXM],r[MAXM];
int d[MAXN],cur[MAXN];
int n,m,S,T;
struct rec{
	int x,y,u,v;
} a[MAXN];
int col[MAXN];
int rd[MAXN],q[MAXM];
int ans;
void add(int u,int v,int R){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,r[edge]=R;
}
void ins(int u,int v,int R){
	add(u,v,R); add(v,u,0); rd[v]++;
}
void dfsc(int u,int c){
	col[u]=c;
	if (c&1) ins(S,u,1);
	else ins(u,T,1);
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (col[v]||r[e]==0) continue;
		dfsc(v,c^1);
	}
}
bool bfs(){
	for (int i=1;i<=T;i++) d[i]=inf;
	d[S]=0; int L=0,R=0; q[++R]=S;
	while (L<R){
		int u=q[++L];
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (d[v]==inf&&r[e]>0){
				d[v]=d[u]+1;
				q[++R]=v;
			}
		}
	}
	return d[T]<inf;
}
int dfs(int u,int b){
	if (u==T) return b;
	int ans=0;
	for (int &e=cur[u];e;e=nex[e]){
		int v=tail[e];
		if (d[v]==d[u]+1&&r[e]>0){
			int res=dfs(v,min(r[e],b));
			r[e]-=res; r[e^1]+=res;
			ans+=res; b-=res;
		}
		if (!b) break;
	}
	return ans;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].u,&a[i].v);
		ins(i,i+n,inf);
	}
//	cout<<"done"<<endl;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (a[j].x>a[i].x+a[i].u||a[j].y>a[i].y+a[i].v){
				ins(i+n,j,inf);
			}
		}
	}
	S=2*n+1; T=S+1;
	for (int i=1;i<=n;i++) ins(S,i+n,1);
	for (int i=1;i<=n;i++) ins(i,T,1);
/*	int L=0,R=0;
	for (int i=1;i<=n;i++){
		if (!rd[i]) q[++R]=i,d[i]=0;
		else d[i]=inf;
	}
	while (L<R){
		int u=q[++L];
		cout<<u<<" "<<d[u]<<endl;
		if (d[u]&1) ins(u,T,1);
		else ins(S,u,1);
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (d[v]==inf){
				d[v]=d[u]+1;
				q[++R]=v;
			}
		}
	}*/
//	cout<<"doneadd"<<endl;
	while (bfs()){
//		cout<<"dinic"<<endl;
		for (int i=1;i<=T;i++) cur[i]=head[i];
		ans+=dfs(S,inf);
	}
	printf("%d\n",n-ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
