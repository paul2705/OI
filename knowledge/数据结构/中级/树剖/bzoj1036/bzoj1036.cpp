#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e4+5;
const int MAXM=MAXN*2;
struct tnode{
	int l,r,cl,cr,s,mx;
} t[MAXN*8];
int n,M,q,rt;
int cnt,l[MAXN],r[MAXN],fa[MAXN],id[MAXN];
int a[MAXN],sz[MAXN],top[MAXN],d[MAXN],dfn[MAXN];
int edge,head[MAXN],tail[MAXM],nex[MAXM];
char op[20];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
int newnode(int l,int r,int cl,int cr,int s,int mx){
	t[++M]=(tnode){l,r,cl,cr,s,mx};
	return M;
}
void update(int id){
	int cl=t[id].cl,cr=t[id].cr;
	t[id].mx=max(t[cl].mx,t[cr].mx);
	t[id].s=t[cl].s+t[cr].s;
}
void dfs1(int u,int p){
	sz[u]=1; d[u]=d[p]+1; fa[u]=p;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
	}
}
void dfs2(int u,int p,int tp){
	int pos=0; dfn[u]=++cnt; id[cnt]=u; top[u]=tp;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		if (pos==0||sz[v]>sz[pos]) pos=v;
	}
	if (pos) dfs2(pos,u,tp);
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		if (v==pos) continue;
		dfs2(v,u,v);
	}
}
int build(int l,int r){
	if (l==r) return newnode(l,r,0,0,a[id[l]],a[id[l]]);
	int mid=(l+r)>>1;
	int cl=build(l,mid),cr=build(mid+1,r);
	return newnode(l,r,cl,cr,t[cl].s+t[cr].s,max(t[cl].mx,t[cr].mx));
}
int qsum(int id,int a,int b){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return 0;
	if (a<=l&&r<=b) return t[id].s;
	return qsum(cl,a,b)+qsum(cr,a,b);
}
int qmax(int id,int a,int b){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return -1e9;
	if (a<=l&&r<=b) return t[id].mx;
	return max(qmax(cl,a,b),qmax(cr,a,b));
}
void modify(int id,int a,int b,int val){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return;
	if (a<=l&&r<=b){
		t[id].s=val;
		t[id].mx=val;
		return;
	}
	modify(cl,a,b,val); modify(cr,a,b,val);
	update(id);
}
int qrysum(int x,int y){
	int ret=0;
//	cout<<__func__<<endl;
	while (top[x]!=top[y]){
//		cout<<x<<" "<<y<<endl;
		if (d[top[x]]<d[top[y]]) swap(x,y);
		ret+=qsum(rt,dfn[top[x]],dfn[x]);
//		ret+=wfa[top[x]];
		x=fa[top[x]];
	}
//	cout<<x<<" "<<y<<endl;
	if (d[x]>d[y]) swap(x,y);
	ret+=qsum(rt,dfn[x],dfn[y]);
	return ret;
}
int qrymax(int x,int y){
	int ret=-1e9;
//	cout<<__func__<<endl;
	while (top[x]!=top[y]){
		if (d[top[x]]<d[top[y]]) swap(x,y);
		ret=max(ret,qmax(rt,dfn[top[x]],dfn[x]));
		x=fa[top[x]];
	}
//	cout<<x<<" "<<y<<endl;
	if (d[x]>d[y]) swap(x,y);
	ret=max(ret,qmax(rt,dfn[x],dfn[y]));
	return ret;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs1(1,0);
	dfs2(1,0,1);
	rt=build(1,cnt);
	scanf("%d",&q);
	while (q--){
		int x,y;
		scanf("%s%d%d",op,&x,&y);
		if (op[1]=='M') printf("%d\n",qrymax(x,y));
		if (op[1]=='S') printf("%d\n",qrysum(x,y));
		if (op[1]=='H') modify(rt,dfn[x],dfn[x],y);
	}
	return 0;
}
