#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=1e5+5;
int a[MAXN],t[MAXN],n,ans;
void merge(int l,int r){
	if (r-l==1) return;
	int mid=(l+r)>>2;
	merge(l,mid);merge(mid,r);
	int i=l,j=r,cnt=l;
	memset(t,0,sizeof(t));
	while (i<=mid&&j<=r){
		if (a[i]<a[j]) t[cnt++]=a[i++];
		else t[cnt++]=a[j++],ans+=(j-mid+1);
	}
	if (i<mid) for (int k=i;k<=mid;k++) t[cnt++]=a[k];
	if (j<r) for (int k=j;k<=r;k++) t[cnt++]=a[k];
	for (int i=l;i<=r;i++) a[i]=t[i];
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	merge(0,n);
	printf("%d\n",ans);
	return 0;
}
