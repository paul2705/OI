#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e5+5;
const int MAXM=6e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int d[MAXN],fa[MAXN][22];
int n,m,tp;
struct rec{
	int u,v,w;
	bool flag;
} ed[MAXN];
int cnt;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs(int u,int p){
	d[u]=d[p]+1; fa[u][0]=p;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u);
	}
}
void ini(){
	for (int k=1;k<=20;k++){
		for (int i=1;i<=n;i++){
			fa[i][k]=fa[fa[i][k-1]][k-1];
		}
	}
}
int lca(int x,int y){
	if (d[x]<d[y]) swap(x,y);
	for (int k=20;k>=0;k--){
		if (d[fa[x][k]]>d[y]) x=fa[x][k];
	}
	if (d[x]>d[y]) x=fa[x][0];
	if (x==y) return x;
	for (int k=20;k>=0;k--){
		if (fa[x][k]!=fa[y][k]){
			x=fa[x][k];
			y=fa[y][k];
		}
	}
	if (x!=y) return fa[x][0];
	else return x;
}
int main(){
	scanf("%d%d%d",&n,&m,&tp);
	for (int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	dfs(1,0); ini();
	int S=0;
	for (int i=1;i<=m;i++){
		int op; scanf("%d",&op);
		if (op==1){
			int u,v,w; scanf("%d%d%d",&u,&v,&w);
			if (tp==0){
				ed[cnt++]=(rec){u,v,w,1};
				S+=w;
			}
			else {
				u=(u+S)%(n+1); v=(v+S)%(n+1); w=(w+S)%(n+1);
				ed[cnt++]=(rec){u,v,w,1};
				S+=w;
			}
		}
		if (op==2){
			int x,w; scanf("%d%d",&x,&w);
			if (tp==1){
				x=(x+S)%(n+1); w=(w+S)%(n+1);
			}
			int ans=0;
			for (int j=0;j<cnt;j++){
				if (!ed[j].flag) continue;
				int u=ed[j].u,v=ed[j].v;
				int t1=lca(u,x),t2=lca(v,x);
				int L=lca(u,v);
//				cout<<u<<" "<<v<<" "<<x<<" "<<t1<<" "<<t2<<" "<<L<<endl;
				if ((t1==x&&t2==L)||(t1==L&&t2==x)){
					ed[j].w-=w;
					if (ed[j].w<0){
						ans++; S-=(ed[j].w+w);
					}
					else S-=w;
				}
				else continue;
			}
			printf("%d %d ",S,ans);
			for (int j=0;j<cnt;j++){
				if (!ed[j].flag) continue;
				if (ed[j].w<0){
					printf("%d ",j+1);
					ed[j].flag=0;
				}
			}
			printf("\n");
		}
	}
	return 0;
}
