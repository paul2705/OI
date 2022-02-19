#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=2e5+5;
const int MAXM=4e5+5;
struct rec{
	int from,tail,nex,w,a;
} ed[MAXM];
struct ask{
	int v,p,id,ans;
} x[MAXM];
int edge,head[MAXN];
int dist[MAXN],fa[MAXN],mn[MAXN];
bool use[MAXN];
int n,m;
int T,q,k,s;
void add(int u,int v,int l,int A){
	edge++,ed[edge]=(rec){u,v,head[u],l,A},head[u]=edge;
}
void SPFA(int s){
    queue<int> que;
    memset(use,0,sizeof(use)); memset(dist,63,sizeof(dist));
    que.push(s); dist[s]=0; use[s]=true;
    while (!que.empty()){
        int u=que.front();que.pop();
        use[u]=false;
        for (int e=head[u];e;e=ed[e].nex){
            int v=ed[e].tail;
            if (dist[v]>dist[u]+ed[e].w){
                dist[v]=dist[u]+ed[e].w; 
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
bool cmp_ask_ans(ask a,ask b){ return a.id<b.id; }
bool cmp_ed(rec a,rec b){ return a.a>b.a; }
bool cmp_ask(ask a,ask b){ return a.p>b.p; }
void solve1(){
	for (int i=1;i<=n;i++) fa[i]=i,mn[i]=dist[i];
	for (int i=0;i<q;i++) scanf("%d%d",&x[i].v,&x[i].p),x[i].id=i;
	sort(x,x+q,cmp_ask);
	sort(ed+1,ed+edge+1,cmp_ed);
	int i=0;
	while (x[i].p>=ed[1].a) x[i].ans=mn[find(x[i].v)],i++;
	for (int e=1;e<=edge;e++){
		int u=ed[e].from,v=ed[e].tail;
		if (find(u)!=find(v)) uion(u,v);
		while (x[i].p>=ed[e+1].a&&i<q){
			x[i].ans=mn[find(x[i].v)];
			i++;
		}
	}
	sort(x,x+q,cmp_ask_ans);
	for (int i=0;i<q;i++) printf("%d\n",x[i].ans);
}
void solve2(){}
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
		}
		SPFA(1);
		scanf("%d%d%d",&q,&k,&s);
		if (k==0) solve1();
		else solve2();
	}
	return 0;
	fclose(stdin); fclose(stdout);
}
