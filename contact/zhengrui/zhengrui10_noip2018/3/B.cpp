#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e3+5;
const int mod=998244353;
int l[MAXN],r[MAXN],a[MAXN];
int n,m,f[MAXN][MAXN];
int ans;
int find(int id,int x){
	int l=0,r=m+1,mid;
	while (l+1<r){
		mid=(l+r)>>1;
		if (id==2) if (a[mid]<x) l=mid;
		else r=mid;
		else if (a[mid]<=x) l=mid;
		else r=mid;
	}
	if (id==1) return l;
	else return r;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%d%d",&l[i],&r[i]);
	for (int i=1;i<=m;i++) scanf("%d",&a[i]);
	sort(a+1,a+m+1);
	for (int i=1;i<(1<<n);i++){
		int mn=1e9,mx=0;
		for (int j=0;j<n;j++){
			if (i&(1<<j)){
//				cout<<j<<" ";
				mn=min(mn,r[j]);
				mx=max(mx,l[j]);
			}
		}
//		cout<<mn<<" "<<mx<<endl;
		if (mx<=mn){
			int l=find(2,mx),r=find(1,mn);
			if (l<=r) ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}

