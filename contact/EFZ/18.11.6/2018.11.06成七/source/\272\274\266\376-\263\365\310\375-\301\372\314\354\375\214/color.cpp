#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#define N (100010)
#define inf (0x7f7f7f7f)
#define rg register int
#define Label puts("NAIVE")
typedef long double ld;
typedef long long LL;
typedef unsigned long long ull;
using namespace std;
inline char read(){
	static const int IN_LEN=1000000;
	static char buf[IN_LEN],*s,*t;
	return (s==t?t=(s=buf)+fread(buf,1,IN_LEN,stdin),(s==t?-1:*s++):*s++);
}
template<class T>
inline void read(T &x){
	static bool iosig;
	static char c;
	for(iosig=false,c=read();!isdigit(c);c=read()){
		if(c=='-')iosig=true;
		if(c==-1)return;
	}
	for(x=0;isdigit(c);c=read())x=((x+(x<<2))<<1)+(c^'0');
	if(iosig)x=-x;
}
const int OUT_LEN = 10000000;
char obuf[OUT_LEN],*ooh=obuf;
inline void print(char c) {
	if(ooh==obuf+OUT_LEN)fwrite(obuf,1,OUT_LEN,stdout),ooh=obuf;
	*ooh++=c;
}
template<class T>
inline void print(T x){
	static int buf[30],cnt;
	if(x==0)print('0');
	else{
		if(x<0)print('-'),x=-x;
		for(cnt=0;x;x/=10)buf[++cnt]=x%10+48;
		while(cnt)print((char)buf[cnt--]);
	}
}
inline void flush(){fwrite(obuf,1,ooh-obuf,stdout);}
struct sss{
	int c,l,r;
}aans[N];
vector<int> tong[N];
int t[N],h,tail;
int fi[N],ne[N<<1],b[N<<1],E;
int cnt[N],n,m,col[N],siz[N],fa[N],q[N],son[N][2],pp[N],rr[N],dep[N];
int f[N][18];
bool vis[N],used[N];
void add(int x,int y){
	ne[++E]=fi[x],fi[x]=E,b[E]=y;
}
int ask(int x){
	return x==fa[x]?x:fa[x]=ask(fa[x]);
}
void dfs1(int u,int pre){
	for(int i=fi[u];i;i=ne[i]){
		int v=b[i];
		if(v==pre)continue;
		if(col[v]==col[u]){
			int p=ask(v),q=ask(u);
			fa[p]=q,siz[q]+=siz[p];
			if(!son[u][0])son[u][0]=v;
			else son[u][1]=v;
			pp[v]=u,rr[u]++,rr[v]++;
			//cout<<siz[q]<<" "<<col[u]<<endl;
		}
		dep[v]=dep[u]+1,f[v][0]=u;
		dfs1(v,u);
	}
}
void dfs(int u,int &rt1,int &rt2){
	vis[u]=1;
	if(rr[u]<=1){
		if(!rt1)rt1=rt2=u;else rt2=u;
	}
	for(int i=fi[u];i;i=ne[i]){
		int v=b[i];
		if(vis[v]||col[v]==col[u]||used[v])continue;
		int x=col[v];
		used[v]=1,tong[x].push_back(v);
		if(t[x]==0)t[x]=v;
		else {
			int p=ask(t[x]),r=ask(v);
			if(p==r)continue;
			fa[r]=p,siz[p]+=siz[r];
			if(siz[p]==cnt[x])q[++tail]=x;
		}
	}
	if(!vis[son[u][0]]&&son[u][0])dfs(son[u][0],rt1,rt2);
	if(!vis[son[u][1]]&&son[u][1])dfs(son[u][1],rt1,rt2);
	if(!vis[pp[u]]&&pp[u])dfs(pp[u],rt1,rt2);
}
void bz(){
	for(int j=1;j<=17;j++)
	for(int i=1;i<=n;i++)
	f[i][j]=f[f[i][j-1]][j-1];
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	int k=dep[x]-dep[y];
	for(int i=0;i<=17;i++)if(k&(1<<i))x=f[x][i];
	if(x==y)return x;
	for(int i=17;~i;i--)
	if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	return x==y?x:f[x][0];
}
int getdis(int u,int v){return dep[u]+dep[v]-2*dep[lca(u,v)];}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++)read(col[i]),cnt[col[i]]++,fa[i]=i,siz[i]=1;
	for(int i=1,x,y;i<n;i++){
		read(x),read(y);
		add(x,y),add(y,x);
	}
	dfs1(1,0),bz();
	for(int i=1;i<=n;i++){
		//cout<<siz[ask(i)]<<" "<<col[i]<<" "<<cnt[col[i]]<<endl;
		if(siz[ask(i)]==cnt[col[i]]){
			//if(vis[col[i]])continue;
			q[++tail]=col[i],used[i]=1;
			//Label;
			tong[col[i]].push_back(ask(i));
		}
	}
	int ff=m;
	while(h<tail){
		int c=q[++h];
		if(vis[c])continue;
		vis[c]=1;
		int L,R,len;
		for(int i=0;i<tong[c].size();i++){
			int x=0,y=0;
			dfs(tong[c][i],x,y);
			if(!i)L=x,R=y,len=getdis(x,y);
			else {
				int tmpl=L,tmpr=R,v;
				if((v=getdis(L,x))>len)len=v,tmpl=L,tmpr=x;
				if((v=getdis(L,y))>len)len=v,tmpl=L,tmpr=y;
				if((v=getdis(R,x))>len)len=v,tmpl=R,tmpr=x;
				if((v=getdis(R,y))>len)len=v,tmpl=R,tmpr=y;
				L=tmpl,R=tmpr;
			}
		}
		aans[ff].c=c,aans[ff].l=L,aans[ff--].r=R;
		//printf("%d %d %d wcnm\n",c,L,R);
	}
	for(int i=1;i<=m;i++)
	printf("%d %d %d\n",aans[i].c,aans[i].l,aans[i].r);
}
