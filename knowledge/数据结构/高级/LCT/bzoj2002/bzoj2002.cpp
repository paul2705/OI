#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=3e5+5;
int n,m,a[MAXN],s[MAXN],top;
struct tnode{
	int dat,cl,cr,tag,fa;
	int ch[2];
} t[MAXN];
int d[MAXN],cnt,sum;
void dfs(int x,int p){
//	printf("id:%d fa:%d cl:%d cr:%d dat:%d\n",x,t[x].fa,t[x].ch[0],t[x].ch[1],t[x].dat);
	int cl=t[x].ch[0],cr=t[x].ch[1];
	d[x]=d[p]+1; sum+=d[x]; cnt++;
	if (cl) dfs(cl,x);
	if (cr) dfs(cr,x);
}
void read(int &x){
    int f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    x*=f;
}
void print(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
bool isroot(int x){
	int fa=t[x].fa;
	return t[fa].ch[0]!=x&&t[fa].ch[1]!=x;
}
void update(int x){
	t[0].dat=0;
	int cl=t[x].ch[0],cr=t[x].ch[1];
	t[x].dat=t[cl].dat+t[cr].dat+1;
}
void pushdown(int x){
	int tag=t[x].tag;
	if (tag==0) return;
	swap(t[x].ch[0],t[x].ch[1]);
	t[t[x].ch[0]].tag^=1;
	t[t[x].ch[1]].tag^=1;
	t[x].tag=0;
}
void rotate(int x){
	int fa1=t[x].fa;
	int fa2=t[fa1].fa;
	int dir1=t[fa1].ch[1]==x;
	int dir2=t[fa2].ch[1]==fa1;
	if (!isroot(fa1)) t[fa2].ch[dir2]=x;
	t[x].fa=fa2;
	t[fa1].ch[dir1]=t[x].ch[dir1^1];
	t[t[x].ch[dir1^1]].fa=fa1;
	t[x].ch[dir1^1]=fa1; t[fa1].fa=x;
	update(fa1); update(x);
}
void splay(int x){
	top=0; int u=x;
	while (!isroot(u)) s[++top]=u,u=t[u].fa;
	pushdown(u);
	while (top) pushdown(s[top--]);
	while (!isroot(x)){
		int fa1=t[x].fa;
		int fa2=t[fa1].fa;
		int dir1=t[fa1].ch[1]==x;
		int dir2=t[fa2].ch[1]==fa1;
		if (!isroot(fa1)) rotate(dir1!=dir2?x:fa1);
		rotate(x);
	}
	update(x);
}
void access(int x){
	for (int y=0;x;x=t[x].fa){
		splay(x); t[x].ch[1]=y; y=x; update(x);
	}
}
void makeroot(int x){
	access(x); splay(x); t[x].tag^=1; pushdown(x);
}
int findroot(int x){
	access(x); splay(x);
	while (t[x].ch[0]!=0) x=t[x].ch[0];
	return x;
}
bool cut(int u,int v){
	makeroot(u);
	if (findroot(v)==u&&t[u].fa==v&&t[u].ch[1]==0){
		t[u].fa=t[v].ch[0]=0;
		return 1;
	}
	return 0;
}
bool link(int u,int v){
	makeroot(u); 
//	if (findroot(v)==u) return 0;
	t[u].fa=v;
	return 1;
}
int main(){
	freopen("1.in","r",stdin);
//	read(n);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
//		read(a[i]);
		scanf("%d",&a[i]);
		cout<<i<<endl;
		if (i+a[i]<=n) link(i+a[i],i);
		else link(n+1,i);
		
	}
//	read(m);
	scanf("%d",&m);
//	cout<<"done"<<endl;
	for (int i=1;i<=m;i++){
		int op,u;
		cout<<i<<endl;
//		read(op); read(u);
		scanf("%d%d",&op,&u);
		u++;
		if (op==1){
			makeroot(n+1); access(u); splay(u);
			printf("%d\n",t[u].dat-1);
//			print(t[u].dat-1);
		}
		else {
			int x;
//			read(x);
			scanf("%d",&x);
			if (u+a[u]<=n) cut(u+a[u],u);
			else cut(n+1,u);
			if (u+x<=n) link(u+x,u);
			else link(n+1,u);
			a[u]=x;
		}
	}
	return 0;
}
