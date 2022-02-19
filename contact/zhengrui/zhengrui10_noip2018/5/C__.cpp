#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
ll T,n;
int a[MAXN],b[MAXN];
int main(){
	scanf("%lld%lld",&T,&n);
	for (int i=1;i<=n;i++){
		char c=getchar(); while (c!='1'&&c!='0') c=getchar();
		a[i]=c-'0';
	}
	mod_pow(--T);
	for (int i=1;i<=n;i++) printf("%d ",b[i]);
	return 0;
}
