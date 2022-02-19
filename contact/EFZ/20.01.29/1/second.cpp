#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=5e3+5;
ll n,t[MAXN],a[MAXN];
ll f[MAXN];
int main(){
	freopen("second.in","r",stdin);
	freopen("second.out","w",stdout);
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) scanf("%lld%lld",&t[i],&a[i]);
	for (int i=0;i<=n;i++) f[i]=3e9;
	f[0]=0;
	for (int i=1;i<=n;i++){
		ll mx=a[i];
		for (int j=i;j>0;j--){
			mx=max(mx,a[j]);
//			cout<<j<<" "<<f[j]<<" "<<mx<<endl;
			f[i]=min(f[i],max(f[j-1],t[i])+2ll*mx);
		}
//		cout<<i<<" "<<f[i]<<endl;
	}
	printf("%lld\n",f[n]);
	fclose(stdin); fclose(stdout);
	return 0;
}
