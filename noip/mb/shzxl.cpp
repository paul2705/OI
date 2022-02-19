#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int f[MAXN],n,a[MAXN],id[MAXN];
int b[MAXN];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),id[a[i]]=i;
	for (int i=1;i<=n;i++) scanf("%d",&b[i]),b[i]=id[b[i]];
	int m=0; f[0]=0;
	for (int i=1;i<=n;i++){
		if (b[i]>=f[m]) f[++m]=b[i];
		else {
			int x=lower_bound(f+1,f+m+1,b[i])-f;
			f[x]=min(f[x],b[i]);
		}
	}
	printf("%d\n",m);
	return 0;
}
