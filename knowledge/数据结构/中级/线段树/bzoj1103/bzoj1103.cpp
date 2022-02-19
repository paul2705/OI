#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e5+5;
const int MAXM=1e6+6;
int edge,head[MAXN],nex[MAXM],tail[MAXM];
int dfn[MAXN],cnt,id[MAXN];
int out[MAXN],d[MAXN];
int n,m,M,rt;
struct tnode{
	int l,r,cl,cr,dat,tag;
} t[MAXN];
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
int newnode(int l,int r,int cl,int cr,int dat){
	t[++M]=(tnode){l,r,cl,cr,dat,0};
	return M;
}
int build(int l,int r){
	if (l==r) return newnode(l,r,0,0,d[id[l]]);
	int mid=(l+r)>>1;
	int cl=build(l,mid),cr=build(mid+1,r);
	return newnode(l,r,cl,cr,t[cl].dat+t[cr].dat);
}
void pushdown(int id){
	int cl=t[id].cl,cr=t[id].cr;
	int tag=t[id].tag;
	if (!tag) return;
	t[id].dat+=tag;
	t[cl].tag+=tag;
	t[cr].tag+=tag;
	t[id].tag=0;
}
void update(int id){
	int cl=t[id].cl,cr=t[id].cr;
	t[id].dat=t[cl].dat+t[cr].dat;
}
void modify(int a,int b,int id,int val){
	pushdown(id);
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return;
	if (a<=l&&r<=b){
		t[id].tag+=val;
		pushdown(id);
		return;
	}
	modify(a,b,cl,val); modify(a,b,cr,val);
	update(id);
}
int query(int a,int b,int id){
	pushdown(id);
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>a||r<a) return 0;
	if (a<=l&&r<=b) return t[id].dat;
	return query(a,b,cl)+query(a,b,cr);
}
void dfs(int u,int p){
	dfn[u]=++cnt; id[cnt]=u; d[u]=d[p]+1;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u);
	}
	out[u]=cnt;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int u,v; scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	dfs(1,0);
	rt=build(1,n);
	scanf("%d",&m);
	for (int i=1;i<n+m;i++){
		char op=getchar(); while (op!='W'&&op!='A') op=getchar();
		if (op=='W'){
			int u; scanf("%d",&u);
			printf("%d\n",query(dfn[u],dfn[u],rt)-1);
		}
		else {
			int u,v; scanf("%d%d",&u,&v);
			modify(dfn[v],out[v],rt,-1);
		}
	}
	return 0;
}
