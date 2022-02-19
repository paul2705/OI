#include<bits/stdc++.h>
const int N=1000005;
typedef long long ll;
ll H,W;
struct mat{
	char c[N],*s[N];
	int h,w,kh,kw;
	int*a1[N],*a2[N],*a3[N];
	inline void input(){
		scanf("%d%d%s",&h,&w,c+1);
	}
	inline void init(){
		int i,j;char *p=c+1;
		for(i=0;i<=h;++i){
			a1[i]=new int[w+5],a3[i]=new int[w+5],s[i]=new char[w+5];
			memset(a1[i],0,(w+5)<<2);memset(a3[i],0,(w+5)<<2);
		}
		for(i=1;i<=w;++i)a2[i]=new int[h+5],memset(a2[i],0,(h+5)<<2);
		for(i=1;i<=h;++i)for(j=1;j<=w;++j)a1[i][j]=a2[j][i]=s[i][j]=*p++-'0';
		for(i=1;i<=h;++i)for(j=2;j<=w;++j)a1[i][j]+=a1[i][j-1];
		for(i=1;i<=w;++i)for(j=2;j<=h;++j)a2[i][j]+=a2[i][j-1];
		memcpy(a3[1]+1,a1[1]+1,w<<2);
		for(i=2;i<=h;++i)for(j=1;j<=w;++j)a3[i][j]=a1[i][j]+a3[i-1][j];
	}
	inline ll sum(ll x,ll y){
		if(x<=0 || y<=0)return 0;
		int xx=(x-1)/kh,yy=(y-1)/kw;
		ll ans=1ll*kh*kw*a3[xx][yy]+(x-1ll*xx*kh)*(y-1ll*yy*kw)*s[xx+1][yy+1];
		ans+=(x-1ll*xx*kh)*kw*a1[xx+1][yy]+(y-1ll*yy*kw)*kh*a2[yy+1][xx];
		return ans;
	}
	inline ll sum(ll x1,ll y1,ll x2,ll y2){
		return sum(x2,y2)-sum(x1,y2)-sum(x2,y1)+sum(x1,y1);
	}
}A,B;
inline int gcd(int a,int b){return b?gcd(b,a%b):a;}
inline ll lcm(int a,int b){return 1ll*a*b/gcd(a,b);}
ll ans,x;
int main(){
	freopen("picture.in","r",stdin);freopen("picture.out","w",stdout);
	int i,j;char *p=B.c+1;
	A.input();A.init();B.input();H=lcm(A.h,B.h);W=lcm(A.w,B.w);
	A.kh=H/A.h;A.kw=W/A.w;B.kh=H/B.h;B.kw=W/B.w;
	for(i=1;i<=B.h;++i)for(j=1;j<=B.w;++j){
		x=A.sum(1ll*(i-1)*B.kh,1ll*(j-1)*B.kw,1ll*i*B.kh,1ll*j*B.kw);
		if(*p++=='0')x=1ll*B.kw*B.kh-x;
		ans+=x;
	}
	printf("%lld\n",ans);
	return 0;
}
