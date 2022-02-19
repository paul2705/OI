#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=6e5+5;
const int MAXM=9e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
queue<int> q;
int a[MAXN],b[MAXN],c[MAXN];
int n,dist[MAXN],use[MAXN];
int res[MAXN*5],cnt,id[MAXN*5];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
int main(){
	freopen("anomalies.in","r",stdin);
	freopen("anomalies.out","w",stdout);
	int mx=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		res[++cnt]=a[i]; res[++cnt]=b[i]; res[++cnt]=c[i];
	}
	sort(res+1,res+cnt+1);
	int nn=unique(res+1,res+cnt+1)-res;
	for (int i=1;i<=n;i++){
		int ia=lower_bound(res+1,res+nn+1,a[i])-res-1;
		int ib=lower_bound(res+1,res+nn+1,b[i])-res-1;
		int ic=lower_bound(res+1,res+nn+1,c[i])-res-1;
		id[ia]=a[i]; id[ib]=b[i]; id[ic]=c[i];
//		cout<<ia<<" "<<ib<<" "<<ic<<endl;
		add(ia,ib); add(ib,ia); add(ia,ic); add(ic,ia);
		add(ib,ic); add(ic,ib);
		use[ia]=use[ib]=use[ic]=1;
		mx=max(mx,max(ia,max(ib,ic)));
	}
	memset(dist,-1,sizeof(dist));
	queue<int> q; q.push(0); dist[0]=0;
	while (!q.empty()){
		int u=q.front(); q.pop();
		use[u]=1;
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (dist[v]>=0) continue;
			dist[v]=dist[u]+1;
			q.push(v);
		}
	}
	for (int i=0;i<=mx;i++){
		if (use[i]) printf("%d %d\n",id[i],dist[i]);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
