#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=2e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int rd[MAXN],d[MAXN];
int n,m;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs1(int u){
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (d[v]==-1){
			d[v]=d[u]+1; dfs1(v);
		}
		else if (d[v]>d[u]){
			printf("%d %d\n",u,v);
//			cout<<"in"<<endl;
			rd[u]++;
//			cout<<"out"<<endl;
		}
	}
}
void dfs2(int u,int p){
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (d[v]==d[u]+1) dfs2(v,u);
	}
//	cout<<u<<" "<<p<<endl;
	if (u==1) return;
	if (rd[u]&1) printf("%d %d\n",u,p);
	else printf("%d %d\n",p,u),rd[p]++;
}
int main(){
	scanf("%d%d",&n,&m);
//	if (m&1) return printf("0\n"),0;
	for (int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	if (m&1) return printf("-1\n"),0;
	for (int i=2;i<=n;i++) d[i]=-1;
	dfs1(1); 
//	for (int i=1;i<=n;i++) printf("id:%d d:%d rd:%d\n",i,d[i],rd[i]);
	dfs2(1,0);
	return 0;
}
