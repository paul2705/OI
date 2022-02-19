#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
const int MAXN=1e5+5;
int fa[MAXN],e[MAXN],p[MAXN];
int n,m;
long long ans=1;
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){
	int fx=find(x),fy=find(y);
	fa[fx]=fy; e[fy]+=e[fx]+1; p[fy]+=p[fx]; p[fx]=0;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) fa[i]=i,p[i]=1;
	for (int i=0,u,v;i<m;i++){
		scanf("%d%d",&u,&v);
		if (find(u)!=find(v)) uion(u,v);
		else e[find(u)]++;
	}
	for (int i=1;i<=n;i++){
		if (fa[i]==i){
			if (e[i]<p[i]) ans*=p[i],ans%=mod;
			else ans*=2,ans%=mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
