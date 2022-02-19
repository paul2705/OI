#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
int n,T,a[MAXN];
int l[MAXN][MAXN],r[MAXN][MAXN];
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int k=0;k<=n;k++){
			for (int i=1;i<=n;i++){
				int j=i+k; if (j>n) break;
				int L=l[i][j-1],R=r[i][j-1];
				int x=a[j];
				if (x==R) l[i][j]=0;
				else if (x<L&&x<R) l[i][j]=x;
				else if (L>R&&R<x&&x<=L) l[i][j]=x-1;
				else if (R>L&&L<x&&x<=R) l[i][j]=x+1;
				else l[i][j]=x;
				L=l[i+1][j],R=r[i+1][j];
				x=a[i];
				if (x==L) r[i][j]=0;
				else if (x<L&&x<R) r[i][j]=x;
				else if (L>R&&R<x&&x<=L) r[i][j]=x+1;
				else if (R>L&&L<x&&x<=R) r[i][j]=x-1;
				else r[i][j]=x;
			}
		}
		if (n==1) printf("1\n");
		else printf("%d\n",(r[1][n-1]!=a[n]));
	}
	return 0;
}
