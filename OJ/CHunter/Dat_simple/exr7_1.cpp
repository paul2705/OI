#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const ll mod1=998244353;
const ll mod2=1004535809;
const int MAXN=1e3+5;
const int MAXH=1e6+10;
int a[MAXN][MAXN];
int has1[MAXN][MAXN],has2[MAXN][MAXN];
int n,m,A,B;
ll inv1,inv2;
int pow1[MAXH],pinv1[MAXH];
int pow2[MAXH],pinv2[MAXH];
map<int,int> use1,use2;
ll mod_pow(ll x,ll n,ll mod){
	ll ret=1;
	while (n){
		if (n&1) ret=ret*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return ret;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&A,&B);
	inv1=mod_pow(5,mod1-2,mod1);
	inv2=mod_pow(7,mod2-2,mod2);
	pow1[0]=pinv1[0]=pow2[0]=pinv2[0]=1;
	for (int i=1;i<=n*m+5;i++){
		pow1[i]=(ll)pow1[i-1]*5%mod1;
		pinv1[i]=(ll)pinv1[i-1]*inv1%mod1;
		pow2[i]=(ll)pow2[i-1]*7%mod2;
		pinv2[i]=(ll)pinv2[i-1]*inv2%mod2;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			char c=getchar(); while (c!='1'&&c!='0') c=getchar();
			a[i][j]=(c=='1');
			has1[i][j]=(((ll)has1[i][j-1]*5%mod1+a[i][j]%mod1)%mod1+mod1)%mod1;
			has2[i][j]=(((ll)has2[i][j-1]*7%mod2+a[i][j]%mod2)%mod2+mod2)%mod2;
		}
	}
	for (int j=B;j<=m;j++){
		ll tmp1=0,tmp2=0;
		for (int i=1;i<=A-1;i++){
			tmp1=(((ll)tmp1*pow1[B]%mod1+has1[i][j]-(ll)has1[i][j-B]*pow1[B]%mod1)%mod1+mod1)%mod1;
			tmp2=(((ll)tmp2*pow2[B]%mod2+has2[i][j]-(ll)has2[i][j-B]*pow2[B]%mod2)%mod2+mod2)%mod2;
		}
		for (int i=A;i<=n;i++){
			tmp1=((tmp1-(has1[i-A][j]-(ll)has1[i-A][j-B]*pow1[B]%mod1)*(ll)pow1[(A-1)*B]%mod1)+mod1)%mod1;
			tmp1=(((ll)tmp1*pow1[B]%mod1+has1[i][j]-(ll)has1[i][j-B]*pow1[B]%mod1)%mod1+mod1)%mod1;
//			cout<<"1: "<<tmp1<<endl;
			use1[tmp1]++;
			tmp2=((tmp2-(has2[i-A][j]-(ll)has2[i-A][j-B]*pow2[B]%mod2)*(ll)pow2[(A-1)*B]%mod2)+mod2)%mod2;
			tmp2=(((ll)tmp2*pow2[B]%mod2+has2[i][j]-(ll)has2[i][j-B]*pow2[B]%mod2)%mod2+mod2)%mod2;
			use2[tmp2]++;
//			cout<<"2: "<<tmp2<<endl;
		}
	}
	int q; scanf("%d",&q);
	while (q--){
		for (int i=1;i<=A;i++){
			for (int j=1;j<=B;j++) has1[i][j]=has2[i][j]=0;
		}
		for (int i=1;i<=A;i++){
			for (int j=1;j<=B;j++){
				char c=getchar(); while (c!='1'&&c!='0') c=getchar();
				int x=c=='1';
				has1[i][j]=(((ll)has1[i][j-1]*5%mod1+x%mod1)%mod1+mod1)%mod1;
				has2[i][j]=(((ll)has2[i][j-1]*7%mod2+x%mod2)%mod2+mod2)%mod2;
			}
		}
		ll tmp1=0,tmp2=0;
		for (int i=1;i<=A;i++){
			tmp1=((ll)tmp1*pow1[B]%mod1+has1[i][B])%mod1;
			tmp2=((ll)tmp2*pow2[B]%mod2+has2[i][B])%mod2;
		}
//		cout<<tmp1<<" "<<tmp2<<endl;
		if (use1[tmp1]&&use2[tmp2]) printf("1\n");
		else printf("0\n");
	}
	return 0;
}
