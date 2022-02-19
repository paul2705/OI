#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
const int MAXM=4e5+5;
int n,m,Q;
ll R(ll x){ return x+x/10; }
int edge,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
int tot,d[MAXN];
ll f[MAXN][330];
int num[MAXN];
queue<int> q;
ll tmp[1010];
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
	d[v]++;
}
void ins(int u,int v,int c){
	int cnt=0;
	for (int i=1;i<=num[u];i++) tmp[++cnt]=f[u][i]+c;
	for (int i=1;i<=num[v];i++) tmp[++cnt]=f[v][i];
	sort(tmp+1,tmp+cnt+1);
	num[v]=1;
	f[v][1]=tmp[1]; f[v][0]=-100;
	for (int i=2;i<=cnt;i++){
		if (R(f[v][num[v]-1]+1)>=tmp[i]) f[v][num[v]]=tmp[i];
		else f[v][++num[v]]=tmp[i];
	}
	return;
}
void solve(){
	f[1][1]=0;
	num[1]=1;
	for (int i=1;i<=n;i++){
		if (!d[i]) q.push(i);
	}
	while (!q.empty()){
		int u=q.front();
		q.pop();
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e],W=w[e];
			ins(u,v,W);
			d[v]--;
			if (!d[v]) q.push(v);
		}
	}
	return;
}
bool check(int u,ll dis){
	int l=0,r=num[u]+1;
	while (l+1<r){
		int mid=(l+r)>>1;
		if (f[u][mid]>=dis) r=mid;
		else l=mid;
	}
	if (r==num[u]+1) return false;
	return R(dis)>=f[u][r];
}
int main(){
	scanf("%d %d %d",&n,&m,&Q);
	for (int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		add(u,v,w);
	}
	solve();
	for (int i=1;i<=Q;i++){
		int k; ll dis;
		scanf("%d %lld",&k,&dis);
		if (check(k,dis)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
