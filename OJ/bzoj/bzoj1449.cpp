#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#define pa pair<int,int>
#define ll long long
#define inf 1000000000
using namespace std;
int n,m,cnt=1,ans,T;
int last[6005],q[6005],d[6005];
int win[5005],lose[5005],C[5005],D[5005],in[6005];
int mark[6005];
struct edge{
	int to,next,v,c;
}e[100005];
void insert(int u,int v,int w,int c){
	e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;e[cnt].v=w;e[cnt].c=c;
	e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;e[cnt].v=0;e[cnt].c=-c;
}
bool spfa(){
	int head=0,tail=1;
	for(int i=0;i<=T;i++)d[i]=inf;
	memset(mark,0,sizeof(mark));
	q[0]=T;d[T]=0;mark[T]=1;
	while(head!=tail){
		int now=q[head];mark[now]=0;head++;
		if(head==6005)head=0;
		for(int i=last[now];i;i=e[i].next)
			if(d[now]+e[i^1].c<d[e[i].to]&&e[i^1].v){
				d[e[i].to]=d[now]+e[i^1].c;
				if(!mark[e[i].to]){
					mark[e[i].to]=1;
					q[tail++]=e[i].to;
					if(tail==6005)tail=0;
				}
			}
	}
	return d[0]!=inf;
}
int dfs(int x,int f){
	mark[x]=1;
	if(x==T)return f;
	int w,used=0;
	for(int i=last[x];i;i=e[i].next)
		if(!mark[e[i].to]&&e[i].v&&d[x]-e[i].c==d[e[i].to]){
			w=dfs(e[i].to,min(e[i].v,f-used));
			e[i].v-=w;e[i^1].v+=w;
			ans+=w*e[i].c;
			used+=w;if(used==f)return f;
		}
	return used;
}
void zkw(){
	while(spfa()){
		mark[T]=1;
		while(mark[T]){
			memset(mark,0,sizeof(mark));
			dfs(0,inf);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m); T=n+m+1;
	for(int i=1;i<=n;i++) scanf("%d%d%d%d",&win[i],&lose[i],&C[i],&D[i]);
   	for(int i=1;i<=m;i++){
		insert(0,i,1,0);
		int u,v; scanf("%d%d",&u,&v);
		insert(i,m+u,1,0);
		insert(i,m+v,1,0);
		in[u]++;in[v]++;
	}
	for(int i=1;i<=n;i++)
		lose[i]+=in[i];
	for(int i=1;i<=n;i++)
		ans+=win[i]*win[i]*C[i]+lose[i]*lose[i]*D[i];
	for(int i=1;i<=n;i++)
 		for(int j=1;j<=in[i];j++){
			insert(m+i,T,1,2*C[i]*win[i]+C[i]+D[i]-2*D[i]*lose[i]);
			lose[i]--;win[i]++;
		}
	zkw();
	printf("%d\n",ans);
	return 0;
}
