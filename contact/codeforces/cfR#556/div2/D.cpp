#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=1e5+5;
const int inf=1e8;
struct tnode{
	int key,dat,sz,fa;
	bool flag;
	int ch[2];
} t[27][MAXN];
int n,m,M[27],rt[27];
struct rec{
	int b[MAXN];
	int pos[MAXN];
	int l,r;
	int op[MAXN];
	int cnt;
	rec(){ l=r=cnt=0; }
} a[4];
int newnode(int id,int key,int fa,int cl,int cr){
	t[id][++M[id]]=(tnode){key,1,1,fa};
	t[id][M[id]].ch[0]=cl; t[id][M[id]].ch[1]=cr;
	t[id][M[id]].flag=0;
	if (abs(key)==inf) t[id][M[id]].flag=1;
	return M[id];
}
void update(int id,int u){
	t[id][0]=(tnode){0,0,0,0};
	int cl=t[id][u].ch[0],cr=t[id][u].ch[1];
	t[id][u].sz=t[id][cl].sz+t[id][cr].sz+1;
	t[id][u].dat=t[id][cl].dat+t[id][cr].dat+(t[id][u].flag==0);
}
void rotate(int id,int u){
	int f1=t[id][u].fa;
	int f2=t[id][f1].fa;
	int dir1=t[id][f1].ch[1]==u;
	int dir2=t[id][f2].ch[1]==f1;
	int w=t[id][u].ch[dir1^1];
	t[id][f1].ch[dir1]=w; t[id][w].fa=f1;
	t[id][u].ch[dir1^1]=f1; t[id][f1].fa=u;
	t[id][u].fa=f2; t[id][f2].ch[dir2]=u;
	update(f1); update(u);
}
void splay(int id,int u,int go){
	if (go==u) return;
	while (t[id][u].fa!=go){
		int f1=t[id][u].fa;
		int f2=t[id][f1].fa;
		int dir1=t[id][f1].ch[1]==u;
		int dir2=t[id][f2].ch[1]==f1;
		if (f2==go){
			rotate(id,u); break;
		}
		if (dir1==dir2) rotate(id,f1);
		else rotate(id,u);
		rotate(id,u);
	}
	if (go==0) rt[id]=u;
}
void ins(int id,int key){
	if (rt[id]==0){
		rt[id]=newnode(id,key,0,0,0);
		return;
	}
	int u=rt[id];
	while (t[id][u].ch[key>t[id][u].key]) u=t[id][u].ch[key>t[id][u].key];
	int dir=key>t[id][u].key;
	int nt=newnode(id,key,u,0,0);
	t[id][u].ch[dir]=nt;
}
void find(int id,int key){
	int u=rt[id];
	while (t[id][u].ch[key>t[id][u].key]) u=t[id][u].ch[key>t[id][u].key];
	splay(id,u,0);
}
int num(int id,int u){
	int cl=t[id][u].ch[0],cr=t[id][u].ch[1];
	if (cl==0&&cr==0) return u;
	if (t[id][cl].dat>0) return num(id,cl);
	else if (t[id][cr].dat==0&&t[id][u].flag==0) return u;
	else if (t[id][cr].dat==0&&t[id][u].flag==1) return inf;
	else return num(id,cr);
}
int nex(int id,int key,int dir){
	find(id,key);
	int u=rt[id];
	if (t[id][u].key>key&&dir==1){
		u=t[id][u].ch[0];
		splay(id,u,0);
	}
	return num(id,t[u].ch[1]);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=26;i++) ins(i,inf),ins(i,-inf);
	for (int i=1;i<=n;i++){
		char c=getchar(); while (c<'a'||c>'z') c=getchar();
		int x=c-'a'+1;
		ins(x,i);
	}
	for (int i=1;i<=m;i++){
		char op=getchar(); while (op!='+'&&op!='-') op=getchar();
		int tmp; scanf("%d",&tmp);
		if (op=='+'){
			char c=getchar(); while (c<'a'||c>'z') c=getchar();
			int pos=a[tmp].pos[r-1];
			int ct=c-'a'+1;
			int nx=nex(ct,pos,1);
			if (nx==inf||a[tmp].cnt>0){
				printf("NO\n");
				a[tmp].op[a[tmp].cnt++]=ct;
				continue;
			}
			splay(nx);
			int u=rt[id];
			t[ct][u].flag=1; update(ct,u);
			a[tmp].pos[a[tmp].r++]=t[tmp][u].key;
			a[tmp].b[a[tmp].r-1]=ct;
			printf("YES\n");
		}
		if (op=='-'){
			int pos=a[tmp].pos[l++];
			int ch=a[tmp].b[l-1];
			find(ch,pos);
			int u=rt[ch];
			t[ch][u].flag=0; update(ch,u);
			
