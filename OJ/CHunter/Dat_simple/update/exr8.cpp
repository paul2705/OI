#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int MAXN=1e4+5;
const int MAXM=2e4+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int has1,has2;
int T,n,fa[MAXN];
char s[MAXN];
ll sz[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs(int d,int u,int p){
	if (d==strlen(s+1)+1) return;
	if (s[d]=='1') dfs(d+1,p,fa[p]);
	else{
		n++; add(u,n); fa[n]=u;
		dfs(d+1,n,u);
	}
}
int Get(int u,int p){
	vector<int> lis; lis.clear();
	sz[u]=1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		lis.push_back(Get(v,u));
		sz[u]+=sz[v];
	}
	if (lis.empty()) return 1;
	sort(lis.begin(),lis.end());
	int ret=0;
	for (int i=0;i<lis.size();i++){
		ret=((ll)ret*29%mod+lis[i])%mod;
	}
//	cout<<__func__<<" "<<ret<<" "<<sz[u]<<endl;
	return (ll)ret*sz[u]%mod;
}
int main(){
	scanf("%d",&T);
	while (T--){
		has1=has2=0;
		n=1;
		edge=0; memset(head,0,sizeof(head));
		scanf("%s",s+1);
		dfs(1,1,0);
		has1=Get(1,0);
		scanf("%s",s+1);
		edge=0; memset(head,0,sizeof(head));
		n=1;
		dfs(1,1,0);
		has2=Get(1,0);
//		cout<<has1<<" "<<has2<<endl;
		if (has1==has2) printf("same\n");
		else printf("different\n");
	}
	return 0;
}
