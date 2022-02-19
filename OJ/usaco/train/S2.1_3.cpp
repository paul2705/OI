/*
ID: paul1202
LANG: C++
TASK: sort3
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
const int MAXM=MAXN*MAXN;
int a[MAXN],n,cnt;
int b[MAXN];
bool use[MAXM],f;
int edge,head[MAXN],nex[MAXM],tail[MAXM];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs(int u,int fe,int to,int s){
	if (f) return;
	use[fe]=1;
//	cout<<__func__<<u<<endl;
	if (u==to){
		f=1;
		return;
	}
	for (int e=head[u];e;e=nex[e]){
		if (use[e]) continue;
		int v=tail[e];
		if (s&(1<<v)) continue;
		dfs(v,e,to,s|(1<<v));
	}
}
int main(){
	freopen("sort3.in","r",stdin);
//	freopen("sort3.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	for (int i=1;i<=n;i++){
		if (a[i]==b[i]){
			cnt++;
			continue;
		}
		add(b[i],a[i]);
	}
	for (int i=1;i<=3;i++){
		for (int e=head[i];e;e=nex[e]){
			if (use[e]) continue;
			f=0;
//			cout<<"in"<<i<<endl;
			int v=tail[e];
			dfs(v,e,i,1<<v);
			cnt++;
		}
	}
	printf("%d\n",n-cnt);
	fclose(stdin); fclose(stdout);
	return 0;
}
