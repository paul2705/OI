#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=4e4+5;
const int MAXT=1e6+5;
int a[MAXN],n,M,root,ans;
struct tnode{
	int l,r,cl,cr,mx,mn;
} t[MAXT*50];
int newnode(int l,int r,int cl,int cr,int mx,int mn){
	t[++M]=(tnode){l,r,cl,cr,mx,mn};
	return M;
}
int ini(int l,int r){
	if (l==r) return newnode(l,r,0,0,0,MAXT);
	int mid=(l+r)>>1;
	int cl=ini(l,mid),cr=ini(mid+1,r);
	return r=newnode(l,r,cl,cr,0,MAXT);
}
void update(int id){
	int cl=t[id].cl,cr=t[id].cr;
	t[id].mx=max(t[cl].mx,t[cr].mx);
	t[id].mn=min(t[cl].mn,t[cr].mn);
}
void modify(int a,int b,int val,int id){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return;
	if (a<=l&&r<=b) return t[id].mx=t[id].mn=val,void();
	modify(a,b,val,cl); modify(a,b,val,cr);
	update(id);
}
int query_mx(int a,int b,int id){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return 0;
	if (a<=l&&r<=b) return t[id].mx;
	int clx=query_mx(a,b,cl),crx=query_mx(a,b,cr);
	return max(clx,crx);
}
int query_mn(int a,int b,int id){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (l>b||r<a) return MAXT;
	if (a<=l&&r<=b) return t[id].mn;
	int cln=query_mn(a,b,cl),crn=query_mn(a,b,cr);
	return min(cln,crn);
}
int main(){
	scanf("%d",&n);
	root=ini(1,2*MAXT);
	for (int i=1,x;i<=n;i++){
		scanf("%d",&x);
		int mx=query_mx(1,x+MAXT,root);
		int mn=query_mn(x+MAXT,2*MAXT,root);
		if (mx==0&&mn==MAXT) ans+=x;
		else if (mx==0) ans+=mn-x;
		else if (mn==MAXT) ans+=x-mx;
		else ans+=min(mn-x,x-mx);
		modify(x+MAXT,x+MAXT,x,root);
//		cout<<mn<<" "<<mx<<" "<<x<<" "<<ans<<endl;
	}
	printf("%d\n",ans);
	return 0;
}
