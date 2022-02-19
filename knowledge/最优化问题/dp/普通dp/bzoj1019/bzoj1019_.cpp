#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=55;
typedef long long ll;
ll f[MAXN][4][4];
int n;
char s[10][4];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=6;i++) scanf("%s",s[i]);
	for (int i=0;i<3;i++){
		f[1][i][0]=f[1][i][1]=f[1][i][2]=-1;
		for (int j=1;j<=6;j++){
			if (s[j][0]-'A'==i){
				int to=s[j][1]-'A';
				f[1][i][to]=1;
				break;
			}
		}
	}
	for (int i=2;i<=n;i++){
		for (int j=0;j<3;j++){
			for (int k=0;k<3;k++){
				int l=3-j-k;
				f[i][j][k]=-1;
				if (f[i-1][j][k]!=-1&&f[i-1][k][j]!=-1){
					f[i][j][k]=f[i-1][j][k]*2+2+f[i-1][k][j];
				}
				if (f[i-1][j][l]!=-1&&f[i-1][l][k]!=-1){
					f[i][j][k]=f[i-1][j][l]+1+f[i-1][l][k];
				}
//				cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<endl;
			}
		}
	}
	if (f[n][0][1]!=-1) printf("%lld\n",f[n][0][1]);
	else printf("%lld\n",f[n][0][2]);
	return 0;
}
