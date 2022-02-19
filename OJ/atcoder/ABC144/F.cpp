#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
const int MAXM=6e5+6;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int n,m;
double ans=1e15,dp[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v);
	}
	for (int i=0;i<n;i++){
		dp[n]=0;
		for (int j=n-1;j>=1;j--){
			double num=0,sum=0,mx=0;
			for (int e=head[j];e;e=nex[e]){
				int v=tail[e];
				sum+=dp[v];
				mx=max(mx,dp[v]);
				num++;
			}
			if (j==i&&num>1){
				num--; sum-=mx;
			}
			dp[j]=sum/num+1;
		}
		ans=min(ans,dp[1]);
	}
	printf("%.6lf\n",ans);
	return 0;
}
