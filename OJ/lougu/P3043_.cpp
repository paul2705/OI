#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int mod=1e9+7;
int fa[MAXN],d[MAXN],e[MAXN],n,m;
int ans=1;
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){
	int fx=find(x),fy=find(y);
	fa[fx]=fy; d[fy]+=d[fx]; e[fy]+=e[fx]+1;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) fa[i]=i,d[i]=1;
	for (int i=0,u,v;i<m;i++){
		scanf("%d%d",&u,&v);
		if (find(u)!=find(v)) uion(u,v);
		else e[find(u)]++;
	}
	for (int i=1;i<=n;i++){
		if (fa[i]==i){
			if (e[i]<d[i]) (ans*=d[i])%=mod;
			else (ans*=2)%=mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}
