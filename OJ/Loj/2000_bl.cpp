#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int MAXN=1e3+5;
int n,m;
int f[MAXN],ans;
int sup[MAXN];
int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }
int main(){
	scanf("%d%d",&n,&m);
	f[1]=1; f[2]=1;
	for (int i=3;i<=max(n,m);i++) f[i]=(ll)(f[i-1]+f[i-2])%mod;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
//			ans=(ll)(ans+f[gcd(i,j)])%mod;
//			sup[gcd(i,j)]++;
			cout<<gcd(i,j)<<" ";
		}
		cout<<endl;
	}
//	for (int i=1;i<=n;i++) printf("%d %d\n",i,sup[i]);
//	printf("%d\n",ans);
	return 0;
}
