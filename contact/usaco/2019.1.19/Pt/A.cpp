#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=3e5+5;
const int inf=1e8;
struct tnode{
	int key,fa,cnt,sz,mn,smn;
	int ch[2];
	vector<int> ls;
	int mymin(){ return min(mn,smn); }
} t[MAXN];
int n,k,M,rt;
int cnt[3],a[MAXN],f[MAXN],s[MAXN];
int newnode(int key,int dat,int cl,int cr,int fa){
	t[++M]=(tnode){key,fa,1,1,inf,dat};
	t[M].ls.push_back(dat);
	t[M].ch[0]=cl; t[M].ch[1]=cr;
	return M;
}
void dfs(int id){
	int cl=t[id].ch[0],cr=t[id].ch[1];
	printf("id:%d key:%d fa:%d cl:%d cr:%d sz:%d cnt:%d mn:%d\n",id,t[id].key,t[id].fa,cl,cr,t[id].sz,t[id].cnt,t[id].mn);
//	if (id==0||cl+cr==0) return;
	if (cl!=0) dfs(cl);
	if (cr!=0) dfs(cr);
}
void update(int u){
	int cl=t[u].ch[0],cr=t[u].ch[1];
	t[u].sz=t[cl].sz+t[cr].sz+t[u].cnt;
	t[0].mn=inf;
//	cout<<t[u].key<<" "<<t[u].mn<<" "<<t[cl].key<<" "<<t[cr].key<<endl;
	t[u].mn=min(t[cl].mymin(),t[cr].mymin());
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
void ins(int key,int dat){
	int u=rt;
	while (t[u].ch[t[u].key<key]&&t[u].key!=key)
		u=t[u].ch[t[u].key<key];
	if (t[u].key==key){
		t[u].cnt++; t[u].ls.push_back(dat);
		t[u].smn=min(t[u].smn,dat);
		splay(u,rt);
		return;
	}
	int id=newnode(key,dat,0,0,u);
	if (rt==0) rt=id;
	else t[u].ch[t[u].key<key]=id;
	splay(id,rt);
}
int fnex(int key,int dir){
	find(key);
	int u=rt;
	if (t[rt].key!=key&&(t[rt].key>key)==dir) return u;
	if (t[u].ch[dir]==0) return 0;
	u=t[u].ch[dir];
	while (t[u].ch[dir^1]) u=t[u].ch[dir^1];
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
void del(int key,int dat){
	int pre=fnex(key,0),nxt=fnex(key,1);
	splay(pre,rt); splay(nxt,t[pre].ch[1]);
	int id=t[nxt].ch[0];
	if (t[id].cnt>1){
		t[id].cnt--;
		int mnn=1e9;
		for (int i=0;i<t[id].ls.size();i++){
			int x=t[id].ls[i];
			if (x==dat){
				t[id].ls[i]=inf;
				break;
			}
		}
		for (int i=0;i<t[id].ls.size();i++){
			int x=t[id].ls[i];
			mnn=min(mnn,x);
		}
		t[id].smn=mnn;
		splay(id,rt);
		return;
	}
	t[nxt].ch[0]=0; t[id].fa=0; update(nxt);
}
int main(){
	freopen("redistricting.in","r",stdin);
	freopen("redistricting.out","w",stdout);
	t[0].mn=t[0].smn=inf;
	ins(-inf,inf); ins(inf,inf);
	scanf("%d%d",&n,&k);
	int cntg=0;
	for (int i=1;i<=n;i++){
		char c=getchar(); while (c!='G'&&c!='H') c=getchar();
		a[i]=(c=='H'?1:-1);
		s[i]=s[i-1]+a[i];
		f[i]=inf;
		cntg+=(c=='G');
	}
//	if (k==1){
///		printf("%d\n",cntg);
//		fclose(stdin); fclose(stdout);
//		return 0;
//	}
	f[1]=a[1]==-1;
	ins(s[1],f[1]);
//	printf("%d %d %d\n",1,s[1],f[1]);
	for (int i=2;i<=n;i++){
//		dfs(rt);
		if (i<=k) f[i]=(s[i]<=0);
//		cout<<f[i]<<endl;
		int id=fnex(s[i],0);
//		cout<<id<<endl;
		if (id==0) f[i]=min(f[i],t[rt].mymin()+1);
		else f[i]=min(f[i],t[t[rt].ch[1]].mymin()+1);
		find(s[i]);
//		cout<<f[i]<<endl;
//		cout<<t[t[rt].ch[0]].key<<" "<<t[t[rt].ch[0]].mymin()<<" "<<t[rt].mn<<endl;
		if (t[rt].key==s[i]) f[i]=min(f[i],t[t[rt].ch[0]].mymin());
		else{
			id=fnex(s[i],1);
			if (id!=0) f[i]=min(f[i],t[t[rt].ch[0]].mymin());
			else f[i]=min(f[i],t[rt].mymin());
		}
//		cout<<f[i]<<endl;
		if (i>k) del(s[i-k],f[i-k]); 
		ins(s[i],f[i]);
//		printf("%d %d %d\n",i,s[i],f[i]);
	}
	printf("%d\n",f[n]);
	fclose(stdin); fclose(stdout);
	return 0;
}
