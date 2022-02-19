#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=2e5+5;
vector<int> g[MAXN];
int n,m,M=1,root;
struct tnode{
	int l,r,cl,cr,dat,tag;
} t[MAXN*8];
struct rec{
	int l,r,id;
} q[MAXN];
int ans[MAXN];
int cmp(int a,int b){ return a>b; }
int newnode(int l,int r,int cl,int cr,int dat){
	t[++M]=(tnode){l,r,cl,cr,dat,0};
	return M;
}
int build(int l,int r){
	if (l==r) return newnode(l,r,0,0,0);
	int mid=(l+r)>>1;
	int cl=build(l,mid),cr=build(mid+1,r);
	return newnode(l,r,cl,cr,0);
}
void pushdown(int id){
	int cl=t[id].cl,cr=t[id].cr;
	int tag=t[id].tag;
	if (tag==0) return;
	t[id].dat+=tag;
	t[cl].tag+=tag;
	t[cr].tag+=tag;
	t[id].tag=0;
}
void modify(int a,int b,int id,int val){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return;
	if (a<=l&&r<=b){
		t[id].tag+=val;
		pushdown(id);
		return;
	}
	pushdown(id);
	modify(a,b,cl,val); modify(a,b,cr,val);
//	update(id); pushdown(id);
}
int query(int a,int b,int id){
	pushdown(id);
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return 0;
	if (a<=l&&r<=b) return t[id].dat;
	return max(query(a,b,cl),query(a,b,cr));
}
bool cmpq(rec a,rec b){ return a.r==b.r?a.l<b.l:a.r<b.r; }
int main(){
	freopen("icekingdom.in","r",stdin);
	freopen("icekingdom.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1,u,v;i<n;i++){
		scanf("%d%d",&u,&v);
		if (u>=v) g[u].push_back(v); 
		if (v>=u) g[v].push_back(u);
	}
	for (int i=1;i<=n;i++) sort(g[i].begin(),g[i].end(),cmp);
	for (int i=1;i<=m;i++) scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
	sort(q+1,q+m+1,cmpq);
 	int l=1,r=1,las=1;
	root=build(1,n);
	for (int i=1;i<=m&&r<=m;i++){
		if (r>m) break;
		while (r<=m&&q[r+1].r==q[l].r) r++;
		if (r>m) r=m;
		for (int j=las;j<=q[r].r;j++){
			modify(1,j,root,1);
			for (int k=0;k<g[j].size();k++){
				int v=g[j][k];
				modify(1,v,root,-1);
			}
		}
		las=q[r].r+1;
		for (int j=l;j<=r;j++){
			ans[q[j].id]=query(q[j].l,q[j].l,root);
		}
		l=r+1; r=r+1;
	}
	for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
	fclose(stdin); fclose(stdout);
	return 0;
}
