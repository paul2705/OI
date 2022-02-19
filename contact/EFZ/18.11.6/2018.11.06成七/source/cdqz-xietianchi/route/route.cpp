#include <bits/stdc++.h>
#define mod 998244353
using namespace std;

const int N = 1e5 + 10;

int add(int x,int y){
	x += y;
	if (x >= mod){
		x -= mod;
	}
	return x;
}
struct Graph{
	struct E{
		int fr , to , nex , val;
	}e[N * 2];int head[N] , ecnt;
	
	void adde(int fr,int to,int val){e[++ecnt]=(E){fr,to,head[fr],val};head[fr]=ecnt;}


}G1 , G2 , G3;
int n , m;

struct Node{
	int pos , dis;
	inline bool operator < (const Node &a) const{
		return dis > a.dis;
	}
};
priority_queue <Node> q;
int dis1[N] , dis2[N];
void dj(int s,int *dis,const Graph &p){
	memset(dis , 0x3f , sizeof (int) * (n + 1) );

	dis[s] = 0;q.push((Node){s , 0});
	
	while (q.size()){
		Node cur = q.top();q.pop();
		if (cur.dis > dis[cur.pos] ) continue;
		for (int j = p.head[cur.pos];j;j=p.e[j].nex)
		if (dis[p.e[j].to] > dis[cur.pos] + p.e[j].val){
			dis[p.e[j].to] = dis[cur.pos] + p.e[j].val;
			q.push((Node){p.e[j].to , dis[p.e[j].to] });
		}
	}
	
}

int f[N] , g[N] , ind[N] , oud[N];

queue <int> que;
int dfn[N] , clk;
int main(){
	
	freopen("route.in","r",stdin);
	freopen("route.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= m;i++){
		int u , v , val;scanf("%d%d%d",&u,&v,&val);
		G1.adde(u , v , val);
		G2.adde(v , u , val);
	}
	
	dj(1 , dis1 , G1);
	dj(2 , dis2 , G2);
	
//	for (int i = 1;i <= n;i++){
//		printf("%d %d\n",dis1[i],dis2[i]);
//	}
	for (int i = 1;i <= m;i++){
//		printf("%d dis1 %d %d dis2 %d\n",G1.e[i].fr,dis1[G1.e[i].fr],G1.)
		if (dis1[G1.e[i].fr] + G1.e[i].val + dis2[G1.e[i].to] == dis1[2]){
			G3.adde(G1.e[i].fr , G1.e[i].to , G1.e[i].val );
			ind[G1.e[i].to]++;
			oud[G1.e[i].fr]++;
			
//			printf("%d -> %d %d\n",G1.e[i].fr,G1.e[i].to,G1.e[i].val);
		}
	}	
	
	for (int i = 1;i <= n;i++){
		if (!ind[i]){
			dfn[++clk] = i;
			que.push(i);
			f[i] = 1;
		}
	}
	
	while (que.size()){
		int cur = que.front();que.pop();
		for (int j = G3.head[cur];j;j=G3.e[j].nex)
		{
			f[G3.e[j].to] = add(f[G3.e[j].to] , f[cur]);
			ind[G3.e[j].to]--;
			if (!ind[G3.e[j].to]){
				dfn[++clk] = G3.e[j].to;
				que.push(G3.e[j].to);
			}
		}
	}
	
	g[2] = 1;
	for (int i = clk - 1;i >= 1;i--){
		int cur = dfn[i];
		for (int j = G3.head[cur];j;j=G3.e[j].nex){
			g[cur] = add(g[G3.e[j].to] , g[cur]);
		}
	}
	
//	for (int i = 1;i <= n;i++){
//		printf("%d:: %d %d\n",i,f[i],g[i]);
//	}
	
	for (int i = 1;i <= m;i++){
		if (dis1[G1.e[i].fr] + G1.e[i].val + dis2[G1.e[i].to] == dis1[2]){
			int val = 1ll * f[G1.e[i].fr] * g[G1.e[i].to] % mod; 
			if (val  == f[2] && oud[G1.e[i].fr] == 1){
				puts("1");
			}else{
				puts("0");
			}
		}else{
			if (dis1[G1.e[i].to] + G1.e[i].val + dis2[G1.e[i].fr] < dis1[2]){
				puts("-1");
			}else{
				puts("0");
			}
		}
	}
	return 0;
}
