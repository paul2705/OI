#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int MAXN=1e5+5;
ll f[MAXN][3],n;
int main(){
	freopen("problem1.in","r",stdin);
	freopen("problem1.out","w",stdout);
	scanf("%lld",&n);
	f[1][0]=1;
	for (int i=2;i<=n;i++){
		if ((i-1)%2==0){
			f[i][0]=(f[i-1][1]*((i-1)/2)%mod+f[i-1][0]*((i-1)/2+1)%mod)%mod;
			f[i][1]=(f[i-1][1]*((i-1)/2+1)%mod+f[i-1][0]*((i-1)/2)%mod)%mod;
		}
		else {
			f[i][0]=(f[i-1][1]+f[i-1][0])*((i-1)/2+1)%mod;
			f[i][1]=(f[i-1][1]+f[i-1][0])*((i-1)/2+1)%mod;
		}
//		cout<<i<<" "<<f[i][0]<<" "<<f[i][1]<<endl;
	}
	if (n%10>=1&&n%10<=3){
		if (n%100>=11&&n%100<=13) printf("The %lldth answer is %lld.\n",n,f[n][0]);
		else if (n%10==1) printf("The %lldst answer is %lld.\n",n,f[n][0]);
		else if (n%10==2) printf("The %lldnd answer is %lld.\n",n,f[n][0]);
		else if (n%10==3) printf("The %lldrd answer is %lld.\n",n,f[n][0]);
	}
	else printf("The %lldth answer is %lld.\n",n,f[n][0]);
	fclose(stdin); fclose(stdout);
	return 0;
}
