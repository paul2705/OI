#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e2+5;
const int inf=1e7;
ll f[MAXN][MAXN],g[MAXN][MAXN];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) f[i][j]=inf;
	}
	for (int i=1;i<=m;i++){
		int u,v,w; scanf("%d%d%d",&u,&v,&w);
		f[u][v]=f[v][u]=w;
		g[u][v]=g[v][u]=1;
	}
//	for (int i=1;i<=n;i++) g[i][i]=1;
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (f[i][k]+f[k][j]<f[i][j]){
					f[i][j]=f[i][k]+f[k][j];
					g[i][j]=g[i][k]*g[k][j];
				}
				else if (f[i][k]+f[k][j]==f[i][j]){
					g[i][j]+=g[i][k]*g[k][j];
				}
			}
		}
	}
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=n;j++) cout<<i<<" "<<j<<" "<<g[i][j]<<endl;
//	}
	for (int i=1;i<=n;i++){
		double ans=0;
		for (int s=1;s<=n;s++){
			for (int t=1;t<=n;t++){
				if (s==t||s==i||t==i) continue;
				if (f[s][i]+f[i][t]!=f[s][t]) continue;
//				cout<<g[s][i]<<"*"<<g[i][t]<<"/"<<g[s][t]<<"="<<(double)g[s][i]*g[i][t]/(double)g[s][t]<<endl;
				ans+=(double)g[s][i]*(double)g[i][t]/(double)g[s][t];
			}
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}
