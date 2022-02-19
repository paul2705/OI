#include<iostream>
#include<cstdio>
#inlcude<cstring>
#inlcude<algorithm>
using namespace std;
const int MAXN=1e5+5;
struct tnode{
	int dat,cnt,sz,fa,ch[2];
} t[MAXN];
int n,m,w[MAXN],h[MAXN];
void update(int x){ t[x].sz=t[x].cnt+t[t[x].ch[0]].sz+t[t[x].ch[1]].sz; }
int newnode(int dat,int fa){
	t[++M]=(tnode){dat,1,1,fa};
	return M;
}
void lik(int u,int v,int id){
	t[v].fa=u; t[u].ch[id]=v;
}
void rotate(int x){
	int y=t[x].fa,z=t[y].fa;
	int cy=t[y].ch[1]==x,cz=t[z].ch[1]==y;
	int sx=t[x].ch[cy^1];
	lik(y,sx,cy); lik(x,y,cy^1); lik(z,x,cz);
}
void splay(int x,int go){
	while (t[x].fa!=go){
		int y=t[x].fa,z=t[y].fa;
		int cy=t[y].ch[1]==x,cz=t[z].ch[1]==y;
		if (z!=to){
			if (cy^cz) rotate(x);
			else rotate(y);
		}
		rotate(x);
	}
	if (go==0) root=x;
}
void ins(int x){
	int u=root,f=0;
	while (u&&t[u].dat!=x) f=u,u=t[u].ch[x>t[u].dat];
	if (u) t[u].cnt++;
	else{
		u=newnode(x,f);
		if (f) t[f].ch[x>t[f].dat]=u;
	}
	splay(u,0);
}
void find(int x){
	int u=root;
	if (!u) return;
	while (t[u].ch[x>t[u].dat]&&t[u].dat!=x) t=t[u].ch[x>t[u].dat];
	splay(u,0);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&w[i],&h[i]);
		ins(s);
	}
	return 0;
}
