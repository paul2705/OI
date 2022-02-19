#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int ans;
int n,f[MAXN],c[MAXN],d[MAXN],a[MAXN],di[MAXN];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d%d%d%d",&f[i],&c[i],&d[i],&a[i]);
	for (int i=1;i<=n;i++){
		if (d[f[i]]-c[i]>0) di[f[i]]=max(di[f[i]],d[f[i]]-c[i]);
	}
	for (int i=1;i<=n;i++) ans+=di[i]*a[i];
	printf("%d\n",ans);
	return 0;
}
