#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e5+5;
const int inf=1e9;
struct tnode{
	int fa,cnt,dat,sz,ch[2];
} t[MAXN];
int n,M,root;
int newnode(int fa,int cnt,int dat,int sz){
	M++;
	t[M]=(tnode){fa,cnt,dat,sz};
	return M;
}
void update(int u){ t[u].sz=t[u].cnt+t[t[u].ch[0]].sz+t[t[u].ch[1]].sz; }
void lik(int u,int v,int id){
	t[v].fa=u;
	t[u].ch[id]=v;
}
void rotate(int x){
	int y=t[x].fa,z=t[y].fa;
	int cy=t[y].ch[1]==x,cz=t[z].ch[1]==y;
	int xs=t[x].ch[cy^1];
	lik(y,xs,cy); lik(x,y,cy^1); lik(z,x,cz);
	update(y); update(x);
}
void splay(int x,int to){
	while (t[x].fa!=to){
		int y=t[x].fa,z=t[y].fa;
		int cy=t[y].ch[1]==x,cz=t[z].ch[1]==y;
		if (z!=to){
			if (cy^cz) rotate(x);
			else rotate(y);
		}
		rotate(x);
	}
	if (to==0) root=x;
}
void ins(int x){
	int u=root,f=0;
	while (u&&t[u].dat!=x) f=u,u=t[u].ch[x>t[u].dat];
	if (u) t[u].cnt++;
	else{
		u=newnode(f,1,x,1);
		if (f) t[f].ch[x>t[f].dat]=u;
	}
	splay(u,0);
}
void find(int x){
	int u=root;
	if (!u) return;
	while (t[u].ch[x>t[u].dat]&&x!=t[u].dat) 
		u=t[u].ch[x>t[u].dat];
	splay(u,0);
}
int nex(int x,int f){
	find(x);
	int u=root;
	if ((t[u].dat>x&&f)||(t[u].dat<x&&!f)) return u;
	u=t[u].ch[f];
	while (t[u].ch[f^1]) u=t[u].ch[f^1];
	return u;
}
void del(int x){
	int las=nex(x,0),nxt=nex(x,1);
	splay(las,0); splay(nxt,las);
	int delt=t[nxt].ch[0];
	if (t[delt].cnt>1) t[delt].cnt--,splay(delt,0);
	else t[nxt].ch[0]=0;
}
int kth(int x){
	int u=root;
	if (t[u].sz<x) return 0;
	while (1){
		int y=t[u].ch[0];
		if (x>t[y].sz+t[u].cnt){
			x-=t[y].sz+t[u].cnt;
			u=t[u].ch[1];
		}
		else if (t[y].sz>=x) u=y;
		else return t[u].dat;
	}
}
int main(){
	ins(-inf); ins(inf);
	scanf("%d",&n);
	for (int i=1,op,x;i<=n;i++){
		scanf("%d%d",&op,&x);
		if (op==1) ins(x);
		else if (op==2) del(x);
		else if (op==3){
			find(x);
			printf("%d\n",t[t[root].ch[0]].sz);
		}
		else if (op==4) printf("%d\n",kth(x+1));
		else if (op==5) printf("%d\n",t[nex(x,0)].dat);
		else printf("%d\n",t[nex(x,1)].dat);
	}
	return 0;
}
