#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=2e3+5;
const int MAXM=MAXN*MAXN;
int edge,head[MAXN],nex[MAXM],tail[MAXM];
int d[MAXN];
int n,rd[MAXN];
struct rec{
	int l,r;
} a[MAXN];
queue<int> q;
void add(int u,int v){
//	cout<<u<<" "<<v<<endl;
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
	rd[v]++;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d",&a[i].l,&a[i].r);
	for (int i=1;i<=n;i++){
		if (a[i].l>a[i].r) continue;
		for (int j=1;j<=n;j++){
			if (i==j) continue;
			if (a[j].l>a[j].r) continue;
			if (a[i].l<=a[j].l&&a[j].r<=a[i].r) add(i,j);
		}
	}
	for (int i=1;i<=n;i++){
		d[i]=-1;
//		cout<<rd[i]<<" ";
		if (rd[i]==0) q.push(i),d[i]=1;
	}
//	cout<<endl;
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			d[v]=max(d[v],d[u]+1);
			rd[v]--;
			if (rd[v]==0) q.push(v);
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++) ans=max(ans,d[i]);
	printf("%d\n",ans);
	return 0;
}
