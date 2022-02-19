#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=155;
const int MAXV=505;
const int MAXM=MAXN*MAXN*2;
int edge,head[MAXN],nex[MAXM],tail[MAXM],w[MAXM],l[MAXM];
double dis[MAXN][MAXV];
int n,m,d;
bool use[MAXN][MAXV];
void add(int u,int v,int W,int L){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W,l[edge]=L;
}
struct loc{
	int x,s;
};
int pr[MAXN][MAXV],ps[MAXN][MAXV];
void dij(){
	memset(use,0,sizeof(use));
	memset(dis,66,sizeof dis ); queue<loc> q;
	q.push((loc){1,70}); dis[1][70]=0; use[1][70]=1;
	while (!q.empty()){
		loc u=q.front(); q.pop(); use[u.x][u.s]=0;
//		cout<<u.x<<" "<<u.s<<endl;
		for (int e=head[u.x];e;e=nex[e]){
			int v=tail[e];
//			cout<<v<<endl;
			if (w[e]==0){
				if (1.0*l[e]/u.s+dis[u.x][u.s]<dis[v][u.s]){
					dis[v][u.s]=1.0*l[e]/u.s+dis[u.x][u.s];
					pr[v][u.s]=u.x; ps[v][u.s]=u.s;
					if (!use[v][u.s]) q.push((loc){v,u.s}),use[v][u.s]=1;
				}
			}
			else {
				int mv=w[e];
				cout<<1.0*l[e]/mv+dis[u.x][u.s]<<" ";
				cout<<dis[v][mv]<<endl;
		                if (1.0*l[e]/mv+dis[u.x][u.s]<dis[v][mv]){
					cout<<"in "<<v<<endl;
             	     			dis[v][mv]=1.0*l[e]/mv+dis[u.x][u.s];
                    			pr[v][mv]=u.x; ps[v][mv]=u.s;
                    			if (!use[v][mv]) q.push((loc){v,mv}),use[v][mv]=1;
                		}
			}
		}
//		cout<<"done"<<endl;
	}
}
void print(int a,int b){
	if (a!=1) print(pr[a][b],ps[a][b]);
	printf("%d ",a-1);
}
int main(){
	scanf("%d%d%d",&n,&m,&d); d++;
	for (int i=1,u,v,w,l;i<=m;i++){
		scanf("%d%d%d%d",&u,&v,&w,&l); u++,v++;
		add(u,v,l,w);
	}
	dij();
//	cout<<"fuck"<<endl;
	double mn=1e18; int ans=0;
	for (int i=1;i<=500;i++){
		if (mn>dis[d][i]) mn=dis[d][i],ans=i;
	}
//	cout<<"fuck"<<endl;
	print(pr[d][ans],ps[d][ans]);
	printf("%d\n",d-1);
}
