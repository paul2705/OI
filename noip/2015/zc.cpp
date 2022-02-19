#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
const int MAXM=2e2+5;
const int mod=1e9+7;
char a[MAXN],b[MAXM];
int n,m,K,f[3][MAXM][MAXM][2];
int main(){
	scanf("%d%d%d",&n,&m,&K);
	scanf("%s\n%s",a+1,b+1);
//	cout<<a[1]<<endl<<b[1]<<endl;
	for (int i=1;i<=n;i++){
		f[1][0][0][0]=f[0][0][0][0]=1;
		int c=i&1,o=c^1;
		for (int j=1;j<=min(i,m);j++){
			for (int k=1;k<=K;k++){
//				cout<<i<<" "<<j<<" "<<k<<endl;
				if (j<i) f[c][j][k][0]=(f[o][j][k][0]+f[o][j][k][1])%mod;
				else f[c][j][k][0]=0;
//				cout<<"fuck"<<endl;
				if (a[i]==b[j]) 
					f[c][j][k][1]=((f[o][j-1][k-1][1]+f[o][j-1][k][1])%mod+f[o][j-1][k-1][0])%mod;
				else f[c][j][k][1]=0;
//				cout<<"out"<<endl;
			}
		}
	}
	printf("%d\n",(f[n&1][m][K][0]+f[n&1][m][K][1])%mod);
	return 0;
}
