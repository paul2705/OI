#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=5e5+5;
const int MAXM=1e6+6;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int c[MAXN],n,w[MAXN],f[MAXN];
struct rec{
	int dat,id;
} res[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
bool cmp(rec a,rec b){ return a.dat>b.dat; }
void dfs(int u,int p){
	int cnt=0; f[u]=c[u];
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v!=p){
			dfs(v,u); w[v]+=2; f[v]++;
			res[cnt++]=(rec){f[v]-w[v],v};
		}
	}
	sort(res,res+cnt,cmp);
	for (int i=0;i<cnt;i++){
		int v=res[i].id;
		f[u]=max(f[u],w[u]+f[v]); w[u]+=w[v];
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	for (int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	dfs(1,0);
//	for (int i=1;i<=n;i++) printf("%d %d %d\n",i,w[i],f[i]);
	printf("%d\n",max(f[1],(n-1)*2+c[1]));
	return 0;
}
