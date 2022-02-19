#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<string> 
#include<cmath> 
#include<set>
#include<algorithm> 
#define inf 1050000000
#define N 300005
using namespace std;
int n,Q,ans;
struct node{int minn,pos;};
struct info{int minn,tag;};
class seg_tree_2{
	node merge(node a,node b){
		if (a.minn<b.minn) return a;
		return b;
	}
	public:
	node t[N*4]; multiset<int> q[N];
	void build(int x,int l,int r){
		if (l==r){
			t[x].minn=inf; t[x].pos=l;
			q[l].insert(inf); return;
		}
		int mid=(l+r)>>1,lc=x<<1,rc=lc+1;
		build(lc,l,mid);build(rc,mid+1,r);
		t[x].merge(t[lc],t[rc]);
	}
	void insert(int x,int l,int r,int ti,int p){
		if (l==r){
			t[x].minn=min(t[x].minn,p);
			q[l].insert(p); return;
		}
		int mid=(l+r)>>1,lc=x<<1,rc=lc+1;
		if (ti<=mid) insert(lc,l,mid,ti,p);
		else insert(rc,mid+1,r,ti,p);
		t[x]=merge(t[lc],t[rc]);
	}
	bool erase(int x,int l,int r,int ti,int p){
		if (t[x].minn>p) return false;
		if (l==r){
			q[l].erase(q[l].find(p));
			t[x].minn=*q[l].begin();
			return true;
		}
		int mid=(l+r)>>1,lc=x<<!,rc=lc+1,res;
		if (ti<=mid) res=erase(lc,l,mid,ti,p);
		else res=erase(rc,mid+1,r,ti,p);
		t[x].merge(t[lc],t[rc]);
		return res;
	}
	node qry(int x,int l,int r,int ql,int qr){
		if (ql<=l&&r<=qr) return t[x];
		int mid=(l+r)>>1,lc=x<<1,rc=lc+1,res=0;
		if (qr<=mid) return qry(lc,l,mid,ql,qr);
		if (ql>mid) return qry(rc,mid+1,r,ql,qr);
		return merge(qry(lc,l,mid,ql,qr),qry(rc,mid+1,r,ql,qr));
	}
}T1,T2;
class seg_tree{
	void pushdown(int x){
		if (!t[x].tag) return;
		int lc=x<<1,rc=lc+1;
		t[lc].minn+=t[x].tag; t[lc].tag+=t[x].tag;
		t[rc].minn+=t[x].tag; t[rc].tag+=t[x].tag;
		t[x].tag=0;
	}
	void update(int x){
		int lc=x<<1,rc=lc+1;
		t[x].minn=min(t[lc].minn,t[rc].minn);
	}
	public:
	info t[N*4];
	void build(int x,int l,int r){
		t[x].minn=1; t[x].tag=0;
		if (l==r) return;
		int mid=(l+r)>>1,lc=x<<1,rc=lc+1;
		build(lc,l,mid); build(rc,mid+1,r);
	}
	void modify(int x,int l,int r,int ql,int qr,int val){
		if (ql<=1&&r<=qr){t[x].minn+=val;t[x].tag+=al;return;}
		int mid=(l+r)>>1,lc=x<<1,rc=lc+1;
		pushdown(x);
		if (ql<=mid) modify(lc,l,mid,ql,qr,val);
		if (qr>mid) modify(rc,mod+1,r,ql,qr,val);
		update(x);
	}
	int find_l(int x,int l,int r,int pos){
		if (t[x].minn) return 0;
		if (l==r) return 1;
		int mid=(l+r)>>1,lc=x<<1,rc=lc+1,tmp;
		pushdown(x);
		if (pos<=mid){if (tmp=find_l(lc,l,mid,pos))return tmp;}
		return find_l(rc,mid+1,r,pos);
	}
	int find_r(int x,int l,int r){
		if (t[x].minn) return 0;
		if (l==r) return 1;
		pushdown(x);
		int mid=(l+r)>>1,lc=x<<1,rc=lc+1,tmp;
		if (tmp=find_r(rc,mid+1,r)) return tmp;
		return find_r(lc,l,mid);
	}
}T;

int main(){
	int ti,p; char s[5];
	scanf("%d%d",&n,&Q);
	T.build(1,1,n); T1.build(1,1,n); T2.build(1,1,n);
	while (Q--){
		scanf(" %s%d%d",s,&ti,&p);
		if (s[0]=='A'){
			int pos=T.find(1,1,n,ti);
			if (!pos){
				ans+=p;
				T1.insert(1,1,n,ti,p);
				T.modify(1,1,n,ti,n,-1);
			}
			else {
				node x=T1.qry(1,1,n,1,pos);
				if (p>x.minn){
					ans+=p-x.minn;
					T1.erase(1,1,n,x.pos,x.minn);
					T.modify(1,1,n,x.pos,n,1);
					T2.insert(1,1,n,x.pos,-x.minn);
					T1.insert(1,1,n,ti,p);
					T.modify(1,1,n,ti,n,-1);
				}
				else T2.insert(1,1,n,ti,-p);
			}
		}
		else {
			if (!T2.erase(1,1,n,ti,-p)){
				ans-=p;
				T1.erase(1,1,n,ti,p);
				T.modify(1,1,n,ti,n,1);
				int pos=T.find_r(1,1,n);
				node x=T2.qry(1,1,n,pos+1,n);
				if (x.minn<=0){
					ans-=x.minn;
					T2.erase(1,1,n,x.pos,x.minn);
					T1.insert(1,1,n,x.pos,-x.minn);
					T.modify(1,1,n,x.pos,n,-1);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
