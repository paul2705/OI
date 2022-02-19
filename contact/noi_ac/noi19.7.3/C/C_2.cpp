#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e2+5;
const int MAXB=8e7+5;
int n,K,a[MAXN],w[MAXN],cnt[MAXN];
int now[MAXN][11];
bitset<80000001> f[3];
int ans[MAXN];
int main(){
	freopen("x2.in","r",stdin);
	freopen("x2.out","w",stdout);
	scanf("%d%d",&n,&K);
	for (int i=1;i<=10;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d%d",&w[i],&cnt[i]);
	f[0][0]=1;
	for (int i=1;i<=n;i++){
		int c=i&1; int o=c^1;
		for (int j=1;j<=cnt[i];j++){
			f[c]=f[o]|(f[o]<<w[i]);

	}
	fclose(stdin); fclose(stdout);
	return 0;
}
