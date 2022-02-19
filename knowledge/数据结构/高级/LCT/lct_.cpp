#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e5+5;
struct tnode{
	int dat,tag,fa;
	int ch[2];
} t[MAXN];
int n,m,a[MAXN],s[MAXN];
bool isroot(int x){
//	cout<<__func__<<endl;
	int fa=t[x].fa;
	return t[fa].ch[0]!=x&&t[fa].ch[1]!=x;
}
void update(int x){
//	cout<<__func__<<" "<<x<<endl;
	int cl=t[x].ch[0],cr=t[x].ch[1];
//	cout<<cl<<" "<<cr<<endl;
	t[x].dat=t[cl].dat^t[cr].dat^a[x];
}
void pushdown(int x){
//	cout<<__func__<<endl;
	int tag=t[x].tag;
	if (tag==0) return;
	swap(t[x].ch[0],t[x].ch[1]);
	t[t[x].ch[0]].tag^=1;
	t[t[x].ch[1]].tag^=1;
	t[x].tag=0;
}
void rotate(int x){
//	cout<<__func__<<endl;
	int fa1=t[x].fa;
	int fa2=t[fa1].fa;
	int dir1=t[fa1].ch[1]==x;
	int dir2=t[fa2].ch[1]==fa1;
	int chx=t[x].ch[dir1^1];
	if (!isroot(fa1)) t[fa2].ch[dir2]=x;
	t[chx].fa=fa1; t[fa1].ch[dir1]=chx;
	t[fa1].fa=x; t[x].ch[dir1^1]=fa1; t[x].fa=fa2;
	update(fa1); update(x);
}
void splay(int x){
//	cout<<__func__<<endl;
	int cnt=0,u=x;
//	cout<<"in"<<endl;
	while (!isroot(u)) s[++cnt]=u,u=t[u].fa;
	pushdown(u); 
//	cout<<endl<<" out"<<endl;
	while (cnt) pushdown(s[cnt--]);
	while (!isroot(x)){
//		cout<<x<<endl;
//		cout<<t[x].fa<<" "<<t[t[x].fa].ch[0]<<" "<<t[t[x].fa].ch[1]<<endl;
//		cout<<"fuck"<<endl;
		int fa1=t[x].fa;
		int fa2=t[fa1].fa;
		int dir1=t[fa1].ch[1]==x;
		int dir2=t[fa2].ch[1]==fa1;
		if (!isroot(fa1)) rotate(dir1==dir2?fa1:x);
		rotate(x);
	}
	update(x);
}
void access(int x){
//	cout<<__func__<<endl;
	for (int y=0;x;x=t[x].fa){
//		cout<<y<<" "<<x<<endl;
		splay(x); t[x].ch[1]=y; y=x; update(x);
	}
}
void makeroot(int x){
//	cout<<__func__<<endl;
	access(x); splay(x); t[x].tag^=1; pushdown(x);
}
int findroot(int x){
//	cout<<__func__<<endl;
	access(x); splay(x);
	while (t[x].ch[0]!=0) pushdown(x),x=t[x].ch[0];
	return x;
}
int split(int u,int v){
//	cout<<__func__<<endl;
	makeroot(u); access(v); splay(v);
	return t[v].dat;
}
bool cut(int u,int v){
//	cout<<__func__<<endl;
	makeroot(u);
	if (findroot(v)==u&&t[u].fa==v&&t[u].ch[1]==0){
		t[u].fa=t[v].ch[0]=0;
		update(v);
		return 1;
	}
	return 0;
}
bool link(int u,int v){
//	cout<<__func__<<endl;
	makeroot(u);
	if (findroot(v)==u) return 0;
	t[u].fa=v;
	return 1;
}
void dfs(int x){
	printf("id:%d fa:%d cl:%d cr:%d dat:%d\n",x,t[x].fa,t[x].ch[0],t[x].ch[1],t[x].dat);
	int cl=t[x].ch[0],cr=t[x].ch[1];
	if (cl) dfs(cl);
	if (cr) dfs(cr);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=m;i++){
		int op,u,v;
//		cout<<i<<endl;
		scanf("%d%d%d",&op,&u,&v);
		if (op==0) printf("%d\n",split(u,v));
		if (op==1) link(u,v);
		if (op==2) cut(u,v);
		if (op==3){ splay(u); a[u]=v; }
//		makeroot(2); access(1); splay(1); dfs(1);
	}
	return 0;
}
