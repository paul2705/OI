#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> par;
const int inf=1e9;
const int MAXN=2e5+5;
int n,m,a[MAXN];
struct tnode{
	int dat,fa,sz,mx;
	int ch[3];
} t[MAXN];
int M,rt;
set<par > bl;
bool ismx[MAXN];
void update(int id){
	t[0].mx=t[0].dat=-inf; t[0].sz=0;
	int cl=t[id].ch[0],cr=t[id].ch[1];
	t[id].mx=max(t[id].dat,max(t[cl].mx,t[cr].mx));
	t[id].sz=t[cl].sz+t[cr].sz+1;
}
void rotate(int id){
	int f1=t[id].fa;
	int f2=t[f1].fa;
	int dir1=t[f1].ch[1]==id;
	int dir2=t[f2].ch[1]==f1;
	int w=t[id].ch[dir1^1];
	t[w].fa=f1; t[f1].ch[dir1]=w;
	t[id].ch[dir1^1]=f1; t[f1].fa=id;
	t[id].fa=f2; t[f2].ch[dir2]=id;
	update(f1); update(id);
}
void splay(int u,int go){
	if (u==go) return;
	while (t[u].fa!=go){
		int f1=t[u].fa;
		int f2=t[f1].fa;
		int dir1=t[f1].ch[1]==u;
		int dir2=t[f2].ch[1]==f1;
		if (f2==go){ rotate(u); break; }
		if (dir1==dir2) rotate(f1);
		else rotate(u);
		rotate(u);
	}
	if (go==0) rt=u;
}
int rnk(int u){
	splay(u,0);
	return t[t[u].ch[0]].sz+1;
}
int num(int u,int rk){
	int cl=t[u].ch[0],cr=t[u].ch[1];
	int lsz=t[cl].sz;
	if (!cl&&!cr) return u;
	if (rk<=lsz) return num(cl,rk);
	else if (rk>lsz+1) return num(cr,rk-lsz-1);
	else return u;
}
int Gmx(int u){
	while (t[u].ch[1]){
//		cout<<u<<" "<<t[u].ch[1]<<endl;
		u=t[u].ch[1];
	}
	splay(u,0);
	return u;
}
int merge(int x,int y){
	if (!x||!y) return x+y;
	splay(x,0);
	int xmx=Gmx(x);
	t[xmx].ch[1]=y; t[y].fa=xmx;
	update(xmx);
	return xmx;
}
int nxt_mx(int l,int x){
	splay(l,0);
	int u=t[l].ch[1];
	while (u){
		if (t[t[u].ch[0]].mx>x) u=t[u].ch[0];
		else if (t[u].dat>x) break;
		else if (t[t[u].ch[1]].mx>x) u=t[u].ch[1];
		else break;
	}
	if (t[u].dat>x) return u;
}
int Gbl(int l,int r){ // pre,[l,r),nxt
	int pre,nxt=r;
	splay(r,0);
	pre=t[r].ch[0]; t[pre].fa=t[r].ch[0]=0; update(r);
	splay(l,0);
	pre=t[l].ch[0]; t[l].ch[0]=t[pre].fa=0; update(l);
//	cout<<"get"<<endl;
	merge(pre,nxt);
//	cout<<"exit"<<endl;
	return l;
}
void prt(int id){
	if (t[id].ch[0]) prt(t[id].ch[0]);
	printf("id:%d fa:%d dat:%d sz:%d mx:%d\n",id,t[id].fa,t[id].dat,t[id].sz,t[id].mx);
	if (t[id].ch[1]) prt(t[id].ch[1]);
}
void myprt(){
	printf("---------prt--------\n");
	prt(rt);
	printf("--------------------\n");
}
vector<int> newbl;
int main(){
//	freopen("B.in","r",stdin);
//	freopen("B.out","w",stdout);
	scanf("%d%d",&n,&m);
	int mx=0; rt=n+1; t[0].mx=t[0].dat=-inf;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		t[i].ch[0]=i-1; t[i].dat=a[i]; 
		t[i].fa=i+1;
		update(i);
		mx=max(mx,a[i]);
		if (mx==a[i]){
			ismx[i]=1;
//			cout<<a[i]<<" "<<i<<endl;
			bl.insert(make_pair(a[i],i));
		}
	}
	t[n+1].dat=inf; t[n+1].ch[0]=n; update(n+1);
//	myprt();
	for (int i=1;i<=m;i++){
//		cout<<i<<endl;
		int op; scanf("%d",&op);
		if (op==2){
			int x; scanf("%d",&x);
//			cout<<"out"<<endl;
			int id=num(rt,x);
//			cout<<"out"<<endl;
			printf("%d\n",t[id].dat);
		}
		else {
			newbl.clear();
			int l,m,r; scanf("%d%d%d",&l,&m,&r);
//			cout<<"in"<<endl;
			int pos=num(rt,m+1);
//			cout<<"in"<<endl;
			while (!ismx[pos]){
				newbl.push_back(pos);
				pos=nxt_mx(pos,t[pos].dat);
//				cout<<pos<<" "<<t[pos].dat<<endl;
				if (rnk(pos)>r){
					newbl.push_back(num(rt,r+1));
					break;
				}
				else if (ismx[pos]){
					newbl.push_back(pos);
					break;
				}
			}
//			cout<<"done"<<endl;
//			newbl.push_back(r+1);
			for (int i=0;i+1<newbl.size();i++){
				int pos=newbl[i];
//				cout<<pos<<" "<<t[pos].dat<<endl;
				par Bp=*bl.lower_bound(make_pair(t[pos].dat,0));
				int nrt=Gbl(pos,newbl[i+1]);
				int u=Bp.second;
//				cout<<Bp.first<<" "<<Bp.second<<" "<<pos<<" "<<newbl[i+1]<<endl;
				splay(u,0);
				int w=t[u].ch[0];
//				cout<<w<<" "<<t[w].dat<<" "<<u<<" "<<t[u].dat<<endl;
				t[w].fa=t[u].ch[0]=0; update(u);
				w=merge(w,nrt); 
				t[u].ch[0]=w; t[w].fa=u; update(u);
				rt=u;
			}
//			cout<<"fuck"<<endl;
			for (int i=0;i+1<newbl.size();i++){
				int pos=newbl[i];
				bl.insert(par(t[pos].dat,pos));
				ismx[pos]=1;
			}
		}
//		myprt();
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
