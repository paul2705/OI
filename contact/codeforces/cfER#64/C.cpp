#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
int n,z,ans;
int a[MAXN];
bool use[MAXN];
int main(){
	scanf("%d%d",&n,&z);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int pos=1;
	for (int i=1;i<=n;i++){
		if (use[i]) continue;
		while (pos<=n&&a[pos]-a[i]<z) pos++;
		if (pos<=n) ans++,use[pos++]=1;
		else break;
	}
	printf("%d\n",ans);
	return 0;
}
