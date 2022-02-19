#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int inf=1e9;
struct tnode{
	int key,sz,cnt,fa;
	int ch[3];
} t[MAXN];
int n,rt,M;
int newnode(int key,int fa){
	t[++M]=(tnode){key,1,1,fa};
	return M;
}
void update(int x){
	int cl=t[x].ch[0],cr=t[x].ch[1];
	t[x].sz=t[cl].sz+t[cr].sz+t[x].cnt;
}
void rotate(int x){
	int f1=t[x].fa;
	int f2=t[f1].fa;
	int dir1=t[f1].ch[1]==x;
	int dir2=t[f2].ch[1]==f1;
	t[f1].ch[dir1]=t[x].ch[dir1^1]; t[t[x].ch[dir1^1]].fa=f1;
	t[f1].fa=x; t[x].ch[dir1^1]=f1;
	t[x].fa=f2; if (f2!=0) t[f2].ch[dir2]=x;
	update(f1); update(x);
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
		if (dir1==dir2) rotate(f1);
		rotate(u);
	}
	if (go==0) rt=u;
}
void ins(int key){
	int u=rt;
	while (t[u].ch[t[u].key<key]){
		if (t[u].key==key) break;
		u=t[u].ch[t[u].key<key];
	}
	if (t[u].key==key){
		t[u].cnt++; t[u].sz++;
		splay(u,0);
		return;
	}
	int nu=newnode(key,u);
	t[u].ch[t[u].key<key]=nu;
	if (rt==0) rt=nu;
	splay(nu,0);
}
void find(int key){
	int u=rt;
	while (t[u].ch[t[u].key<key]){
		if (t[u].key==key) break;
		u=t[u].ch[t[u].key<key];
	}
	splay(u,0);
}
int nxt(int key,int dir){
	find(key);
	if (t[rt].key<key&&dir==0) return rt;
	if (t[rt].key>key&&dir==1) return rt;
	int u=t[rt].ch[dir]; dir^=1;
	while (t[u].ch[dir]) u=t[u].ch[dir];
	return u;
}
void del(int key){
	int las=nxt(key,0);
	int net=nxt(key,1);
	splay(las,0); splay(net,rt);
	if (t[t[net].ch[0]].cnt>1){
		t[t[net].ch[0]].cnt--;
		splay(t[net].ch[0],0);
	}
	else t[net].ch[0]=0;
}
int num(int u,int rk){
	int sz=t[t[u].ch[0]].sz+t[u].cnt;
	if (rk>sz) return num(t[u].ch[1],rk-sz);
	else if (rk<=t[t[u].ch[0]].sz) return num(t[u].ch[0],rk);
	else return u;
}
int rnk(int key){
	find(key);
	return t[t[rt].ch[0]].sz;
}
int main(){
	ins(inf); ins(-inf);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int op,x;
		scanf("%d%d",&op,&x);
		if (op==1) ins(x);
		if (op==2) del(x);
		if (op==3) printf("%d\n",rnk(x));
		if (op==4) printf("%d\n",t[num(rt,x+1)].key);
		if (op==5) printf("%d\n",t[nxt(x,0)].key);
		if (op==6) printf("%d\n",t[nxt(x,1)].key);
	}
	return 0;
}
