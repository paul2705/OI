#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
const int MAXM=1e3+5;
int a[MAXM];
int n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int l,r,k; scanf("%d%d%d",&l,&r,&k);
		a[l]+=k; a[r+1]-=k;
	}
	int mx=0;
	for (int i=1;i<=1000;i++){
		a[i]+=a[i-1];
		mx=max(mx,a[i]);
	}
	printf("%d\n",mx);
	return 0;
}
