#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#define pii pair<int,int>
#define mp make_pair
#define fir first
#define sec second
using namespace std;
typedef long long ll;
int read(){
	char c=getchar();int num=0;
	for (;!isdigit(c);c=getchar());
	for (;isdigit(c);c=getchar()) num=num*10+c-'0';
	return num;
}
const int N=3e5+5;
const int M=1e6+5;
int n,m;
int L[N],R[N],ans[N];
int head[N],num_edge;
struct Edge{ 
	int v,nxt;
}edge[M];
void add_edge(int u,int v){
	edge[++num_edge].v=v;
	edge[num_edge].nxt=head[u];
	head[u]=num_edge;
}
int deg[N],deg2[N];
priority_queue<pii,vector<pii>,greater<pii> > q1,q2;
int que[N],h,t;
bool topsort(){
	memcpy(deg2,deg,sizeof(deg2));
	for (int i=1;i<=n;++i)
		if(deg2[i]==0) que[++t]=i;
	int x;
	for (h=1;h<=t;++h){
		x=que[h];
		for (int i=head[x],v;i;i=edge[i].nxt){
			v=edge[i].v,--deg2[v];
			if (deg2[v]==0) que[++t]=v;
		}
	}
	if (t<n) return 0;
	for (int i=n;i;--i){
		x=que[i];
		for (int i=head[x];i;i=edge[i].nxt)
			R[x]=min(R[x],R[edge[i].v]-1);
		if (L[x]>R[x]) return 0;
	}
	for (int i=1;i<=n;++i)
		if (!deg[i]) q1.push(mp(L[i],i));
	for (int now=1,x,v;now<=n;++now){
		while (!q1.empty()&&q1.top().fir<=now)
			q2.push(mp(R[q1.top().sec],q1.top().sec)),q1.pop();
		if (q2.empty()) return 0;
		ans[now]=x=q2.top().sec,q2.pop();
		if (R[x]<now) return 0;
		for (int i=head[x];i;i=edge[i].nxt){
			v=edge[i].v,--deg[v];
			if (!deg[v]) q1.push(mp(L[v],v));
		}
	}
	for(int i=1;i<=n;++i) cout<<ans[i]<<'\n';
	return 1;
}
int main(){
	n=read(),m=read();
	for (int i=1;i<=n;++i) L[i]=read(),R[i]=read();
	for (int i=1,a,b;i<=m;++i){
		a=read(),b=read();
		add_edge(a,b);
		++deg[b];
	}
	if (topsort()==0) puts("-1");
	return 0;
}
