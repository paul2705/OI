#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=2e5+5;
const int MAXM=4e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int n,a[MAXN];
bool use[MAXN];
queue<int> q;
int s[MAXN],s1[MAXN],s2[MAXN],cnt,ret;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
int main(){
	scanf("%d",&n);
	for (int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	q.push(1); use[1]=1;
	ret=1;
	while (!q.empty()){
		int u=q.front(); q.pop(); cnt=0;
//		cout<<u<<" "<<ret<<endl;
		for (int e=head[u];e;e=nex[e]){
			int v=tail[e];
			if (!use[v]){
				use[v]=1;
				s1[++cnt]=v;
			}
		}
		for (int i=1;i<=cnt;i++) s[i]=s2[i]=a[++ret];
		sort(s1+1,s1+cnt+1); sort(s2+1,s2+cnt+1);
		for (int i=1;i<=cnt;i++){
//			cout<<s1[i]<<" "<<s2[i]<<endl;
			if (s1[i]!=s2[i]) return printf("No\n"),0;
		}
		for (int i=1;i<=cnt;i++) q.push(s[i]);
//		cout<<endl;
	}
	printf("Yes\n");
	return 0;
}
