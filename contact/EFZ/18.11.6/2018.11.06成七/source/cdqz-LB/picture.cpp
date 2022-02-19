#include<bits/stdc++.h>
#define FIO "picture"
#define INF 0x3f3f3f
#define DBUG(...) fprintf(stderr,__VA_ARGS__)
typedef long long ll;
const int MOD=1e9+7,MAXN=1e6+5;
using namespace std;
template <class T>inline void read(T &x){T f=1;x=0;char ch=getchar();for(;!isdigit(ch)&&ch!='-';ch=getchar());if(ch=='-')f=-1,ch=getchar();for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';x*=f;}
int h1,w1,h2,w2,g1,g2;
ll ans;
char s1[MAXN],s2[MAXN];
inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline ll nxt(int o,ll k){
	if(o)return min((k/(w1/g2)+1)*w1/g2,(k/(w2/g2)+1)*w2/g2);
	else return min((k/(h1/g1)+1)*h1/g1,(k/(h2/g1)+1)*h2/g1);
}
int main(){
	freopen(FIO".in","r",stdin);
	freopen(FIO".out","w",stdout);
	read(h1);read(w1);
	scanf("%s",s1+1);
	read(h2);read(w2);
	scanf("%s",s2+1);
	g1=gcd(h1,h2);g2=gcd(w1,w2);
	for(ll i=nxt(0,0),lsti=0;i<=h1/g1*h2;lsti=i,i=nxt(0,i))
	for(ll j=nxt(1,0),lstj=0;j<=w1/g2*w2;j=nxt(1,j)){
		if(s1[(i-1)/(h2/g1)*w1+(j-1)/(w2/g2)+1]==s2[(i-1)/(h1/g1)*w2+(j-1)/(w1/g2)+1])ans+=(i-lsti)*(j-lstj);
//		printf("now i=%lld j=%lld\n",i,j);		printf("lsti=%lld,lstj=%lld\n",lsti,lstj);
		lstj=j;
	}
	printf("%lld\n",ans);
	return 0;
}


