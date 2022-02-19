#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int T,n,r,a[MAXN];
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&r);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		int cnt=0;
		sort(a+1,a+n+1);
		n=unique(a+1,a+n+1)-a-1;
		for (int i=n;i>=1;i--){
			if (a[i]>cnt*r) cnt++;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
