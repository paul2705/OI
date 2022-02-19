#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define mkp make_pair
#define ls c[x][0]
#define rs c[x][1]
using namespace std;
const int MAXN=1e4+5;
const int MAXM=5e5+5;
int n,m,tot,op[MAXM],fa[MAXN],c[MAXN][2],sta[MAXN],top;
int del_pl[MAXN],del_top;
bool rev[MAXN];
map<pair<int,int>,int> mp;
struct Node{ int x,y,t; } a[MAXM];
struct Dt{
	int t,id,bh;
	Dt(int a=0,int b=0,int c=0):t(a),id(b),bh(c) {}
} vl[MAXN],mn[MAXN];
Dt Mn(Dt x,Dt y){
	if (!x.t) return y; 
	if (!y.t) return x;
	return (x.t<y.t)?x:y;
}
int New(){
	int ret=(del_top?del_pl[del_top--]:++tot);
	c[ret][1]=c[ret][0]=fa[ret]=0; return ret; 
}
bool isroot(int x){ return c[fa[x]][0]!=x&&c[fa[x]][1]!=x; }
void pshp(int x){ mn[x]=Mn(vl[x],Mn(mn[ls],mn[rs])); }
void Rev(int x){
	if (!rev[x]) return; 
	rev[x]=0;
	rev[ls]^=1; rev[rs]^=1; swap(ls,rs);
}
void rotate(int x){
	int y=fa[x],z=fa[y],d=(x==c[y][1]);
	if (!isroot(y)) c[z][y==c[z][1]]=x;
	fa[x]=z;
	fa[y]=x; fa[c[x][!d]]=y;
	c[y][d]=c[x][!d]; c[x][!d]=y;
	pshp(y); pshp(x);
}
void splay(int x){
	sta[top=1]=x;
	for (int k=x;!isroot(k);k=fa[k]) sta[++top]=fa[k];
	for (int i=top;i;i--) Rev(sta[i]);
	while (!isroot(x)){
		int y=fa[x],z=fa[y];
		if (!isroot(y)) ((x==c[y][0])^(y==c[z][0]))?rotate(x):rotate(y);
		rotate(x);
	}
}
void access(int x){
	for (int t=0;x;rs=t,pshp(x),t=x,x=fa[x]) splay(x);
}
void mkrt(int x){
	access(x); splay(x); rev[x]^=1;
}
void link(int x,int y){
	mkrt(x); fa[x]=y;
}
void cut(int x,int y){
	mkrt(x); access(y); splay(y);
	c[y][0]=0; pshp(y); fa[x]=0;
}
bool chk(int x,int y){
	mkrt(x); access(y); splay(y);
	while (c[y][0]) y=c[y][0];
	return x==y;
}
void ins(Node cr,int id){
	int x=cr.x,y=cr.y;
	if (chk(x,y)){
		splay(x);
		Dt tp=mn[x]; 
		if (tp.t>cr.t) return;
		Node k=a[tp.id]; int bh=tp.bh;
		cut(k.x,bh); cut(k.y,bh); del_pl[++del_top]=bh;
	}
	int nw=New(); 
	mn[nw]=vl[nw]=Dt(cr.t,id,nw);
	link(cr.x,nw); link(cr.y,nw);
}
int qry(int x,int y){
	if (!chk(x,y)) return 0;
	splay(x); 
	return mn[x].t;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) mn[i]=vl[i]=Dt(0,0,0); 
	tot=n;
	for(int i=1;i<=m;i++){
		scanf("%d",&op[i]);
		int x,y; scanf("%d%d",&x,&y);
		if (x>y) swap(x,y);
		if (op[i]==0){
			mp[mkp(x,y)]=i;
			a[i].x=x; a[i].y=y;
			a[i].t=m+1;
		}
		else if (op[i]==1) a[mp[mkp(x,y)]].t=i;
		else a[i].x=x,a[i].y=y;
	}
	for(int i=1;i<=m;i++){
		if (op[i]==0) ins(a[i],i);
		if (op[i]==2) puts(qry(a[i].x,a[i].y)>i?"Y":"N");
    }
	return 0;
}
