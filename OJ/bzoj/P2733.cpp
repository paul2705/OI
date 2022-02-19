#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN=300;
int a[MAXN][MAXN],sum[MAXN][MAXN],n,ans;
bool gain(int k){
	k--; ans=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (i+k>n||j+k>n) continue;
			if (sum[i+k][j+k]-sum[i-1][j+k]-sum[i+k][j-1]+sum[i-1][j-1]==(k+1)*(k+1)) ans++;
		}
	}
	return ans>0;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		char c;
		for (int j=1;j<=n;j++){
			scanf("%c",&c);
			while (c!='1'&&c!='0') c=getchar();
			a[i][j]= c=='1'?1:0;
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) 
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
	for (int k=2;gain(k);k++) printf("%d %d\n",k,ans);
	return 0;
}
