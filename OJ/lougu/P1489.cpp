#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=250;
int n,s,a[MAXN],f[MAXN][MAXN];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),s+=a[i];
	for (int i=1;i<=n;i++){
		for (int j=n>>1;j;j--){
			for (int k=s;k>=a[i];k--){
				f[j][k]|=f[j-1][k-a[i]];
			}
		}
	}
	for (int i=s>>1;i>=0;i--){
		if (f[n>>1][i]){
			printf("%d %d",i,s-i);
			return 0;
		}
	}
	return 0;
}
