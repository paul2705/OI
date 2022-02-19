#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=4e6+6;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int n,m,ans[MAXN],cnt;
bool use[MAXN];
int pre[MAXN],nxt[MAXN];
int q[MAXN],l=0,r=0;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	for (int i=1;i<=n;i++) pre[i]=i-1,nxt[i]=i+1;
	nxt[0]=1; pre[n+1]=0; nxt[n]=0;
	while (nxt[0]){
		l=r=0;
		q[r++]=nxt[0];
		while (l<r){
			int u=q[l++]; //cout<<u<<" : ";
			for (int e=head[u];e;e=nex[e]){
				int v=tail[e];
				use[v]=1;
			}
			for (int x=nxt[0];x;x=nxt[x]){
				if (!use[x]){
					nxt[pre[x]]=nxt[x];
					pre[nxt[x]]=pre[x];
					q[r++]=x; //cout<<x<<" ";
				}
			}
//			cout<<endl;
			for (int e=head[u];e;e=nex[e]){
				int v=tail[e];
				use[v]=0;
			}
		}
//		cout<<nxt[0]<<endl;
		ans[cnt++]=l-1;
	}
	sort(ans,ans+cnt);
	printf("%d\n",cnt);
	for (int i=0;i<cnt;i++) printf("%d ",ans[i]);
	return 0;
}
