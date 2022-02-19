#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int MAXM=2e5+5;
int edge=1,head[MAXN],tail[MAXM],nex[MAXM];
int dfn[MAXN],root,n,m,M,cnt,go[MAXN];
struct tnode{
	int l,r,cl,cr,mx,tag;
} t[MAXN*20];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
int newnode(int l,int r,int cl,int cr,int mx){
	M++;
	t[M]=(tnode){l,r,cl,cr,mx,0};
	return M;
}
int ini(int l,int r){
	if (l==r) return newnode(l,r,0,0,1);
	int mid=(l+r)>>1;
	int cl=ini(l,mid),cr=ini(mid+1,r);
	return newnode(l,r,cl,cr,1);
}
void dfs(int u,int p){
	dfn[u]=++cnt; go[u]=dfn[u];
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u);
		go[u]=max(go[u],go[v]);
	}
}
void pushup(int id){
	int cl=t[id].cl,cr=t[id].cr;
	t[id].mx=max(t[cl].mx,t[cr].mx);
}
void pushdown(int id){
	int cl=t[id].cl,cr=t[id].cr;
	t[cl].tag=max(t[cl].tag,t[id].tag);
	t[cr].tag=max(t[cr].tag,t[id].tag);
	t[id].mx=max(t[id].mx,t[id].tag);
	t[id].tag=0;
}
void modify(int a,int b,int id,int val){
	int l=t[id].l,r=t[id].r;
	if (l>b||r<a) return;
	if (a<=l&&r<=b){
		t[id].tag=max(t[id].tag,val);
		return;
	}
	pushdown(id);
	modify(a,b,t[id].cl,val);
	modify(a,b,t[id].cr,val);
	pushup(id);
}
int query(int a,int b,int id){
	pushdown(id);
	int l=t[id].l,r=t[id].r;
	if (l>a||r<b) return 1;
	if (a<=l&&r<=b) return t[id].mx;
	int cl=query(a,b,t[id].cl),cr=query(a,b,t[id].cr);
	return max(cl,cr);
}
int main(){
	scanf("%d%d",&n,&m);
	int root=ini(1,n);
	for (int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	dfs(1,0);
	for (int i=0,x;i<m;i++){
		char op=getchar(); while (op!='C'&&op!='Q') op=getchar();
		scanf("%d",&x);
		if (op=='C') modify(dfn[x],go[x],root,x);
		if (op=='Q') printf("%d\n",query(dfn[x],dfn[x],root));
	}
	return 0;
}
