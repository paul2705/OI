#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2e3+5;
const int MAXV=3e2+5;
const int MAXM=2e5+5;
int edge,head[MAXV],tail[MAXM],nex[MAXM];
double dis[MAXN][MAXN],f[MAXN][MAXN][3],w[MAXM];
int c[MAXN],d[MAXN];
double k[MAXN],ans=1e9;
int n,m,V,E;
void add(int u,int v,double W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&V,&E);
	for (int i=1;i<=n;i++) scanf("%d",&c[i]);
	for (int i=1;i<=n;i++) scanf("%d",&d[i]);
	for (int i=1;i<=n;i++) scanf("%lf",&k[i]);
	for (int i=1;i<=V;i++){
		for (int j=1;j<=V;j++) dis[i][j]=1e6;
//		dis[i][i]=0;
	}
	for (int i=1,u,v;i<=E;i++){
		double w=0;
		scanf("%d%d%lf",&u,&v,&w);
//		add(u,v,w);add(v,u,w);
		dis[u][v]=dis[v][u]=min(dis[u][v],w);
	}
	for (int k=1;k<=V;k++){
		for (int i=1;i<=V;i++){
			for (int j=1;j<=V;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for (int i=1;i<=V;i++) dis[i][i]=dis[i][0]=dis[0][i]=0;
	for (int i=1;i<=n;i++){
		for (int j=0;j<=n;j++){
//			cout<<i<<" "<<j<<" "<<dis[i][j]<<endl;
			f[i][j][0]=f[i][j][1]=1e6;
		}
	}
	f[1][0][0]=f[1][1][1]=0;
	for (int i=2;i<=n;i++){
		f[i][0][0]=f[i-1][0][0]+dis[c[i-1]][c[i]];
		for (int j=1;j<=min(i,m);j++){
			f[i][j][0]=min(f[i-1][j][1]+dis[c[i-1]][c[i]]*(1-k[i-1])+dis[d[i-1]][c[i]]*k[i-1],f[i-1][j][0]+dis[c[i-1]][c[i]]);
			f[i][j][1]=min(f[i-1][j-1][0]+dis[c[i-1]][d[i]]*k[i]+dis[c[i-1]][c[i]]*(1-k[i]),f[i-1][j-1][1]+dis[d[i-1]][d[i]]*k[i-1]*k[i]+dis[c[i-1]][c[i]]*(1-k[i-1])*(1-k[i])+dis[c[i-1]][d[i]]*(1-k[i-1])*k[i]+dis[d[i-1]][c[i]]*k[i-1]*(1-k[i]));
//			cout<<i<<" "<<j<<" "<<f[i][j][0]<<" "<<f[i][j][1]<<endl;
			if (i==n) ans=min(ans,min(f[i][j][1],f[i][j][0]));
		}
		ans=min(ans,f[n][0][0]);
	}
	if (n==1) ans=min(f[1][0][0],f[1][1][1]);
	printf("%.2lf\n",ans);
	return 0;
}
