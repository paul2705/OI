#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
const int MAXM=MAXN*2;
ll unk[MAXN][25],rig[MAXN][25];
int n,s,k;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int ans;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs(int u,int p){
	unk[u][0]++;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u);
		for (int i=0;i<k;i++){
			unk[u][i+1]+=unk[v][i];
			rig[u][i]+=rig[v][i+1];
		}
	}
	int d=(unk[u][k]+s-1)/s;
	ans+=d;
	rig[u][k]+=d*s;
	for (int i=0;i<=k;i++){
		for (int j=i;rig[u][i]&&j>=0&&(j>=i-1||u==1);j--){
			d=min(rig[u][i],unk[u][j]);
			rig[u][i]-=d; unk[u][j]-=d;
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&s,&k);
	for (int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	dfs(1,0);
	int tmp=0;
	for (int i=0;i<=k;i++) tmp+=unk[1][i];
	printf("%d",ans+(tmp+s-1)/s);
	return 0;
}
