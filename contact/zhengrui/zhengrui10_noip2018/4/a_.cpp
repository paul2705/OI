#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,int> par;
const int MAXN=2e3+5;
par f[MAXN][MAXN];
ll a[MAXN];
int T,n;
par max(par a,par b){
	if (a.first>b.first) return a;
	else if (a.first<b.first) return b;
	else if (a.second<b.second) return a;
	else return b;
}
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for (int i=0;i<=n;i++){
			for (int j=0;j<=n;j++) f[i][j]=make_pair(-1ll*1e9*n,0);
		}
		f[0][0]=make_pair(0ll,0);
		for (int i=1;i<=n;i++){
			for (int j=0;j<=i;j++){
				f[i][j]=f[i-1][j];
				if (j) f[i][j]=max(f[i][j],make_pair(f[i-1][j-1].first-a[i],f[i-1][j-1].second+1));
				f[i][j]=max(f[i][j],make_pair(f[i-1][j+1].first+a[i],f[i-1][j+1].second+1));
			}
		}
		printf("%lld %d\n",f[n][0].first,f[n][0].second);
	}
	return 0;
}
