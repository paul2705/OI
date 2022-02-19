#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=2e5+5;
const int MAXM=4e5+5;
int edge,head[MAXN],from[MAXN],tail[MAXM],nex[MAXM],w[MAXM],a[MAXM];
int dist[MAXN],fa[MAXN],mn[MAXN];
bool use[MAXN];
int n,m,v[MAXM],p[MAXM];
int T,q,k,s;
bool flag=1;
void add(int u,int v,int l,int A){
	edge++,nex[edge]=head[u],head[u]=edge,from[edge]=u,tail[edge]=v,w[edge]=l,a[edge]=A;
}
void SPFA(int s){
    queue<int> que;
    memset(use,0,sizeof(use)); memset(dist,63,sizeof(dist));
    que.push(s); dist[s]=0; use[s]=true;
    while (!que.empty()){
        int u=que.front();que.pop();
        use[u]=false;
        for (int e=head[u];e;e=nex[e]){
            int v=tail[e];
            if (dist[v]>dist[u]+w[e]){
                dist[v]=dist[u]+w[e]; 
                if (!use[v]){
                    que.push(v);
                    use[v]=true;
                }
            }
        }
    }
}
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){
	int fx=find(x),fy=find(y);
	fa[fx]=fy;
	mn[fy]=min(mn[fx],mn[fy]);
}
void solve1_1(){
	for (int i=0,v,p;i<q;i++){
		scanf("%d%d",&v,&p);
		if (p>=1) printf("%d\n",dist[v]);
		else printf("0\n");
	}
}
void solve1_2(){
	
}
void solve1(){
	if (flag) solve1_1();
	else solve1_2();
}
void solve2(){
	
}
int main(){
	freopen("return.in","r",stdin);
	freopen("return.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		memset(head,0,sizeof(head)); edge=0;
		scanf("%d%d",&n,&m);
		for (int i=0,u,v,l,a;i<m;i++){
			scanf("%d%d%d%d",&u,&v,&l,&a);
			add(u,v,l,a); add(v,u,l,a);
			if (a!=1) flag=0;
		}
		SPFA(1);
		scanf("%d%d%d",&q,&k,&s);
		if (k==0) solve1();
		else solve2();
	}
	return 0;
	fclose(stdin); fclose(stdout);
}
