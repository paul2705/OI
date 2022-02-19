#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=1e5+5;
int a[MAXN],n,m;
int mn[MAXN][20],mx[MAXN][20];
int bin[21];
int main(){
	scanf("%d%d",&n,&m);
	for (int k=0;k<=20;k++){
		for (int i=1;i<=n;i++) mn[i][k]=1e9;
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		mn[i][0]=mx[i][0]=a[i];
	}
	bin[0]=1;
	for (int i=1;i<=20;i++) bin[i]=bin[i-1]*2;
	for (int k=0;k<=19;k++){
		for (int i=1;i<=n;i++){
			if (i+bin[k]>n) break;
			mn[i][k+1]=min(mn[i][k],mn[i+bin[k]][k]);
			mx[i][k+1]=max(mx[i][k],mx[i+bin[k]][k]);
//			cout<<i<<" "<<k+1<<" "<<mn[i][k+1]<<" "<<mx[i][k+1]<<endl;
		}
	}
	for (int i=1;i<=m;i++){
		int l,r; scanf("%d%d",&l,&r);
		int len=log2(r-l+1);
		int x=min(mn[l][len],mn[r-bin[len]+1][len]);
		int y=max(mx[l][len],mx[r-bin[len]+1][len]);
		printf("%d\n",y-x);
	}
	return 0;
}
