#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=1e5+5;
int a[MAXN],t[MAXN];
int n,ans;
void merge(int l,int r){
	if (l==r) return;
	int mid=(l+r)>>1;
	merge(l,mid);merge(mid+1,r);
	int i=l,j=mid+1;
	int k=1;
	while (i<=mid&&j<=r){
		if (a[i]<=a[j]) t[k++]=a[i++];
		else t[k++]=a[j++],ans+=mid-i+1;
	}
	if (i<=mid) for (int l=i;l<=mid;l++) t[k++]=a[l];
	if (j<=r) for (int l=j;l<=r;l++) t[k++]=a[l];
	k=1;
	for (int i=l;i<=r;i++) a[i]=t[k++];
}
int main(){
	freopen("sort.in","r",stdin);
	freopen("sort,out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	merge(1,n);
	printf("%d\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
