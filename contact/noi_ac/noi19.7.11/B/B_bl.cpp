#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const ll inf=1e11;
const int MAXN=1e5+5;
const int MAXD=5e6+5;
const int MAXM=2e7+5;
int edge,head[MAXD],nex[MAXM],tail[MAXM],w[MAXM];
ll d[MAXD];
int n,m,mp[1005][1005];
struct rec{
	int x,y;
} a[MAXN];
deque<int> q;
bool cmp(rec a,rec b){ return a.x==b.x?a.y<b.y:a.x<b.x; }
void add(int u,int v,int W){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
void ins(int u,int v,int W){
	add(u,v,W); add(v,u,W);
}
bool ub(int x,int y){
	return x<1||x>n||y<1||y>n;
}
int Get(int x,int y){ return (x-1)*n+y; }
void build(int pos,int x,int y,int op){
	int dal=op*n*n;
	d[pos+dal]=inf;
	ins(pos+dal,pos+((op+1)%4)*n*n,1);
	if (ub(x,y)||mp[x][y]) return;
	int nu=Get(x,y);
//	cout<<pos<<" "<<x<<" "<<y<<" "<<nu<<endl;
	add(pos+dal,nu+dal,0);
}
void solve1(){
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (mp[i][j]) continue;
			int pos=Get(i,j);
			build(pos,i,j-1,0);
			build(pos,i+1,j,1);
			build(pos,i,j+1,2);
			build(pos,i-1,j,3);
		}
	}
	int S=Get(1,1)+n*n; d[S]=0;
	q.push_back(S);
	while (!q.empty()){
		int u=q.front(); q.pop_front();
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (d[v]<inf) continue;
			if (w[e]==0){
				d[v]=d[u]; q.push_front(v);
			}
			else {
				d[v]=d[u]+w[e]; q.push_back(v);
			}
		}
	}
	ll ans=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			ll mn=inf;
			int pos=Get(i,j);
			for (int k=0;k<4;k++){
//				cout<<i<<" "<<j<<" "<<k<<" "<<d[pos+k*n*n]<<endl;
				mn=min(mn,d[pos+k*n*n]);
			}
//			cout<<i<<" "<<j<<" "<<mn<<endl;
			ans+=mn==inf?0:mn;
		}
	}
	printf("%lld\n",ans);
}
void solve2(){

}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		mp[a[i].x][a[i].y]=1;
	}
	sort(a+1,a+m+1,cmp);
	if (a[1].x==1&&a[1].y==1){
		printf("0\n");
		return 0;
	}
	if (n<=1e3) solve1();
	else solve2();
	return 0;
}
