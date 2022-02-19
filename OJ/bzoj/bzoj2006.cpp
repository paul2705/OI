#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=5e5+5;
const int MAXT=2e6+6;
struct tnode{
	int l,r,cl,cr,dat;
} t[MAXT];
int a[MAXN],b[MAXN],root[MAXN],rnk[MAXN],id[MAXN];
int n,m,M,L,R,ans;
struct rec{
	int x,id,rk;
	bool operator < (const rec& b) const {
		return x<b.x;
	}
};
priority_queue<rec> q;
int newnode(int l,int r,int cl,int cr,int dat){
	t[++M]=(tnode){l,r,cl,cr,dat};
	return M;
}
int build(int l,int r,int id,int rk){
	int sz=t[id].dat+1;
	if (l==r) return newnode(l,r,0,0,sz);
	else {
		int mid=(l+r)>>1,cl=t[id].cl,cr=t[id].cr;
		if (rk<=mid) cl=build(l,mid,t[id].cl,rk);
		else cr=build(mid+1,r,t[id].cr,rk);
		return newnode(l,r,cl,cr,sz);
	}
}
int get(int lid,int rid,int rk){
	int l=t[lid].l,r=t[lid].r;
	int lcl=t[lid].cl,lcr=t[lid].cr;
	int rcl=t[rid].cl,rcr=t[rid].cr;
	cout<<l<<" "<<r<<" "<<rk<<endl;
	if (l==r) return l;
	int srk=t[rcl].dat-t[lcl].dat;
	if (rk<=srk) return get(lcl,rcl,rk);
	else return get(lcr,rcr,rk-srk);
}
int main(){
	scanf("%d%d%d%d",&n,&m,&L,&R);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]+=a[i-1],b[i]=a[i];
	sort(b+1,b+n+1);
	int nn=unique(b+1,b+n+1)-b-1;
	for (int i=1;i<=n;i++){
		rnk[i]=lower_bound(b+1,b+nn+1,a[i])-b;
		id[rnk[i]]=a[i];
	}
	for (int i=1;i<=n;i++) root[i]=build(1,n,root[i-1],rnk[i]);
	for (int i=1;i<=n;i++){
		int l=max(i-R,0),r=i-L;
		cout<<l<<" "<<r<<" : ";
		if (r<0) continue;
		int x=get(root[l-1],root[r],1);
		cout<<" : "<<i<<" "<<x<<" "<<id[x]<<" "<<a[i]-id[x]<<endl;
		q.push((rec){a[i]-id[x],i,1});
	}
	while (m--){
		rec res=q.top(); q.pop();
		ans+=res.x;
		int pos=res.id,rak=res.rk+1;
		int l=max(pos-R,0),r=max(pos-L,0);
		int x=get(root[l-1],root[r],rak);
		q.push((rec){a[pos]-id[x],pos,rak});
	}
	printf("%d\n",ans);
	return 0;
}
