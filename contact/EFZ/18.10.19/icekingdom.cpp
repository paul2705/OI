#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e3+5;
const int MAXM=MAXN*2;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int n,m,fa[MAXN];
bool use[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){ fa[find(x)]=find(y); }
int main(){
	freopen("icekingdom.in","r",stdin);
	freopen("icekingdom1.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	for (int i=1,l,r;i<=m;i++){
		scanf("%d%d",&l,&r);
		for (int i=1;i<=n;i++) fa[i]=i,use[i]=0;
		for (int u=l;u<=r;u++){
			for (int e=head[u];e;e=nex[e]){
				int v=tail[e];
				if (v<l||v>r) continue;
				uion(u,v);
			}
		}
		int ans=0;
		for (int i=l;i<=r;i++){
			if (!use[find(i)]){
				use[find(i)]=1;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
