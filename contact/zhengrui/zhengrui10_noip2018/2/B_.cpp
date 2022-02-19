#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e3+5;
const int mod=323232323;
typedef long long ll;
int f[MAXN][MAXN],a[MAXN];
int n,iv[MAXN],ans;
int dfs(int x,int y){
	if (x>y) swap(x,y);
	if (f[x][y]>0) return (ll)(f[x][y]+mod)%mod;
	if (x==0&&y==0) f[x][y]=1;
	else if (x==0) f[x][y]=y%mod;
	else if (y==0) f[x][y]=x%mod;
	else f[x][y]=(ll)iv[2]*(dfs(x-1,y)+dfs(x,y-1))%mod;
	f[x][y]=(ll)(f[x][y]%mod+mod)%mod;
	return (ll)(f[x][y]+mod)%mod;
}
int main(){
	scanf("%d",&n); 
	iv[1]=1;
	for (int i=2;i<=n;i++) iv[i]=(ll)(-iv[mod%i]*(mod/i))%mod;
//	cout<<iv[2];
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	if (n==1) printf("%d\n",a[1]%mod);
	else if (n==2){
		ans=dfs(a[1],a[2])%mod;
		printf("%lld\n",(ll)(ans+mod)%mod);
	}
//	for (int i=0;i<=n;i++){
//		for (int j=0;j<=n;j++) cout<<i<<" "<<j<<" "<<(f[i][j]+mod)%mod<<endl;
//	}
//	cout<<dfs(1,2)<<" "<<dfs(0,2)<<" "<<dfs(1,1)<<endl;
//	cout<<(15*iv[2]*iv[2]*iv[2]%mod+mod)%mod<<endl;
//	cout<<(3*iv[2]%mod+mod)%mod<<endl;;
	return 0;
}
