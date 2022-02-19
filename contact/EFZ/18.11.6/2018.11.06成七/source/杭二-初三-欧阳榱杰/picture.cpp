#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<queue>
#include<map>
#include<set>
#define ll long long
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define drp(i,j,k) for(int i=j;i>=k;--i)
#define cross(i,x) for(int i=h[x];i;i=e[i].n)
using namespace std;
char buf[25];
const ll MAXN=1000010;
char a[MAXN],b[MAXN];
int h1,h2,w1,w2,h3,h4,w3,w4,h,w;
ll ans;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*f;
}
inline void write(ll x){
    if(x<0){putchar('-');x=-x;}
    if(!x){putchar('0');return;}
    int cnt=0;
    while(x){buf[++cnt]='0'+x%10;x/=10;}
    drp(i,cnt,1)putchar(buf[i]);
}
inline int gcd(int x,int y){
	int z=x%y;
	while(z){x=y;y=z;z=x%y;}
	return y;
}
/*inline ll solve2(int x,int y){
	ll head=1;ll ans=0;
	while(head<=w){
		ll tail=min(((head-1)/w1+1)*w1,((head-1)/w2+1)*w2);
		ans+=(tail-head+1)*(a[(x-1)*h1+tail/w1]!=a[(y-1)*h2+tail/w2]);
		head=tail+1; 
	}
	return ans;
}
inline ll solve1(){
	ll head=1;ll ans=0;
	while(head<=h){
		ll tail=min(((head-1)/h1+1)*h1,((head-1)/h2+1)*h2);
		ans+=(tail-head+1)*solve2(tail/h1,tail/h2);
		head=tail+1; 
	}
	return ans;
}*/
int main(){
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	/*h1=read(),w1=read();
	rep(i,1,h1) rep(j,1,w1) 
		while(a[(i-1)*h1+j]=getchar()&&(a[(i-1)*h1+j]!='0'&&a[(i-1)*h1+j]!='1'));
	h2=read(),w2=read();
	rep(i,1,h2) rep(j,1,w2)
		while(b[(i-1)*h2+j]=getchar()&&(b[(i-1)*h2+j]!='0'&&b[(i-1)*h2+j]!='1'));
	h=(ll)h1*h2/gcd(h1,h2);w=(ll)w1*w2/gcd(w1,w2);
	h1=h/h1;h2=h/h2;w1=w/w1;w2=w/w2;
	write(solve1());*/
	h1=read(),w1=read();
	rep(i,1,h1) rep(j,1,w1){
		char ch=getchar();
		while(ch!='0'&&ch!='1') ch=getchar();
		a[(i-1)*h1+j]=ch-'0';
	}
	h2=read(),w2=read();
	rep(i,1,h2) rep(j,1,w2){
		char ch=getchar();
		while(ch!='0'&&ch!='1') ch=getchar();
		b[(i-1)*h2+j]=ch-'0';
	}
	h=(ll)h1*h2/gcd(h1,h2);w=(ll)w1*w2/gcd(w1,w2);
	h3=h/h1;h4=h/h2;w3=w/w1;w4=w/w2;
	rep(i,1,h) rep(j,1,w){
		int xa=(i-1)/h3+1,ya=(j-1)/w3+1;
		int xb=(i-1)/h4+1,yb=(j-1)/w4+1;
		if(a[(xa-1)*h1+ya]==a[(xb-1)*h2+yb]) ++ans;
	}
	write(ans);
    return 0;
}
