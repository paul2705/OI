#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int n,k;
ll ans;
int main(){
	freopen("P2261.in","r",stdin);
	freopen("P2261.ans","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) ans+=k%i;
	printf("%lld\n",ans);
	fclose(stdin); fclose(stdout);
	return 0;
}
