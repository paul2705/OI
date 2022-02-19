#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e3+5;
int f[MAXN],cnt[MAXN];
int n,a[MAXN],ans,acnt;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		f[i]=1;
		for (int j=1;j<i;j++){
			if (a[j]>a[i]) f[i]=max(f[i],f[j]+1);
		}
		ans=max(ans,f[i]);
	}
	for (int i=1;i<=n;i++){
		if (f[i]==1) cnt[i]=1;
		for (int j=1;j<i;j++){
			if (f[j]+1==f[i]&&a[j]>a[i]) cnt[i]+=cnt[j];
			if (f[j]==f[i]&&a[j]==a[i]) cnt[i]=0;
		}
		if (f[i]==ans) acnt+=cnt[i];
	}
	printf("%d %d\n",ans,acnt);
	return 0;
}
