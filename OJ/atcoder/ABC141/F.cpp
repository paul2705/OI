#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
const int MAXB=65;
ll a[MAXN],p[MAXB];
int n;
ll sum;
bool use[MAXB];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		 scanf("%lld",&a[i]);
		 sum^=a[i];
	}
	for (int i=0;i<60;i++) use[i]=(sum>>i)&1;
	for (int i=1;i<=n;i++){
		for (int j=59;j>=0;j--){
			if (use[j]) continue;
			if (a[i]&(1ll<<j)){
				if (!p[j]) p[j]=a[i];
				a[i]^=p[j];
			}
		}
	}
	ll res=0;
	for (int i=59;i>=0;i--){
//		cout<<i<<" "<<use[i]<<endl;
		if (use[i]) continue;
		else if (!(res&(1ll<<i))) res^=p[i];
	}
//	cout<<(sum^res)<<" "<<res<<endl;
	printf("%lld\n",res+(sum^res));
	return 0;
}
