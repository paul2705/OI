#include<bits/stdc++.h>
namespace Super{
	using namespace std;
	#define ll long long
	#define debug(...) fprintf(stderr, __VA_ARGS__)
	#define get getchar
	//inline char get(){
	//	static char C[100000000],*l=C,*r=C;
	//	return l==r&&(r=(l=C)+fread(C,1,100000000,stdin),l==r)?EOF:*l++;
	//}
	template<typename Ty> inline void read(Ty &x) {
		x=0;int f=0;char ch=get();for(;ch<48||ch>57;ch=get())f|=ch=='-';
		for(;ch>47&&ch<58;ch=get())x=(x<<1LL)+(x<<3LL)+ch-'0';x=f?-x:x;
	}
	inline void print(int x){
		static int A[12];int Top=0;
		if(x==0){puts("0");return;}
		for(;x;x/=10)A[++Top]=x%10;
		for(;Top;putchar(A[Top--]+'0'));putchar(10);
	}
	int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
	int exgcd(int a,int b,int &x,int &y){
		if(b==0){x=1;y=0;return a;}int ret=exgcd(b,a%b,y,x);y-=a/b*x;return ret;
	}
	#define mod 19260817
	#define inf 0x3f3f3f3f
	ll Q_P(ll x,int y){
		ll R=1;for(;y;y>>=1,x=x*x%mod)if(y&1)R=R*x%mod;return R;
	}
	ll Div(ll x,ll y){return x*Q_P(y,mod-2)%mod;}
	template<typename Ty> inline int Add(Ty x,Ty y){x+=y;return x<mod?x:x-mod;}
	template<typename Ty> inline int Del(Ty x,Ty y){x-=y;return x<0?x+mod:x;}
	#define pii pair<int,int> 
	#define MP make_pair
	#define fi first
	#define se second
	template<typename Ty> inline void updmax(Ty &x,Ty y){x=x>y?x:y;}
	template<typename Ty> inline void updmin(Ty &x,Ty y){x=x<y?x:y;}
	template<typename Ty> inline int Max(Ty x,Ty y){return x>y?x:y;}
	template<typename Ty> inline int Min(Ty x,Ty y){return x<y?x:y;}
}
using namespace Super;
int n,m,p,f[6401][81][81];
void add(int &x,int y){x+=y;x=x<p?x:x-p;}
signed main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	read(n),read(m),read(p),f[n*m][1][1]=n*m;
	for(int i=n*m-1;i>=1;i--){
		for(int j=1;j<=n;j++)for(int k=1;k<=m;k++)if(f[i+1][j][k]){
			add(f[i][j+1][k],1LL*f[i+1][j][k]*(n-j)%p*k%p);
			add(f[i][j][k+1],1LL*f[i+1][j][k]*(m-k)%p*j%p);
			add(f[i][j][k],1LL*f[i+1][j][k]*(j*k-n*m+i)%p);
		}
	}
	printf("%d\n", f[1][n][m]);
	return 0;
}
