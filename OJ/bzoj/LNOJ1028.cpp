#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e3+5;
typedef long long ll;
ll f[MAXN][MAXN],s[MAXN][MAXN];
ll a[MAXN],n;
int main(){
	memset(f,63,sizeof(f));
	scanf("%lld",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++) a[i+n]=a[i];
	for (int i=1;i<=n*2;i++) a[i]+=a[i-1],s[i][i]=i,f[i][i]=0;
	for (int l=1;l<=n*2;l++){
		for (int i=1;i<=n*2;i++){
			int j=i+l; if (j>n*2) continue;
			int l=s[i][j-1],r=s[i+1][j];
			for (int k=l;k<=r;k++){
				if (f[i][j]>f[i][k]+f[k+1][j]+a[j]-a[i-1]){
					f[i][j]=f[i][k]+f[k+1][j]+a[j]-a[i-1];
					s[i][j]=k;
				}
			}
		}
	}
	ll ans=1e13;
	for (int i=1;i<=n;i++) ans=min(ans,f[i][i+n-1]);
	printf("%lld\n",ans);
	return 0;
}
