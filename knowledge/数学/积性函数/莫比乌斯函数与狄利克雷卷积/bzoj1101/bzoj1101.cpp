#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e4+5;
int T,a,b,d;
int pri[MAXN],mu[MAXN];
bool use[MAXN];
int f[MAXN];
int main(){
	use[1]=1; mu[1]=1;
	for (int i=2;i<=5e4;i++){
		if (!use[i]) pri[++pri[0]]=i,mu[i]=-1;
		for (int j=1;j<=pri[0]&&pri[j]*i<=5e4;j++){
			use[i*pri[j]]=1;
			if (i%pri[j]!=0) mu[i*pri[j]]=-mu[i];
			else break;
		}
	}
	for (int i=1;i<=5e4;i++) f[i]=f[i-1]+mu[i];
	scanf("%d",&T);
	while (T--){
		scanf("%d%d%d",&a,&b,&d);
		if (a>b) swap(a,b);
		a/=d; b/=d;
		int j=0,ans=0;
		for (int i=1;i<=a;i=j+1){
			j=min(a/(a/i),b/(b/i));
			ans+=(a/i)*(b/i)*(f[j]-f[i-1]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
