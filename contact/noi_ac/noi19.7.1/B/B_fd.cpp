#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int MAXN=1e7+5;
int pri[MAXN],n,k;
int f[MAXN];
int ans;
bool use[MAXN];
int mod_pow(int x,int n){
	int ret=1;
	while (n){
		if (n&1) ret=(ll)ret*(ll)x%mod;
		x=(ll)x*(ll)x%mod;
		n>>=1;
	}
	return ret;
}
int main(){
	scanf("%d%d",&n,&k);
	f[1]=1;
	for (int i=2;i<=n;i++){
		if (!use[i]){
			pri[++pri[0]]=i;
			f[i]=mod_pow(i,k);
//			cout<<i<<" "<<f[i]<<endl;
		}
		for (int j=1;j<=pri[0]&&(ll)i*(ll)pri[j]<=n;j++){
			use[i*pri[j]]=1;
			if (i%pri[j]==0){
				f[i*pri[j]]=f[i];
				break;
			}
			else f[i*pri[j]]=(ll)f[i]*(ll)f[pri[j]]%mod;
		}
		cout<<i<<" "<<f[i]<<endl;
	}
//	for (int i=1;i<=n;i++){
//		if (n%i==0) ans=(ans+f[i])%mod;
//	}
//	printf("%d\n",ans);
	return 0;
}
