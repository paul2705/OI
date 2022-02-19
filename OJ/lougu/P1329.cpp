#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e2+5;
int f[MAXN][MAXN][MAXN];
int n,s,ans;
int main(){
	scanf("%d%d",&n,&s);
	f[1][0]=1;
	for (int i=2;i<=n;i++){
		for (int j=0;j<=s;j++){
			for (int k=0;k<=s;k++){
				f[i][k][j]+=f[i-1][k-1][j-k]+f[i-1][k+1][j-k];
				if (j==s) ans+=f[i][k][s];
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
