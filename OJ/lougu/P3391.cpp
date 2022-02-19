#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int inf=1e9;
int n,m,M,rt;
struct tnode{
	int key,sz,fa,tag;
	int ch[2];
} t[MAXN];
int newnode(int key,int fa){
	t[++M]=(tnode){key,1,fa,0};
	t[M].ch[0]=t[M].ch[1]=0;
	return M;
}
void update(int id){
	int cl=t[id].ch[0],cr=t[id].ch[1];
	t[id].sz=t[cl].sz+t[cr].sz+1;
}
void pushdown(int id){
	int tag=t[id].tag;
	int cl=t[id].ch[0],cr=t[id].ch[1];
	if (!tag) return;
	swap(t[id].ch[0],t[id].ch[1]);
	t[cl].tag^=1; t[cr].tag^=1;
	t[id].tag^=1;
}
void rotate(int u){
	int f1=t[u].fa;
	int f2=t[f1].fa;
	int dir1=t[f1].ch[1]==u;
	int dir2=t[f2].ch[1]==f1;
	t[u].fa=f2; t[f2].ch[dir2]=u;
	int w=t[u].ch[dir1^1];
	t[w].fa=f1; t[f1].ch[dir1]=w;
	t[u].ch[dir1^1]=f1; t[f1].fa=u;
	update(f1); update(u);
}
void splay(int u,int go){
	if (u==go) return;
	while (t[u].fa!=go){
		int f1=t[u].fa;
		int f2=t[f1].fa;
		int dir1=t[f1].ch[1]==u;
		int dir2=t[f2].ch[1]==f1;
		if (f2==go){
			rotate(u);
			break;
		}
		else {
			if (dir1==dir2) rotate(f1);
			else rotate(u);
			rotate(u);
		}
	}
	if (go==0) rt=u;
}
void ins(int key){
	if (rt==0){
		rt=newnode(key,0);
		return;
	}
	int u=rt;
	while (t[u].ch[key>t[u].key]) u=t[u].ch[key>t[u].key];
	int dir=key>t[u].key;
	t[u].ch[dir]=newnode(key,u);
	u=t[u].ch[dir];
	splay(u,0);
}
int num(int u,int rk){
	pushdown(u);
	int cl=t[u].ch[0],cr=t[u].ch[1];
	int s=t[cl].sz;
	if (rk>s+1) return num(cr,rk-s-1);
	else if (s>=rk) return num(cl,rk);
	else return u;
}
void rev(int l,int r){
	int ul=num(rt,l-1);
	int ur=num(rt,r+1);
	splay(ul,0); splay(ur,rt);
	t[t[ur].ch[0]].tag^=1;
}
void prt(int u){
//	if (abs(t[u].key)==inf) return;
	pushdown(u);
	if (t[u].ch[0]) prt(t[u].ch[0]);
	if (abs(t[u].key)!=inf) printf("%d ",t[u].key);
	if (t[u].ch[1]) prt(t[u].ch[1]);
}
int main(){
	scanf("%d%d",&n,&m);
	ins(-inf); ins(inf);
	for (int i=1;i<=n;i++) ins(i);
//	cout<<t[num(rt,2)].key<<" "<<t[num(rt,4)].key<<endl;
//	prt(rt);
//	printf("\n");
	for (int i=1;i<=m;i++){
		int l,r;
		scanf("%d%d",&l,&r);
		l++; r++;
//		cout<<t[num(rt,1)].key<<" "<<t[num(rt,6)].key<<endl;
		rev(l,r);
//		prt(rt);
//		printf("\n");
	}
	prt(rt);
	printf("\n");
	return 0;
}
