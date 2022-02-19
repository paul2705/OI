#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll T,n,k,ans;
int main(){
	freopen("pill.in","r",stdin);
	freopen("pill.out","w",stdout);
	scanf("%lld",&T);
	while (T--){
		scanf("%lld%lld",&n,&k);
		ll res1=(n-k+1)*(n-k+2)/2ll;
		k--; if (k%3!=0) res1=0; k++;
		ll res2=0;
		if (k>=3){
			ll tmp=(k-2)/3ll;
			if ((k+1)&1) res2=(tmp+1)/2;
			else res2=tmp/2+1;
			res2*=(n-k+1);
			res2*=2ll;
		}
		ll res3=(k+1)*k/2ll;
		ll tmp=k/2ll;
		res3-=2ll*(tmp*(tmp+1)+(k+1)/2ll*(k&1));
		tmp=k/3ll;
		res3+=tmp*(tmp+1)/2ll*3ll+(k+2)/3ll*(k%3);
		printf("%lld\n",res1+res2+res3);
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
