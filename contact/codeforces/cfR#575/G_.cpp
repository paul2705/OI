#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int inf=1e9;
const int MAXN=1e5+5;
const int MAXM=2e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
int fa[MAXN],pre[MAXN];
int n,m;
struct rec{
	int u,cnt;
} st[MAXN];
queue<rec> q;
int d[MAXN],dist[3][MAXN];
vector<int> pth,ans;
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void bfs(int id){
	queue<int> q;
	for (int i=1;i<=n;i++) dist[id][i]=inf;
	if (id==0) q.push(1),dist[id][1]=0;
	else q.push(n),dist[id][n]=0;
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (dist[id][v]>=inf){
				dist[id][v]=dist[id][u]+1;
				q.push(v);
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		u++; v++;
		add(u,v,w); add(v,u,w);
	}
//	cout<<"done"<<endl;
	for (int i=1;i<=n;i++) d[i]=inf;
	st[n]=(rec){n,0};
	q.push(st[n]); d[n]=0;
	while (!q.empty()){
		rec u=q.front(); q.pop();
		for (int e=head[u.u];e;e=nex[e]){
			int v=tail[e];
			if (w[e]==0){
				if (d[v]>=inf){
					d[v]=d[u.u]+1;
					st[v]=u;
					st[v].u=v; st[v].cnt++; 
					pre[v]=u.u;
					q.push(st[v]);
				}
			}
		}
	}
//	cout<<"done"<<endl;
	if (d[1]<inf){
		printf("0\n");
		for (int u=1;u!=n;u=pre[u]){
			ans.push_back(u);
		}
		ans.push_back(n);
		int cnt=ans.size();
		printf("%d\n",cnt);
		for (int i=ans.size()-1;i>=0;i--){
			int x=ans[i];
			printf("%d ",x-1);
		}
		printf("\n");
		return 0;
	}
	bfs(0); bfs(1);
//	cout<<"ini: ";
	for (int i=1;i<=n;i++){
		if (d[i]>=inf) continue;
		q.push(st[i]);
//		cout<<st[i].u<<" ";
	}
//	cout<<endl;
//	cout<<"done"<<endl;
	while (!q.empty()){
		rec u=q.front(); q.pop();
//		cout<<u.u<<endl;	
		int mn=inf,pos=-1;
		for (int e=head[u.u];e;e=nex[e]){
			int v=tail[e];
//			cout<<v<<" "<<w[e]<<" "<<mn<<" "<<d[v]<<endl;
//			cout<<dist[0][v]<<" "<<dist[1][u.u]<<" "<<dist[0][n]<<endl;
//			if (dist[0][v]+w[e]+dist[1][u.u]!=dist[0][n]) continue;
			bool flag=(dist[0][v]+1+dist[1][u.u]==dist[0][n]);
			flag|=(dist[0][u.u]+1+dist[1][v]==dist[0][n]);
			if (w[e]<mn&&d[v]>=inf&&flag){
				mn=w[e];
				pos=v;
			}
		}
//		cout<<pos<<endl;
		if (pos==-1) continue;
		d[pos]=d[u.u]+1;
		st[pos]=u;
		st[pos].u=pos; st[pos].cnt++;
		pre[pos]=u.u;
		q.push(st[pos]);
	}
//	cout<<"done "<<d[1]<<endl;
	for (int u=1;u!=n;u=pre[u]){
//		cout<<u<<" "<<pre[u]<<endl;
		pth.push_back(u);
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (v==pre[u]){
				ans.push_back(w[e]);
				break;
			}
		}
	}
	pth.push_back(n);
//	cout<<"done"<<endl;
	int cnt=0;
	bool flag=1;
	for (int i=ans.size()-1;i>=0;i--){
		int x=ans[i];
		if (flag&&x==0) continue;
		if (x!=0&&flag) flag=0;
		cnt++;
		printf("%d",x);
	}
	printf("\n%d\n",cnt);
	for (int i=0;i<pth.size();i++){
		int x=pth[i];
		printf("%d ",x-1);
	}
	printf("\n");
	return 0;
}
