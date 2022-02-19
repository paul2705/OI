#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=2e2+10;
const int MAXM=1e5+5;
const int inf=1e9;
int edge=1,head[MAXN],tail[MAXM],nex[MAXM],r[MAXM];
int d[MAXN],cur[MAXN];
int n,m,S,T,flow;
queue<int> q;
void add(int u,int v,int R){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,r[edge]=R;
}
void ins(int u,int v,int R){
	add(u,v,R); add(v,u,0);
}
bool bfs(){
	for (int i=1;i<=T+1;i++) d[i]=0;
	d[S]=1; q.push(S);
	while (!q.empty()){
		int u=q.front(); q.pop();
//		cout<<u<<endl;
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (d[v]==0&&r[e]>0){
				d[v]=d[u]+1;
				q.push(v);
			}
		}
	}
//	cout<<d[T]<<endl;
	return d[T]>0;
}
int dfs(int u,int b){
//	cout<<u<<" "<<b<<endl;
	if (u==T) return b;
	int ans=0;
	for (int& e=cur[u];e;e=nex[e]){
		int v=tail[e];
		if (d[v]==d[u]+1&&r[e]>0){
			int tmp=dfs(v,min(r[e],b));
			r[e]-=tmp; r[e^1]+=tmp;
//			cout<<tmp<<endl;
			b-=tmp; ans+=tmp;
			if (!b) break;
		}
	}
	return ans;
}
int main(){
	scanf("%d%d",&m,&n);
	S=n+1;T=n+2;
	int u,v;
	scanf("%d%d",&u,&v);
	while (u!=-1&&v!=-1){
		ins(u,v,inf);
//		ins(S,u,1);
//		ins(v,T,1);
		scanf("%d%d",&u,&v);
	}
	for (int i=1;i<=m;i++) ins(S,i,1);
	for (int i=m+1;i<=n;i++) ins(i,T,1);
//	cout<<"done"<<endl;
	while (bfs()){
//		cout<<"in"<<endl;;
		for (int i=1;i<=T;i++) cur[i]=head[i];
//		int tmp;
//		while ((tmp=dfs(S,inf))>0){
//			flow+=tmp;
//			cout<<tmp<<endl;
//		}
//		cout<<flow<<endl;
		flow+=dfs(S,inf);
	}
	printf("%d\n",flow);
	for (int i=1;i<=m;i++){
		for (int e=head[i];e;e=nex[e]){
			int v=tail[e];
//			cout<<i<<" "<<v<<" "<<r[e]<<endl;
			if (v==S||v==T) continue;
			if (r[e^1]!=0) printf("%d %d\n",i,v);
		}
	}
	return 0;
}
