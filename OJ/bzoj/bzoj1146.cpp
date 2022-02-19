#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=2e5+5;
int edge,head[MAXN],tail[MAXM],nex[MAXM];
int n,m,a[MAXN];
struct rec{
	int k,a,b,op,id;
} q[MAXM],p1[MAXM],p2[MAXM];
int cnt=0,fa[MAXN],d[MAXN],dfn[MAXN],dtim;
int sz[MAXN],top[MAXN],cnta=0;
int t[MAXN],ans[MAXM];
void add(int x,int val){
	for (;x<=n;x+=x&-x) t[x]+=val;
}
int sum(int x){
	int ret=0;
	for (;x>0;x-=x&-x) ret+=t[x];
	return ret;
}
void add_e(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs1(int u,int p){
	sz[u]=1; fa[u]=p; d[u]=d[p]+1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
	}
}
void dfs2(int u,int p,int tp){
	int ws=0; top[u]=tp; dfn[u]=++dtim;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		if (sz[ws]<sz[v]) ws=v;
	}
	if (ws) dfs2(ws,u,tp);
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p||v==ws) continue;
		dfs2(v,u,v);
	}
}
int lca(int u,int v){
	while (top[u]!=top[v]){
		if (d[top[u]]>d[top[v]]) u=fa[top[u]];
		if (d[top[v]]>d[top[u]]) v=fa[top[v]];
	}
	return d[u]>d[v]?v:u;
}
int get(int u,int v){
	int ret=0;
	while (top[u]!=top[v]){
		if (d[top[u]]<d[top[v]]) swap(u,v);
		ret+=sum(dfn[u])-sum(dfn[top[u]]-1);
		u=fa[top[u]];
	}
	if (d[u]<d[v]) swap(u,v);
	ret+=sum(dfn[u])-sum(dfn[v]-1);
	return ret;
}
void divd(int ql,int qr,int al,int ar){
	int mid=(al+ar)>>1;
	if (ql>qr) return;
	if (al==ar){
		for (int i=ql;i<=qr;i++){
			if (q[i].k>0&&ans[q[i].id]!=-1) ans[q[i].id]=al;
		}
		return;
	}
//	cout<<__func__<<" "<<ql<<" "<<qr<<" "<<al<<" "<<ar<<endl;
	int t1=0,t2=0;
	for (int i=ql;i<=qr;i++){
		if (q[i].k==0){
			if (q[i].b<=mid) p1[++t1]=q[i];
			else p2[++t2]=q[i],add(dfn[q[i].a],q[i].op);
		}
		else {
			int ss=get(q[i].a,q[i].b);
			if (ss>=q[i].k) p2[++t2]=q[i];
			else q[i].k-=ss,p1[++t1]=q[i];
		}
	}
	for (int i=ql;i<=qr;i++){
		if (q[i].k==0&&q[i].b>mid) add(dfn[q[i].a],-q[i].op);
	}
	for (int i=1;i<=t1;i++) q[ql+i-1]=p1[i];
	for (int i=1;i<=t2;i++) q[ql+t1+i-1]=p2[i];
	divd(ql,ql+t1-1,al,mid); divd(ql+t1,qr,mid+1,ar);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		q[++cnt]=(rec){0,i,a[i],1};
	}
	for (int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		add_e(u,v); add_e(v,u);
	}
	dfs1(1,0); dfs2(1,0,1);
	for (int i=1;i<=m;i++){
		int op,x,y;scanf("%d%d%d",&op,&x,&y);
		if (op==0){
			q[++cnt]=(rec){0,x,a[x],-1,1};
			q[++cnt]=(rec){0,x,a[x]=y,1,1};
		}
		else {
			q[++cnt]=(rec){op,x,y,1,++cnta};
			int fxy=lca(x,y);
			int sz=d[x]+d[y]-d[fxy]*2+1;
			if (sz<op) ans[cnta]=-1;
//			cout<<sz<<" "<<op<<endl;
		}
	}
	divd(1,cnt,1,1e8);
	for (int i=1;i<=cnta;i++){
		if (ans[i]==-1) printf("invalid request!\n");
		else printf("%d\n",ans[i]);
	}
	return 0;
}
