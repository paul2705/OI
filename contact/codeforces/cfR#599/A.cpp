#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
int a[MAXN],cnt[MAXN];
int n,T;
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++) cnt[i]=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			cnt[a[i]]++;
		}
		for (int i=n-1;i>=1;i--) cnt[i]+=cnt[i+1];
		int now=n;
		for (int i=1;i<=n;i++){
			if (cnt[i]<i){
				now=i-1;
				break;
			}
		}
		printf("%d\n",now);
	}
	return 0;
}
