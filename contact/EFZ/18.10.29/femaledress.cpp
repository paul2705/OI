#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=6e5+5;
int edge,head[MAXN],nex[MAXM],tail[MAXM];
int n,m,ans;
int fa[MAXN],sz[MAXN],sw[MAXN];
bool use[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){
	int fx=find(x),fy=find(y);
	if (fx==fy){
		sw[fx]++;
		return;
	}
	fa[fx]=fy;
	sz[fy]+=sz[fx];
	sz[fx]=0;
	sw[fy]+=sw[fx]+1;
	sw[fx]=0;
}
int main(){
	freopen("femaledress.in","r",stdin);
	freopen("femaledress.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
	for (int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
		uion(u,v);
	}
	for (int i=1;i<=n;i++) use[find(i)]=1;
	int cnt=0;
	for (int i=1;i<=n;i++){
		if (use[i]){
//			cout<<i<<" "<<sz[i]<<" "<<sw[i]<<endl;
			if (sz[i]==sw[i]+1) ans+=sz[i];
			else ans+=sw[i];
		}
	}
	printf("%d\n0\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
