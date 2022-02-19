#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010];
int cnt=0,hed[100010],to[200010],nxt[200010];
int sum[100010],lca[100010],a1[100010],a2[100010];
int ans1[100010],ans2[100010],ans3[100010];
int dep[100010],fa[100010],top[100010],size[100010],seg[100010],son[100010];
int ss[400010],tot=0;
bool used[100010],lz[400010];

inline void file() {
	freopen("color.in","r",stdin);freopen("color.out","w",stdout);
}
inline void Swap(int &x,int &y) { int t=x;x=y,y=t; }
inline void add(int x,int y) { to[++cnt]=y,nxt[cnt]=hed[x],hed[x]=cnt; }
void dfs1(int u) {
	size[u]=1;
	for(int i=hed[u];i;i=nxt[i])
		if(!dep[to[i]]) {
			dep[to[i]]=dep[u]+1,fa[to[i]]=u,dfs1(to[i]),size[u]+=size[to[i]];
			if(size[to[i]]>size[son[u]])	son[u]=to[i];
		}
}
void dfs2(int u) {
	if(son[u])	top[son[u]]=top[u],seg[son[u]]=++seg[0],dfs2(son[u]);
	for(int i=hed[u];i;i=nxt[i])
		if(!top[to[i]])	top[to[i]]=to[i],seg[to[i]]=++seg[0],dfs2(to[i]);
}
inline int LCA(int x,int y) {
	while(top[x]!=top[y]) { if(dep[top[x]]<dep[top[y]])	Swap(x,y); x=fa[top[x]]; }
	return dep[x]<dep[y]?	x:y;
}
inline void pushdown(int u,int x,int y) {
	if(lz[u])	lz[u*2]=lz[u*2+1]=1,ss[u*2]=x,ss[u*2+1]=y,lz[u]=0;
}
int query(int u,int l,int r,int L,int R) {
	if(l==L&&r==R)	return ss[u];
	int mid=(l+r)>>1; pushdown(u,mid-l+1,r-mid);
	if(R<=mid)	return query(u*2,l,mid,L,R); if(L>mid)	return query(u*2+1,mid+1,r,L,R);
	return query(u*2,l,mid,L,mid)+query(u*2+1,mid+1,r,mid+1,R);
}
int Ask(int x,int y) {
	int tsum=0;
	while(top[x]!=top[y]) {
		if(dep[top[x]]<dep[top[y]])	Swap(x,y);
		tsum+=query(1,1,n,seg[top[x]],seg[x]),x=fa[top[x]];
	}
	if(dep[x]>dep[y])	Swap(x,y); tsum+=query(1,1,n,seg[x],seg[y]);return tsum;
}
void modify(int u,int l,int r,int L,int R) {
	if(l==L&&r==R) { ss[u]=r-l+1,lz[u]=1;return ; }
	int mid=(l+r)>>1; pushdown(u,mid-l+1,r-mid);
	if(R<=mid)	modify(u*2,l,mid,L,R); else if(L>mid)	modify(u*2+1,mid+1,r,L,R);
	else	modify(u*2,l,mid,L,mid),modify(u*2+1,mid+1,r,mid+1,R);
	ss[u]=ss[u*2]+ss[u*2+1];
}
void Change(int x,int y) {
	while(top[x]!=top[y]) {
		if(dep[top[x]]<dep[top[y]])	Swap(x,y);
		modify(1,1,n,seg[top[x]],seg[x]),x=fa[top[x]];
	}
	if(dep[x]>dep[y])	Swap(x,y); modify(1,1,n,seg[x],seg[y]);
}
int main() {
	file();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)	scanf("%d",&a[i]);
	for(int i=1,x,y;i<n;i++)	scanf("%d%d",&x,&y),add(x,y),add(y,x);
	dep[1]=1,dfs1(1),top[1]=1,seg[1]=++seg[0],dfs2(1);
	for(int i=1;i<=n;i++) {
		++sum[a[i]]; if(!lca[a[i]])	lca[a[i]]=i,a1[a[i]]=i;
		else	lca[a[i]]=LCA(lca[a[i]],i),a1[a[i]]=dep[i]>dep[a1[a[i]]]?	i:a1[a[i]];
	}
	for(int i=1;i<=n;i++)	if(LCA(i,a1[a[i]])==lca[a[i]]&&dep[i]>dep[a2[a[i]]])	a2[a[i]]=i;
	for(int h=1;h<=m;h++) {
		int u=-1;
		for(int i=1;i<=m;i++) {
			if(!used[i]&&a1[i]&&
			dep[a1[i]]+dep[a2[i]]-2*dep[lca[i]]+1==sum[i]+Ask(a1[i],a2[i])) { u=i;break; }
		}
		if(u==-1)	for(int i=1;i<=m;i++)	if(!used[i]&&!a1[i]) { u=i;break; }
		used[u]=1;
		if(!lca[u]) { ans1[h]=u,ans2[h]=1,ans3[h]=1;continue; }
		ans1[h]=u,ans2[h]=a1[u],ans3[h]=a2[u],Change(a1[u],a2[u]);
	}
	for(int i=m;i>=1;i--)	printf("%d %d %d\n",ans1[i],ans2[i],ans3[i]);
	return 0;
}
