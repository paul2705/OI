#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int MAXN=4e5+5;
int a[MAXN],f[MAXN][21];
int pw[21];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	pw[0]=1;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]),f[i][0]=a[i];
	for (int i=1;i<=20;i++){
		pw[i]=pw[i-1]*2;
		for (int j=1;j<=n;j++){
			if (j+pw[i]>4*n) continue;
			f[j][i]=max(f[j][i-1],f[j+pw[i-1]][i-1]);
		}
	}
	for (int i=1;i<=m;i++){
		int l,r; scanf("%d%d",&l,&r);
		int w=log2(r-l+1);
//		cout<<w<<endl;
		printf("%d\n",max(f[l][w],f[r-pw[w]+1][w]));
	}
	return 0;
}
