#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=3e6+6;
const int MAXM=6e6+6;
int n,m,a[MAXN];
int dfn[MAXN],out[MAXN],tim;
struct rec{
	int l,r;
} q[MAXN];
int edge,head[MAXN],tail[MAXM],nex[MAXM];
struct mx{
	int pos,val;
};
struct tnode{
	int l,r,cl,cr;
	mx x;
} t[MAXN*4];
int M,rt;
void add(int u,int v){
	edge++,nex[edge]=head[u],head[u]=edge,tail[edge]=v;
}
void dfs(int u,int p){
	dfn[u]=++tim;
	for (int e=head[u];e;e=nex[e]){
		int v=tail[e];
		if (v==p) continue;
		dfs(v,u);
	}
	out[u]=tim;
}
bool cmp_dfn(int a,int b){ return dfn[a]<dfn[b]; }
bool cmp_r(rec a,rec b){ return a.r==b.r?a.l>b.l:a.r<b.r; }
int newnode(int l,int r,int cl,int cr,mx x){
	t[++M]=(tnode){l,r,cl,cr,x};
	return M;
}
mx merge(mx a,mx b){
	if (a.val>b.val) return a;
	if (a.val<b.val) return b;
	return (mx){max(a.pos,b.pos),a.val};
}
int build(int l,int r){
	if (l==r) return newnode(l,r,0,0,(mx){l,0});
	int mid=(l+r)>>1;
	int cl=build(l,mid),cr=build(mid+1,r);
	return newnode(l,r,cl,cr,merge(t[cl].x,t[cr].x));
}
void update(int id){
	int cl=t[id].cl,cr=t[id].cr;
	t[id].x=merge(t[cl].x,t[cr].x);
}
void modify(int a,int b,int id,int val){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return;
	if (a<=l&&r<=b){
		t[id].x.val=val;
		return;
	}
	modify(a,b,cl,val); modify(a,b,cr,val);
	update(id);
}
mx qry(int a,int b,int id){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return (mx){-1,-1};
	if (a<=l&&r<=b) return t[id].x;
	return merge(qry(a,b,cl),qry(a,b,cr));
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++){
		int p; scanf("%d",&p);
		add(p,i);
	}
	dfs(0,0);
	for (int i=1;i<=n;i++) a[i]=i-1;
	sort(a+1,a+n+1,cmp_dfn);
//	for (int i=0;i<n;i++) printf("%d %d\n",i,dfn[i]);
//	for (int i=1;i<=n;i++) cout<<i<<" "<<a[i]<<endl;
	rt=build(1,n);
	for (int i=1;i<=m;i++){
		int x; scanf("%d",&x);
		q[i]=(rec){dfn[x],out[x]};
//		cout<<x<<" "<<dfn[x]<<" "<<out[x]<<endl;
	}
	sort(q+1,q+m+1,cmp_r);
	int r=1; ll ans=0;
	for (int i=1;i<=m;i++){
		while (r<=q[i].r){
			modify(r,r,rt,a[r]);
//			cout<<"mof: "<<r<<" "<<a[r]<<endl;
			r++;
		}
		mx x=qry(q[i].l,q[i].r,rt);
		if (x.pos==-1) continue;
		modify(x.pos,x.pos,rt,0);
//		cout<<"mof: "<<x.pos<<" "<<0<<endl;
//		cout<<x.pos<<" "<<x.val<<endl;
		ans+=x.val;
	}
	printf("%lld\n",ans);
	return 0;
}
