#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
struct tnode{
	int l,r,cl,cr,mx,lx,rx;
} t[MAXN*4];
struct qry{
	int mx,lx,rx;
};
int T,n,m,M,a[MAXN],root;
int newnode(int l,int r,int cl,int cr,int mx,int lx,int rx){
	t[++M]=(tnode){l,r,cl,cr,mx,lx,rx};
	return M;
}
void update(int id){
	int cl=t[id].cl,cr=t[id].cr;
	int mx=max(t[cl].mx,t[cr].mx);
	bool f=a[t[cl].r]<a[t[cr].l];
	if (f) mx=max(mx,t[cl].rx+t[cr].lx);
	int llen=t[cl].r-t[cl].l+1,rlen=t[cr].r-t[cr].l+1;
	int lx=(t[cl].lx==llen&&f)?t[cl].lx+t[cr].lx:t[cl].lx;
	int rx=(t[cr].rx==rlen&&f)?t[cr].rx+t[cl].rx:t[cr].rx;	
	t[id]=(tnode){t[id].l,t[id].r,cl,cr,mx,lx,rx};
}
int ini(int l,int r){
	if (l==r) return newnode(l,r,0,0,1,1,1);
	int mid=(l+r)>>1;
	int cl=ini(l,mid),cr=ini(mid+1,r);
	int id=newnode(l,r,cl,cr,0,0,0);
	update(id);
//	cout<<l<<" "<<r<<" "<<t[id].mx<<" "<<t[id].lx<<" "<<t[id].rx<<endl;
	return id;
}
void modify(int a,int b,int id){
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	if (b<l||r<a) return;
	if (a<=l&&r<=b){
		t[id]=(tnode){l,r,0,0,1,1,1};
		return;
	}
	modify(a,b,cl); modify(a,b,cr);
	update(id);
//	cout<<t[id].l<<" "<<t[id].r<<" "<<t[id].mx<<" "<<t[id].lx<<" "<<t[id].rx<<endl;
}
qry query(int x,int y,int id){
//	cout<<x<<" "<<y<<endl;
	int l=t[id].l,r=t[id].r;
	int cl=t[id].cl,cr=t[id].cr;
	qry ans=(qry){0,0,0}; 
	if (y<l||r<x) return ans;
	if (x<=l&&r<=y){
		ans=(qry){t[id].mx,t[id].lx,t[id].rx};
		return ans;
	}
	qry ql=query(x,y,cl),qr=query(x,y,cr);
	ans.mx=max(ql.mx,qr.mx);
	bool f=(a[t[cl].r]<a[t[cr].l]);
	if (f) ans.mx=max(ans.mx,ql.rx+qr.lx);
	int llen=t[cl].r-t[cl].l+1,rlen=t[cr].r-t[cr].l+1;
	ans.lx=(ql.lx==llen&&f)?ql.lx+qr.lx:ql.lx;
	ans.rx=(qr.rx==rlen&&f)?qr.rx+ql.rx:qr.rx;
	if (x>t[id].l) ans.lx=0;
	if (y<t[id].r) ans.rx=0;
//	cout<<l<<" "<<r<<" "<<ans.mx<<" "<<ans.lx<<" "<<ans.rx<<endl;
	return ans;
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		root=ini(1,n);
		for (int i=1,x,y;i<=m;i++){
			char op=getchar();while (op!='Q'&&op!='U') op=getchar();
			scanf("%d%d",&x,&y); x++;
			if (op=='U') a[x]=y,modify(x,x,root);
			else{
				y++; qry ans=query(x,y,root);
//				cout<<ans.mx<<" "<<ans.lx<<" "<<ans.rx<<endl;
				printf("%d\n",max(ans.mx,max(ans.lx,ans.rx)));
			}
		}
	}
	return 0;
}
