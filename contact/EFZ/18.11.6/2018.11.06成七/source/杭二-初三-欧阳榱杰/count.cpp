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
const int MAXN=90;
ll f[MAXN*MAXN][MAXN][MAXN];
ll n,m,p;
inline ll read(){
    ll x=0,f=1;char ch=getchar();
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
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	/*ll n=read(),m=read(),p=read();
	if(n==1||m==1){
		ll tmp=max(n,m);
		ll sum=1;
		rep(i,1,tmp) sum=sum*i%p;
		write(sum); 
	}
	if(n==2&&m==2) write(16%p);
	if(n==2&&m==3||n==3&&m==2) write(360%p);
	if(n==3&&m==3) write(108864%p);*/
	/*n=read(),m=read(),p=read();
	f[1][1][1]=n*m%p;
	rep(i,1,n*m)
		drp(j,n,1)
			drp(k,m,1)
				if(j*k>=i){
					f[i+1][j][k]+=f[i][j][k]*(j*k-i);f[i+1][j][k]%=p;
					f[i+1][j+1][k]+=f[i][j][k]*k*(n-j);f[i+1][j+1][k]%=p;
					f[i+1][j][k+1]+=f[i][j][k]*j*(m-k);f[i+1][j][k+1]%=p;
				}
				else break;
	ll ans=0;
	rep(i,1,n)
		rep(j,1,m){
			ans+=f[n*m][i][j];ans%=p;
		}
	write(ans);*/
	n=read(),m=read(),p=read();
	f[1][1][1]=n*m%p;
	rep(i,1,n*m)
		drp(j,n,1)
			drp(k,m,1)
				if(j*k>=i){
					f[i][j][k]%=p;
					f[i+1][j][k]+=f[i][j][k]*(j*k-i);
					f[i+1][j+1][k]+=f[i][j][k]*k*(n-j);
					f[i+1][j][k+1]+=f[i][j][k]*j*(m-k);
				}
				else break;
	ll ans=0;
	rep(i,1,n)
		rep(j,1,m){
			ans+=f[n*m][i][j];ans%=p;
		}
	write(ans);
    return 0;
}
