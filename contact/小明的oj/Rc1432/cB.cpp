#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
const int MAXN=2e2+5;
double x[MAXN],y[MAXN],mp[MAXN][MAXN],dist[MAXN];
int n;
struct rec{
	double dis;
	int u;
	bool operator > (const rec& b) const {
		return dis>b.dis;
	}
	bool operator < (const rec& b) const {
		return dis<b.dis;
	}
};
priority_queue<rec,vector<rec>,greater<rec> > q;
double sq(double x){ return x*x; }
double dis(int i,int j){
	return sqrt(sq(x[i]-x[j])+sq(y[i]-y[j]));
}
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lf%lf",&x[i],&y[i]);
	for (int i=1;i<=n;i++){
		dist[i]=1e9;
		for (int j=1;j<=n;j++) mp[i][j]=dis(i,j);
	}
	dist[1]=0; q.push((rec){0,1});
	while (!q.empty()){
		rec u=q.top(); q.pop();
		if (u.dis>dist[u.u]) continue;
		for (int i=1;i<=n;i++){
			if (dist[i]>max(dist[u.u],mp[u.u][i])){
				dist[i]=max(dist[u.u],mp[u.u][i]);
				q.push((rec){dist[i],i});
			}
		}
	}
	printf("%.3lf\n",dist[2]);
	fclose(stdin); fclose(stdout);
	return 0;
}
