#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e3+5;
const ll mod=1e9+7;
ll f[MAXN][MAXN];
ll g[MAXN][3];
ll n,m,k;
int main(){
	freopen("card.in","r",stdin);
	freopen("card1.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
//	for (int i=2;i<=n;i++){
//		int res=0;
//		for (int j=1;j<=m;j++){
//			if (k>j) f[i][j]=s-f[i-1][k-j];
//			else f[i][j]=s;
//			res+=f[i][j];
//		}
//		s=res;
//	}
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=m;j++) cout<<f[i][j]<<" ";
//		cout<<endl;
//	}
	g[1][1]=g[1][2]=1;
	for (int i=2;i<=n+1;i++){
		g[i][1]=(g[i-1][1]*(k-2)%mod+g[i-1][2]*(m-k+1)%mod)%mod;
		g[i][2]=(g[i-1][1]*(k-1)%mod+g[i-1][2]*(m-k+1)%mod)%mod;
	}
//	for (int i=1;i<=n+1;i++) cout<<g[i][1]<<" "<<g[i][2]<<endl;
	printf("%lld\n",(g[n+1][2]+mod)%mod);
	return 0;
}
