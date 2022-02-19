#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int MAXN=1e6+6;
int T,n,m;
int pri[MAXN],mu[MAXN];
bool use[MAXN];
int fb[MAXN],f[MAXN][3];
int pre[MAXN];
int fm[MAXN],fr[MAXN];
int mod_pow(int x,int n){
	int ret=1;
	while (n){
		if (n&1) ret=(ll)ret*x%mod;
		x=(ll)x*x%mod;
		n>>=1;
	}
	return ret;
}
int main(){
	use[1]=0; mu[1]=1;
	for (int i=2;i<=1e6;i++){
		if (!use[i]) pri[++pri[0]]=i,mu[i]=-1;
		for (int j=1;j<=pri[0]&&i*pri[j]<=1e6;j++){
			use[i*pri[j]]=1;
			if (i%pri[j]!=0) mu[i*pri[j]]=-mu[i];
			else break;
		}
	}
	fb[1]=1; fb[2]=1;
	for (int i=3;i<=1e6;i++) fb[i]=(ll)(fb[i-1]+fb[i-2])%mod;
	for (int i=1;i<=1e6;i++){
		f[i][0]=mod_pow(fb[i],mod-2);
		f[i][1]=1; f[i][2]=fb[i];
	}
	for (int i=1;i<=1e6;i++) pre[i]=1;
	for (int i=1;i<=1e6;i++){
		for (int j=i;j<=1e6;j+=i){
			pre[j]=(ll)pre[j]*f[i][mu[j/i]+1]%mod;
		}
	}
//	for (int i=1;i<=10;i++) printf("%d\n",pre[i]);
//	cout<<pre[(int)1e6]<<endl;
	fm[0]=1;
	for (int i=1;i<=1e6;i++) fm[i]=(ll)fm[i-1]*pre[i]%mod;
	fr[(int)1e6]=mod_pow(fm[(int)1e6],mod-2);
//	cout<<fr[(int)1e6]<<endl;
	for (int i=(int)1e6-1;i>=0;i--) fr[i]=(ll)fr[i+1]*pre[i+1]%mod;
//	for (int i=1;i<=10;i++) printf("%d %d\n",fm[i],fr[i]);
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		if (n>m) swap(n,m);
		int j=0,ans=1;
		for (int i=1;i<=n;i=j+1){
			j=min(n/(n/i),m/(m/i));
			ans=(ll)ans*mod_pow((ll)fr[i-1]*fm[j]%mod,(ll)(n/i)*(m/i)%(mod-1))%mod;
//			cout<<i<<" "<<j<<" "<<ans<<endl;
		}
		printf("%d\n",ans);
	}
	return 0;
}
