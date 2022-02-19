#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e4+5;
const int inf=1e9;
struct tnode{
	int sz,fa,dat,mx,tag1,tag2;
	// tag1: add
	// tag2: rev
	int ch[3];
} t[MAXN];
int n,m,M,rt;
int st[MAXN],top;
int newnode(int sz,int fa,int dat,int mx,int cl,int cr){
	t[++M]=(tnode){sz,fa,dat,mx,0,0};
	t[M].ch[0]=cl; t[M].ch[1]=cr;
	return M;
}
void update(int id){
	if (!id) return;
	int cl=t[id].ch[0],cr=t[id].ch[1];
	t[0].mx=t[0].dat=-inf;
	t[id].mx=max(t[id].dat,max(t[cl].mx,t[cr].mx));
	t[id].sz=t[cl].sz+t[cr].sz+1;
}
void rotate(int id){
	int f1=t[id].fa;
	int f2=t[f1].fa;
	int dir1=t[f1].ch[1]==id;
	int dir2=t[f2].ch[1]==f1;
	int w=t[id].ch[dir1^1];
	t[f1].ch[dir1]=w; t[w].fa=f1;
	t[id].ch[dir1^1]=f1; t[f1].fa=id;
	t[f2].ch[dir2]=id; t[id].fa=f2;
	update(f1); update(id);
}
void pushdown(int id){
	int cl=t[id].ch[0],cr=t[id].ch[1];
	if (t[id].tag1){
		t[id].dat+=t[id].tag1;
		t[id].mx+=t[id].tag1;
		t[cl].tag1+=t[id].tag1;
		t[cr].tag1+=t[id].tag1;
		t[id].tag1=0;
	}
	if (t[id].tag2){
		swap(t[id].ch[0],t[id].ch[1]);
		t[cl].tag2^=1;
		t[cr].tag2^=1;
		t[id].tag2=0;
	}
}
void splay(int id,int go){
	if (id==go) return;
	top=0; int u=id;
	while (u!=go) st[++top]=u,u=t[u].fa;
//	st[++top]=go;
	while (top) pushdown(st[top--]);
	while (t[id].fa!=go){
		int f1=t[id].fa;
		int f2=t[f1].fa;
		int dir1=t[f1].ch[1]==id;
		int dir2=t[f2].ch[1]==f1;
		if (f2==go){
			rotate(id);
			break;
		}
		if (dir1==dir2) rotate(f1);
		else rotate(id);
		rotate(id);
	}
	if (go==0) rt=id;
}
int num(int u,int rk){
//	cout<<u<<" "<<rk<<endl;
	pushdown(u);
	int cl=t[u].ch[0],cr=t[u].ch[1];
	int szl=t[cl].sz;
	if (szl+1<rk) return num(cr,rk-szl-1);
	else if (szl+1==rk) return u;
	else return num(cl,rk);
}
int build(int id,int l,int r){
//	cout<<__func__<<" "<<l<<" "<<r<<endl;
	if (l>r) return 0;
	if (l==r){
		int nt=newnode(1,id,0,0,0,0);
		return nt;
	}
	int mid=(l+r)>>1;
	int nt=newnode(0,id,0,0,0,0); 
	int cl=build(nt,l,mid-1),cr=build(nt,mid+1,r);
	t[nt]=(tnode){t[cl].sz+t[cr].sz+1,id,0,0,0,0};
	t[nt].ch[0]=cl; t[nt].ch[1]=cr;
	return nt;
}
void add(int l,int r,int val){
	int pre=num(rt,l),net=num(rt,r+2);
	splay(pre,0); splay(net,pre);
	int u=t[t[rt].ch[1]].ch[0];
	t[u].tag1+=val;
	pushdown(u);
	splay(u,0);
}
void rev(int l,int r){
	int pre=num(rt,l),net=num(rt,r+2);
	splay(pre,0); splay(net,pre);
	int u=t[t[rt].ch[1]].ch[0];
	t[u].tag2^=1;
	pushdown(u);
	splay(u,0);
}
int qry(int l,int r){
	int pre=num(rt,l),net=num(rt,r+2);
	splay(pre,0); splay(net,pre);
	int u=t[t[rt].ch[1]].ch[0];
	pushdown(pre); pushdown(net); pushdown(u);
	top=0; int id=u;
	while (id!=0) st[++top]=id,id=t[id].fa;
	bool flag1=0,flag2=0;
	while (top){
		flag1|=t[st[top]].tag1;
		flag2|=t[st[top]].tag2;
		top--;
	}
	if (flag1) printf("NO 1\n");
	if (flag2) printf("NO 2\n");
	return t[u].mx;
}
void prt(int id){
	int cl=t[id].ch[0],cr=t[id].ch[1];
	if (cl) prt(cl);
	printf("id:%d dat:%d mx:%d tag1:%d tag2:%d fa:%d cl:%d cr:%d\n",id,t[id].dat,t[id].mx,t[id].tag1,t[id].tag2,t[id].fa,cl,cr);
	if (cr) prt(cr);
}
void myprt(){
	printf("_______prt_______\n");
	prt(rt);
	printf("_________________\n");
}
int main(){
	freopen("bzoj1251.in","r",stdin);
	freopen("bzoj1251.out","w",stdout);
	scanf("%d%d",&n,&m);
	rt=build(0,0,n+1);
	int u=num(rt,1); t[u].dat=t[u].mx=-inf;
	u=num(rt,n+2); t[u].dat=t[u].mx=-inf;
	for (int i=1;i<=m;i++){
		myprt();
		int op,l,r,v; scanf("%d%d%d",&op,&l,&r);
		if (op==1){
			scanf("%d",&v);
			add(l,r,v);
		}
		if (op==2) rev(l,r);
		if (op==3) printf("%d\n",qry(l,r));
	}
	myprt();
	fclose(stdin); fclose(stdout);
	return 0;
}
