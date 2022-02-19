#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e6+6;
const int MAXK=65;
int edge,head[MAXK],nex[MAXN],w[MAXN];
int a[MAXN],cnt;
int n,m;
ll ans=2e10;
void add(int u,int W){
	edge++,nex[edge]=head[u],head[u]=edge,w[edge]=W;
}
bool calc(int x){
	ll mx=0;
	for (int i=1;i<=m;i++){
		while (w[head[i]]>x){
			if (!nex[head[i]]) return 0;
			head[i]=nex[head[i]];
		}
		if (w[head[i]]<=x) mx=max(mx,(ll)x-w[head[i]]);
	}
	ans=min(ans,mx);
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int x; scanf("%d",&x);
		for (int j=1;j<=x;j++){
			int pos; scanf("%d",&pos);
			add(i,pos); a[++cnt]=pos;
		}
	}
	sort(a+1,a+cnt+1);
	for (int i=cnt;i>=1;i--){
		if (a[i]!=a[i-1]){
			if (!calc(a[i])) break;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
