#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=5050;
ll f[5][MAXN],l[3][MAXN];
int n,m,ans;
int main(){
	memset(f,63,sizeof(f));
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&l[1][i]);
	scanf("%d",&m);
	for (int i=1;i<=m;i++) scanf("%lld",&l[2][i]);
	sort(l[1]+1,l[1]+n+1); sort(l[2]+1,l[2]+m+1);
	f[1][1]=abs(l[1][1]-l[2][1]);
	for (int i=2;i<=n;i++){
		for (int j=1;j<=m;j++) f[i&1][j]=min(f[(i-1)&1][j],f[(i-1)&1][j-1])+abs(l[1][i]-l[2][j]);
	}
	printf("%lld\n",f[n&1][m]);
	return 0;
}
