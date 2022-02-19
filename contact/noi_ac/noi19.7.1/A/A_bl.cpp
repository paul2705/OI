#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int MAXN=11;
const int MAXS=1<<MAXN;
int n,a[MAXN],f[MAXS][MAXN];
int rfac[MAXN],inv[MAXN];
int bin[MAXN];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	inv[1]=1;
	for (int i=2;i<=n;i++) inv[i]=(ll)inv[mod%i]*(ll)(mod-mod/i)%mod;
//	cout<<inv[2]<<" "<<inv[3]<<endl;
	rfac[1]=1; bin[1]=2; bin[0]=1;
	for (int i=2;i<=n;i++){
		rfac[i]=(ll)rfac[i-1]*(ll)inv[i]%mod;
		bin[i]=1ll*bin[i-1]*2%mod;
	}
	f[0][0]=1;
	for (int s=1;s<bin[n];s++){
		for (int i=1;i<=n;i++){
			for (int s1=s;s1;s1=(s1-1)&s){
				int cnt=0;
				for (int j=0;j<n;j++){
					if (s1&bin[j]) cnt++;
				}
				bool flag=1;
				for (int j=0;j<n;j++){
					if (s1&bin[j]){
						if (a[j+1]<cnt) flag=0;
					}
				}
				f[s][i]=(f[s][i]+flag*f[s^s1][i-1])%mod;
			}
//			cout<<"pre: "<<s<<" "<<i<<" "<<f[s][i]<<endl;
			f[s][i]=(ll)f[s][i]*(ll)inv[i]%mod;
//			cout<<s<<" "<<i<<" "<<f[s][i]<<endl;
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++){
		ans=(ans+f[bin[n]-1][i])%mod;
	}
	printf("%d\n",(ans+mod)%mod);
	return 0;
}
