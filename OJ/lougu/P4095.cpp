#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
int f[MAXN][MAXN],p[MAXN][MAXN];
int a[MAXN],b[MAXN],c[MAXN];
int n,q;
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d%d%d",&a[i],&b[i],&c[i]);
	for (int i=0;i<n;i++){
		for (int j=0;j<=1000;j++) f[i][j]=f[i-1][j];
		int now=1,it=c[i];
		while (now<=it){
			for (int j=1000;j>=now*a[i];j--) f[i][j]=max(f[i][j],f[i][j-now*a[i]]+now*b[i]);
			it-=now; now*=2;
		}
		if (it) for (int j=1000;j>=it*a[i];j--) f[i][j]=max(f[i][j],f[i][j-it*a[i]]+it*b[i]);
	}
	for (int i=n-1;i>=0;i--){
		for (int j=0;j<=1000;j++) p[i][j]=p[i+1][j];
		int now=1,it=c[i];
		while (now<=it){
			for (int j=1000;j>=now*a[i];j--) p[i][j]=max(p[i][j],p[i][j-now*a[i]]+now*b[i]);
			it-=now; now*=2;
		}
		if (it) for (int j=1000;j>=it*a[i];j--) p[i][j]=max(p[i][j],p[i][j-it*a[i]]+it*b[i]);
	}
	scanf("%d",&q);
	for (int i=0,d,e;i<q;i++){
		scanf("%d%d",&d,&e);
		int ans=0;
		for (int i=0;i<=e;i++) ans=max(ans,f[d-1][i]+p[d+1][e-i]);
		printf("%d\n",ans);
	}
	return 0;
}
