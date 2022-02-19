#include<bits/stdc++.h>

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double llf;
typedef std::pair<int,int> pii;

#define xx first
#define yy second

template<typename T> inline T max(T a,T b){return a>b?a:b;}
template<typename T> inline T min(T a,T b){return a<b?a:b;}
template<typename T> inline T abs(T a){return a>0?a:-a;}
template<typename T> inline bool repr(T &a,T b){return a<b?a=b,1:0;}
template<typename T> inline bool repl(T &a,T b){return a>b?a=b,1:0;}
template<typename T> inline T gcd(T a,T b){T t;if(a<b){while(a){t=a;a=b%a;b=t;}return b;}else{while(b){t=b;b=a%b;a=t;}return a;}}
template<typename T> inline T sqr(T x){return x*x;}
#define mp(a,b) std::make_pair(a,b)
#define pb push_back
#define I __attribute__((always_inline))inline
#define mset(a,b) memset(a,b,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))

#define fo0(i,n) for(int i=0,i##end=n;i<i##end;i++)
#define fo1(i,n) for(int i=1,i##end=n;i<=i##end;i++)
#define fo(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define fd0(i,n) for(int i=(n)-1;~i;i--)
#define fd1(i,n) for(int i=n;i;i--)
#define fd(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define foe(i,x)for(__typeof((x).end())i=(x).begin();i!=(x).end();++i)
#define fre(i,x)for(__typeof((x).rend())i=(x).rbegin();i!=(x).rend();++i)

struct Cg{I char operator()(){return getchar();}};
struct Cp{I void operator()(char x){putchar(x);}};
#define OP operator
#define RT return *this;
#define UC unsigned char
#define RX x=0;UC t=P();while((t<'0'||t>'9')&&t!='-')t=P();bool f=0;\
if(t=='-')t=P(),f=1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define RL if(t=='.'){lf u=0.1;for(t=P();t>='0'&&t<='9';t=P(),u*=0.1)x+=u*(t-'0');}if(f)x=-x
#define RU x=0;UC t=P();while(t<'0'||t>'9')t=P();x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define TR *this,x;return x;
I bool IS(char x){return x==10||x==13||x==' ';}template<typename T>struct Fr{T P;I Fr&OP,(int&x)
{RX;if(f)x=-x;RT}I OP int(){int x;TR}I Fr&OP,(ll &x){RX;if(f)x=-x;RT}I OP ll(){ll x;TR}I Fr&OP,(char&x)
{for(x=P();IS(x);x=P());RT}I OP char(){char x;TR}I Fr&OP,(char*x){char t=P();for(;IS(t);t=P());if(~t){for(;!IS
(t)&&~t;t=P())*x++=t;}*x++=0;RT}I Fr&OP,(lf&x){RX;RL;RT}I OP lf(){lf x;TR}I Fr&OP,(llf&x){RX;RL;RT}I OP llf()
{llf x;TR}I Fr&OP,(uint&x){RU;RT}I OP uint(){uint x;TR}I Fr&OP,(ull&x){RU;RT}I OP ull(){ull x;TR}};Fr<Cg>in;
#define WI(S) if(x){if(x<0)P('-'),x=-x;UC s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
#define WL if(y){lf t=0.5;for(int i=y;i--;)t*=0.1;if(x>=0)x+=t;else x-=t,P('-');*this,(ll)(abs(x));P('.');if(x<0)\
x=-x;while(y--){x*=10;x-=floor(x*0.1)*10;P(((int)x)%10+'0');}}else if(x>=0)*this,(ll)(x+0.5);else *this,(ll)(x-0.5);
#define WU(S) if(x){UC s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
template<typename T>struct Fw{T P;I Fw&OP,(int x){WI(10);RT}I Fw&OP()(int x){WI(10);RT}I Fw&OP,(uint x){WU(10);RT}
I Fw&OP()(uint x){WU(10);RT}I Fw&OP,(ll x){WI(19);RT}I Fw&OP()(ll x){WI(19);RT}I Fw&OP,(ull x){WU(20);RT}I Fw&OP()
(ull x){WU(20);RT}I Fw&OP,(char x){P(x);RT}I Fw&OP()(char x){P(x);RT}I Fw&OP,(const char*x){while(*x)P(*x++);RT}
I Fw&OP()(const char*x){while(*x)P(*x++);RT}I Fw&OP()(lf x,int y){WL;RT}I Fw&OP()(llf x,int y){WL;RT}};Fw<Cp>out;

const int N=100007,inf=1e9;

struct node
{
	int min_value,min_count,add_tag;
	int min_tag,min_tag_count;
	int history_min_value;ll history_min_count;
	int recover_time;
}f[262333];

std::pair<int,node>recover[N*100];

int enable_recover,recover_size;

inline void add_recover(int x)
{
	if(enable_recover&&f[x].recover_time!=enable_recover)
	{
		recover[recover_size++]=mp(x,f[x]);
		f[x].recover_time=enable_recover;
	}
}

inline void merge(const node&a,const node&b,node&res)
{
	if(a.min_value<b.min_value)res.min_value=a.min_value,res.min_count=a.min_count;
	else if(a.min_value>b.min_value)res.min_value=b.min_value,res.min_count=b.min_count;
	else res.min_value=a.min_value,res.min_count=a.min_count+b.min_count;
	if(a.history_min_value<b.history_min_value)res.history_min_value=a.history_min_value,res.history_min_count=a.history_min_count;
	else if(a.history_min_value>b.history_min_value)res.history_min_value=b.history_min_value,res.history_min_count=b.history_min_count;
	else res.history_min_value=a.history_min_value,res.history_min_count=a.history_min_count+b.history_min_count;
}

inline void settag(node&a,int add_tag,int min_tag,int min_tag_count)
{
	int tmp_min_tag=a.add_tag+min_tag;
	if(tmp_min_tag<a.min_tag)a.min_tag=tmp_min_tag,a.min_tag_count=0;
	if(tmp_min_tag==a.min_tag)a.min_tag_count+=min_tag_count;
	int tmp_min_value=a.min_value+min_tag;
	if(tmp_min_value<a.history_min_value)a.history_min_value=tmp_min_value,a.history_min_count=0;
	if(tmp_min_value==a.history_min_value)a.history_min_count+=(ll)min_tag_count*a.min_count;
	a.min_value+=add_tag;
	a.add_tag+=add_tag;
}

inline void pushdown(node&a,node&lc,node&rc,int x)
{
	if(a.min_tag_count||a.add_tag)
	{
		add_recover(x<<1);
		add_recover(x<<1|1);
		settag(lc,a.add_tag,a.min_tag,a.min_tag_count);
		settag(rc,a.add_tag,a.min_tag,a.min_tag_count);
		a.add_tag=0;
		a.min_tag=0;
		a.min_tag_count=0;
	}
}

//add v to [ql,qr]
inline void modify(int x,int l,int r,int ql,int qr,int v)
{
	//out,"modify:",x,' ',l,' ',r,' ',ql,' ',qr,' ',v,'\n';
	add_recover(x);
	if(l>=ql&&r<=qr)
	{
		return settag(f[x],v,v,1);
	}
	int t=(l+r)>>1;pushdown(f[x],f[x<<1],f[x<<1|1],x);
	if(ql<=t)modify(x<<1,l,t,ql,qr,v);
	if(qr>t)modify(x<<1|1,t+1,r,ql,qr,v);
	merge(f[x<<1],f[x<<1|1],f[x]);
}

std::pair<int,ll>query_result;

inline void _query(int x,int l,int r,int ql,int qr)
{
	//out,"query:",x,' ',l,' ',r,' ',ql,' ',qr,'\n';
	if(l>=ql&&r<=qr)
	{
		if(f[x].history_min_value<query_result.xx)query_result=mp(f[x].history_min_value,0);
		if(f[x].history_min_value==query_result.xx)query_result.yy+=f[x].history_min_count;
		return;
	}
	add_recover(x);
	int t=(l+r)>>1;pushdown(f[x],f[x<<1],f[x<<1|1],x);
	if(ql<=t)_query(x<<1,l,t,ql,qr);
	if(qr>t)_query(x<<1|1,t+1,r,ql,qr);
}

//return history min of [ql,qr]
inline std::pair<int,ll> query(int x,int l,int r,int ql,int qr)
{
	query_result=mp(1e9,0);
	_query(x,l,r,ql,qr);
	return query_result;
}

//set all to 0
inline void build(int x,int l,int r)
{
	f[x].min_value=inf;
	f[x].min_count=r-l+1;
	f[x].history_min_value=inf;
	f[x].history_min_count=r-l+1;
	if(l!=r)
	{
		int t=(l+r)>>1;
		build(x<<1,l,t);
		build(x<<1|1,t+1,r);
	}
}

std::vector<int>pa[N],pb[N],q[N];
std::vector<pii>qt[N];
int n,m,idm,fa[N],dep[N],sz[N],ws[N],top[N],id[N],idr[N],u[N],v[N];
ll ans[N];
bool vis[N];

inline void dfs(int x)
{
	sz[x]=1;int y=0;
	foe(i,pa[x])if(*i!=fa[x])
	{
		fa[*i]=x;
		dep[*i]=dep[x]+1;
		dfs(*i);
		sz[x]+=sz[*i];
		if(repr(y,sz[*i]))ws[x]=*i;
	}
}

inline void dfs2(int x,int to)
{
	top[x]=to;
	id[x]=++idm;
	if(ws[x])dfs2(ws[x],to);
	foe(i,pa[x])if(*i!=fa[x]&&*i!=ws[x])
		dfs2(*i,*i);
	idr[x]=idm;
}

inline int lca(int a,int b)
{
	while(top[a]!=top[b])
	{
		if(dep[top[a]]<dep[top[b]])b=fa[top[b]];
		else a=fa[top[a]];
	}
	if(dep[a]<dep[b])return a;
	return b;
}

inline ll query(int l,int r)
{
	std::pair<int,ll>tmp=query(1,1,n,l,r);
	//out,"query:",l,' ',r,' ',tmp.xx,' ',tmp.yy,'\n';
	if(tmp.xx==1)return tmp.yy;
	return 0;
}

inline ll query_link(int x,int y,bool type)
{
	ll res=0;
	while(top[x]!=top[y])
	{
		res+=query(id[top[x]],id[x]);
		x=fa[top[x]];
	}
	if(type)res+=query(id[y],id[x]);
	else if(x!=y)res+=query(id[y]+1,id[x]);
	return res;
}

inline void modify(int l,int r,int v)
{
	//out,"modify:",l,' ',r,' ',v,'\n';
	modify(1,1,n,l,r,v);
}

inline void work_subtree(int x,int rt)
{
	//out,"work_subtree:",x,' ',rt,'\n';
	enable_recover++;
	int old_recover_size=recover_size;
	vis[x]=1;
	modify(id[rt],idr[rt],1);
	foe(i,pb[x])
	{
		if(vis[*i])modify(id[rt],idr[rt],-1);
		else if(id[*i]>=id[rt]&&id[*i]<=idr[rt])
			modify(id[*i],idr[*i],-1);
	}
	foe(i,qt[x])
	{
		//out,'$',i->xx,' ',rt,' ',id[i->xx],' ',id[rt],'\n';
		//out,'%',query_link(i->xx,rt),' ',query(id[rt],id[rt]),'\n';
		//ans[i->yy]+=query_link(i->xx,rt)-query(id[rt],id[rt]);
		ans[i->yy]+=query_link(i->xx,rt,0);
	}
	foe(i,pa[x])if(*i!=fa[x])work_subtree(*i,rt);
	while(recover_size>old_recover_size)
	{
		recover_size--;
		f[recover[recover_size].xx]=recover[recover_size].yy;
	}
	vis[x]=0;
	enable_recover--;
}

inline void work(int x)
{
	foe(i,pa[x])if(*i!=fa[x])work(*i);
	//out,"work:",x,'\n';
	modify(id[x],id[x],1-inf);
	if(id[x]!=idr[x])modify(id[x]+1,idr[x],1);
	//modify(id[x],idr[x],0);
	foe(i,pb[x])if(id[*i]>=id[x]&&id[*i]<=idr[x])
		modify(id[*i],idr[*i],-1);
	foe(i,q[x])
	{
		int a=u[*i],b=v[*i];
		if(id[a]>id[b])std::swap(a,b);
		//out,'/',x,' ',a,' ',b,'\n';
		if(a==x)ans[*i]=query_link(b,x,1);
		else
		{
			ans[*i]=query_link(b,x,1);
			//out,'@',ans[*i],'\n';
			qt[b].pb(mp(a,*i));
		}
	}
	//out,"===",query(4,4),'\n';
	//fo1(i,3)out,query(i,i),' ';out,'\n';
	//fo1(i,3)out,f[4].history_min_value,' ';out,'\n';
	foe(i,pa[x])if(*i!=fa[x]&&*i!=ws[x])
		work_subtree(*i,x);
	foe(i,q[x])
	{
		int a=u[*i],b=v[*i];
		qt[a].clear(),qt[b].clear();
	}
}

int main()
{
	in,n,m;
	fo1(i,n-1)
	{
		int x,y;
		in,x,y;
		pa[x].pb(y);
		pa[y].pb(x);
	}
	fo1(i,n-1)
	{
		int x,y;
		in,x,y;
		pb[x].pb(y);
		pb[y].pb(x);
	}
	dfs(1);
	dfs2(1,1);
	fo1(i,m)
	{
		in,u[i],v[i];
		q[lca(u[i],v[i])].pb(i);
	}
	build(1,1,n);
	work(1);
	fo1(i,m)out,ans[i],'\n';
}
