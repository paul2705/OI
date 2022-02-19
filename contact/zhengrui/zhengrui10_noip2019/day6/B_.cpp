#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N=400005,P=998244353;
int n,m,k,a[N],ch[N],s[N],f[N],h[N],fac[N],ifac[N];vector<int>g[N];
namespace IOStream {
	const int MAXR = 10000000;
	char _READ_[MAXR], _PRINT_[MAXR];
	int _READ_POS_, _PRINT_POS_, _READ_LEN_;
	inline char readc(){
		if (!_READ_POS_) _READ_LEN_ = fread(_READ_, 1, MAXR, stdin);
		char c = _READ_[_READ_POS_++];
		if (_READ_POS_ == MAXR) _READ_POS_ = 0;
		if (_READ_POS_ > _READ_LEN_) return 0;
		return c;
	}
	template<typename T> inline void read(T &x) {
		x = 0; register int c;
		while ((c = readc()) < '0' || c > '9');
		x = c - '0';
		while ((c = readc()) >= '0' && c <= '9') x = x * 10 - '0' + c;
	}
}
using namespace IOStream;
inline void md(int&x){x<0?x+=P:0;}
inline int pw(int a,int b){int r=1;for(;b;b>>=1,a=1ll*a*a%P)if(b&1)r=1ll*r*a%P;return r;}
inline int C(int a,int b){return 1ll*fac[a]*ifac[b]%P*ifac[a-b]%P;}
inline int pre(int c,int s)
{
	h[k]=pw(c,k);
	for(int i=k+1,p=1;i<=s;i++,p=1ll*p*(c-1)%P)md(h[i]=(1ll*c*h[i-1]-1ll*ch[i-1]*p)%P);
}
int main()
{
	read(n);read(m);read(k);k=n-k;
	for(int i=fac[0]=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%P;
	ifac[n]=pw(fac[n],P-2);for(int i=n;i;i--)ifac[i-1]=1ll*ifac[i]*i%P;
	for(int i=k;i<=n;i++)ch[i]=C(i,k);
	for(int i=1;i<=n;i++)read(a[i]),s[a[i]]++;
	for(int i=1;i<=m;i++)for(int j=i+i;j<=m;j+=i)s[i]+=s[j];
	for(int i=1,j;i<=m;i=j+1)
	{
		int c=m/i,mx=0,q=pw(c,n);j=m/c;
		for(int t=i;t<=j;t++)mx=max(mx,s[t]);
		if(mx>k)pre(c,mx);
		for(int t=i;t<=j;t++)if(s[t]<=k)f[t]=q;else f[t]=1ll*h[s[t]]*pw(c,n-s[t])%P;
	}
	for(int i=m;i>=1;i--)for(int j=i+i;j<=m;j+=i)f[i]-=f[j],md(f[i]);
	for(int i=1;i<=m;i++)printf("%d ",f[i]);
	return 0;
}
