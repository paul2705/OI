#include<bits/stdc++.h>

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef double llf;
typedef long double lf;
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

const int N=505;
const lf eps=1e-9,pi=3.141592653589793;

struct vec
{
	lf x,y,g;
	vec(){}
	vec(lf a,lf b){x=a,y=b;}
	inline void calg()
	{
		g=atan2l(y,x);
	}
	inline vec&operator+=(const vec&a)
	{
	 	x+=a.x,y+=a.y;
		return *this;
	}
	inline vec&operator-=(const vec&a)
	{
		x-=a.x,y-=a.y;
		return *this;
	}
	inline vec&operator/=(const lf&a)
	{
		x/=a,y/=a;
		return *this;
	}
	inline vec&operator*=(const lf&a)
	{
		x*=a,y*=a;
		return *this;
	}
	inline vec operator+(const vec&b)const
	{
		vec a=*this;a+=b;return a;
	}
	inline vec operator-(const vec&b)const
	{
		vec a=*this;a-=b;return a;
	}
	inline vec operator/(const lf&b)const
	{
		vec a=*this;a/=b;return a;
	}
	inline vec operator*(const lf&b)const
	{
		vec a=*this;a*=b;return a;
	}
	inline lf operator*(const vec&a)const
	{
		return x*a.x+y*a.y;
	}
	inline lf operator%(const vec&a)const
	{
		return x*a.y-y*a.x;
	}
	inline bool operator<(const vec&a)const
	{
		return g<a.g;
	}
};

struct line
{
	vec a,b;
	line(){}
	line(vec x,vec y){a=x,b=y;}
};

inline lf intf(const line&a,const line&b)
{
	return(b.b%(a.a-b.a))/(a.b%b.b);
}

inline lf ca(vec a,vec b)
{
	return abs(a%b)/2;
}

inline lf ca(vec a,vec b,lf g)
{
	line x(vec(0,0),vec(cos(g),sin(g))),y(a,b-a);
	return ca(a,x.b*intf(x,y));
}

int n,m,uuu;
vec v[N],c[N],_s[N*2],*s=_s+1,t[N*2];
lf ar[N],ans=-1926;
bool spe;

inline void cs(lf area,lf tar,int cnt)
{
	//printf("cs:%.2lf %.2lf %d ",area,tar,cnt);
	if(spe)cnt=uuu;else cnt+=uuu;
	//if(m==1)cnt=1;else cnt+=uuu;
	//printf("%.2lf\n",(lf)cnt/m-area/tar);
	repr(ans,(lf)cnt/m-area/tar);
}

inline lf sol(lf l,lf r,vec a1,vec b1,vec a2,vec b2)
{
	//lf res=1e9;
	//for(lf i=l;i<r;i+=0.00001)repl(res,ca(a1,b1,i)+ca(a2,b2,i));
	//return res;
	lf fl=ca(a1,b1,l)+ca(a2,b2,l),fr=ca(a1,b1,r)+ca(a2,b2,r);
	fo0(i,20)
	{
		lf ml=(l*2+r)/3,mr=(l+r*2)/3;
		lf fml=ca(a1,b1,ml)+ca(a2,b2,ml),fmr=ca(a1,b1,mr)+ca(a2,b2,mr);
		if(fml<fmr)r=mr,fr=fmr;
		else l=ml,fl=fml;
	}
	return fl;
}

int main()
{
	//freopen("data\\c3.in","r",stdin);
	//freopen("data\\c3.out","w",stdout);
	in,n,m;
	fo0(i,n)in,v[i].x,v[i].y;
	fo0(i,m)in,c[i].x,c[i].y;
	fo0(i,m)
	{
		fo0(j,n)s[j]=v[j]-c[i];
		int l=0;
		uuu=1;
		fo0(j,m)if(j^i)
		{
			t[l]=c[j]-c[i];
			if(abs(t[l].x)+abs(t[l].y)>0.1)l++;
			else uuu++;
		}
		spe=!l;
		if(!l)t[l++]=vec(1,0);
		fo0(j,n)s[j].calg();
		fo0(j,l)t[j].calg();
		std::sort(s,s+n);
		std::sort(t,t+l);
		//out,'\n';
		//out,"s:";fo0(i,n)printf("(%.2lf,%.2lf)",s[i].x,s[i].y);out,'\n';
		//out,"sg:";fo0(i,n)printf("%.2lf ",s[i].g);out,'\n';
		//out,"t:";fo0(i,l)printf("(%.2lf,%.2lf)",t[i].x,t[i].y);out,'\n';
		//out,"tg:";fo0(i,l)printf("%.2lf ",t[i].g);out,'\n';
		fo(j,0,n)s[j+n]=s[j],s[j+n].g+=pi*2;
		//out,"sg:";fo0(i,n*2)printf("%.2lf ",s[i].g);out,'\n';
		fo(j,0,l)t[j+l]=t[j],t[j+l].g+=pi*2;
		fo0(j,n)ar[j]=ca(s[j],s[j+1]);
		s[-1]=s[n-1],s[-1].g-=pi*2;
		int sl=0,sr=1,tr=0;
		lf ta=0,tar=0;
		fo0(j,n)tar+=ar[j];
		fo0(j,l)
		{
			for(;sr<n*2&&s[sr].g<t[j].g+pi;sr++)ta+=ar[(sr-1)%n];
			for(;sl<n*2&&s[sl].g<t[j].g;sl++)ta-=ar[sl%n];
			for(;tr<l*2&&t[tr].g<t[j].g+pi+eps;tr++);
			//out,'/',j,':',sl,' ',sr,' ',tr,'\n';
			//cross t[j]
			cs(ca(s[sl],s[sl-1],t[j].g)+ca(s[sr-1],s[sr],t[j].g)+ta,tar,tr-j);
			//not cross t[j]
			lf now=t[j].g;
			while((sr<n*2&&s[sr].g<t[j+1].g+pi)||(sl<n*2&&s[sl].g<t[j+1].g)||(tr<l*2&&t[tr].g<t[j+1].g+pi))
			{
				lf srn=sr==n*2?1e9:s[sr].g-pi,sln=sl==n*2?1e9:s[sl].g,trn=tr==l*2?1e9:t[tr].g-pi;
				int mi;lf mv=1e9;bool flag=0;
				//printf("\n:%.2lf %.2lf %.2lf t[j+1].g=%.2lf\n",srn,sln,trn,t[j+1].g);
				if(srn<mv)mv=srn,mi=1;
				if(sln<mv)mv=sln,mi=2;
				if(trn<mv)mv=trn,mi=3;
				//printf("%d %d %d ta=%.2lf now=%.2lf mv=%.2lf\n",sl,sr,tr,ta,now,mv);
				if(mv>t[j+1].g)mv=t[j+1].g,flag=1;
				lf tmp=sol(now,mv,s[sl],s[sl-1],s[sr-1],s[sr]);
				cs(tmp+ta,tar,tr-j-1);
				if(flag)break;
				now=mv;
				if(mi==1)ta+=ar[(sr-1)%n],sr++;
				if(mi==2)ta-=ar[sl%n],sl++;
				if(mi==3)tr++;
			}
			lf tmp=sol(now,t[j+1].g,s[sl],s[sl-1],s[sr-1],s[sr]);
			cs(tmp+ta,tar,tr-j-1);
		}
		printf("%.10lf\n",(double)ans);
		ans=-1926;
	}
}
