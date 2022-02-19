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

const int N=505;

int n,m,bc,ac,cid,cnt,vt[N*N],id[N][N];
char s[N][N],r[N][N],buf[N*(N+5)*3];
bool rev;

inline void add(bool isadd)
{
	ac++;
	if(isadd)buf[bc++]='+';else buf[bc++]='-';
	buf[bc++]='\n';
	if(rev)
	{
		fo1(i,m){fo1(j,n)buf[bc++]=r[j][i]+48;buf[bc++]='\n';}
	}
	else
	{
		fo1(i,n){fo1(j,m)buf[bc++]=r[i][j]+48;buf[bc++]='\n';}
	}
}

inline void print()
{
	out,ac,'\n';
	fo0(i,bc)out,buf[i];
}

inline void dfs(int x,int y,int i)
{
	if(id[x][y]||!s[x][y])return;
	id[x][y]=i;
	if(x>1)dfs(x-1,y,i);
	if(x<n)dfs(x+1,y,i);
	if(y>1)dfs(x,y-1,i);
	if(y<m)dfs(x,y+1,i);
}

inline void dfs2(int x,int y,int i)
{
	if(s[x][y])
	{
		if(vt[id[x][y]]!=i)cnt++;
		vt[id[x][y]]=i;
	}
	if(id[x][y]||s[x][y])return;
	id[x][y]=i;
	if(x>1)dfs2(x-1,y,i);
	if(x<n)dfs2(x+1,y,i);
	if(y>1)dfs2(x,y-1,i);
	if(y<m)dfs2(x,y+1,i);
}

int main()
{
	in,n,m;
	fo1(i,n)in,s[i]+1;
	if(n>m)
	{
		fo1(i,n)fo1(j,i-1)std::swap(s[i][j],s[j][i]);
		std::swap(n,m);
		rev=1;
	}
	fo1(i,n)fo1(j,m)s[i][j]-=48;
	if(n==1)
	{
		for(int i=1;i<=m;i++)
		{
			if(!s[1][i])continue;
			int t=i;
			for(;t<=m&&s[1][t];t++);
			fo(j,i,t-1)r[1][j]=1;
			add(1);
			fo(j,i,t-1)r[1][j]=0;
			i=t-1;
		}
		return print(),0;
	}
	fo1(i,n)fo1(j,m)if(!id[i][j]&&s[i][j])dfs(i,j,++cid);
	if(cid==0)return print(),0;
	if(cid==1)
	{
		fo1(i,n)fo1(j,m)r[i][j]=s[i][j];
		add(1);
		return print(),0;
	}
	if(cid==2)
	{
		fo1(i,n)fo1(j,m)r[i][j]=id[i][j]==1;add(1);
		fo1(i,n)fo1(j,m)r[i][j]=id[i][j]==2;add(1);
		return print(),0;
	}
	int u=0;
	fo1(i,n)fo1(j,m)if(!id[i][j]&&!s[i][j])
	{
		cnt=0,dfs2(i,j,--u);
		if(cnt==cid)
		{
			fo1(x,n)fo1(y,m)r[x][y]=s[x][y]||id[x][y]==u;add(1);
			fo1(x,n)fo1(y,m)r[x][y]=id[x][y]==u;add(0);
			return print(),0;
		}
	}
	fo1(i,n)fo1(j,m)r[i][j]=j!=m&&(j==1||(i&1)||s[i][j]);add(1);
	fo1(i,n)fo1(j,m)r[i][j]=j!=1&&(j==m||(~i&1)||s[i][j]);add(1);
	fo1(i,n)fo1(j,m)r[i][j]=(j!=1&&j!=m)||!s[i][j];add(0);
	print();
}
