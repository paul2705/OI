#include<bits/stdc++.h>
namespace Super{
	using namespace std;
	#define ll long long
	#define debug(...) fprintf(stderr, __VA_ARGS__)
	#define get getchar
	//inline char get(){
	//	static char C[100000000],*l=C,*r=C;
	//	return l==r&&(r=(l=C)+fread(C,1,100000000,stdin),l==r)?EOF:*l++;
	//}
	template<typename Ty> inline void read(Ty &x) {
		x=0;int f=0;char ch=get();for(;ch<48||ch>57;ch=get())f|=ch=='-';
		for(;ch>47&&ch<58;ch=get())x=(x<<1LL)+(x<<3LL)+ch-'0';x=f?-x:x;
	}
	inline void print(int x){
		static int A[12];int Top=0;
		if(x==0){puts("0");return;}
		for(;x;x/=10)A[++Top]=x%10;
		for(;Top;putchar(A[Top--]+'0'));putchar(10);
	}
	int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
	int exgcd(int a,int b,int &x,int &y){
		if(b==0){x=1;y=0;return a;}int ret=exgcd(b,a%b,y,x);y-=a/b*x;return ret;
	}
	#define mod 19260817
	#define inf 0x3f3f3f3f
	ll Q_P(ll x,int y){
		ll R=1;for(;y;y>>=1,x=x*x%mod)if(y&1)R=R*x%mod;return R;
	}
	ll Div(ll x,ll y){return x*Q_P(y,mod-2)%mod;}
	template<typename Ty> inline int Add(Ty x,Ty y){x+=y;return x<mod?x:x-mod;}
	template<typename Ty> inline int Del(Ty x,Ty y){x-=y;return x<0?x+mod:x;}
	#define pii pair<int,int> 
	#define MP make_pair
	#define fi first
	#define se second
	template<typename Ty> inline void updmax(Ty &x,Ty y){x=x>y?x:y;}
	template<typename Ty> inline void updmin(Ty &x,Ty y){x=x<y?x:y;}
	template<typename Ty> inline int Max(Ty x,Ty y){return x>y?x:y;}
	template<typename Ty> inline int Min(Ty x,Ty y){return x<y?x:y;}
}
using namespace Super;
int n,m,col[100005],t;
vector<int> v[100005];
int head[100005],eot,deg[100005];
struct edge{
	int t,nxt;
}e[200005];
void add(int u,int v){
	e[++eot]=(edge){v,head[u]};head[u]=eot,deg[u]++;
	e[++eot]=(edge){u,head[v]};head[v]=eot,deg[v]++;
}
int fa[100005][20],dep[100005];
void dfs(int x){
	dep[x]=dep[fa[x][0]]+1;
	for(int i=1;i<=17;i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=head[x];i;i=e[i].nxt){
		if(e[i].t==fa[x][0])continue;
		fa[e[i].t][0]=x,dfs(e[i].t);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])x^=y^=x^=y;
	if(dep[x]>dep[y])for(int i=17;i>=0;i--)
		if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;for(int i=17;i>=0;i--)
		if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int dis(int x,int y){return dep[x]+dep[y]-(dep[lca(x,y)]<<1);}
int q[100005],hd,tl;bool vis[100005];
struct node{
	int u,v,c;
}a[100005];
bool dfs1(int x,int pa,int to){
	vis[x]=(x==to);
	for(int i=head[x];i;i=e[i].nxt)
		if(e[i].t!=pa&&dfs1(e[i].t,x,to))vis[x]=1;
	return vis[x];
}
bool app1,app2;int c1,c2;
bool dfs2(int x,int pa,int to){
	if(x==to){
		if(vis[x])app1|=col[x]==c1,app2|=col[x]==c2;
		return 1;
	}
	for(int i=head[x];i;i=e[i].nxt){
		if(e[i].t==pa)continue;
		if(dfs2(e[i].t,x,to)){
			if(vis[x])app1|=col[x]==c1,app2|=col[x]==c2;
			return 1;
		}
	}
	return 0;
}
struct Edge{
	int t,nxt;
}E[100005];
int Head[100005],Eot,Deg[100005];
void ADD(int u,int v){
	E[++Eot]=(Edge){v,Head[u]};Head[u]=Eot,Deg[v]++;
}
void cross(int p1,int p2){
	dfs1(a[p1].u,0,a[p1].v);
	c1=a[p1].c,c2=a[p2].c,app1=0,app2=0;
	dfs2(a[p2].u,0,a[p2].v);
	if(app1)ADD(p2,p1);
	else if(app2)ADD(p1,p2);
}
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++)
		read(col[i]),v[col[i]].push_back(i);
	for(int i=1,u,v;i<n;i++)
		read(u),read(v),add(u,v);
	for(int i=1;i<=n;i++)if(deg[i]==1)q[++tl]=i;
	dfs(1);
	for(int x,c;hd<tl;){
		x=q[++hd];if(vis[x])continue;c=col[x];int mxid=0,mx=-1;
		for(vector<int>::iterator it=v[c].begin();it!=v[c].end();it++){
			vis[(*it)]=1;int dist=dis(x,(*it));if(dist>mx)mx=dist,mxid=(*it);
		}
		a[++t]=(node){x,mxid,c};
		for(vector<int>::iterator it=v[c].begin();it!=v[c].end();it++){
			for(int i=head[(*it)];i;i=e[i].nxt)
				if(!vis[e[i].t])if((--deg[e[i].t])==1)q[++tl]=e[i].t;
		}
	}
	for(int i=1;i<t;i++)
		for(int j=i+1;j<=t;j++)cross(i,j);
	hd=tl=0;
	for(int i=1;i<=t;i++)if(!Deg[i])q[++tl]=i;
	for(int x;hd<tl;){
		x=q[++hd];printf("%d %d %d\n", a[x].c, a[x].u, a[x].v);
		for(int i=Head[x];i;i=E[i].nxt)
			if(!(--Deg[E[i].t]))q[++tl]=E[i].t;
	}
	return 0;
}
