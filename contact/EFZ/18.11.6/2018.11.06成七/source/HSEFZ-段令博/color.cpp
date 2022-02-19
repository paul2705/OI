#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=1e2+5;
const int MAXM=MAXN*2;
int edge,head[MAXN],nex[MAXM],tail[MAXM];
int ed,he[MAXN],ne[MAXM],ta[MAXM];
int n,m,a[MAXN],d[MAXN],d1[MAXN];
int fa[MAXN][20],fa1[MAXN];
bool mp[MAXN][MAXN],use1[MAXN];
int lis[MAXN],cnt;
int rd[MAXN];
struct rec{
	int a,b,c;
} ans[MAXN];
queue<int> q;
vector<int> col[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void ad(int u,int v){
	if (mp[u][v]) return;
//	cout<<":: "<<u<<" "<<v<<endl;
	mp[u][v]=1; rd[v]++;
	ed++,ne[ed]=he[u],he[u]=ed,ta[ed]=v;
}
void dfs(int u,int p){
	fa[u][0]=p; d[u]=d[p]+1; fa1[u]=p;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u);
	}
}
void ini(){
	for (int k=1;k<20;k++){
		for (int u=1;u<=n;u++){
			fa[u][k]=fa[fa[u][k-1]][k-1];
		}
	}
}
void dfs1(int u,int p){
//	cout<<u<<" "<<p<<endl;
	d1[u]=d1[p]+1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];	
		if (d1[v]>0) continue;
		if (v==p) continue;
		dfs1(v,u);
	}
}
int lca(int u,int v){
	if (d[u]<d[v]) swap(u,v);
	for (int k=19;k>=0;k--){
		if (d[fa[u][k]]>d[v]) u=fa[u][k];
	}
	if (d[u]>d[v]) u=fa[u][0];
	if (u==v) return u;
	for (int k=19;k>=0;k--){
		if (fa[u][k]!=fa[v][k]) u=fa[u][k],v=fa[v][k];
	}
	if (u!=v) return fa[u][0];
}
void get(int u,int v,int col){
//	cout<<__func__<<endl;
	while (u!=v){
//		cout<<u<<" "<<v<<endl;
//		cout<<d[u]<<" "<<d[v]<<endl;
//		if (u==v) break;
		if (a[u]!=col) ad(a[u],col);
		if (a[v]!=col) ad(a[v],col);
		if (d[u]<d[v]) swap(u,v);
		if (d[u]>d[v]) u=fa1[u];
		if (d[u]==d[v]) u=fa1[u],v=fa1[v];
//		cout<<"fa: "<<u<<" "<<v<<endl;
	}
//	cout<<"out"<<endl;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),col[a[i]].push_back(i);
	for (int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	dfs(1,0); ini();
	for (int i=1;i<=m;i++){
//		cout<<i<<endl;
		int mx=0,pos=0,pos1=0;
		if (col[i].size()==0) continue;
		for (int j=0;j<col[i].size();j++){
			int v=col[i][j];
			if (mx<d[v]){
				mx=d[v];
				pos=v;
			}
		}
//		cout<<"fuck"<<endl;
		dfs1(pos,0); 
		mx=0;
//		cout<<"fuck"<<endl;
		for (int j=0;j<col[i].size();j++){
			int v=col[i][j];
//			cout<<v<<": "<<d1[v]<<endl;
			if (mx<d1[v]){
				mx=d1[v];
				pos1=v;
			}
		}
		ans[i]=(rec){pos,pos1,i};
//		cout<<i<<" "<<pos<<" "<<pos1<<endl;
		get(pos,pos1,i);
	}
	for (int i=1;i<=m;i++) if (rd[i]==0) q.push(i);
//	cout<<"fuck"<<endl;
	while (!q.empty()){
		int u=q.front(); q.pop();
		lis[cnt++]=u;
		for (int e=he[u];e;e=ne[e]){
			int v=ta[e];
			rd[v]--;
			if (rd[v]==0) q.push(v);
		}
	}
//	cout<<"fuck"<<endl;
	for (int i=0;i<cnt;i++){
		use1[lis[i]]=1;
	}
	for (int i=1;i<=m;i++){
		if (!use1[i]) printf("%d %d %d\n",i,1,1);
	}
	for (int i=0;i<cnt;i++){
		int x=lis[i];
		printf("%d %d %d\n",ans[x].c,ans[x].a,ans[x].b);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
