#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=2e3+5;
const int MAXM=2e6+5;
int n,m,fa[MAXN];
struct rec{
	int x,y;
} a[MAXM];
int cnt;
int edge,head[MAXN],tail[MAXM],nex[MAXM],w[MAXM];
int rd[MAXN],f[MAXN];
queue<int> q;
void add(int u,int v,int W){
	rd[v]++;
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v,w[edge]=W;
}
int find(int x){ return fa[x]==x?x:fa[x]=find(fa[x]); }
void uion(int x,int y){ fa[find(x)]=find(y); }
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n+m;i++) fa[i]=i;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			char c=getchar(); while (c!='<'&&c!='>'&&c!='=') c=getchar();
			if (c=='=') uion(i,n+j);
			else if (c=='>') a[cnt++]=(rec){n+j,i};
			else a[cnt++]=(rec){i,n+j};
		}
	}
	for (int i=0;i<cnt;i++){
		int u=a[i].x,v=a[i].y;
		if (find(u)==find(v)) return printf("No\n"),0;
		add(find(u),find(v),1);
	}
	for (int i=1;i<=n+m;i++){
		if (rd[i]==0&&i==find(i)){
			f[i]=1;
			q.push(i);
		}
	}
	while (!q.empty()){
		int u=q.front(); q.pop();
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (rd[v]==0) continue;
			rd[v]--;
			f[v]=max(f[v],f[u]+w[e]);
			if (rd[v]==0) q.push(v);
		}
	}
	for (int i=1;i<=n+m;i++){
		if (i==find(i)&&rd[i]>0){
			return printf("No\n"),0;
		}
	}
	printf("Yes\n");
	for (int i=1;i<=n;i++) printf("%d ",f[find(i)]);
	cout<<endl;
	for (int i=n+1;i<=n+m;i++) printf("%d ",f[find(i)]);
	cout<<endl;
	return 0;
}
