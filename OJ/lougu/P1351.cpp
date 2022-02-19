#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
const int MAXM=4e5+5;
const int mod=10007;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int a[MAXN],n;
int use[MAXN],mx[MAXN],sum[MAXN],sqr[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs(int u){
	if (use[u]) return;
	use[u]=1;
	int mx1=0,mx2=0;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (a[v]>a[mx1]) mx2=mx1,mx1=v;
		else if (a[v]>a[mx2]) mx2=v;
		sum[u]=(sum[u]+a[v])%mod;
		sqr[u]=(sqr[u]+a[v]*a[v]%mod)%mod;
		dfs(v);
	}
//	cout<<__func__<<" "<<u<<" "<<mx1<<" "<<mx2<<endl;
//	cout<<sum[u]<<" "<<sqr[u]<<endl;
	if (mx1!=mx2) mx[u]=a[mx1]*a[mx2];
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1);
	int ansmx=0,anssum=0;
	for (int i=1;i<=n;i++){
		ansmx=max(ansmx,mx[i]);
		anssum=(anssum+sum[i]*sum[i]%mod-sqr[i])%mod;
	}
	printf("%d %d\n",ansmx,(anssum+mod)%mod);
	return 0;
}
