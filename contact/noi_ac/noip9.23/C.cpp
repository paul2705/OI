#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define ls(x) (x<<1)
#define rs(x) (ls(x)|1)
#define maxn 500001
using namespace std;
struct Q {
	int l,r,index;
}q[maxn];
bool mycmp(const Q& a,const Q& b) {
	return a.r<b.r;
}
int tag[maxn<<2],ans[maxn];
int n,m,k,T,a[maxn],w[maxn];
vector<int> pos[maxn];
void push_down(int p) {
	tag[ls(p)]+=tag[p];
	tag[rs(p)]+=tag[p];
	tag[p]=0;
}
void modify(int nl,int nr,int l,int r,int p,int v) {
	if(nl<=l&&r<=nr) {
		tag[p]+=v;
		return;
	}
	push_down(p);
	int m=l+r>>1;
	if(nl<=m) modify(nl,nr,l,m,ls(p),v);
	if(m<nr) modify(nl,nr,m+1,r,rs(p),v);
}
int query(int tar,int l,int r,int p) {
	if(l==r) return tag[p];
	push_down(p);
	int m=l+r>>1;
	if(tar<=m) return query(tar,l,m,ls(p));
	else return query(tar,m+1,r,rs(p));
}
int main() {
#ifdef LOCAL
	freopen("color.in","r",stdin);
#endif
	cin>>n>>m>>k>>T;
	for(int i=1;i<=k;i++)
		pos[i].push_back(0);
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		pos[a[i]].push_back(i);
		w[i]=pos[a[i]].size()-1;
	}
	for(int i=1;i<=m;i++) {
		cin>>q[i].l>>q[i].r;
		q[i].index=i;
	}
	sort(q+1,q+1+m,mycmp);
	int rec=1;
	for(int i=1;i<=n;i++) {
		int c=a[i];
		if(w[i]<T) continue;
		if(w[i]==T) modify(1,pos[c][1],1,n,1,1);
		else {
			modify(pos[c][w[i]-T-1]+1,pos[c][w[i]-T],1,n,1,-1);
			modify(pos[c][w[i]-T]+1,pos[c][w[i]-T+1],1,n,1,1);
		}
		while(q[rec].r==i) {
			ans[q[rec].index]=query(q[rec].l,1,n,1);
			rec++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<'\n';
	return 0;
}
