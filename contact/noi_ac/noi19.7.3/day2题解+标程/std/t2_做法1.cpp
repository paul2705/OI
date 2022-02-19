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
#define I inline
#define mset(a,b) memset(a,b,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))

#define fo0(i,n) for(int i=0,i##end=n;i<i##end;i++)
#define fo1(i,n) for(int i=1,i##end=n;i<=i##end;i++)
#define fo(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define fd0(i,n) for(int i=(n)-1;~i;i--)
#define fd1(i,n) for(int i=n;i;i--)
#define fd(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define foe(i,x)for(__typeof((x).end())i=(x).begin();i!=(x).end();++i)

struct Cg{I char operator()(){return getchar();}};
struct Cp{I void operator()(char x){putchar(x);}};
#define OP operator
#define RT return *this;
#define RX x=0;char t=P();while((t<'0'||t>'9')&&t!='-')t=P();bool f=0;\
if(t=='-')t=P(),f=1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define RL if(t=='.'){lf u=0.1;for(t=P();t>='0'&&t<='9';t=P(),u*=0.1)x+=u*(t-'0');}if(f)x=-x
#define RU x=0;char t=P();while(t<'0'||t>'9')t=P();x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0'
#define TR *this,x;return x;
I bool IS(char x){return x==10||x==13||x==' ';}template<typename T>struct Fr{T P;I Fr&OP,(int&x)
{RX;if(f)x=-x;RT}I OP int(){int x;TR}I Fr&OP,(ll &x){RX;if(f)x=-x;RT}I OP ll(){ll x;TR}I Fr&OP,(char&x)
{for(x=P();IS(x);x=P());RT}I OP char(){char x;TR}I Fr&OP,(char*x){char t=P();for(;IS(t);t=P());if(~t){for(;!IS
(t)&&~t;t=P())*x++=t;}*x++=0;RT}I Fr&OP,(lf&x){RX;RL;RT}I OP lf(){lf x;TR}I Fr&OP,(llf&x){RX;RL;RT}I OP llf()
{llf x;TR}I Fr&OP,(uint&x){RU;RT}I OP uint(){uint x;TR}I Fr&OP,(ull&x){RU;RT}I OP ull(){ull x;TR}};Fr<Cg>in;
#define WI(S) if(x){if(x<0)P('-'),x=-x;char s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
#define WL if(y){lf t=0.5;for(int i=y;i--;)t*=0.1;if(x>=0)x+=t;else x-=t,P('-');*this,(ll)(abs(x));P('.');if(x<0)\
x=-x;while(y--){x*=10;x-=floor(x*0.1)*10;P(((int)x)%10+'0');}}else if(x>=0)*this,(ll)(x+0.5);else *this,(ll)(x-0.5);
#define WU(S) if(x){char s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
template<typename T>struct Fw{T P;I Fw&OP,(int x){WI(10);RT}I Fw&OP()(int x){WI(10);RT}I Fw&OP,(uint x){WU(10);RT}
I Fw&OP()(uint x){WU(10);RT}I Fw&OP,(ll x){WI(19);RT}I Fw&OP()(ll x){WI(19);RT}I Fw&OP,(ull x){WU(20);RT}I Fw&OP()
(ull x){WU(20);RT}I Fw&OP,(char x){P(x);RT}I Fw&OP()(char x){P(x);RT}I Fw&OP,(const char*x){while(*x)P(*x++);RT}
I Fw&OP()(const char*x){while(*x)P(*x++);RT}I Fw&OP()(lf x,int y){WL;RT}I Fw&OP()(llf x,int y){WL;RT}};Fw<Cp>out;

namespace pollard_rho
{
	inline ull mrand(){static ull s=124124124713812490;return s+=s<<2|1;}
	//inline ull mul(ull a,ull b,ull c){a%=c,b%=c;ull t=a*b-(ull)((llf)a*b/c+0.5)*c;if(t>c)return t+c;return t;}
	inline ull mul(ull a,ull b,ull c){ull r=0;for(;b;b>>=1,(a+=a)%=c)if(b&1)r=(r+a)%c;return r;}
	inline ull pow(ull a,ull b,ull c){ll r=1;for(;b;b>>=1,a=mul(a,a,c))if(b&1)r=mul(a,r,c);return r;}
	
	std::map<ull,int> ys;
	typedef std::map<ull,int>::iterator iter;
	
	inline bool mr(ull x)
	{
		if(x==2)return 1;
		if(x<2||(~x&1))return 0;
		ull u=x-1,p,a,b;int t=0;
		while(~u&1)u>>=1,t++;
		fo0(i,5)
		{
			p=mrand()%(x-1)+1;
			a=pow(p,u,x);
			fo0(j,t)
			{
				b=mul(a,a,x);
				if(b==1&&a!=1&&a!=x-1)return 0;
				a=b;
			}
			if(a!=1)return 0;
		}
		return 1;
	}
	
	inline ull f(ull a,ull b,ull n)
	{
		return (mul(a,a,n)+b)%n;
	}
	
	void pr(ull n)
	{
		if(n==1)return;
		if(mr(n)){ys[n]++;return;}
		if(n==4){ys[2]+=2;return;}
		ull a,x,y,p;
		while(1)
		{
			a=mrand()&63,x=y=2;
			while(1)
			{
				x=f(x,a,n),y=f(f(y,a,n),a,n);
				if(x==y)break;
				p=gcd(n,x>=y?x-y:y-x);
				if(p>1){pr(p),pr(n/p);return;}
			}
		}
	}
}

const int N=200007,M=30,U=1005,P=1000000007;

int n,fc,f[N];
ull m,A,s[N];
std::pair<ull,int>fac[M];
std::vector<ull>a,b;
std::vector<int>ax[U],bx[U];

inline void dfs(int pos,ull cur,int mask,std::vector<ull>&s)
{
	if(pos==fc)s.pb(cur);
	else
	{
		if(mask>>pos&1)
		{
			fo(i,0,fac[pos].yy)
			{
				dfs(pos+1,cur,mask,s);
				cur*=fac[pos].xx;
			}
		}
		else dfs(pos+1,cur,mask,s);
	}
}

inline int getai(ull x)
{
	return std::lower_bound(a.begin(),a.end(),x)-a.begin();
}

inline int getbi(ull x)
{
	return std::lower_bound(b.begin(),b.end(),x)-b.begin();
}

inline void modify(ull x,int v)
{
	ull a=gcd(x,A),b=x/a;
	int ai=getai(a),bi=getbi(b);
	//foe(i,ax[ai])out,"add:",*i,' ',bi,' ',v,' ',*i*::b.size()+bi,'\n';
	foe(i,ax[ai])(f[*i*::b.size()+bi]+=v)%=P;
}

inline int query(ull x)
{
	ull a=gcd(x,A),b=x/a;
	int ai=getai(a),bi=getbi(b),r=0;
	//out,'/',a,' ',b,' ',ai,' ',bi,' ',bx[bi].size(),'\n';
	//foe(i,bx[bi])out,"qry:",ai,' ',*i,' ',a*::b.size()+*i,'\n';
	foe(i,bx[bi])(r+=f[ai*::b.size()+*i])%=P;
	return r;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	in,n,m;
	fo1(i,n)in,s[i];
	pollard_rho::pr(m);
	//out,"ok\n";
	foe(i,pollard_rho::ys)
		fac[fc++]=*i;
	int fs=1,ri=0,rv=1e9;
	fo0(i,fc)fs*=fac[i].yy+1;
	fo0(i,1<<fc)
	{
		int tx=1;
		fo0(j,fc)if(i>>j&1)tx*=fac[j].yy+1;
		if(max(tx,fs/tx)<rv)rv=max(tx,fs/tx),ri=i;
		//out,max(tx,fs/tx),'\n';
	}
	A=1;
	fo0(i,fc)if(ri>>i&1)fo0(j,fac[i].yy)A*=fac[i].xx;
	dfs(0,1,ri,a);
	dfs(0,1,ri^((1<<fc)-1),b);
	std::sort(a.begin(),a.end());
	std::sort(b.begin(),b.end());
	//out,'/',a.size(),' ',b.size(),' ',*a.rbegin(),' ',*b.rbegin(),'\n';return 0;
	//foe(i,a)out,*i,' ';out,'\n';
	//foe(i,b)out,*i,' ';out,'\n';
	fo0(i,a.size())fo0(j,a.size())if(a[j]%a[i]==0)ax[i].pb(j);
	fo0(i,b.size())fo0(j,b.size())if(b[i]%b[j]==0)bx[i].pb(j);
	//out,ri,' ',A,' ',a.size(),' ',b.size(),'\n';
	fo1(i,n)
	{
		int vn;
		if(i==1)vn=1;else vn=query(s[i]);
		modify(s[i],vn);
		out,vn,'\n';
	}
}
