#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e4+5;
int n,nn,K,A[MAXN],w[MAXN],cnt[MAXN];
int a[MAXN];
int main(){
	freopen("C_2_txt.in","r",stdin);
	freopen("C_2.out","w",stdout);
	scanf("%d",&nn);
	for (int i=1;i<=nn;i++) scanf("%d",&a[i]);
	freopen("x2.in","r",stdin);
	scanf("%d%d",&n,&K);
	for (int i=1;i<=10;i++) scanf("%d",&A[i]);
	for (int i=1;i<=n;i++) scanf("%d%d",&w[i],&cnt[i]);
	for (int i=1;i<=n;i++){
		bool flag=0;
		for (int j=1;j<=nn;j++){
			if (a[j]==i) flag=1;
		}
		if (flag) printf("%d\n",cnt[i]);
		else printf("0\n");
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
