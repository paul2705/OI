#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int MAXN=1e4+5;
const int MAXM=55;
map<int,int> f[MAXN];
int A,B,n,m,D,K,inv;
struct rec{
	int x,y;
} a[MAXM];
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
	scanf("%d%d",&A,&B);
	scanf("%d%d%d%d",&n,&m,&D,&K);
	for (int i=1;i<=K;i++) scanf("%d%d",&a[i].x,&a[i].y);
	inv=mod_pow(A+B,mod-2);
	f[0][0]=0;
	for (int l=1;l<=n;l++){
		for (int i=0;i<=l;i++){
			int j=l-i;
			if (i==0) f[i][j]=((ll)f[i][j-1]*(ll)B%mod*(ll)inv%mod+inv)%mod;
			else if (j==0) f[i][j]=((ll)f[i-1][j]*(ll)A%mod*(ll)inv%mod+inv)%mod;
			else f[i][j]=((ll)f[i-1][j]*(ll)A%mod+(ll)f[i][j-1]*(ll)B%mod+1)*(ll)inv%mod;
		}
	}
	int ans=0;
	for (int i=0;i<=n;i++){
		int j=n-i;
		cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
		ans=(ans+f[i][j])%mod;
	}
	printf("%d\n",ans);
	return 0;
}
