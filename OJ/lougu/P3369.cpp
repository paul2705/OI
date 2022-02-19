#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int inf=1e9;
int n,M,rt=0;
struct tnode{
	int key,fa,sz,cnt;
	int ch[2];
} t[MAXN];
int newnode(int key,int fa){
	t[++M]=(tnode){key,fa,1,1};
	t[M].ch[0]=t[M].ch[1]=0;
	return M;
}
void update(int id){
	int cl=t[id].ch[0],cr=t[id].ch[1];
	t[id].sz=t[cl].sz+t[cr].sz+t[id].cnt;
}
void rotate(int u){
	int f1=t[u].fa,f2=t[f1].fa;
	int dir1=t[f1].ch[1]==u;
	int dir2=t[f2].ch[1]==f1;
	t[u].fa=f2;
	if (f2) t[f2].ch[dir2]=u;
	int w=t[u].ch[dir1^1];
	t[f1].ch[dir1]=w;
	if (w) t[w].fa=f1;
	t[f1].fa=u; t[u].ch[dir1^1]=f1;
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
	while (key!=t[u].key&&t[u].ch[key>t[u].key]) u=t[u].ch[key>t[u].key];
	if (key==t[u].key) t[u].cnt++,t[u].sz++;
	else {
		int dir=key>t[u].key;
		t[u].ch[dir]=newnode(key,u);
		u=t[u].ch[dir];
	}
	splay(u,0);
}
void find(int key){
	int u=rt;
	while (key!=t[u].key&&t[u].ch[key>t[u].key]) u=t[u].ch[key>t[u].key];
	splay(u,0);
}
int nex(int key,int dir){
	find(key);
	if (t[rt].key<key&&dir==0) return rt;
	if (t[rt].key>key&&dir==1) return rt;
	int u=t[rt].ch[dir]; dir^=1;
	while (t[u].ch[dir]) u=t[u].ch[dir];
	return u;
}
void del(int key){
	int pre=nex(key,0);
	int nxt=nex(key,1);
	splay(pre,0); splay(nxt,rt);
	if (t[t[nxt].ch[0]].cnt>1){
		t[t[nxt].ch[0]].cnt--;
		t[t[nxt].ch[0]].sz--;
		splay(t[nxt].ch[0],0);
	}
	else t[nxt].ch[0]=0;
}
int num(int u,int rk){
	int cl=t[u].ch[0],cr=t[u].ch[1];
	int s=t[cl].sz+t[u].cnt;
	if (s<rk) return num(cr,rk-s);
	else if (t[cl].sz>=rk) return num(cl,rk);
	else return u;
}
int rnk(int key){
	find(key);
	return t[t[rt].ch[0]].sz;
}
int main(){
	scanf("%d",&n);
	ins(inf); ins(-inf);
	for (int i=1;i<=n;i++){
		int op,x;
		scanf("%d%d",&op,&x);
		if (op==1) ins(x);
		if (op==2) del(x);
		if (op==3) printf("%d\n",rnk(x));
		if (op==4) printf("%d\n",t[num(rt,x+1)].key);
		if (op==5) printf("%d\n",t[nex(x,0)].key);
		if (op==6) printf("%d\n",t[nex(x,1)].key);
	}
	return 0;
}
