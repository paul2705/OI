#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e3+5;
const int MAXM=1e4+5;
int edge,head[MAXN],nex[MAXM],tail[MAXM];
int n,m;
char ans[MAXN];
bool flag=0,use[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs(int u){
	use[u]=1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (!use[v]) dfs(v);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1,u,v;i<=m;i++){
		char a,b;
		scanf("%d %c %d %c",&u,&a,&v,&b);
//		cout<<a<<" "<<b<<endl;
		if (a=='Y'&&b=='Y') add(u+n,v),add(v+n,u);
		if (a=='Y'&&b=='N') add(u+n,v+n),add(v,u);
		if (a=='N'&&b=='Y') add(u,v),add(v+n,u+n);
		if (a=='N'&&b=='N') add(u,v+n),add(v,u+n);
	}
	for (int i=1;i<=n;i++){
		for (int i=1;i<=2*n;i++) use[i]=0;
		dfs(i); bool f=use[i+n];
		for (int i=1;i<=2*n;i++) use[i]=0;
		dfs(i+n); bool ff=use[i];
		if (f&&ff) flag=1;
		else if (f) ans[i]='N';
		else if (ff) ans[i]='Y';
		else ans[i]='?';
	}
	if (flag) return printf("IMPOSSIBLE\n"),0;
	for (int i=1;i<=n;i++) printf("%c",ans[i]);
	return 0;
}
