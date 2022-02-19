#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
const int mod=1e5;
int n,ans,a[MAXN];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		int ret=0,sum=0;
		for (int j=i;j<=n;j++){
			sum+=a[j]; ret=max(ret,sum);
			ans=(ans+ret)%mod;
			if (sum<0) sum=0;
		}
	}
	printf("%d\n",ans);
	return 0;
}
