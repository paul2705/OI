#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
const int MAXM=5e5+5;
struct rec{
	int u,v;
	ll w;
	bool operator < (const rec& b) const {
		return w<b.w;
	}
} ed[MAXM];
int n,m,fa[MAXN],cnt=0;
ll ans;
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){ fa[find(x)]=find(y); }
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v; ll w; scanf("%d%d%lld",&u,&v,&w);
		if (w>0) ed[cnt++]=(rec){u,v,w};
		ans+=w;
	}
	sort(ed,ed+cnt);
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=cnt-1;i>=0;i--){
		int u=ed[i].u,v=ed[i].v;
		ll w=ed[i].w;
		if (find(u)!=find(v)){
			uion(u,v);
			ans-=w; cout<<u<<" "<<v<<" "<<w<<endl;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
