#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=10005;
int a[MAXN];
int l,m;
int main(){
	scanf("%d%d",&l,&m);
	for (int i=0;i<=l;i++) a[i]=1;
	for (int i=1;i<=m;i++){
		int l,r; scanf("%d%d",&l,&r);
		for (int j=l;j<=r;j++) a[j]=0;
	}
	int cnt=0;
	for (int i=0;i<=l;i++) cnt+=a[i];
	printf("%d\n",cnt);
	return 0;
}
