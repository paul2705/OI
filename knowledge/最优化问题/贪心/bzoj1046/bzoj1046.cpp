#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e4+5;
const int MAXM=1e3+5;
int n,m;
int a[MAXN],f[MAXN];
int b[MAXN],mxl;
int qry(int x){
	int l=1,r=n+1,mid;
	while (l+1<r){
		mid=(l+r)>>1;
		if (b[mid]>x) l=mid;
		else r=mid;
	}
	return l;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	f[n]=1; b[1]=a[n];
	for (int i=n-1;i>=1;i--){
		int len=qry(a[i]);
		f[i]=len+1;
		mxl=max(mxl,f[i]);
		if (b[len+1]<a[i]) b[len+1]=a[i];
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++){
		int l; scanf("%d",&l);
		if (l>mxl){
			printf("Impossible\n");
			continue;
		}
		else {
			int las=0;
			for (int j=1;j<=n&&l>0;j++){
				if (f[j]>=l&&a[j]>las){
					printf("%d ",a[j]);
					l--; las=a[j];
				}
			}
			printf("\n");
		}
	}
	return 0;
}
