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

const int n=30;

std::vector<pii>s;

inline lf cal(int x1,int y1,int x2,int y2,int x3,int y3)
{
	x2-=x1,y2-=y1,x3-=x1,y3-=y1;
	if(x2*y3-y2*x3==0)return 180;
	int t=x2*x3+y2*y3;
	lf v=acos(t/sqrt((x2*x2+y2*y2)*(x3*x3+y3*y3)));
	for(int i=2;i;i--)
	{
		x1=x3,x3=-x2,x2=x1-x2;
		y1=y3,y3=-y2,y2=y1-y2;
		t=x2*x3+y2*y3;
		v=max(v,acos(t/sqrt((x2*x2+y2*y2)*(x3*x3+y3*y3))));
	}
	return v*57.29577951308232;
}

inline lf cal(pii a,pii b,pii c)
{
	return cal(a.xx,a.yy,b.xx,b.yy,c.xx,c.yy);
}

inline lf chkswap(pii a,pii b)
{
	lf res=233;
	fo0(i,s.size())if(s[i]!=a&&s[i]!=b)fo0(j,i)if(s[j]!=a&&s[j]!=b)
	{
		repl(res,max(cal(a,s[i],s[j]),cal(b,s[i],s[j])));
	}
	return res;
}

int main()
{
	printf("%.2lf\n",cal(1,2,3,3,3,1));
	printf("%.2lf\n",cal(0,0,1,0,0,1));
	fo1(i,n)fo1(j,n)s.pb(mp(i,j));
	//fo1(i,n){fo1(j,n-1)printf("%.2lf ",chkswap(mp(i,j),mp(i,j+1)));out,'\n';}
	//lf ua=0;
	//fo1(i,n)fo1(j,n-1)if(repr(ua,chkswap(mp(i,j),mp(i,j+1))))printf("%d %d %.5lf\n",i,j,ua);
	//while(1);
	freopen("in.txt","w",stdout);
	fo0(i,s.size())fo0(j,i)fo0(k,j)
	{
		lf t=cal(s[i],s[j],s[k]);
		if(t<60.15)
		{
			printf("%d %d %d %d %d %d %.5lf\n",s[i].xx,s[i].yy,s[j].xx,s[j].yy,s[k].xx,s[k].yy,t);
		}
	}
}
