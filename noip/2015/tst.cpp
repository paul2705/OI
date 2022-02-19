#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e5+5;
int n,m,a[MAXN],L;
int las[MAXN];
bool check(int x){
	int ret=0;
	for (int i=1;i<=n+1;i++) las[i]=i-1;
	for (int i=0;i<n;i++){
		if (a[i+1]-a[las[i+1]]<x) ret++,las[i+2]=las[i+1];
	}
	if (a[n]-a[las[n]]>=x&&a[n+1]-a[las[n+1]]<x) ret++;
//	cout<<x<<" "<<ret<<endl;
	return ret<=m;
}
int main(){
	scanf("%d%d%d",&L,&n,&m); a[0]=0; a[n+1]=L;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int l=0,r=L+1,mid;
	while (l+1<r){
//		cout<<l<<" "<<r<<" ";
		mid=(l+r)>>1;
		if (check(mid)) l=mid;
		else r=mid;
	}
	printf("%d\n",l);
	return 0;
}
