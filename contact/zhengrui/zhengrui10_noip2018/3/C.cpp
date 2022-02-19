#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=5e3+5;
int n;
char a[MAXN];
int f[MAXN][MAXN];
int main(){
	cin>>a;
	n=strlen(a);
	for (int i=0;i<n-1;i++) if (a[i]==a[i+1]) f[i][i+1]=1;
	for (int l=2;l<=n;l++){
		for (int i=0;i<n;i++){
			int j=i+l; if (j>=n) break;
			if (a[i]==a[j]) f[i][j]=f[i+1][j-1];
			for (int k=i;k<j;k++)
				f[i][j]=max(f[i][j],f[i][k]&f[k+1][j]);
//			cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
		}
	}
	int ans=0;
	for (int i=0;i<n;i++){
		for (int j=i;j<n;j++){
			ans+=f[i][j];
//			cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
		}
	}
	printf("%d\n",ans);
	return 0;
} 
