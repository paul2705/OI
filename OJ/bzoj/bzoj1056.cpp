#pragma GCC optimize(3)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
const int MAXN=2e5+5e4+5;
const int mod=998244353;
const int inf=1e9;
struct tnode{
	int key1,key2,key3,sz,fa;
	int ch[3];
} t[MAXN];
map<string,int> id;
map<int,string> nm;
int scr[MAXN],pos[MAXN];
int cnt;
int n,M,rt;
string nam;
int newnode(int k1,int k2,int k3,int fa,int cl,int cr){
	t[++M]=(tnode){k1,k2,k3,1,fa};
	t[M].ch[0]=cl; t[M].ch[1]=cr;
	return M;
}
void update(int u){
//	t[0].sz=t[0].fa=t[0].ch[0]=t[0].ch[1]=t[0].key1=0;
	int cl=t[u].ch[0],cr=t[u].ch[1];
	t[u].sz=t[cl].sz+t[cr].sz+1;
//	t[u].dat=t[cl].dat+t[cr].dat;
}
void rotate(int u){
	int f1=t[u].fa;
	int f2=t[f1].fa;
	int dir1=t[f1].ch[1]==u;
	int dir2=t[f2].ch[1]==f1;
	int w=t[u].ch[dir1^1];
	t[f1].ch[dir1]=w; t[w].fa=f1;
	t[u].ch[dir1^1]=f1; t[f1].fa=u;
	t[f2].ch[dir2]=u; t[u].fa=f2;
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
		if (dir1==dir2) rotate(f1);
		else rotate(u);
		rotate(u);
	}
	if (go==0) rt=u;
}
bool cmp(int k1,int k2,int u){
//	return k1==t[u].key1?k2<t[u].key2:k1>t[u].key1;
	return k1==t[u].key1?k2<t[u].key2:k1>t[u].key1;
}
void ins(int k1,int k2,int k3){
	if (rt==0){
		rt=newnode(k1,k2,k3,0,0,0);
		return;
	}
	int u=rt;
	while (t[u].ch[cmp(k1,k2,u)]) u=t[u].ch[cmp(k1,k2,u)];
	int dir=cmp(k1,k2,u);
	int nt=newnode(k1,k2,k3,u,0,0);
	t[u].ch[dir]=nt;
	update(u);
	splay(nt,0);
}
void find(int k1,int k2){
	int u=rt;
	while (t[u].ch[cmp(k1,k2,u)]){
		if (k1==t[u].key1&&k2==t[u].key2) break;
		u=t[u].ch[cmp(k1,k2,u)];
	}
	splay(u,0);
}
int nex(int k1,int k2,int dir){
	find(k1,k2);
	int u=rt;
	if (k1<t[u].key1&&dir==0) return u;
	if (k1==t[u].key1&&k2>t[u].key2&&dir==0) return u;
	if (k1>t[u].key1&&dir==1) return u;
	if (k1==t[u].key1&&k2<t[u].key2&&dir==1) return u;
	u=t[u].ch[dir];
	dir^=1;
	while (t[u].ch[dir]) u=t[u].ch[dir];
	return u;
}
void del(int k1,int k2){
	int pre=nex(k1,k2,0);
	int nxt=nex(k1,k2,1);
	splay(pre,0); splay(nxt,rt);
	t[t[t[rt].ch[1]].ch[0]].fa=0;
	t[t[rt].ch[1]].ch[0]=0;
	update(t[rt].ch[1]);
	splay(t[rt].ch[1],0);
}
int num(int u,int rk){
	int cl=t[u].ch[0],cr=t[u].ch[1];
	int szr=t[cr].sz;
	if (szr>=rk) return num(cr,rk);
	else if (szr+1==rk) return u;
	else return num(cl,rk-szr-1);
}
void prt(int u){
	int cl=t[u].ch[0],cr=t[u].ch[1];
	if (cl) prt(cl);
	printf("(%d %d ",t[u].key1,t[u].key2);
	cout<<nm[t[u].key3]<<") "<<endl;
	if (cr) prt(cr);
}
void myprt(){
	printf("__prt__\n");
	prt(rt);
	printf("_________\n");
}
int main(){
	scanf("%d",&n);
	ins(inf,inf,inf); ins(-inf,-inf,-inf);
	for (int i=1;i<=n;i++){
//		myprt();
		char op=getchar(); while (op!='+'&&op!='?') op=getchar();
		if (op=='+'){
			nam.clear();
			cin>>nam;
			int sc; scanf("%d",&sc);
			int t=id[nam];
			if (t==0){
				id[nam]=++cnt; nm[cnt]=nam;
				scr[cnt]=sc; pos[cnt]=i;
				ins(sc,i,cnt);
			}
			else {
				del(scr[t],pos[t]);
				ins(sc,i,t); scr[t]=sc; pos[t]=i;
			}
		}
		else {
			char c=getchar(); 
			if (c>='A'&&c<='Z'){
				int tmp=0;
				nam.clear();
				while (c>='A'&&c<='Z'){
					nam.push_back(c);
					c=getchar();
				}
				int tid=id[nam];
				int tsc=scr[tid];
				int tpos=pos[tid];
				find(tsc,tpos);
				if (t[t[rt].ch[1]].sz==0) printf("1\n");
				else printf("%d\n",t[t[rt].ch[1]].sz);
			}
			else {
				int rk=0;
				while (c>='0'&&c<='9'){
					rk=rk*10+c-'0';
					c=getchar();
				}
//				cout<<"rk: "<<rk<<endl;
				splay(num(rt,rk+1),0);
				for (int k=0;k<10;k++){
					int tid=t[rt].key3;
					if (abs(tid)==inf){
						cout<<endl;
						break;
					}
					int tsc=scr[tid];
					int tpos=pos[tid];
					string tnm=nm[tid];
					if (k==9) cout<<tnm<<endl;
					else cout<<tnm<<" ";
					splay(nex(tsc,tpos,0),0);
				}
			}
		}
	}
	return 0;
}
