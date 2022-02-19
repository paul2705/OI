#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
int a[MAXN],b[MAXN],n,m;
int l[MAXN],r[MAXN],w[MAXN];
bool check(int x){
//	cout<<x<<endl;
	for (int i=1;i<=n;i++) b[i]=a[i]-a[i-1];
	for (int i=1;i<=x;i++){
		b[l[i]]-=w[i]; b[r[i]+1]+=w[i];
	}
//	for (int i=1;i<=n;i++) cout<<b[i]<<" "; cout<<endl;
	for (int i=1;i<=n;i++) b[i]+=b[i-1];
	for (int i=1;i<=n;i++){
	//	cout<<b[i]+a[i]<<" ";
		if (b[i]<0) return 0;
	}
//	cout<<endl;
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
//	for(int i=1;i<=n;i++) cout<<a[i]-a[i-1]<<" "; cout<<endl;
	for (int i=1;i<=m;i++) scanf("%d%d%d",&w[i],&l[i],&r[i]);
	int l=0,r=m+1,mid;
	while (l+1<r){
		mid=(l+r)>>1;
		if (check(mid)) l=mid;
		else r=mid;
	}
	if (l==m) printf("0\n");
	else printf("-1\n%d\n",r);
	return 0;
}
