#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5*5+5;
int a[MAXN],f[MAXN],cnt=1;
int n,k,p[MAXN],c[MAXN];
int binsch(int l,int r,int x){
	while (l<=r){
		int mid=(l+r)>>1;
		if (f[mid]<x) l=mid+1;
		else r=mid-1;
	}
	return r;
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=k;i++) scanf("%d",&p[i]);
	sort(p+1,p+k+1); p[k+1]=n+1;
	for (int i=1;i<=n;i++) scanf("%d",&c[i]); c[n+1]=1e9;
	for (int i=2;i<=k;i++){
		if (c[p[i]]<c[p[i-1]]) return printf("impossible\n"),0;
	}
	int l=-1,r=c[p[1]],res=1;
	for (int i=1;i<=n;i++){
		if (i==p[res]) l=r,r=c[p[++res]],a[cnt++]=c[i];
		else if (l<c[i]&&c[i]<r) a[cnt++]=c[i];
	}
	memset(f,63,sizeof(f));
	f[0]=-1e9; f[1]=a[1];
	int tot=1;
	for (int i=2;i<cnt;i++){
		int j=binsch(1,tot+1,a[i]);
		f[j+1]=a[i];
		if (j>=tot) tot=j+1;
	}
	printf("%d\n",tot);
	return 0;
}
