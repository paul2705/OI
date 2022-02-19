#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
const int MAXM=1e6+6;
int d[MAXM],s[MAXM],t[MAXM];
int n,m,r[MAXN];
int a[MAXN];
bool check(int x){
//	cout<<__func__<<" "<<x<<endl;
	for (int i=1;i<=n;i++) a[i]=0;
	for (int i=1;i<=x;i++){
		a[s[i]]+=d[i];
		a[t[i]+1]-=d[i];
	}
	for (int i=1;i<=n;i++){
		a[i]+=a[i-1];
//		cout<<i<<" "<<a[i]<<endl;
		if (a[i]>r[i]) return 0;
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&r[i]);
	for (int i=1;i<=m;i++) scanf("%d%d%d",&d[i],&s[i],&t[i]);
	int l=0,r=m+1,mid;
	while (l+1<r){
		mid=(l+r)>>1;
		if (check(mid)) l=mid;
		else r=mid;
	}
	if (l==m) printf("0\n");
	else printf("-1\n%d\n",l+1);
	return 0;
}
