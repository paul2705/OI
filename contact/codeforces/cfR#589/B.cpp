#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int MAXN=1e3+5;
int a[MAXN][MAXN];
bool fl=1;
int n,m,r[MAXN],c[MAXN];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&r[i]);
		for (int j=1;j<=r[i];j++){
			if (a[i][j]==2) fl=0;
			a[i][j]=1;
		}
		if (a[i][r[i]+1]==1) fl=0;
		a[i][r[i]+1]=2;
	}
	for (int i=1;i<=m;i++){
		scanf("%d",&c[i]);
		for (int j=1;j<=c[i];j++){
			if (a[j][i]==2) fl=0;
			a[j][i]=1;
		}
		if (a[c[i]+1][i]==1) fl=0;
		a[c[i]+1][i]=2;
	}
	ll cnt=1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (a[i][j]) continue;
			cnt=cnt*2ll%mod;
		}
	}
	if (!fl) return printf("0\n"),0;
	else /*printf("%lld\n",cnt)*/cout<<cnt<<endl;
	return 0;
}
