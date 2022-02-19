#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e3+5;
ll a[MAXN][MAXN];
ll n,m,p,q;
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&p,&q);
	for (ll i=1;i<=p;i++){
		ll sx,sy,tx,ty;
		scanf("%lld%lld%lld%lld",&sx,&sy,&tx,&ty);
		a[sx][sy]++; a[sx][ty+1]--;
		a[tx+1][sy]--; a[tx+1][ty+1]++;
	}
	for (ll i=1;i<=n;i++){
		for (ll j=1;j<=m;j++){
			a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
		}
	}
	for (ll i=1;i<=n;i++){
		for (ll j=1;j<=m;j++){
			a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
		}
	}
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=m;j++) cout<<a[i][j]<<" ";
//		cout<<endl;
//	}
	for (ll i=1;i<=q;i++){
		ll sx,sy,tx,ty;
		scanf("%lld%lld%lld%lld",&sx,&sy,&tx,&ty);
		ll ans=a[tx][ty]-a[tx][sy-1]-a[sx-1][ty]+a[sx-1][sy-1];
		printf("%lld\n",ans);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
