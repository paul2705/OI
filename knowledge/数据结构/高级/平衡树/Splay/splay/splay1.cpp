#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int inf=1e8;
struct tnode{
	int key,fa,cnt,sz;
	int ch[2];
} t[MAXN];
int n,m,M,rt;
int newnode(int key,int cl,int cr,int fa){
	t[++M]=(tnode){key,fa,1,1};
	t[M].ch[0]=cl; t[M].ch[1]=cr;
	return M;
}
void dfs(int id){
	int cl=t[id].ch[0],cr=t[id].ch[1];
	printf("id:%d key:%d fa:%d cl:%d cr:%d sz:%d cnt:%d\n",id,t[id].key,t[id].fa,cl,cr,t[id].sz,t[id].cnt);
//	if (id==0||cl+cr==0) return;
	if (cl!=0) dfs(cl); 
	if (cr!=0) dfs(cr);
}
void update(int u){
	int cl=t[u].ch[0],cr=t[u].ch[1];
	t[u].sz=t[cl].sz+t[cr].sz+t[u].cnt;
}
void rotate(int u){
	int fa1=t[u].fa;
	int fa2=t[fa1].fa;
	int dir2=t[fa2].ch[1]==fa1,dir1=t[fa1].ch[1]==u;
	t[t[u].ch[dir1^1]].fa=fa1; t[fa1].ch[dir1]=t[u].ch[dir1^1];
	t[fa1].fa=u; t[u].ch[dir1^1]=fa1;
	t[u].fa=fa2; if (fa2!=0) t[fa2].ch[dir2]=u;
	update(fa1); update(u);
}
void splay(int u,int go){
	if (u==go) return;
//	cout<<u<<" "<<t[u].fa<<" "<<go<<endl;
	while (t[u].fa!=go){
		int fa1=t[u].fa;
		int fa2=t[fa1].fa;
		int dir2=t[fa2].ch[1]==fa1,dir1=t[fa1].ch[1]==u;
		if (fa2==go){ rotate(u); break; }
		if (fa1==go) break;
		if (dir1==dir2){ rotate(fa1); rotate(u); }
		else { rotate(u); rotate(u); }
	}
	if (t[u].fa==go) rotate(u);
	if (rt==go) rt=u;
}
void find(int key){
	int u=rt;
	while (t[u].ch[t[u].key<key]&&t[u].key!=key)
		u=t[u].ch[t[u].key<key];
	splay(u,rt);
}
void ins(int key){
//	cout<<__func__<<" "<<rt<<" "<<t[rt].key<<endl;
	int u=rt;
	while (t[u].ch[t[u].key<key]&&t[u].key!=key)
		u=t[u].ch[t[u].key<key];
	if (t[u].key==key){
		t[u].cnt++;
		splay(u,rt);
		return;
	}
//	cout<<u<<" "<<t[u].key<<endl;
	int id=newnode(key,0,0,u);
	if (rt==0) rt=id;
	else t[u].ch[t[u].key<key]=id;
//	dfs(rt); cout<<endl;
	splay(id,rt);
}
int fnex(int key,int dir){
	find(key);
//	cout<<rt<<" "<<t[rt].key<<" "<<key<<endl;
	int u=rt;
	if (t[rt].key!=key&&(t[rt].key>key)==dir) return u;
//	if (((t[rt].key>key)&&dir)||((t[rt].key<key)&&!dir)) return u;
	if (t[u].ch[dir]==0) return 0;
	u=t[u].ch[dir];
//	cout<<"in "<<t[u].key<<endl;
	while (t[u].ch[dir^1]) u=t[u].ch[dir^1];
//	cout<<"out "<<t[u].key<<endl;
	return u;
}
int fkth(int key){
	find(key);
	return t[t[rt].ch[0]].sz;
}
int fkey(int id,int rk){
	int cl=t[id].ch[0],cr=t[id].ch[1];
	int lsz=t[cl].sz;
	if (cl+cr==0) return t[id].key;
	if (lsz<rk){
		if (lsz+t[id].cnt<rk) return fkey(cr,rk-lsz-t[id].cnt);
		else return t[id].key;
	}
	else return fkey(cl,rk);
}
void del(int key){
	int pre=fnex(key,0),nxt=fnex(key,1);
	splay(pre,rt); splay(nxt,t[pre].ch[1]);
	int id=t[nxt].ch[0];
	if (t[id].cnt>1){
		t[id].cnt--;
		splay(id,rt);
		return;
	}
    t[nxt].ch[0]=0; t[id].fa=0; update(nxt);
}
int main(){
	scanf("%d",&n);
	ins(-inf); ins(inf);
	for (int i=1;i<=n;i++){
		int op,x;
//		cout<<"fuck: "<<i<<endl;
		scanf("%d%d",&op,&x);
		if (op==1) ins(x);
		if (op==2) del(x);
		if (op==3) printf("%d\n",fkth(x));
		if (op==4) printf("%d\n",fkey(rt,x+1));
		if (op==5) printf("%d\n",t[fnex(x,0)].key);
		if (op==6) printf("%d\n",t[fnex(x,1)].key);
//		dfs(rt); cout<<endl;
	}
	return 0;
}
