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

const int table[1316*6]={16,1,12,16,1,5,16,2,12,17,1,6,16,3,12,18,1,7,16,4,12,19,1,8,16,5,5,16,1,1,16,5,12,20,1,9,16,6,5,17,1,2,16,6,12,21,1,10,16,7,5,18,1,3,16,7,12,22,1,11,16,8,5,19,1,4,16,8,12,23,1,12,16,9,5,20,1,5,16,9,12,24,1,13,16,10,5,21,1,6,16,10,12,25,1,14,16,11,5,22,1,7,16,11,12,26,1,15,16,12,5,1,1,16,16,12,5,23,1,8,16,12,12,27,1,16,16,13,5,2,1,17,16,13,5,24,1,9,16,13,12,28,1,17,16,14,5,3,1,18,16,14,5,25,1,10,16,14,12,29,1,18,16,15,5,4,1,19,16,15,5,26,1,11,16,15,12,30,1,19,16,16,5,5,1,20,16,16,5,27,1,12,16,16,12,1,1,12,16,17,5,6,1,21,16,17,5,28,1,13,16,17,12,2,1,13,16,18,5,7,1,22,16,18,5,29,1,14,16,18,12,3,1,14,16,19,5,8,1,23,16,19,5,30,1,15,16,19,12,4,1,15,16,20,5,9,1,24,16,20,12,5,1,16,16,21,5,10,1,25,16,21,12,6,1,17,16,22,5,11,1,26,16,22,12,7,1,18,16,23,5,12,1,27,16,23,12,8,1,19,16,24,5,13,1,28,16,24,12,9,1,20,16,25,5,14,1,29,16,25,12,10,1,21,16,26,5,15,1,30,16,26,12,11,1,22,16,27,12,12,1,23,16,28,12,13,1,24,16,29,12,14,1,25,16,30,12,15,1,26,17,1,13,16,2,5,17,2,13,17,2,6,17,3,13,18,2,7,17,4,13,19,2,8,17,5,6,16,2,1,17,5,13,20,2,9,17,6,6,17,2,2,17,6,13,21,2,10,17,7,6,18,2,3,17,7,13,22,2,11,17,8,6,19,2,4,17,8,13,23,2,12,17,9,6,20,2,5,17,9,13,24,2,13,17,10,6,21,2,6,17,10,13,25,2,14,17,11,6,22,2,7,17,11,13,26,2,15,17,12,6,1,2,16,17,12,6,23,2,8,17,12,13,27,2,16,17,13,6,2,2,17,17,13,6,24,2,9,17,13,13,28,2,17,17,14,6,3,2,18,17,14,6,25,2,10,17,14,13,29,2,18,17,15,6,4,2,19,17,15,6,26,2,11,17,15,13,30,2,19,17,16,6,5,2,20,17,16,6,27,2,12,17,16,13,1,2,12,17,17,6,6,2,21,17,17,6,28,2,13,17,17,13,2,2,13,17,18,6,7,2,22,17,18,6,29,2,14,17,18,13,3,2,14,17,19,6,8,2,23,17,19,6,30,2,15,17,19,13,4,2,15,17,20,6,9,2,24,17,20,13,5,2,16,17,21,6,10,2,25,17,21,13,6,2,17,17,22,6,11,2,26,17,22,13,7,2,18,17,23,6,12,2,27,17,23,13,8,2,19,17,24,6,13,2,28,17,24,13,9,2,20,17,25,6,14,2,29,17,25,13,10,2,21,17,26,6,15,2,30,17,26,13,11,2,22,17,27,13,12,2,23,17,28,13,13,2,24,17,29,13,14,2,25,17,30,13,15,2,26,18,1,14,16,3,5,18,2,14,17,3,6,18,3,14,18,3,7,18,4,14,19,3,8,18,5,7,16,3,1,18,5,14,20,3,9,18,6,7,17,3,2,18,6,14,21,3,10,18,7,7,18,3,3,18,7,14,22,3,11,18,8,7,19,3,4,18,8,14,23,3,12,18,9,7,20,3,5,18,9,14,24,3,13,18,10,7,21,3,6,18,10,14,25,3,14,18,11,7,22,3,7,18,11,14,26,3,15,18,12,7,1,3,16,18,12,7,23,3,8,18,12,14,27,3,16,18,13,7,2,3,17,18,13,7,24,3,9,18,13,14,28,3,17,18,14,7,3,3,18,18,14,7,25,3,10,18,14,14,29,3,18,18,15,7,4,3,19,18,15,7,26,3,11,18,15,14,30,3,19,18,16,7,5,3,20,18,16,7,27,3,12,18,16,14,1,3,12,18,17,7,6,3,21,18,17,7,28,3,13,18,17,14,2,3,13,18,18,7,7,3,22,18,18,7,29,3,14,18,18,14,3,3,14,18,19,7,8,3,23,18,19,7,30,3,15,18,19,14,4,3,15,18,20,7,9,3,24,18,20,14,5,3,16,18,21,7,10,3,25,18,21,14,6,3,17,18,22,7,11,3,26,18,22,14,7,3,18,18,23,7,12,3,27,18,23,14,8,3,19,18,24,7,13,3,28,18,24,14,9,3,20,18,25,7,14,3,29,18,25,14,10,3,21,18,26,7,15,3,30,18,26,14,11,3,22,18,27,14,12,3,23,18,28,14,13,3,24,18,29,14,14,3,25,18,30,14,15,3,26,19,1,15,16,4,5,19,2,15,17,4,6,19,3,15,18,4,7,19,4,15,19,4,8,19,5,8,16,4,1,19,5,15,20,4,9,19,6,8,17,4,2,19,6,15,21,4,10,19,7,8,18,4,3,19,7,15,22,4,11,19,8,8,19,4,4,19,8,15,23,4,12,19,9,8,20,4,5,19,9,15,24,4,13,19,10,8,21,4,6,19,10,15,25,4,14,19,11,8,22,4,7,19,11,15,26,4,15,19,12,8,1,4,16,19,12,8,23,4,8,19,12,15,27,4,16,19,13,8,2,4,17,19,13,8,24,4,9,19,13,15,28,4,17,19,14,8,3,4,18,19,14,8,25,4,10,19,14,15,29,4,18,19,15,8,4,4,19,19,15,8,26,4,11,19,15,15,30,4,19,19,16,8,5,4,20,19,16,8,27,4,12,19,16,15,1,4,12,19,17,8,6,4,21,19,17,8,28,4,13,19,17,15,2,4,13,19,18,8,7,4,22,19,18,8,29,4,14,19,18,15,3,4,14,19,19,8,8,4,23,19,19,8,30,4,15,19,19,15,4,4,15,19,20,8,9,4,24,19,20,15,5,4,16,19,21,8,10,4,25,19,21,15,6,4,17,19,22,8,11,4,26,19,22,15,7,4,18,19,23,8,12,4,27,19,23,15,8,4,19,19,24,8,13,4,28,19,24,15,9,4,20,19,25,8,14,4,29,19,25,15,10,4,21,19,26,8,15,4,30,19,26,15,11,4,22,19,27,15,12,4,23,19,28,15,13,4,24,19,29,15,14,4,25,19,30,15,15,4,26,20,1,16,16,5,5,20,2,16,17,5,6,20,3,16,18,5,7,20,4,16,19,5,8,20,5,9,16,5,1,20,5,16,20,5,9,20,6,9,17,5,2,20,6,16,21,5,10,20,7,9,18,5,3,20,7,16,22,5,11,20,8,9,19,5,4,20,8,16,23,5,12,20,9,9,20,5,5,20,9,16,24,5,13,20,10,9,21,5,6,20,10,16,25,5,14,20,11,9,22,5,7,20,11,16,26,5,15,20,12,1,23,1,1,20,12,9,1,5,16,20,12,9,23,5,8,20,12,16,27,5,16,20,13,1,24,1,2,20,13,9,2,5,17,20,13,9,24,5,9,20,13,16,28,5,17,20,14,1,25,1,3,20,14,9,3,5,18,20,14,9,25,5,10,20,14,16,29,5,18,20,15,1,26,1,4,20,15,9,4,5,19,20,15,9,26,5,11,20,15,16,30,5,19,20,16,1,27,1,5,20,16,9,5,5,20,20,16,9,27,5,12,20,16,16,1,5,12,20,17,1,28,1,6,20,17,9,6,5,21,20,17,9,28,5,13,20,17,16,2,5,13,20,18,1,29,1,7,20,18,9,7,5,22,20,18,9,29,5,14,20,18,16,3,5,14,20,19,1,30,1,8,20,19,9,8,5,23,20,19,9,30,5,15,20,19,16,4,5,15,20,20,9,9,5,24,20,20,16,5,5,16,20,21,9,10,5,25,20,21,16,6,5,17,20,22,9,11,5,26,20,22,16,7,5,18,20,23,9,12,5,27,20,23,16,8,5,19,20,23,20,1,1,12,20,24,9,13,5,28,20,24,16,9,5,20,20,24,20,2,1,13,20,25,9,14,5,29,20,25,16,10,5,21,20,25,20,3,1,14,20,26,9,15,5,30,20,26,16,11,5,22,20,26,20,4,1,15,20,27,16,12,5,23,20,27,20,5,1,16,20,28,16,13,5,24,20,28,20,6,1,17,20,29,16,14,5,25,20,29,20,7,1,18,20,30,16,15,5,26,20,30,20,8,1,19,21,1,17,16,6,5,21,2,17,17,6,6,21,3,17,18,6,7,21,4,17,19,6,8,21,5,10,16,6,1,21,5,17,20,6,9,21,6,10,17,6,2,21,6,17,21,6,10,21,7,10,18,6,3,21,7,17,22,6,11,21,8,10,19,6,4,21,8,17,23,6,12,21,9,10,20,6,5,21,9,17,24,6,13,21,10,10,21,6,6,21,10,17,25,6,14,21,11,10,22,6,7,21,11,17,26,6,15,21,12,2,23,2,1,21,12,10,1,6,16,21,12,10,23,6,8,21,12,17,27,6,16,21,13,2,24,2,2,21,13,10,2,6,17,21,13,10,24,6,9,21,13,17,28,6,17,21,14,2,25,2,3,21,14,10,3,6,18,21,14,10,25,6,10,21,14,17,29,6,18,21,15,2,26,2,4,21,15,10,4,6,19,21,15,10,26,6,11,21,15,17,30,6,19,21,16,2,27,2,5,21,16,10,5,6,20,21,16,10,27,6,12,21,16,17,1,6,12,21,17,2,28,2,6,21,17,10,6,6,21,21,17,10,28,6,13,21,17,17,2,6,13,21,18,2,29,2,7,21,18,10,7,6,22,21,18,10,29,6,14,21,18,17,3,6,14,21,19,2,30,2,8,21,19,10,8,6,23,21,19,10,30,6,15,21,19,17,4,6,15,21,20,10,9,6,24,21,20,17,5,6,16,21,21,10,10,6,25,21,21,17,6,6,17,21,22,10,11,6,26,21,22,17,7,6,18,21,23,10,12,6,27,21,23,17,8,6,19,21,23,21,1,2,12,21,24,10,13,6,28,21,24,17,9,6,20,21,24,21,2,2,13,21,25,10,14,6,29,21,25,17,10,6,21,21,25,21,3,2,14,21,26,10,15,6,30,21,26,17,11,6,22,21,26,21,4,2,15,21,27,17,12,6,23,21,27,21,5,2,16,21,28,17,13,6,24,21,28,21,6,2,17,21,29,17,14,6,25,21,29,21,7,2,18,21,30,17,15,6,26,21,30,21,8,2,19,22,1,18,16,7,5,22,2,18,17,7,6,22,3,18,18,7,7,22,4,18,19,7,8,22,5,11,16,7,1,22,5,18,20,7,9,22,6,11,17,7,2,22,6,18,21,7,10,22,7,11,18,7,3,22,7,18,22,7,11,22,8,11,19,7,4,22,8,18,23,7,12,22,9,11,20,7,5,22,9,18,24,7,13,22,10,11,21,7,6,22,10,18,25,7,14,22,11,11,22,7,7,22,11,18,26,7,15,22,12,3,23,3,1,22,12,11,1,7,16,22,12,11,23,7,8,22,12,18,27,7,16,22,13,3,24,3,2,22,13,11,2,7,17,22,13,11,24,7,9,22,13,18,28,7,17,22,14,3,25,3,3,22,14,11,3,7,18,22,14,11,25,7,10,22,14,18,29,7,18,22,15,3,26,3,4,22,15,11,4,7,19,22,15,11,26,7,11,22,15,18,30,7,19,22,16,3,27,3,5,22,16,11,5,7,20,22,16,11,27,7,12,22,16,18,1,7,12,22,17,3,28,3,6,22,17,11,6,7,21,22,17,11,28,7,13,22,17,18,2,7,13,22,18,3,29,3,7,22,18,11,7,7,22,22,18,11,29,7,14,22,18,18,3,7,14,22,19,3,30,3,8,22,19,11,8,7,23,22,19,11,30,7,15,22,19,18,4,7,15,22,20,11,9,7,24,22,20,18,5,7,16,22,21,11,10,7,25,22,21,18,6,7,17,22,22,11,11,7,26,22,22,18,7,7,18,22,23,11,12,7,27,22,23,18,8,7,19,22,23,22,1,3,12,22,24,11,13,7,28,22,24,18,9,7,20,22,24,22,2,3,13,22,25,11,14,7,29,22,25,18,10,7,21,22,25,22,3,3,14,22,26,11,15,7,30,22,26,18,11,7,22,22,26,22,4,3,15,22,27,18,12,7,23,22,27,22,5,3,16,22,28,18,13,7,24,22,28,22,6,3,17,22,29,18,14,7,25,22,29,22,7,3,18,22,30,18,15,7,26,22,30,22,8,3,19,23,1,12,20,1,1,23,1,19,16,8,5,23,2,12,21,1,2,23,2,19,17,8,6,23,3,12,22,1,3,23,3,19,18,8,7,23,4,12,23,1,4,23,4,19,19,8,8,23,5,12,16,8,1,23,5,12,24,1,5,23,5,19,20,8,9,23,6,12,17,8,2,23,6,12,25,1,6,23,6,19,21,8,10,23,7,12,18,8,3,23,7,12,26,1,7,23,7,19,22,8,11,23,8,12,19,8,4,23,8,12,27,1,8,23,8,19,23,8,12,23,9,12,20,8,5,23,9,12,28,1,9,23,9,19,24,8,13,23,10,12,21,8,6,23,10,12,29,1,10,23,10,19,25,8,14,23,11,12,22,8,7,23,11,12,30,1,11,23,11,19,26,8,15,23,12,4,23,4,1,23,12,12,1,8,16,23,12,12,23,8,8,23,12,19,27,8,16,23,13,4,24,4,2,23,13,12,2,8,17,23,13,12,24,8,9,23,13,19,28,8,17,23,14,4,25,4,3,23,14,12,3,8,18,23,14,12,25,8,10,23,14,19,29,8,18,23,15,4,26,4,4,23,15,12,4,8,19,23,15,12,26,8,11,23,15,19,30,8,19,23,16,4,27,4,5,23,16,12,5,8,20,23,16,12,27,8,12,23,16,19,1,8,12,23,17,4,28,4,6,23,17,12,6,8,21,23,17,12,28,8,13,23,17,19,2,8,13,23,18,4,29,4,7,23,18,12,7,8,22,23,18,12,29,8,14,23,18,19,3,8,14,23,19,4,30,4,8,23,19,12,8,8,23,23,19,12,30,8,15,23,19,19,4,8,15,23,20,12,1,1,20,23,20,12,9,8,24,23,20,19,5,8,16,23,21,12,2,1,21,23,21,12,10,8,25,23,21,19,6,8,17,23,22,12,3,1,22,23,22,12,11,8,26,23,22,19,7,8,18,23,23,12,4,1,23,23,23,12,12,8,27,23,23,19,8,8,19,23,23,23,1,4,12,23,24,12,5,1,24,23,24,12,13,8,28,23,24,19,9,8,20,23,24,23,2,4,13,23,25,12,6,1,25,23,25,12,14,8,29,23,25,19,10,8,21,23,25,23,3,4,14,23,26,12,7,1,26,23,26,12,15,8,30,23,26,19,11,8,22,23,26,23,4,4,15,23,27,12,8,1,27,23,27,19,12,8,23,23,27,23,5,4,16,23,28,12,9,1,28,23,28,19,13,8,24,23,28,23,6,4,17,23,29,12,10,1,29,23,29,19,14,8,25,23,29,23,7,4,18,23,30,12,11,1,30,23,30,19,15,8,26,23,30,23,8,4,19,24,1,13,20,2,1,24,1,20,16,9,5,24,2,13,21,2,2,24,2,20,17,9,6,24,3,13,22,2,3,24,3,20,18,9,7,24,4,13,23,2,4,24,4,20,19,9,8,24,5,13,16,9,1,24,5,13,24,2,5,24,5,20,20,9,9,24,6,13,17,9,2,24,6,13,25,2,6,24,6,20,21,9,10,24,7,13,18,9,3,24,7,13,26,2,7,24,7,20,22,9,11,24,8,13,19,9,4,24,8,13,27,2,8,24,8,20,23,9,12,24,9,13,20,9,5,24,9,13,28,2,9,24,9,20,24,9,13,24,10,13,21,9,6,24,10,13,29,2,10,24,10,20,25,9,14,24,11,13,22,9,7,24,11,13,30,2,11,24,11,20,26,9,15,24,12,5,23,5,1,24,12,13,1,9,16,24,12,13,23,9,8,24,12,20,27,9,16,24,13,5,24,5,2,24,13,13,2,9,17,24,13,13,24,9,9,24,13,20,28,9,17,24,14,5,25,5,3,24,14,13,3,9,18,24,14,13,25,9,10,24,14,20,29,9,18,24,15,5,26,5,4,24,15,13,4,9,19,24,15,13,26,9,11,24,15,20,30,9,19,24,16,5,27,5,5,24,16,13,5,9,20,24,16,13,27,9,12,24,16,20,1,9,12,24,17,5,28,5,6,24,17,13,6,9,21,24,17,13,28,9,13,24,17,20,2,9,13,24,18,5,29,5,7,24,18,13,7,9,22,24,18,13,29,9,14,24,18,20,3,9,14,24,19,5,30,5,8,24,19,13,8,9,23,24,19,13,30,9,15,24,19,20,4,9,15,24,20,13,1,2,20,24,20,13,9,9,24,24,20,20,5,9,16,24,21,13,2,2,21,24,21,13,10,9,25,24,21,20,6,9,17,24,22,13,3,2,22,24,22,13,11,9,26,24,22,20,7,9,18,24,23,13,4,2,23,24,23,13,12,9,27,24,23,20,8,9,19,24,23,24,1,5,12,24,24,13,5,2,24,24,24,13,13,9,28,24,24,20,9,9,20,24,24,24,2,5,13,24,25,13,6,2,25,24,25,13,14,9,29,24,25,20,10,9,21,24,25,24,3,5,14,24,26,13,7,2,26,24,26,13,15,9,30,24,26,20,11,9,22,24,26,24,4,5,15,24,27,13,8,2,27,24,27,20,12,9,23,24,27,24,5,5,16,24,28,13,9,2,28,24,28,20,13,9,24,24,28,24,6,5,17,24,29,13,10,2,29,24,29,20,14,9,25,24,29,24,7,5,18,24,30,13,11,2,30,24,30,20,15,9,26,24,30,24,8,5,19,25,1,14,20,3,1,25,1,21,16,10,5,25,2,14,21,3,2,25,2,21,17,10,6,25,3,14,22,3,3,25,3,21,18,10,7,25,4,14,23,3,4,25,4,21,19,10,8,25,5,14,16,10,1,25,5,14,24,3,5,25,5,21,20,10,9,25,6,14,17,10,2,25,6,14,25,3,6,25,6,21,21,10,10,25,7,14,18,10,3,25,7,14,26,3,7,25,7,21,22,10,11,25,8,14,19,10,4,25,8,14,27,3,8,25,8,21,23,10,12,25,9,14,20,10,5,25,9,14,28,3,9,25,9,21,24,10,13,25,10,14,21,10,6,25,10,14,29,3,10,25,10,21,25,10,14,25,11,14,22,10,7,25,11,14,30,3,11,25,11,21,26,10,15,25,12,6,23,6,1,25,12,14,1,10,16,25,12,14,23,10,8,25,12,21,27,10,16,25,13,6,24,6,2,25,13,14,2,10,17,25,13,14,24,10,9,25,13,21,28,10,17,25,14,6,25,6,3,25,14,14,3,10,18,25,14,14,25,10,10,25,14,21,29,10,18,25,15,6,26,6,4,25,15,14,4,10,19,25,15,14,26,10,11,25,15,21,30,10,19,25,16,6,27,6,5,25,16,14,5,10,20,25,16,14,27,10,12,25,16,21,1,10,12,25,17,6,28,6,6,25,17,14,6,10,21,25,17,14,28,10,13,25,17,21,2,10,13,25,18,6,29,6,7,25,18,14,7,10,22,25,18,14,29,10,14,25,18,21,3,10,14,25,19,6,30,6,8,25,19,14,8,10,23,25,19,14,30,10,15,25,19,21,4,10,15,25,20,14,1,3,20,25,20,14,9,10,24,25,20,21,5,10,16,25,21,14,2,3,21,25,21,14,10,10,25,25,21,21,6,10,17,25,22,14,3,3,22,25,22,14,11,10,26,25,22,21,7,10,18,25,23,14,4,3,23,25,23,14,12,10,27,25,23,21,8,10,19,25,23,25,1,6,12,25,24,14,5,3,24,25,24,14,13,10,28,25,24,21,9,10,20,25,24,25,2,6,13,25,25,14,6,3,25,25,25,14,14,10,29,25,25,21,10,10,21,25,25,25,3,6,14,25,26,14,7,3,26,25,26,14,15,10,30,25,26,21,11,10,22,25,26,25,4,6,15,25,27,14,8,3,27,25,27,21,12,10,23,25,27,25,5,6,16,25,28,14,9,3,28,25,28,21,13,10,24,25,28,25,6,6,17,25,29,14,10,3,29,25,29,21,14,10,25,25,29,25,7,6,18,25,30,14,11,3,30,25,30,21,15,10,26,25,30,25,8,6,19,26,1,15,20,4,1,26,1,22,16,11,5,26,2,15,21,4,2,26,2,22,17,11,6,26,3,15,22,4,3,26,3,22,18,11,7,26,4,15,23,4,4,26,4,22,19,11,8,26,5,15,16,11,1,26,5,15,24,4,5,26,5,22,20,11,9,26,6,15,17,11,2,26,6,15,25,4,6,26,6,22,21,11,10,26,7,15,18,11,3,26,7,15,26,4,7,26,7,22,22,11,11,26,8,15,19,11,4,26,8,15,27,4,8,26,8,22,23,11,12,26,9,15,20,11,5,26,9,15,28,4,9,26,9,22,24,11,13,26,10,15,21,11,6,26,10,15,29,4,10,26,10,22,25,11,14,26,11,15,22,11,7,26,11,15,30,4,11,26,11,22,26,11,15,26,12,7,23,7,1,26,12,15,1,11,16,26,12,15,23,11,8,26,12,22,27,11,16,26,13,7,24,7,2,26,13,15,2,11,17,26,13,15,24,11,9,26,13,22,28,11,17,26,14,7,25,7,3,26,14,15,3,11,18,26,14,15,25,11,10,26,14,22,29,11,18,26,15,7,26,7,4,26,15,15,4,11,19,26,15,15,26,11,11,26,15,22,30,11,19,26,16,7,27,7,5,26,16,15,5,11,20,26,16,15,27,11,12,26,16,22,1,11,12,26,17,7,28,7,6,26,17,15,6,11,21,26,17,15,28,11,13,26,17,22,2,11,13,26,18,7,29,7,7,26,18,15,7,11,22,26,18,15,29,11,14,26,18,22,3,11,14,26,19,7,30,7,8,26,19,15,8,11,23,26,19,15,30,11,15,26,19,22,4,11,15,26,20,15,1,4,20,26,20,15,9,11,24,26,20,22,5,11,16,26,21,15,2,4,21,26,21,15,10,11,25,26,21,22,6,11,17,26,22,15,3,4,22,26,22,15,11,11,26,26,22,22,7,11,18,26,23,15,4,4,23,26,23,15,12,11,27,26,23,22,8,11,19,26,23,26,1,7,12,26,24,15,5,4,24,26,24,15,13,11,28,26,24,22,9,11,20,26,24,26,2,7,13,26,25,15,6,4,25,26,25,15,14,11,29,26,25,22,10,11,21,26,25,26,3,7,14,26,26,15,7,4,26,26,26,15,15,11,30,26,26,22,11,11,22,26,26,26,4,7,15,26,27,15,8,4,27,26,27,22,12,11,23,26,27,26,5,7,16,26,28,15,9,4,28,26,28,22,13,11,24,26,28,26,6,7,17,26,29,15,10,4,29,26,29,22,14,11,25,26,29,26,7,7,18,26,30,15,11,4,30,26,30,22,15,11,26,26,30,26,8,7,19,27,1,16,20,5,1,27,1,20,27,1,8,27,1,23,16,12,5,27,2,16,21,5,2,27,2,20,28,1,9,27,2,23,17,12,6,27,3,16,22,5,3,27,3,20,29,1,10,27,3,23,18,12,7,27,4,16,23,5,4,27,4,20,30,1,11,27,4,23,19,12,8,27,5,16,16,12,1,27,5,16,24,5,5,27,5,23,20,12,9,27,6,16,17,12,2,27,6,16,25,5,6,27,6,23,21,12,10,27,7,16,18,12,3,27,7,16,26,5,7,27,7,23,22,12,11,27,8,8,27,1,1,27,8,16,19,12,4,27,8,16,27,5,8,27,8,23,23,12,12,27,9,8,28,1,2,27,9,16,20,12,5,27,9,16,28,5,9,27,9,23,24,12,13,27,10,8,29,1,3,27,10,16,21,12,6,27,10,16,29,5,10,27,10,23,25,12,14,27,11,8,30,1,4,27,11,16,22,12,7,27,11,16,30,5,11,27,11,23,26,12,15,27,12,8,23,8,1,27,12,16,1,12,16,27,12,16,23,12,8,27,12,23,27,12,16,27,13,8,24,8,2,27,13,16,2,12,17,27,13,16,24,12,9,27,13,23,28,12,17,27,14,8,25,8,3,27,14,16,3,12,18,27,14,16,25,12,10,27,14,23,29,12,18,27,15,8,26,8,4,27,15,16,4,12,19,27,15,16,26,12,11,27,15,23,30,12,19,27,16,8,27,8,5,27,16,16,5,12,20,27,16,16,27,12,12,27,16,23,1,12,12,27,17,8,28,8,6,27,17,16,6,12,21,27,17,16,28,12,13,27,17,23,2,12,13,27,18,8,29,8,7,27,18,16,7,12,22,27,18,16,29,12,14,27,18,23,3,12,14,27,19,8,30,8,8,27,19,16,8,12,23,27,19,16,30,12,15,27,19,23,4,12,15,27,20,8,1,1,27,27,20,16,1,5,20,27,20,16,9,12,24,27,20,23,5,12,16,27,21,8,2,1,28,27,21,16,2,5,21,27,21,16,10,12,25,27,21,23,6,12,17,27,22,8,3,1,29,27,22,16,3,5,22,27,22,16,11,12,26,27,22,23,7,12,18,27,23,8,4,1,30,27,23,16,4,5,23,27,23,16,12,12,27,27,23,23,8,12,19,27,23,27,1,8,12,27,24,16,5,5,24,27,24,16,13,12,28,27,24,23,9,12,20,27,24,27,2,8,13,27,25,16,6,5,25,27,25,16,14,12,29,27,25,23,10,12,21,27,25,27,3,8,14,27,26,16,7,5,26,27,26,16,15,12,30,27,26,23,11,12,22,27,26,27,4,8,15,27,27,16,8,5,27,27,27,20,1,1,20,27,27,23,12,12,23,27,27,27,5,8,16,27,28,16,9,5,28,27,28,20,2,1,21,27,28,23,13,12,24,27,28,27,6,8,17,27,29,16,10,5,29,27,29,20,3,1,22,27,29,23,14,12,25,27,29,27,7,8,18,27,30,16,11,5,30,27,30,20,4,1,23,27,30,23,15,12,26,27,30,27,8,8,19,28,1,17,20,6,1,28,1,21,27,2,8,28,1,24,16,13,5,28,2,17,21,6,2,28,2,21,28,2,9,28,2,24,17,13,6,28,3,17,22,6,3,28,3,21,29,2,10,28,3,24,18,13,7,28,4,17,23,6,4,28,4,21,30,2,11,28,4,24,19,13,8,28,5,17,16,13,1,28,5,17,24,6,5,28,5,24,20,13,9,28,6,17,17,13,2,28,6,17,25,6,6,28,6,24,21,13,10,28,7,17,18,13,3,28,7,17,26,6,7,28,7,24,22,13,11,28,8,9,27,2,1,28,8,17,19,13,4,28,8,17,27,6,8,28,8,24,23,13,12,28,9,9,28,2,2,28,9,17,20,13,5,28,9,17,28,6,9,28,9,24,24,13,13,28,10,9,29,2,3,28,10,17,21,13,6,28,10,17,29,6,10,28,10,24,25,13,14,28,11,9,30,2,4,28,11,17,22,13,7,28,11,17,30,6,11,28,11,24,26,13,15,28,12,9,23,9,1,28,12,17,1,13,16,28,12,17,23,13,8,28,12,24,27,13,16,28,13,9,24,9,2,28,13,17,2,13,17,28,13,17,24,13,9,28,13,24,28,13,17,28,14,9,25,9,3,28,14,17,3,13,18,28,14,17,25,13,10,28,14,24,29,13,18,28,15,9,26,9,4,28,15,17,4,13,19,28,15,17,26,13,11,28,15,24,30,13,19,28,16,9,27,9,5,28,16,17,5,13,20,28,16,17,27,13,12,28,16,24,1,13,12,28,17,9,28,9,6,28,17,17,6,13,21,28,17,17,28,13,13,28,17,24,2,13,13,28,18,9,29,9,7,28,18,17,7,13,22,28,18,17,29,13,14,28,18,24,3,13,14,28,19,9,30,9,8,28,19,17,8,13,23,28,19,17,30,13,15,28,19,24,4,13,15,28,20,9,1,2,27,28,20,17,1,6,20,28,20,17,9,13,24,28,20,24,5,13,16,28,21,9,2,2,28,28,21,17,2,6,21,28,21,17,10,13,25,28,21,24,6,13,17,28,22,9,3,2,29,28,22,17,3,6,22,28,22,17,11,13,26,28,22,24,7,13,18,28,23,9,4,2,30,28,23,17,4,6,23,28,23,17,12,13,27,28,23,24,8,13,19,28,23,28,1,9,12,28,24,17,5,6,24,28,24,17,13,13,28,28,24,24,9,13,20,28,24,28,2,9,13,28,25,17,6,6,25,28,25,17,14,13,29,28,25,24,10,13,21,28,25,28,3,9,14,28,26,17,7,6,26,28,26,17,15,13,30,28,26,24,11,13,22,28,26,28,4,9,15,28,27,17,8,6,27,28,27,21,1,2,20,28,27,24,12,13,23,28,27,28,5,9,16,28,28,17,9,6,28,28,28,21,2,2,21,28,28,24,13,13,24,28,28,28,6,9,17,28,29,17,10,6,29,28,29,21,3,2,22,28,29,24,14,13,25,28,29,28,7,9,18,28,30,17,11,6,30,28,30,21,4,2,23,28,30,24,15,13,26,28,30,28,8,9,19,29,1,18,20,7,1,29,1,22,27,3,8,29,1,25,16,14,5,29,2,18,21,7,2,29,2,22,28,3,9,29,2,25,17,14,6,29,3,18,22,7,3,29,3,22,29,3,10,29,3,25,18,14,7,29,4,18,23,7,4,29,4,22,30,3,11,29,4,25,19,14,8,29,5,18,16,14,1,29,5,18,24,7,5,29,5,25,20,14,9,29,6,18,17,14,2,29,6,18,25,7,6,29,6,25,21,14,10,29,7,18,18,14,3,29,7,18,26,7,7,29,7,25,22,14,11,29,8,10,27,3,1,29,8,18,19,14,4,29,8,18,27,7,8,29,8,25,23,14,12,29,9,10,28,3,2,29,9,18,20,14,5,29,9,18,28,7,9,29,9,25,24,14,13,29,10,10,29,3,3,29,10,18,21,14,6,29,10,18,29,7,10,29,10,25,25,14,14,29,11,10,30,3,4,29,11,18,22,14,7,29,11,18,30,7,11,29,11,25,26,14,15,29,12,10,23,10,1,29,12,18,1,14,16,29,12,18,23,14,8,29,12,25,27,14,16,29,13,10,24,10,2,29,13,18,2,14,17,29,13,18,24,14,9,29,13,25,28,14,17,29,14,10,25,10,3,29,14,18,3,14,18,29,14,18,25,14,10,29,14,25,29,14,18,29,15,10,26,10,4,29,15,18,4,14,19,29,15,18,26,14,11,29,15,25,30,14,19,29,16,10,27,10,5,29,16,18,5,14,20,29,16,18,27,14,12,29,16,25,1,14,12,29,17,10,28,10,6,29,17,18,6,14,21,29,17,18,28,14,13,29,17,25,2,14,13,29,18,10,29,10,7,29,18,18,7,14,22,29,18,18,29,14,14,29,18,25,3,14,14,29,19,10,30,10,8,29,19,18,8,14,23,29,19,18,30,14,15,29,19,25,4,14,15,29,20,10,1,3,27,29,20,18,1,7,20,29,20,18,9,14,24,29,20,25,5,14,16,29,21,10,2,3,28,29,21,18,2,7,21,29,21,18,10,14,25,29,21,25,6,14,17,29,22,10,3,3,29,29,22,18,3,7,22,29,22,18,11,14,26,29,22,25,7,14,18,29,23,10,4,3,30,29,23,18,4,7,23,29,23,18,12,14,27,29,23,25,8,14,19,29,23,29,1,10,12,29,24,18,5,7,24,29,24,18,13,14,28,29,24,25,9,14,20,29,24,29,2,10,13,29,25,18,6,7,25,29,25,18,14,14,29,29,25,25,10,14,21,29,25,29,3,10,14,29,26,18,7,7,26,29,26,18,15,14,30,29,26,25,11,14,22,29,26,29,4,10,15,29,27,18,8,7,27,29,27,22,1,3,20,29,27,25,12,14,23,29,27,29,5,10,16,29,28,18,9,7,28,29,28,22,2,3,21,29,28,25,13,14,24,29,28,29,6,10,17,29,29,18,10,7,29,29,29,22,3,3,22,29,29,25,14,14,25,29,29,29,7,10,18,29,30,18,11,7,30,29,30,22,4,3,23,29,30,25,15,14,26,29,30,29,8,10,19,30,1,19,20,8,1,30,1,23,27,4,8,30,1,26,16,15,5,30,2,19,21,8,2,30,2,23,28,4,9,30,2,26,17,15,6,30,3,19,22,8,3,30,3,23,29,4,10,30,3,26,18,15,7,30,4,19,23,8,4,30,4,23,30,4,11,30,4,26,19,15,8,30,5,19,16,15,1,30,5,19,24,8,5,30,5,26,20,15,9,30,6,19,17,15,2,30,6,19,25,8,6,30,6,26,21,15,10,30,7,19,18,15,3,30,7,19,26,8,7,30,7,26,22,15,11,30,8,11,27,4,1,30,8,19,19,15,4,30,8,19,27,8,8,30,8,26,23,15,12,30,9,11,28,4,2,30,9,19,20,15,5,30,9,19,28,8,9,30,9,26,24,15,13,30,10,11,29,4,3,30,10,19,21,15,6,30,10,19,29,8,10,30,10,26,25,15,14,30,11,11,30,4,4,30,11,19,22,15,7,30,11,19,30,8,11,30,11,26,26,15,15,30,12,11,23,11,1,30,12,19,1,15,16,30,12,19,23,15,8,30,12,26,27,15,16,30,13,11,24,11,2,30,13,19,2,15,17,30,13,19,24,15,9,30,13,26,28,15,17,30,14,11,25,11,3,30,14,19,3,15,18,30,14,19,25,15,10,30,14,26,29,15,18,30,15,11,26,11,4,30,15,19,4,15,19,30,15,19,26,15,11,30,15,26,30,15,19,30,16,11,27,11,5,30,16,19,5,15,20,30,16,19,27,15,12,30,16,26,1,15,12,30,17,11,28,11,6,30,17,19,6,15,21,30,17,19,28,15,13,30,17,26,2,15,13,30,18,11,29,11,7,30,18,19,7,15,22,30,18,19,29,15,14,30,18,26,3,15,14,30,19,11,30,11,8,30,19,19,8,15,23,30,19,19,30,15,15,30,19,26,4,15,15,30,20,11,1,4,27,30,20,19,1,8,20,30,20,19,9,15,24,30,20,26,5,15,16,30,21,11,2,4,28,30,21,19,2,8,21,30,21,19,10,15,25,30,21,26,6,15,17,30,22,11,3,4,29,30,22,19,3,8,22,30,22,19,11,15,26,30,22,26,7,15,18,30,23,11,4,4,30,30,23,19,4,8,23,30,23,19,12,15,27,30,23,26,8,15,19,30,23,30,1,11,12,30,24,19,5,8,24,30,24,19,13,15,28,30,24,26,9,15,20,30,24,30,2,11,13,30,25,19,6,8,25,30,25,19,14,15,29,30,25,26,10,15,21,30,25,30,3,11,14,30,26,19,7,8,26,30,26,19,15,15,30,30,26,26,11,15,22,30,26,30,4,11,15,30,27,19,8,8,27,30,27,23,1,4,20,30,27,26,12,15,23,30,27,30,5,11,16,30,28,19,9,8,28,30,28,23,2,4,21,30,28,26,13,15,24,30,28,30,6,11,17,30,29,19,10,8,29,30,29,23,3,4,22,30,29,26,14,15,25,30,29,30,7,11,18,30,30,19,11,8,30,30,30,23,4,4,23,30,30,26,15,15,26,30,30,30,8,11,19};

#define rand rand_

inline uint rand_()
{
	static uint s=time(0)^(reinterpret_cast<ull>(new char)&0xffffffff);
    s^=s<<13;
    s^=s>>17;
    s^=s<<5;
    return s;
}

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

struct data
{
	pii a,b,c;
};

std::vector<data>rs;

struct d2
{
	int a,b,c;
	inline int get(int x,int y)
	{
		if(x>y)std::swap(x,y);
		if(x!=a)return a;
		if(y!=c)return c;
		return b;
	}
};

inline d2 gd2(int a,int b,int c)
{
	if(a>b)std::swap(a,b);
	if(b>c)std::swap(b,c);
	if(a>b)std::swap(a,b);
	return(d2){a,b,c};
}

const int nx=n*n+1;

std::vector<d2>p[nx];

inline int id(pii x){return x.xx*n+x.yy-n;}
inline int id(int x,int y){return x*n+y-n;}

int vt,vis[nx],q[nx],pre[nx];
d2 prd[nx];

#define uassert(x) {if(!(x))return std::vector<d2>();}

inline std::vector<d2>_fw(int a,int b,int ax,int ay)
{
	//return a path shift (b,ax,ay)
	++vt;
	int qe=0;
	q[qe++]=a,vis[a]=vt;
	vis[ax]=vis[ay]=vt;
	for(int i=0;i<qe;i++)
	{
		foe(j,p[q[i]])
		{
			#define chk(t) if(t==ax||t==ay)continue;
			chk(j->a);
			chk(j->b);
			chk(j->c);
			#undef chk
			#define chk(t) if(t!=q[i]&&vis[t]!=vt){q[qe++]=t,vis[t]=vt,pre[t]=q[i],prd[t]=*j;if(t==b)goto ok;}
			chk(j->a);
			chk(j->b);
			chk(j->c);
			#undef chk
		}
	}
	//out,qe,'\n';
	//assert(0);
	return std::vector<d2>();
	ok:;
	std::vector<d2>res;
	std::vector<pii>tmp;
	int x=b;
	while(x!=a)
	{
		tmp.pb(mp(x,prd[x].get(x,pre[x])));
		x=pre[x];
		//out,x,' ',a,'\n';
	}
	tmp.pb(mp(a,0));
	//out,tmp.size(),'\n';
	fo0(i,tmp.size()-1)
	{
		res.pb((d2){tmp[i].xx,tmp[i+1].xx,tmp[i].yy});
	}
	res.pb((d2){a,ax,ay});
	fd0(i,tmp.size()-1)
	{
		res.pb((d2){tmp[i].yy,tmp[i+1].xx,tmp[i].xx});
	}
	if(1){
		std::map<int,int>po;
		foe(i,res)po[i->a]=i->a,po[i->b]=i->b,po[i->c]=i->c;
		foe(i,res)
		{
			int t=po[i->a];
			po[i->a]=po[i->c];
			po[i->c]=po[i->b];
			po[i->b]=t;
		}
		//out,a,' ',b,' ',ax,' ',ay,'\n';
		//foe(i,tmp)out,i->xx,' ',i->yy,'\n';
		foe(i,po)
		{
			if(i->xx==b)uassert(i->yy==ay)
			else if(i->xx==ay)uassert(i->yy==ax)
			else if(i->xx==ax)uassert(i->yy==b)
			else uassert(i->xx==i->yy)
		}
		//out,"ok\n";
	}
	return res;
	//out,qe,'\n';
}

inline std::vector<d2> findway(int a,int b,int c)
{
	fo0(i,rand()%3)
	{
		int t=a;
		a=b,b=c,c=t;
	}
	d2 t=p[a][rand()%p[a].size()];
	int bt,ct;
	if(t.a==a)bt=t.b,ct=t.c;
	else if(t.b==a)bt=t.a,ct=t.c;
	else bt=t.a,ct=t.b;
	std::vector<d2>x,y,z;
	x=_fw(bt,b,ct,a);//returns b,ct,a
	y=_fw(ct,c,a,b);//will use ct,a,b
	foe(i,y)
	{
		if(i->a==ct&&i->b==a&&i->c==b)
		{
			//out,"ok\n";
			foe(j,x)z.pb(*j);
		}else z.pb(*i);
	}
	if(1){
		std::map<int,int>po;
		foe(i,z)po[i->a]=i->a,po[i->b]=i->b,po[i->c]=i->c;
		foe(i,z)
		{
			int t=po[i->a];
			po[i->a]=po[i->c];
			po[i->c]=po[i->b];
			po[i->b]=t;
		}
		//out,a,' ',b,' ',c,'\n';
		//foe(i,po)out,i->xx,' ',i->yy,'\n';
		foe(i,po)
		{
			if(i->xx==a)uassert(i->yy==c)
			else if(i->xx==c)uassert(i->yy==b)
			else if(i->xx==b)uassert(i->yy==a)
			else uassert(i->xx==i->yy)
		}
		//out,"ok\n";
	}
	return z;
}

inline void ex(int a,int&b,int&c)
{
	b=(a-1)/n+1;
	c=(a-1)%n+1;
}

int main()
{
	//freopen("data\\x2.in","r",stdin);
	//freopen("in.txt","r",stdin);
	//std::set<lf>u;
	fo0(i,1316)
	{
		data t;
		t.a.xx=table[i*6];
		t.a.yy=table[i*6+1];
		t.b.xx=table[i*6+2];
		t.b.yy=table[i*6+3];
		t.c.xx=table[i*6+4];
		t.c.yy=table[i*6+5];
		rs.pb(t);
	}
	//foe(i,u)printf("%.5lf\n",*i);
	/*std::map<pii,int>tc;
	foe(i,rs)tc[i->a]++,tc[i->b]++,tc[i->c]++;
	int mi=233,ma=0;
	foe(i,tc)repl(mi,i->yy),repr(ma,i->yy);
	out,tc.size(),' ',mi,' ',ma,'\n'; */
	fo1(i,n)fo1(j,n)s.pb(mp(i,j));
	std::vector<d2>q;
	foe(i,rs)
	{
		d2 t=gd2(id(i->a),id(i->b),id(i->c));
		p[t.a].pb(t);
		p[t.b].pb(t);
		p[t.c].pb(t);
		q.pb(t);
	}
	//fo1(i,n)fo1(j,n-2)findway(id(i,j),id(i,j+1),id(i,j+2));
	//fo1(i,n-2)fo1(j,n)findway(id(i,j),id(i+1,j),id(i+2,j));
	int t[n+1][n+1];
	(int)in;
	fo1(i,n)fo1(j,n)in,t[i][j];
	std::vector<d2>ans;
	while(1)
	{
		bool flag=1;
		fo1(i,n)fo1(j,n)if(t[i][j]!=id(i,j))
		{
			//out,i,' ',j,'\n';
			//out,t[9][5],'\n';
			/*if(i==n&&j==n-1)
			{
				fo1(a,n){fo1(b,n)out,t[a][b],' ';out,'\n';}
				flag=0;
				//break;
			}*/
			std::vector<d2>tmp;
			int ux,uy;
			fo1(a,n)fo1(b,n)if(t[a][b]==id(i,j))ux=a,uy=b;
			for(int rc=100;rc;rc--)
			{
				int x,y;
				do x=rand()%n+1,y=rand()%n+1;while(x<i||(x==i&&y<=j)||(x==ux&&y==uy));
				//out,ux,' ',uy,' ',i,' ',j,' ',x,' ',y,'\n';
				tmp=findway(id(ux,uy),id(i,j),id(x,y));
				//out,x,' ',y,' ',tmp.size(),'\n';
				if(tmp.size())break;
			}
			if(!tmp.size())
			{
				flag=0;
				break;
			}
			foe(k,tmp)
			{
				int x1,y1,x2,y2,x3,y3;
				ex(k->a,x1,y1);
				ex(k->b,x2,y2);
				ex(k->c,x3,y3);
				int v=t[x1][y1];
				t[x1][y1]=t[x3][y3];
				t[x3][y3]=t[x2][y2];
				t[x2][y2]=v;
				ans.pb(*k);
				//if(i==9&&j==5)out,x1,' ',y1,' ',x2,' ',y2,' ',x3,' ',y3,'\n';
			}
			assert(t[i][j]==id(i,j));
		}
		if(flag)break;
		out,flag,'\n';
		fo0(i,1000)
		{
			int x=rand()%q.size();
			int x1,y1,x2,y2,x3,y3;
			ex(q[x].a,x1,y1);
			ex(q[x].b,x2,y2);
			ex(q[x].c,x3,y3);
			int v=t[x1][y1];
			t[x1][y1]=t[x3][y3];
			t[x3][y3]=t[x2][y2];
			t[x2][y2]=v;
			ans.pb(q[x]);
		}
	}
	fo1(i,n)fo1(j,n)assert(t[i][j]==id(i,j));
	out,(int)ans.size(),'\n';
	foe(k,ans)
	{
		int x1,y1,x2,y2,x3,y3;
		ex(k->a,x1,y1);
		ex(k->b,x2,y2);
		ex(k->c,x3,y3);
		out,x1,' ',y1,' ',x2,' ',y2,' ',x3,' ',y3,'\n';
	}
}
