#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e6+6;
const int mod=317847191;
const int inf=1e9+5;
struct tnode{
	int dat,cnt,sz,fa,ch[2];
} t[MAXN];
int n,m,M,mul=1,root=0,inv[MAXN];
int newnode(int dat,int cnt,int sz,int fa){
	t[++M]=(tnode){dat,cnt,sz,fa};
	return M;
}
void update(int x){ t[x].sz=t[x].cnt+t[t[x].ch[0]].sz+t[t[x].ch[1]].sz; }
void lik(int u,int v,int id){
	t[v].fa=u;
	t[u].ch[id]=v;
}
void rotate(int x){
	int y=t[x].fa,z=t[y].fa;
	int cy=t[y].ch[1]==x,cz=t[z].ch[1]==y;
	int sx=t[x].ch[y^1];
	lik(y,sx,cy); lik(x,y,cy^1); lik(z,x,cz);
	update(y); update(x);
}
void splay(int x,int go){
	while (t[x].fa!=go){
		int y=t[x].fa,z=t[y].fa;
		int cy=t[y].ch[1]==x,cz=t[z].ch[1]==y;
		if (z!=go){
			if (cy^cz) rotate(x);
			else rotate(y);
		}
		rotate(x);
	}
	if (go==0) root=x;
}
void ins(int val){
	int u=root,f=0;
	while (u&&t[u].dat!=val) f=u,u=t[u].ch[val>t[u].dat];
	if (u) t[u].cnt++;
	else {
		u=newnode(val,1,1,f);
		if (f) t[f].ch[val>t[f].dat]=u;
	}
	splay(u,0);
}
void find(int x){
	int u=root;
	while (!u) return;
	while (t[u].ch[x>t[u].dat]&&t[u].dat!=x) u=t[u].ch[x>t[u].dat];
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
	while (1){
		int y=t[u].ch[0];
		if (t[y].sz+t[u].cnt<x){
			x-=t[y].sz+t[u].cnt;
			u=t[u].ch[1];
		}
		else if (t[y].sz>=x) u=y;
		else return t[u].dat;
	}
}
int mod_pow(int x,int n){
	int ans=1;
	while (n){
		if (n&1) ans=(ll)ans*x%mod;
		x=(ll)x*x%mod;
		n>>=1;
	}
	return ans;
}
int extgcd(int a,int b,int &x,int &y){
	if (b==0){
		x=1,y=0;
		return a;
	}
	int q=extgcd(b,a%b,y,x);
	y-=a/b*x;
	return q;
}
int main(){
	scanf("%d%d",&n,&m);
	ins(inf); ins(-inf);
	for (int i=1,a;i<=n;i++){
		scanf("%d",&a);
		ins(a); mul=(ll)mul*a%mod;
	}
//	cout<<mul<<endl;
	for (int i=0,a;i<m;i++){
		char op=getchar(); while (op<'A'||op>'Z') op=getchar();
		if (op=='M') printf("%d\n",mod_pow(kth(n+1),kth(2)));
		if (op=='T') printf("%d\n",mul);
		if (op=='D'){
			scanf("%d",&a); n--;
			int x,y; int d=extgcd(a,mod,x,y);
//			cout<<(double)mod/a<<endl;
//			cout<<x<<" "<<a<<" "<<mod<<" "<<d<<endl;;
			del(a); mul=(ll)mul*(x%mod+mod)%mod;
		}
		if (op=='B') printf("%d\n",kth(n+1));
		if (op=='S') printf("%d\n",kth(2));
	}
	return 0;
}
