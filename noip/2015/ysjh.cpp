#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=3e5+5;
const int MAXM=6e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
int cnt[MAXN],d[MAXN],fa[MAXN][20],pw[MAXN][20];
int pose,mxe,fl[MAXN],s[MAXN],t[MAXN],len[MAXN];
int fau[MAXN],wu[MAXN];
int n,m,res;
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void dfs(int u,int p){
	d[u]=d[p]+1; fa[u][0]=fau[u]=p; 
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		pw[v][0]=wu[v]=w[e]; dfs(v,u);
	}
}
int gen(int u,int p){
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		cnt[u]+=gen(v,u);
//		if (cnt[u]==cnt[v]&&cnt[u]==res){
//			if (mxe<w[e]) mxe=w[e];
//		}
	}
	return cnt[u];
}
int lca(int u,int v,int &x){
	x=0;
	if (d[u]<d[v]) swap(u,v);
	for (int k=19;k>=0;k--){
		if (d[fa[u][k]]>d[v]) x+=pw[u][k],u=fa[u][k];
	}
	if (d[u]>d[v]) x+=pw[u][0],u=fa[u][0];
	if (u==v) return u;
	for (int k=19;k>=0;k--){
		if (fa[u][k]!=fa[v][k]) x+=pw[u][k]+pw[v][k],u=fa[u][k],v=fa[v][k];
	}
	x+=pw[u][0]+pw[v][0];
	return fa[u][0];
}
void dfs1(int u,int p){
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		if (cnt[u]==cnt[v]&&cnt[u]==res){
			if (mxe<w[e]) mxe=w[e];
		}
		dfs1(v,u);
	}
}
bool check(int mid){
	int mx=mid; res=0;
	for (int i=1;i<=n;i++) cnt[i]=0;
	for (int i=1;i<=m;i++){
		if (len[i]>mid){
			mx=max(mx,len[i]); res++;
			cnt[s[i]]++; cnt[t[i]]++; cnt[fl[i]]--; cnt[fau[fl[i]]]--;
		}
	}
	mxe=0;
	gen(1,0); dfs1(1,0);
	if (mx-mxe>mid) return 0;
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1,u,v,w;i<n;i++){
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	dfs(1,0);
	for (int k=1;k<20;k++){
		for (int u=1;u<=n;u++){
			fa[u][k]=fa[fa[u][k-1]][k-1];
			pw[u][k]=pw[u][k-1]+pw[fa[u][k-1]][k-1];
		}
	}
	int mx=0;
	for (int i=1;i<=m;i++){
		scanf("%d%d",&s[i],&t[i]);
		fl[i]=lca(s[i],t[i],len[i]);
//		cout<<fl[i]<<" "<<len[i]<<endl;
		mx=max(mx,len[i]);
	}
	int l=0,r=mx,mid;
	while (l+1<r){
		mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid;
	}
	printf("%d\n",r);
	return 0;
}
