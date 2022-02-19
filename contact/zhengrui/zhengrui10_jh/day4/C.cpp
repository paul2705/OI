#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
int n,m,tmp,num,F[300010],p[300010],sz,f[300010],ans=1,mul;
long long pw;
int POW(int x,int y,int md){
	int tot=1;
	while(y)y&1?tot=1ll*tot*x%md:0,x=1ll*x*x%md,y>>=1;
	return tot;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=2;i<=m;++i){
		if(!p[i])p[++sz]=i;
		for(int j=1;j<=sz&&i*p[j]<=m;++j){
			p[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
	for(int i=1;i<=m;++i){
		tmp=m/i,F[i]=POW(i,POW(tmp,n,mod-1),mod);
		for(int j=1;j<=sz&&p[j]<=tmp;++j)
			for(pw=p[j];pw<=tmp;pw*=p[j]){
				num=(tmp-tmp/pw+mod)%mod;
				num=(POW(tmp,n,mod-1)-POW(num,n,mod-1)+mod-1)%(mod-1),F[i]=1ll*F[i]*POW(p[j],num,mod)%mod;
			}
	}
	for(int i=m;i>=1;--i){
		f[i]=F[i],mul=1;
		for(int j=i+i;j<=m;j+=i)mul=1ll*mul*f[j]%mod;
		f[i]=1ll*f[i]*POW(mul,mod-2,mod)%mod;
		ans=1ll*ans*POW(f[i],i,mod)%mod;
	}
	printf("%d",ans);
	return 0;
}
