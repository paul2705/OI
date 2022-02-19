#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
int a[MAXN],n,s;
long long ans;
int main(){
	scanf("%d%d",&n,&s);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int m=a[(n+1)/2];
	if (m>s){
		for (int i=(n+1)/2;i>=1;i--){
			if (a[i]>s) ans+=(long long)a[i]-s;
			else break;
		}
	}
	else if (m<s){
		for (int i=(n+1)/2;i<=n;i++){
			if (a[i]<s) ans+=(long long)s-a[i];
			else break;
		}
	}
	printf("%I64d\n",ans);
	return 0;
}
