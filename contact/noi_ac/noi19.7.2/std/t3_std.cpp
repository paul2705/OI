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

#define BSZ 131072
struct Cg{char t[BSZ+1],*o,*e;Cg(){e=o=t+BSZ;}I char operator()(){if(o==e)fread(o=t,1,BSZ,stdin);return *o++;}};
struct Cp{char t[BSZ+1],*o,*e;Cp(){e=(o=t)+BSZ;}I void operator()(char p){if(o==e)fwrite(o=t,1,BSZ,stdout);*o++=p;}~Cp(){fwrite(t,1,o-t,stdout);}};
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

const int N=300007,M=20;
const ll inf=1e18;

typedef std::pair<ll,int>pli;
typedef std::pair<int,ll>pil;

template<typename T,typename V=std::vector<T>,typename C=std::less<T> >struct heap
{
	std::priority_queue<T,V,C>q,d;
	inline void push(const T&a){q.push(a);}
	inline void erase(const T&a){d.push(a);}
	inline void proc(){while(!d.empty()&&q.top()==d.top())q.pop(),d.pop();}
	inline const T&top(){proc();return q.top();}
	inline void pop(){proc();q.pop();}
	inline bool empty(){proc();return q.empty();}
	inline int size(){return q.size()-d.size();}
};

heap<pli,std::vector<pli>,std::greater<pli>>fs[N*2];
//std::vector<pli>fs[N*2];
int fsc;

struct node
{
	ll mi,tag,sum;
	int pi,cnt;
}fp[N*(M+1)*4],*fe=fp;

pil pops[N];
int pc;
ll sumall;

//int CNT1,CNT2;

struct segi
{
	node*f;
	int nc;
	
	inline void build(int x,int l,int r)
	{
		repr(nc,x);
		if(l==r)return;
		int t=(l+r)>>1;
		build(x<<1,l,t);
		build(x<<1|1,t+1,r);
	}
	
	inline void init(int n)
	{
		f=fe-1;
		build(1,1,n);
		fe+=nc;
		nc=n;
	}
	
	inline void pu(int x)
	{
		f[x].mi=f[x].tag+min(f[x<<1].mi,f[x<<1|1].mi);
		f[x].cnt=f[x<<1].cnt+f[x<<1|1].cnt;
		f[x].sum=f[x<<1].sum+f[x<<1|1].sum+f[x].cnt*f[x].tag;
	}
	
	inline ll ins(int x,int l,int r,int p,ll v,int id)
	{
		//CNT1++;
		v-=f[x].tag;
		if(l!=r)
		{
			int t=(l+r)>>1;ll re;
			if(p<=t)re=ins(x<<1,l,t,p,v,id);
			else re=ins(x<<1|1,t+1,r,p,v,id);
			return pu(x),re;
		}
		//CNT2++;
		if(!f[x].pi)f[x].pi=++fsc;
		fs[f[x].pi].push(mp(v,id));
		//fs[f[x].pi].pb(mp(v,id));
		f[x].cnt++;
		f[x].sum+=v+f[x].tag;
		f[x].mi=fs[f[x].pi].top().xx+f[x].tag;
		//assert(fs[f[x].pi].size()==f[x].cnt);
		return v;
	}
	
	inline ll ins(int p,ll v,int id)
	{
		sumall-=f[1].sum;
		ll res=ins(1,1,nc,p,v,id);
		sumall+=f[1].sum;
		return res;
	}
	
	inline void popmi(int x,int l,int r,ll v)
	{
		//out,"popmi:",x,' ',l,' ',r,' ',v,' ',f[x].mi,' ',f[x].mi+v,' ',f[x].cnt,'\n';
		if(f[x].mi+v>=0)return;
		v+=f[x].tag;
		if(l!=r)
		{
			int t=(l+r)>>1;
			popmi(x<<1,l,t,v);
			popmi(x<<1|1,t+1,r,v);
			return pu(x);
		}
		auto&t=fs[f[x].pi];
		//auto&t=fs[f[x].pi];
		while(t.size())
		{
			auto&e=t.top();
			//auto e=--t.end();
			if(e.xx+v>=0)break;
			pops[pc++]=mp(e.yy,e.xx+v);
			f[x].cnt--,f[x].sum-=e.xx+f[x].tag;
			t.pop();
			//t.pop_back();
		}
		if(!t.size())f[x].mi=inf;
		else f[x].mi=t.top().xx+f[x].tag;
		//assert(fs[f[x].pi].size()==f[x].cnt);
	}
	
	inline ll del(int x,int l,int r,int p,ll v,int id)
	{
		if(l!=r)
		{
			int t=(l+r)>>1;ll re;
			if(p<=t)re=del(x<<1,l,t,p,v,id);
			else re=del(x<<1|1,t+1,r,p,v,id);
			return pu(x),re+f[x].tag;
		}
		fs[f[x].pi].erase(mp(v,id));
		//fs[f[x].pi].pop_back();
		f[x].cnt--;
		f[x].sum-=v+f[x].tag;
		if(!fs[f[x].pi].size())f[x].mi=inf;
		else f[x].mi=fs[f[x].pi].top().xx+f[x].tag;
		//assert(fs[f[x].pi].size()==f[x].cnt);
		return v+f[x].tag;
	}
	
	inline ll del(int p,ll v,int id)
	{
		sumall-=f[1].sum;
		ll res=del(1,1,nc,p,v,id);
		sumall+=f[1].sum;
		return res;
	}
	
	inline void add(int x,int l,int r,int ql,int qr,ll v,ll tv)
	{
		if(!x)return;
		if(l>=ql&&r<=qr)
		{
			f[x].mi+=v,f[x].tag+=v,f[x].sum+=f[x].cnt*v;
			return popmi(x,l,r,tv);
		}
		tv+=f[x].tag;
		int t=(l+r)>>1;
		if(ql<=t)add(x<<1,l,t,ql,qr,v,tv);
		if(qr>t)add(x<<1|1,t+1,r,ql,qr,v,tv);
		pu(x);
	}
	
	inline void add(int ql,int qr,ll v)
	{
		sumall-=f[1].sum;
		add(1,1,nc,ql,qr,v,0);
		sumall+=f[1].sum;
	}
}f[N];

std::vector<int>p[N];
int n,m,qc,rdc,type,cl,cro,idm,nro,rsz,nsz,px[N],py[N],rds[N],sz[N],rt[M][N],id[M][N],idr[M][N];
ll sx[N],sy[N];
bool vis[N];

inline void dfs1(int x,int fa)
{
	sz[x]=1;
	foe(i,p[x])if(*i!=fa&&!vis[*i])
		dfs1(*i,x),sz[x]+=sz[*i];
}

inline void dfs2(int x,int fa)
{
	int y=rsz-sz[x];
	foe(i,p[x])if(*i!=fa&&!vis[*i])
		dfs2(*i,x),repr(y,sz[*i]);
	if(repl(nsz,y))nro=x;
}

inline void dfs3(int x,int fa)
{
	rt[cl][x]=cro;
	id[cl][x]=++idm;
	foe(i,p[x])if(*i!=fa&&!vis[*i])
		dfs3(*i,x);
	idr[cl][x]=idm;
}

inline void work(int x,int l)
{
	dfs1(x,0);
	rsz=nsz=sz[nro=x];
	dfs2(x,0);
	vis[x=nro]=1;
	cro=x,cl=l,idm=0;
	dfs3(x,0);
	f[x].init(idm);
	foe(i,p[x])if(!vis[*i])
		work(*i,l+1);
}

inline void addl(int qi,int w)
{
	//out,"addl:",qi,' ',w,'\n';
	int x=px[qi],y=py[qi];
	/*if(x==y)
	{
		sx[qi]=f[x].ins(1,w,qi<<1);
		return;
	}*/
	int w1=w>>1,w2=w-w1;
	//int w1=w*.618,w2=w-w1;
	//int w1=ran()%(w+1),w2=w-w1;
	int i=0;
	while(i<M&&rt[i][x]&&rt[i][x]==rt[i][y])i++;
	i--;
	int r=rt[i][x];
	sx[qi]=f[r].ins(id[i][x],w1,qi<<1);
	//out,"ins:",r,' ',id[i][x],' ',w1,' ',qi<<1,' ',sx[qi],'\n';
	sy[qi]=f[r].ins(id[i][y],w2,qi<<1|1);
	//out,"ins:",r,' ',id[i][y],' ',w2,' ',qi<<1|1,' ',sy[qi],'\n';
}

inline void dell(ll w,int qt)
{
	int qi=qt>>1,x=px[qi],y=py[qi];
	/*if(x==y)
	{
		assert(w<0);
		rds[rdc++]=qi;
		return;
	}*/
	int i=0;
	while(i<M&&rt[i][x]&&rt[i][x]==rt[i][y])i++;
	i--;
	int r=rt[i][x];
	if(qt&1)
	{
		w+=f[r].del(id[i][x],sx[qi],qi<<1);
	}
	else
	{
		w+=f[r].del(id[i][y],sy[qi],qi<<1|1);
	}
	//out,"dell:",qi,' ',w,' ',qt,'\n';
	if(w<0)
	{
		rds[rdc++]=qi;
		return;
	}
	addl(qi,w);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	in,n,m,type;
	fo1(i,n-1)
	{
		int x,y;
		in,x,y;
		p[x].pb(y);
		p[y].pb(x);
	}
	work(1,0);
	//fprintf(stderr,"%d\n",clock());
	while(m--)
	{
		int op,x,y,w;
		in,op,x,y;
		ll tsa=sumall>>1;
		if(type)x=(x+tsa)%n+1,y=(y+tsa)%n+1;
		if(op==1)
		{
			in,w;
			if(type)w=(w+tsa)%n+1;
			++qc,px[qc]=x,py[qc]=y;
			addl(qc,w<<1);
		}
		else
		{
			w=y;
			pc=0;
			for(int i=0;i<M&&rt[i][x];i++)
			{
				if(rt[i][x]==x)f[x].add(1,f[x].nc,-w);
				else f[rt[i][x]].add(id[i][x],idr[i][x],-w*2);
				//out,"add:",rt[i][x],' ',id[i][x],' ',idr[i][x],' ',rt[i][x]==x?-w:-w*2,'\n';
			}
			std::sort(pops,pops+pc);
			//fo0(i,pc)out,'(',pops[i].xx,',',pops[i].yy,')',' ';out,'\n';
			rdc=0;
			for(int i=0;i<pc;i++)
			{
				if(i+1<pc&&(pops[i].xx^pops[i+1].xx)==1)
				{
					ll nv=pops[i].yy+pops[i+1].yy;
					if(nv>=0)addl(pops[i].xx>>1,nv);
					else rds[rdc++]=pops[i].xx>>1;
					i++;
				}
				else dell(pops[i].yy,pops[i].xx);
			}
			std::sort(rds,rds+rdc);
			//out,'@',sumall,' ',f[2].f[1].sum,' ',f[2].f[1].cnt,'\n';
			out,sumall>>1,' ',rdc;
			fo0(i,rdc)out,' ',rds[i];
			out,'\n';
		}
	}
	//fprintf(stderr,"%d\n",clock());
	//fprintf(stderr,"%d %d\n",CNT1,CNT2);
}
