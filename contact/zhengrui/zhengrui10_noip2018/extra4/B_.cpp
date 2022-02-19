#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=15;
const int MAXM=MAXN*2;
ll n,xn,yn;
int edge=1,head[MAXN],tail[MAXM],nex[MAXM],from[MAXM];
ll w[MAXM],ans=1e18;
int id[MAXN];
ll usee[MAXM],use[MAXN];
int fa[MAXN];
void add(int u,int v,ll W){
	edge++,nex[edge]=head[u],from[edge]=u,head[u]=edge,tail[edge]=v,w[edge]=W;
}
bool dfs(int u,int p){
	if (id[u]==2) return 0;
//	if (use[u]) return 1;
//	use[u]=1;
	bool f=1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
//		if (use[v]) continue;
		if (usee[e]) continue;
		if (id[v]==2) return 0;
		f&=dfs(v,u);
	}
	return f;
}
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){ fa[find(x)]=find(y); }
int main(){
	freopen("B.in","r",stdin);
	freopen("B1.out","w",stdout);
	scanf("%lld",&n);
	scanf("%lld",&xn);
	for (int i=1;i<=n+3;i++) fa[i]=i;
	for (int i=1,x;i<=xn;i++){
		scanf("%d",&x);
		id[x]=1;
		uion(x,n+1);
	}
	scanf("%lld",&yn);
	for (int i=1,x;i<=yn;i++){
		scanf("%d",&x);
		id[x]=2;
		uion(x,n+2);
	}
	for (int i=1,u,v;i<n;i++){
		ll w;
		scanf("%d%d%lld",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	for (int s=0;s<(1<<(n-1));s++){
		ll ret=0;
		bool f=1;
		memset(use,0,sizeof(use));
		memset(usee,0,sizeof(usee));
//		for (int i=1;i<=n+3;i++) fa[i]=i;
		for (int i=0;i<n;i++){
			if (s&(1<<i)) ret+=w[(i+1)*2],usee[(i+1)*2]=usee[(i+1)*2+1]=1;
		}
		for (int i=1;i<=n;i++){
			if (id[i]==1){
				if (!use[i]){
					f&=dfs(i,0);
				}
			}
		}
/*		if (ret>ans) continue;
		if (!f) continue;
		for (int i=1;i<=n;i++){
			for (int e=head[i];e;e=nex[e]){
				int v=tail[e];
				if (usee[e]) continue;
				cout<<i<<" "<<v<<endl;
			}
		}
		cout<<ret<<": "<<ans<<endl<<endl;
*/		if (f) ans=min(ans,ret);
	}
/*	for (int s=0;s<(1<<(n-1));s++){
        ll ret=0;
        bool f=1;
        memset(use,0,sizeof(use));
        memset(usee,0,sizeof(usee));
        //        for (int i=1;i<=n+3;i++) fa[i]=i;
        for (int i=0;i<n;i++){
            if (s&(1<<i)) ret+=w[(i+1)*2],usee[(i+1)*2]=usee[(i+1)*2+1]=1;
        }
        for (int i=1;i<=n;i++){
            if (id[i]==1){
                if (!use[i]){
                    f&=dfs(i,0);
                }
            }
        }
               if (ret!=ans) continue;
         if (!f) continue;
         for (int i=1;i<=n;i++){
         for (int e=head[i];e;e=nex[e]){
         int v=tail[e];
         if (usee[e]) continue;
         cout<<i<<" "<<v<<endl;
         }
         }
         cout<<ret<<": "<<ans<<endl<<endl;
    }
*/	printf("%lld\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
