#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e2+5;
struct rec{
	int x,id;
} a[MAXN];
int id[MAXN],f[MAXN][MAXN];
int n,m,k;
bool cmp(rec a,rec b){ return a.x<b.x; }
int main(){
	memset(f,63,sizeof(f));
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i].x),f[i][i]=0,a[i].id=i;
	sort(a+1,a+n+1,cmp);
	for (int i=1,u,v,w;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		u=id[u],v=id[v];
		f[u][v]=f[v][u]=min(f[u][v],w);
	}
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]+max(a[i].x,max(a[j].x,a[k].x)));
			}
		}
	}
	for (int i=1,u,v;i<=k;i++){
		scanf("%d%d",&u,&v);
		printf("%d\n",f[u][v]);
	}
	return 0;
}
