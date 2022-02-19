#include <bits/stdc++.h>
#define mod 998244353
using namespace std;
const int N = 1e5 + 10;

int qpow(int x,int y) {
    int res = 1;
    while (y) {
        if (y & 1) res = 1ll * res * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return res;
}

struct E{
	int to , nex;
}e[N * 6];int head[N] , ecnt;


int d[N];
void addE(int fr,int to){e[++ecnt]=(E){to,head[fr]};head[fr] = ecnt;}
void addEdge(int fr,int to){d[fr]++;d[to]++;addE(fr,to);addE(to,fr);}


bool vis[N] , oncir[N];
int sta[N] , top;

int bcnt , bel[N] , cal[N] , sumE[N] , sz[N];

void col(int o,int fa,int id){
	bel[o] = id; sz[id]++;
	for (int j = head[o];j;j=e[j].nex){
		if ( !bel[e[j].to] ){
			col(e[j].to , o , id);
		}
	}
}


int f[N] , res = 1;
void dp(int o,int fa){
	f[o] = 1;
	
	for (int j = head[o];j;j=e[j].nex)
	if (e[j].to != fa){
		dp(e[j].to , o);
//		f[o][1] = 1ll * f[o][1] * f[e[j].to][1] % mod;
//		f[o][0] = 1ll * f[o][0] * (f[e[j].to][0] + f[e[j].to][1]) % mod;
	}
}

vector <int> bl;
queue <int> q;
bool vis1[N] , vis2[N];
void dfs(int o){
	bl.push_back(o);
	vis1[o] = 1; f[o] = 1;
	
	for (int j = head[o];j;j=e[j].nex)
	if (!vis1[e[j].to]){
		dfs(e[j].to);
	}
}


 
int cnt[N]; 
int n , m;
int main(){
	freopen("femaledress3.in","r",stdin);
//	freopen("femaledress.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	
	for (int i = 1;i <= m;i++){
		int u , v;scanf("%d%d",&u,&v);
		addEdge(u , v);
	}
	
	for (int i = 1;i <= n;i++) if (!bel[i]) {
		cal[++bcnt] = 1;
		col(i , i , bcnt);
	}
	for (int i = 1;i <= ecnt;i += 2) sumE[ bel[e[i].to] ]++;

	for (int i = 1;i <= n;i++)
	if (!vis1[i]){
		if ( sumE[ bel[i] ] >= sz[ bel[i] ] ){
			bl.clear();
			dfs(i);
		
			for (int j = 0;j < bl.size();j++)
			if (d[bl[j]] == 1){
				q.push(bl[j]);
			}
			
			while (q.size()){
				int cur = q.front();q.pop();
				vis2[cur] = true;
				for (int j = head[cur];j;j=e[j].nex){
					if ( !vis2[e[j].to] ){
						f[e[j].to] = 1ll * f[e[j].to] * ( f[cur] + 1 ) % mod;	
					
						if ( --d[e[j].to] == 1){
							q.push(e[j].to);
						}
					}
				}
			}
			
			int mul = 1;
			for (int j = 0;j < bl.size();j++) 
			if (!vis2[bl[j]]) {
//				if (f[bl[j]] != 1)printf("ga %d %d\n",f[bl[j]],mul);
				mul = 1ll * mul * f[bl[j]] % mod;
			}
			
			
			cal[ bel[i] ] = mul;
			if (sumE[bel[i]] == sz[bel[i]]) mul++;
//			if (mul != 1)printf("fafa %d %d\n",bel[i],mul);
			
			res = 1ll * res * mul % mod;
		}
	}


	int ans = 0;
	for (int i = 1;i <= bcnt;i++){
		 ans += max(sumE[i] , sz[i]);
	}
	cout<<ans<<endl;
	ans = 1;
//	for (int i = 1;i <= bcnt;i++) {
//		if (cal[i] != 1) printf("gaga %d\n",cal[i]);
//		ans = 1ll * ans * cal[i] % mod;
//	}
	cout<<res;
//	for (int i = 1;i <= n;i++) printf("%d ",cal[bel[i]]);
	return 0;
}
