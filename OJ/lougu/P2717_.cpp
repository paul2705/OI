#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e5+5;
typedef long long ll;
int a[MAXN],b[MAXN];
int n,k;
ll ans;
void merge(int l,int r){
	if (l==r) return;
	int mid=(l+r)>>1;
	merge(l,mid); merge(mid+1,r);
	int i=l,j=mid+1,res=0;
	while (i<=mid&&j<=r){
		if (a[i]<=a[j]) b[res++]=a[i++];
		else b[res++]=a[j++],ans+=mid-i+1;
	}
	for (;i<=mid;i++) b[res++]=a[i];
	for (;j<=r;j++) b[res++]=a[j];
	for (int i=l;i<=r;i++) a[i]=b[i-l];
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]+=a[i-1]-k;
	merge(0,n);
//	cout<<ans<<endl;
	printf("%lld\n",(ll)(1+n)*n/2-ans);
	return 0;
}
