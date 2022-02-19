#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int f[MAXN],w[MAXN],g[MAXN];
int n,q[MAXN],l=1,r=0;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&w[i]);
	for (int i=n;i;i--) w[i]+=w[i+1];
	q[++r]=n+1;
	for (int i=n;i;i--){
		while (l+1<=r&&w[q[l+1]]+f[q[l+1]]<=w[i]) l++;
		f[i]=w[i]-w[q[l]]; g[i]=g[q[l]]+1;
		while (l<=r&&w[q[r]]+f[q[r]]>=w[i]+f[i]) r--;
		q[++r]=i;
	}
	printf("%d\n",g[1]);
	return 0;
}
