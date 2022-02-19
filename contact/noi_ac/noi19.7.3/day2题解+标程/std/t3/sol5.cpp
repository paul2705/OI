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

namespace flow
{
	const int N=64005,M=432100;
	
	struct edge
	{
		int to,w,ne;
	}e[M*2+2];
	
	int p[N+1],p2[N+1],em=2,dep[N+1],q[N+1],qe,fl[N+1],tm[N+1],T;
	
	inline int add(int a,int b,int w)
	{
		e[em].to=b,e[em].w=w,e[em].ne=p[a],p[a]=em++;
		e[em].to=a,e[em].w=0,e[em].ne=p[b],p[b]=em++;
		return em-2;
	}
	
	bool dfs(int s,int t)
	{
		if(s==t)return 1;
		for(int&j=p2[s];j;j=e[j].ne)
			if(tm[e[j].to]!=T&&e[j].w&&dep[e[j].to]==dep[s]+1)
			{
				tm[e[j].to]=T;
				fl[e[j].to]=min(e[j].w,fl[s]);
				if(dfs(e[j].to,t))
				{
					e[j].w-=fl[t];
					e[j^1].w+=fl[t];
					return 1;
				}
			}
		dep[s]=-1;
		return 0;
	}
	
	inline int dinic(int s,int t)
	{
		int flow=0;
		while(1)
		{
			memset(dep,0,sizeof(dep));
			q[0]=s,qe=1,dep[s]=1;
			++T;
			for(int i=0;i^qe;i++)
			{
				tm[q[i]]=T;
				for(int j=p[q[i]];j;j=e[j].ne)
					if(!dep[e[j].to]&&e[j].w)
					{
						dep[e[j].to]=dep[q[i]]+1;
						q[qe++]=e[j].to;
					}
			}
			if(tm[t]!=T)break;
			for(int i=0;i^qe;i++)
				p2[q[i]]=p[q[i]];
			while(1)
			{
				fl[s]=0x7fffffff;
				++T;
				dfs(s,t);
				if(tm[t]!=T)break;
				flow+=fl[t];
			}
		}
		return flow;
	}
}

int n=600;

char buf[23333];

inline pii get()
{
	in,buf;
	std::deque<char>s(buf,buf+strlen(buf));
	while(s.size()<n*4)s.push_front('0');
	std::vector<int>re;
	fo1(i,n)if(s[i*4-1]=='1')re.pb(i);
	//out,re.size(),'\n';
	assert(re.size()==2);
	return mp(re[0],re[1]);
}

int main()
{
	freopen("data\\x5.in","r",stdin);
	freopen("data\\x5.out","w",stdout);
	int m=in;
	fo0(i,11)in,buf;
	fo1(i,m)
	{
		pii t=get();(int)in;
		assert(flow::add(t.xx,t.yy,1)==i*2);
	}
	int S=n+1,T=n+2;
	fo1(i,n/2)flow::add(S,i,1),flow::add(i+n/2,T,1);
	int fl=flow::dinic(S,T);
	//out,fl,'\n';
	fo1(i,m)if(flow::e[i*2].w==0)out,1,'\n';else out,0,'\n';
}
