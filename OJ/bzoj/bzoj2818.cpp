#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int MAXN=1e7+7;
int pri[MAXN],mu[MAXN];
ll s[MAXN];
int n;
bool use[MAXN];
ll ans;
int main(){
	scanf("%d",&n);
	mu[1]=1;
	for (int i=2;i<=n;i++){
		if (!use[i]){
			pri[++pri[0]]=i;
			mu[i]=-1;
		}
		for (int j=1;j<=pri[0]&&i*pri[j]<=n;j++){
			use[i*pri[j]]=1;
			if (i%pri[j]!=0) mu[i*pri[j]]=-mu[i];
			else{
				mu[i*pri[j]]=0;
				break;
			}
		}
	}
	for (int i=1;i<=n;i++) s[i]=s[i-1]+mu[i];
	for (ll i=1;i<=pri[0];i++){
//		cout<<pri[i]<<" "<<floor((double)n/pri[i])<<endl;;
		ll ub=floor((double)n/pri[i]);
		for (ll l=1,r=1;l<=ub;l=r+1){
			r=ub/(ub/l);
			ans+=(s[r]-s[l-1])*(ub/l)*(ub/l);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
