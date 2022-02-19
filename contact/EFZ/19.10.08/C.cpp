#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN=5e5+5;
const int MAXT=MAXN*4;
int n,T;
ll a[MAXN];
int st[MAXN],top;
struct rec{
	int a,b;
};
vector<rec> lis[MAXN],ask[MAXN];
struct tnode{
	int l,r,cl,cr;
	ll dat,mx,tag;
} t[MAXT];
int M,rt;
ll ans[MAXN];
int newnode(int l,int r,int cl,int cr,ll dat,ll mx){
	t[++M]=(tnode){l,r,cl,cr,dat,mx,0};
	return M;
}
void update(int id){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	t[id].mx=max(t[cl].mx,t[cr].mx);
}
void pushdown(int id){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	ll tag=t[id].tag;
	if (tag==0) return;
	t[cl].tag=max(t[cl].tag,tag);
	t[cr].tag=max(t[cr].tag,tag);
	t[id].mx=max(t[id].mx,t[id].dat+tag);
	t[id].tag=0;
}
int build(int l,int r){
	int mid=(l+r)>>1;
	if (l==r) return newnode(l,r,0,0,a[l],a[l]);
	int cl=build(l,mid),cr=build(mid+1,r);
	ll mx=max(t[cl].mx,t[cr].mx);
	return newnode(l,r,cl,cr,mx,mx);
}
void modify(int a,int b,int id,ll val){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	pushdown(id);
	if (r<a||l>b) return;
	if (a<=l&&r<=b){
		t[id].tag=max(t[id].tag,val);
		pushdown(id);
		return;
	}
	modify(a,b,cl,val); modify(a,b,cr,val);
	update(id);
}
ll query(int a,int b,int id){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	pushdown(id);
	if (r<a||l>b) return 0;
	if (a<=l&&r<=b) return t[id].mx;
	return max(query(a,b,cl),query(a,b,cr));
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	rt=build(1,n);
	st[++top]=1;
	for (int i=2;i<=n;i++){
		while (top&&a[st[top]]<=a[i]){
			lis[st[top]].push_back((rec){st[top],i});
			top--;
		}
		lis[st[top]].push_back((rec){st[top],i});
		st[++top]=i;
	}
	scanf("%d",&T);
	for (int i=1;i<=T;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		ask[l].push_back((rec){r,i});
	}
	for (int i=n;i>=1;i--){
		for (int j=0;j<lis[i].size();j++){
			int A=i,B=lis[i][j].b;
			int C=2*B-A; 
			ll val=a[A]+a[B];
			if (C<=n) modify(C,n,rt,val);
		}
		for (int j=0;j<ask[i].size();j++){
			int l=i,r=ask[i][j].a,id=ask[i][j].b;
			ans[id]=query(l,r,rt);
		}
	}
	for (int i=1;i<=T;i++) printf("%lld\n",ans[i]);
	return 0;
}
