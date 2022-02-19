#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=150;
int f[MAXN],a[MAXN];
int n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),a[i]+=a[i-1];
	for (int i=1;i<=n;i++) f[i]=a[i]-a[i-1];
	for (int l=1;l<n;l++){
		for (int i=1;i+l<=n;i++){
			int j=i+l;
			f[i]=a[j]-a[i-1]-min(f[i],f[i+1]);
		}
	}
	printf("%d %d\n",f[1],a[n]-f[1]);
	return 0;
}
