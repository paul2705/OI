#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e4+5;
int a[MAXN],b[MAXN],n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	for (int i=1;i<=n;i++){
		if (a[i]!=b[i]){
			int k=i+1;
			for (int j=i+1;j<=n;k++,j++){
				if (a[k]==b[i]) break;
			}
			printf("%d %d\n",i,k);
			for (int l=i,r=k;l<r;l++,r--){
				swap(a[l],a[r]);
			}
		}
	}
	printf("-1 -1\n");
	return 0;
}
