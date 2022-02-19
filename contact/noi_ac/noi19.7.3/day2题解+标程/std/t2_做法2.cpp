#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<bitset>
#include<assert.h>
 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
 
using namespace std;
 
template<typename T>inline bool upmin(T &x,T y) { return y<x?x=y,1:0; }
template<typename T>inline bool upmax(T &x,T y) { return x<y?x=y,1:0; }
 
typedef unsigned int u32;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double lod;
typedef pair<int,int> PR;
typedef vector<int> VI;
 
const lod pi=acos(-1);
const int oo=1<<30;
const LL OO=1e18;
const int mod=1e9+7;
 
const int N=2e5+100;
 
int qpow(int x,int y) {
	int ans=1;
	while (y) {
		if (y&1) ans=1LL*ans*x%mod;
		x=1LL*x*x%mod;y>>=1;
	}
	return ans;
}
 
int gi() {
	int w=0;bool q=1;char c=getchar();
	while ((c<'0'||c>'9') && c!='-') c=getchar();
	if (c=='-') q=0,c=getchar();
	while (c>='0'&&c <= '9') w=w*10+c-'0',c=getchar();
	return q? w:-w;
}
 
namespace io {
	const int L=(1<<21)+1;
	char ibuf[L],*iS,*iT,obuf[L],*oS=obuf,*oT=obuf+L-1,c,st[55];int f,tp;
#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,L,stdin),(iS==iT?EOF:*iS++)):*iS++)
	inline void flush() {
		fwrite(obuf,1,oS-obuf,stdout);
		oS=obuf;
	}
	inline void putc(char x) { *oS++=x; if (oS==oT) flush(); }
	template<class I> inline void gi(I&x) {
		for (f=1,c=gc();c<'0'||c>'9';c=gc()) if (c=='-') f=-1;
		for (x=0;c<='9'&&c>='0';c=gc()) x=x*10+(c&15); x*=f;
	}
	template<class I> inline void print(I x) {
		if (!x) putc('0');
		if (x<0) putc('-'),x=-x;
		while (x) st[++tp]=x%10+'0',x/=10;
		while (tp) putc(st[tp--]);
	}
	inline void gs(char*s, int&l) {
		for (c=gc();c<'a'||c>'z';c=gc());
		for (l=0;c<='z'&&c>='a';c=gc()) s[l++]=c;
		s[l]=0;
	}
	inline void ps(const char*s) { for (int i=0,n=strlen(s);i<n;i++) putc(s[i]); }
	struct IOFLUSHER{ ~IOFLUSHER() { flush(); } } _ioflusher_;
};
using io::putc;
using io::gi;
using io::gs;
using io::ps;
using io::print;
 
map<LL,int>c;
inline LL mul(LL x,LL y,LL mod) {
	return (__int128)x*y%mod;
}
inline LL qpow(LL x,LL y,LL mod) {
	LL ans=1;
	while (y) {
		if (y&1) ans=mul(ans,x,mod);
		x=mul(x,x,mod);
		y>>=1;
	}
	return ans;
}
inline bool miller_rubbin(LL n) {
	if (~n&1) return n==2;
	if (n<5) return n==3;
	int T=5,t;
	LL x,y,s;
	while (T--) {
		x=rand()%(n-2)+2;
		for (y=n-1,t=0;~y&1;y>>=1,t++);
		x=qpow(x,y,n);
		if (x==1) continue;
		while (t--) {
			s=mul(x,x,n);
			if (s==1) {
				if (x!=n-1) return false;
				break;
			}
			x=s;
		}
		if (s!=1) return false;
	}
	return true;
}
inline LL gcd(LL x,LL y) { return y?gcd(y,x%y):x; }
inline LL pro(LL n) {
	LL x=rand()%(n-1)+1,c=rand()%(n-1)+1,y=x,g;
	int t=0,k=1;
	while (1) {
		x=(mul(x,x,n)+c)%n;
		if (x==y) return -1;
		if ((g=gcd(x>y?x-y:y-x,n))!=1) return g;
		if (++t==k) k<<=1,y=x;
	}
}
inline void pallord(LL n) {
	if (n==1) return;
	if (miller_rubbin(n)) { c[n]++; return; }
	LL k;
	while ((k=pro(n))==-1);
	pallord(k);
	pallord(n/k);
}
 
LL pri[100];
int num[100],u[100];
int f[N],sum[N],cur[N],suf[100];
LL val[N];
ULL bit[N];
void inc(int &x,int y) { (x+=y)<mod?0:x-=mod; }
int main()
{
#ifndef ONLINE_JUDGE
	freopen("P6.in","r",stdin);
	freopen("P6.out","w",stdout);
#endif
	int n,i,j,g,k,len=0,last,a,b,*w1,*w2;LL m,x,ret;gi(n);gi(m);
	const int B=800;
	pallord(m);
	for (auto t:c)
		pri[len]=t.fi,u[len++]=t.se+1;
	for (i=num[0]=1;i<=len;i++)
		num[i]=num[i-1]*u[i-1];
	suf[len-1]=1;for (i=len-1;i>0;i--) suf[i-1]=suf[i]*u[i];
	gi(val[1]);
	f[1]=last=1;cur[0]=1;for (i=0;i<num[len];i++) sum[i]=1;
	for (i=2;i<=n;i++) {
		gi(val[i]);
		for (j=k=0,x=val[i],b=0;j<len;b+=u[j++]) {
			for (g=0;!(x%pri[j]);x/=pri[j],g++);
			bit[i]|=((1ULL<<g)-1)<<b;
			k+=g*num[j];
		}
		ret=sum[k];
		for (j=last+1;j<i;j++)
			if ((bit[i]&bit[j])==bit[j])
				ret+=f[j];
		f[i]=ret%mod;
		inc(cur[k],f[i]);
		if (i==last+B) {
			last=i;
			for (j=0;j<num[len];j++) sum[j]=cur[j];
			for (k=0;k<len;k++)
				for (g=0,w1=sum,w2=sum+num[k];g<suf[k];g++,w1+=num[k],w2+=num[k])
					for (b=1;b<u[k];b++)
						for (a=0;a<num[k];a++,w1++,w2++)
							inc(*w2,*w1);
		}
	}
	for (i=1;i<=n;i++)
		print(f[i]),putc('\n');
	return 0;
}
