#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int f[55][55],n,m;
int main(){
	scanf("%d%d",&n,&m); f[1][1]=1;
	for (int i=2;i<=n;i++){
		for (int j=1;j<=min(i,m);j++){
			f[i][j]=f[i-1][j-1]+j*f[i-1][j];
			cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
		}
	}
	return 0;
}
