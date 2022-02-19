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
int w1,h1,w2,h2;
char s1[1000005],s2[1000005];
namespace Brute{
	char t1[810005],t2[810005];
	void solve(){
		int w=w1*w2/gcd(w1,w2),h=h1*h2/gcd(h1,h2),ans=0;
		int tw=w/w1,th=h/h1;
		for(int i=1;i<=w1;i++)for(int j=1;j<=h1;j++){
			for(int p=1;p<=tw;p++)for(int q=1;q<=th;q++){
				t1[((i-1)*tw+p-1)*h+(j-1)*th+q]=s1[(i-1)*h1+j];
			}
		}
		tw=w/w2,th=h/h2;
		for(int i=1;i<=w2;i++)for(int j=1;j<=h2;j++){
			for(int p=1;p<=tw;p++)for(int q=1;q<=th;q++){
				t2[((i-1)*tw+p-1)*h+(j-1)*th+q]=s2[(i-1)*h2+j];
			}
		}
//		for(int i=1;i<=w;i++,putchar('\n'))
//			for(int j=1;j<=h;j++)printf("%c", t2[(i-1)*h+j]);
		for(int i=1,u=h*w;i<=u;i++)ans+=t1[i]==t2[i];
		printf("%d\n", ans);
	}
}
signed main(){
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	read(w1),read(h1),scanf("%s", s1+1);
	read(w2),read(h2),scanf("%s", s2+1);
	if(w1<=30&&h1<=30&&w2<=30&&h2<=30)
		{Brute::solve();return 0;}
	
	return 0;
}
