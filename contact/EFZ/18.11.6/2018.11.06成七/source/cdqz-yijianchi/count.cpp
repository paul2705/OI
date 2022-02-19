#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#define maxx 1000007
using namespace std;
inline int read(){
	int X=0,w=1;
	char ch=0;
	while(ch<'0'||ch>'9'){if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') X=(X<<3)+(X<<1)+ch-'0',ch=getchar();
	return X*w;
}
long long n,m,mod,mul[maxx];
long long qkpow(long long x,long long y){
	long long z=1;
	while(y){
		if(y&1){
			z=z*x%mod;
		}
		y>>=1;
		x=x*x%mod;
	}
	return z;
}
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	n=read(),m=read(),mod=read();
	mul[0]=1;
	for(int i=1;i<maxx;i++){
		mul[i]=mul[i-1]*i%mod;
	}
	printf("%lld",mul[n]*mul[m]%mod*mul[n*m]%mod*qkpow(mul[m+n-1],mod-2)%mod);
	return 0;
}
