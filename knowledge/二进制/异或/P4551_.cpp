#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5;
const int MAXM=MAXN*2;
const int MAXT=MAXN*45;
int cnt=1,ch[MAXT][3];
int n,ans;
int edge,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
int d[MAXN];
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
int inverse(int x){
//	cout<<endl<<__func__<<endl;
	int tmp=0;
	while (x>0){
//		cout<<x<<" "<<tmp<<endl;
		tmp=tmp*2+(x&1);
		x>>=1;
	}
	return tmp;
}
void ins(int x){
//	cout<<x<<" "<<inverse(x)<<endl;
	x=inverse(x);
	for (int u=1;x!=0;x>>=1){
//		cout<<(x&1)<<" ";
		if (ch[u][x&1]==0) ch[u][x&1]=++cnt;
		u=ch[u][x&1];
	}
//	cout<<endl;
}
void dfs(int u,int p){
	ins(d[u]);
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		d[v]=d[u]^w[e];
		dfs(v,u);
	}
}
int qry(int x){
//	cout<<__func__<<endl;
	int ret=0;
	x=inverse(x);
	for (int u=1;;x>>=1){
		int pos=(x&1)^1; 
		if (ch[u][pos]!=0) u=ch[u][pos],ret=ret*2+pos;
		else if (ch[u][pos^1]!=0) u=ch[u][pos^1],ret=ret*2+(pos^1);
		else break;
//		cout<<(ret&1)<<" "<<(x&1)<<endl;
	}
	return ret;
}
void dfs1(int u){
	if (u==0) return;
	printf("%d: 0:%d 1:%d\n",u,ch[u][0],ch[u][1]);
	dfs1(ch[u][0]); dfs1(ch[u][1]);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	dfs(1,0);
//	dfs1(1);
//	for (int i=1;i<=n;i++) printf("%d %d %d\n",i,d[i],inverse(qry(d[i])));
	for (int i=1;i<=n;i++) ans=max(ans,inverse(qry(d[i]))^d[i]);
	printf("%d\n",ans);
	return 0;
}
