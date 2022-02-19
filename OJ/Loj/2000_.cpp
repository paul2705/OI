#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e6+6;
const int mod=1e9+7;
int n,m;
int sp[MAXN];
int pri[MAXN],phi[MAXN];
int f[MAXN];
bool use[MAXN];
int main(){
	scanf("%d%d",&n,&m);
	use[1]=1; phi[1]=sp[1]=1;
	for (int i=2;i<=n;i++){
		if (!use[i]) pri[++pri[0]]=i,phi[i]=i-1;
		for (int j=1;j<=pri[0]&&i*pri[j]<=n;j++){
			use[i*pri[j]]=1;
			if (i%pri[j]==0){
				phi[i*pri[j]]=pri[j]*phi[i];
				break;
			}
			else phi[i*pri[j]]=phi[pri[j]]*phi[i];
		}
		sp[i]=(ll)(sp[i-1]+phi[i])%mod;
//		cout<<i<<" "<<phi[i]<<endl;
	}
	f[1]=1; f[2]=1;
	for (int i=3;i<=n;i++) f[i]=(ll)(f[i-1]+f[i-2])%mod;
	int ans=0;
	for (int i=1;i<=n;i++){
		ans=(ll)(ans+f[i]*(sp[n/i]-1)%mod)%mod;
//		cout<<i<<" "<<2*(sp[n/i]-1)+1<<endl;
	}
	ans=(ll)2*ans%mod;
	for (int i=1;i<=n;i++) ans=(ans+f[i])%mod;
	printf("%d\n",ans%mod);
	return 0;
}
