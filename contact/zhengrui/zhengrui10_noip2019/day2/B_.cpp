#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int,int> par;
const int MAXN=2e5+5;
int n,tot;
int a[MAXN][2],fa[MAXN][2],d[MAXN][2];
queue<par> q;
bool vis[MAXN][2];
int find(int x,int p){
	if (fa[x][p]==x) return x;
	int f=find(fa[x][p],p);
	d[x][p]+=d[fa[x][p]][p];
	fa[x][p]=f; 
	return f;
}
bool check(int k){
	memset(vis,0,sizeof(vis));
	memset(d,0,sizeof(d));
	for (int i=1;i<=n;i++){
		fa[i][0]=fa[i][1]=i;
	}
	while (!q.empty()) q.pop();
	q.push(make_pair(1,0)), q.push(make_pair(1,1));
	vis[1][0]=vis[1][1]=1;
	while (!q.empty()){
		int x=q.front().first,p=q.front().second;
		if (x==n) return 1;
		q.pop(); x=a[x][p];
		for (int v=x;;){
			x=find(x,p); find(v,p);
			if (vis[x][p^1]||d[v][p]>=k) break;
			vis[x][p^1]=1,q.push(make_pair(x,p^1));
			if (find(a[x][p],p)==x) break;
			fa[x][p]=a[x][p],d[x][p]++;
		}
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	if (n==1) return printf("0\n"),0;
	for (int i=1;i<=n;i++){
		scanf("%d%d",&a[i][0],&a[i][1]);
	}
	int l=0,r=n+1;
	while (l+1<r){
		int mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid;
	}
	printf("%d\n",r==n+1?-1:r);
	return 0;
}
