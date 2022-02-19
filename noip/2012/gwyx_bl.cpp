#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=15;
int id[MAXN];
bool use[MAXN];
struct rec{
	ll x,y;
} a[MAXN];
int n;
ll ans=1e18;
void dfs(int d){
	if (d==n+1){
		ll sum=1,ret=0;
		for (int i=1;i<=n;i++){
//			cout<<id[i]<<" ";
			sum=sum*a[id[i-1]].x;
			//cout<<sum
			ret=max(ret,sum/a[id[i]].y);
		}
		ans=min(ans,ret);
//		cout<<endl<<"ans: "<<ans<<" "<<ret<<endl;
		return;
	}
	for (int i=1;i<=n;i++){
		if (!use[i]){
			use[i]=1; id[d]=i;
			dfs(d+1);
			use[i]=0;
		}
	}
}
int main(){
	freopen("gwyx.in","r",stdin);
	freopen("gwyx1.out","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<=n;i++) scanf("%lld%lld",&a[i].x,&a[i].y);
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}
