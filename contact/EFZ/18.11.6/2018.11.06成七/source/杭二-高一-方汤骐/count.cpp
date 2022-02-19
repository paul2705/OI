#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline void judge(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
}
int n,m,mod;
int fac[1000005],ifac[1000005];
inline int C(int x,int y){
	if(y<0||y>x)return 0;
	return 1ll*fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}
inline int pow(int x,int y){
	int z=1;
	while(y){
		if(y&1)z=1ll*z*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return z;
}
int f[1005];
int main(){
	judge();
	scanf("%d%d%d",&n,&m,&mod);
	fac[0]=1;
	for(int i=1;i<=n*m;i++)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n*m]=pow(fac[n*m],mod-2);
	for(int i=n*m;i>0;i--)ifac[i-1]=1ll*ifac[i]*i%mod;
	if(n>m)swap(n,m);
	int ans=0;
	for(int i=1;i<=n;i++){
		int res=1ll*C(n,i)*C(m,i)%mod*fac[i]%mod*fac[i]%mod*C(n*m,(n-i)*(m-i))%mod*fac[(n-i)*(m-i)]%mod,R=n*m-(n-i)*(m-i);
		for(int j=1;j<=i;j++){
			int now=n+m-2-2*(i-j)+1;
			res=1ll*res*C(R-1,now-1)%mod*fac[now-1]%mod;
			R-=now;
		}
//		printf("%d\n",res);
//		ans=(ans+(i&1?1:-1)*1ll*res%mod+mod)%mod;
		f[i]=res;
	}
	for(int i=n;i>=1;i--)
		for(int j=i+1;j<=n;j++)
			f[i]=(f[i]-1ll*f[j]*C(j,i)%mod+mod)%mod;
	printf("%d\n",f[1]);
}