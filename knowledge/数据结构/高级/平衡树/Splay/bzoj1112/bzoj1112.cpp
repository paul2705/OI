#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
const int inf=1e9;
int n,m,a[MAXN],M,rt=0;
ll ans=1e18,pos,pos_dat;
struct tnode{
	int key,sz,cnt,fa;
	ll dat;
	int ch[2];
} t[MAXN];
int newnode(int key,int fa,int cl,int cr){
	if (abs(key)!=inf) t[++M]=(tnode){key,1,1,fa,key};
	else t[++M]=(tnode){key,1,1,fa,0};
	t[M].ch[0]=cl; t[M].ch[1]=cr;
	return M;
}
void update(int u){
	int cl=t[u].ch[0],cr=t[u].ch[1];
	t[u].sz=t[cl].sz+t[cr].sz+t[u].cnt;
	t[u].dat=t[cl].dat+t[cr].dat+(ll)t[u].cnt*(abs(t[u].key)==inf?0:t[u].key);
}
void rotate(int u){
	int f1=t[u].fa;
	int f2=t[f1].fa;
	int dir1=t[f1].ch[1]==u;
	int dir2=t[f2].ch[1]==f1;
	int w=t[u].ch[dir1^1];
	t[w].fa=f1; t[f1].ch[dir1]=w;
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
		rotate(u);
	}
	if (go==0) rt=u;
}
void ins(int key){
	if (rt==0){
		rt=newnode(key,0,0,0);
		return;
	}
	int u=rt;
	while (t[u].ch[key>t[u].key]){
		if (key==t[u].key) break;
		u=t[u].ch[key>t[u].key];
	}
	if (key==t[u].key){
		t[u].cnt++;
		splay(u,0);
	}
	else {
		int nt=newnode(key,u,0,0);
		int dir=key>t[u].key;
		t[u].ch[dir]=nt;
		splay(nt,0);
	}
}
void find(int key){
	int u=rt;
	while (t[u].ch[key>t[u].key]){
		if (key==t[u].key) break;
		u=t[u].ch[key>t[u].key];
	}
	splay(u,0);
}
int nex(int key,int dir){
	find(key);
	int u=rt;
	if (t[u].key<key&&dir==0) return u;
	if (t[u].key>key&&dir==1) return u;
	u=t[u].ch[dir];
	dir^=1;
	while (t[u].ch[dir]) u=t[u].ch[dir];
	return u;
}
void del(int key){
	int pre=nex(key,0);
	int nxt=nex(key,1);
	splay(pre,0); splay(nxt,pre);
	int u=t[nxt].ch[0];
	if (t[u].cnt>1){
		t[u].cnt--;
		splay(u,0);
	}
	else {
		t[nxt].ch[0]=0;
		splay(nxt,0);
	}
}
int num(int u,int rk){
	int cl=t[u].ch[0],cr=t[u].ch[1];
	int scl=t[cl].sz,cnt=t[u].cnt;
	if (scl>=rk) return num(cl,rk);
	else if (scl+cnt>=rk) return u;
	else return num(cr,rk-scl-cnt);
}
ll Get(ll &dat){
//	cout<<__func__<<(m+1)/2+1<<endl;
	splay(num(rt,(m+1)/2+1),0);
	int u=rt;
	ll sl=t[t[u].ch[0]].dat;
	ll sr=t[t[u].ch[1]].dat;
	ll cl=t[t[u].ch[0]].sz-1;
	ll cr=t[t[u].ch[1]].sz-1;
	dat=t[u].key;
//	cout<<__func__<<dat<<" "<<cl<<" "<<sl<<" "<<cr<<" "<<sr<<endl;
	return (ll)dat*cl-sl+sr-dat*cr;
}
void prt(int u){
	int cl=t[u].ch[0],cr=t[u].ch[1];
	if (cl) prt(cl);
	printf("key:%d dat:%lld sz:%d cnt:%d\n",t[u].key,t[u].dat,t[u].sz,t[u].cnt);
	if (cr) prt(cr);
}
void myprt(){
	printf("____prt____\n");
	prt(rt);
	printf("___________\n");
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	ins(inf); ins(-inf);
	for (int i=1;i<=m;i++) ins(a[i]);
//	myprt();
//	ans=min(ans,get());
	ll x;
	ll tmp=Get(x);
	if (ans>tmp){
		ans=tmp;
		pos_dat=x;
		pos=m;
	}
	for (int i=m+1;i<=n;i++){
		del(a[i-m]);
		ins(a[i]);
//		myprt();
//		ans=min(ans,get());
		tmp=Get(x);
		if (ans>tmp){
			ans=tmp;
			pos_dat=x;
			pos=i;
		}
	}
	printf("%lld\n",ans);
//	for (int i=1;i<=pos-m;i++) printf("%d\n",a[i]);
//	for (int i=pos-m+1;i<=pos;i++) printf("%lld\n",pos_dat);
//	for (int i=pos+1;i<=n;i++) printf("%d\n",a[i]);
	return 0;
}
