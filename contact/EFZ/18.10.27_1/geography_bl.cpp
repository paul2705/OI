#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
const int MAXM=MAXN*2;
const ll mod=1e9+7;
int edge,head[MAXN],nex[MAXM],tail[MAXM];
int fa[MAXN],sz[MAXN];
int n,m,u[MAXM],v[MAXM],cnt;
bool use[MAXN],usew[MAXM];
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){
	int fx=find(x),fy=find(y);
	if (fx==fy) return;
	fa[fx]=fy;
	sz[fy]+=sz[fx];
	sz[fx]=0;
}
int main(){
	freopen("geography.in","r",stdin);
	freopen("geography1.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1,op,uc,vc;i<=m;i++){
		ll ans=1;
		for (int j=1;j<=n;j++) use[j]=0,fa[j]=j,sz[j]=1;
		scanf("%d",&op);
		if (op==1){
			cnt++;
			scanf("%d%d",&u[cnt],&v[cnt]);
		}
		else {
			scanf("%d%d",&uc,&vc);
			for (int j=1;j<=cnt;j++){
				if (usew[j]==0&&u[j]==uc&&v[j]==vc){
//					cout<<"cnt: "<<u[j]<<" "<<v[j]<<endl;
					usew[j]=1;
					break;
				}
			}
		}
		for (int j=1;j<=cnt;j++){
			if (usew[j]) continue;
			uion(u[j],v[j]);
		}
		for (int j=1;j<=n;j++){
			int fj=find(j);
//			cout<<j<<" "<<fj<<" "<<sz[fj]<<endl;
			if (use[fj]) continue;
			ans=(ans*(ll)sz[fj])%mod; use[fj]=1;
		}
		printf("%lld\n",ans);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
