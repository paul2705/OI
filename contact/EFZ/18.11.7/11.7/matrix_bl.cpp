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
	freopen("matrix1.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&p,&q);
	for (ll i=1;i<=p;i++){
		ll sx,sy,tx,ty;
		scanf("%lld%lld%lld%lld",&sx,&sy,&tx,&ty);
		for (ll j=sx;j<=tx;j++){
			for (ll k=sy;k<=ty;k++){
				a[j][k]++;
			}
		}
	}
	for (ll i=1;i<=q;i++){
		ll sx,sy,tx,ty;
		scanf("%lld%lld%lld%lld",&sx,&sy,&tx,&ty);
		ll ans=0;
		for (ll j=sx;j<=tx;j++){
			for (ll k=sy;k<=ty;k++){
				ans+=a[j][k];
			}
		}
		printf("%lld\n",ans);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
