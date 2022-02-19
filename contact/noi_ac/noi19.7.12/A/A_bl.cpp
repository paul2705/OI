#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e3+5;
const int MAXM=4e6+6;
int n,m,id[MAXN];
bool use[MAXN];
int edge,head[MAXN],tail[MAXM],nex[MAXM];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
bool flag=0;
int rid[MAXN];
bool check(){
	for (int i=1;i<=n;i++) rid[id[i]]=i;
	for (int i=1;i<=n;i++){
		int posl=rid[i];
		for (int e=head[i];e;e=nex[e]){
			int v=tail[e];
			int posr=rid[v];
			for (int j=1;j<=n;j++){
				if (i==j||j==v) continue;
				int posx=rid[j];
				if (posx<posl||posx>posr) continue;
				for (int ne=head[j];ne;ne=nex[ne]){
					int nv=tail[ne];
					if (nv==i||nv==v) continue;
					int posy=rid[nv];
//					cout<<i<<" "<<v<<" "<<j<<" "<<nv<<" "<<(posy<posl||posy<posr)<<endl;
					if (posy<posl||posy>posr) return 0;
				}
			}
		}
	}
	return 1;
}
void dfs(int d){
//	if (flag) return;
	if (d==n+1){
//		cout<<__func__;
//		for (int i=1;i<=n;i++) printf("%d ",id[i]);
//		cout<<endl;
		if (check()){
			for (int i=1;i<=n;i++) printf("%d ",id[i]);
			cout<<endl;
			flag=1;
			return;
		}
	}
	for (int i=1;i<=n;i++){
		if (use[i]) continue;
		id[d]=i; use[i]=1;
		dfs(d+1);
		use[i]=0;
	}
}
void solve1(){
	dfs(1);
	if (!flag) printf("-1\n");
}
void solve2(){

}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	if (n<=10) solve1();
	else solve2();
	return 0;
}
