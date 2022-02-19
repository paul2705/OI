#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=50;
ll f[MAXN][4],g[MAXN][4];
int n;
char s[10][3];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=6;i++) scanf("%s",s[i]);
	for (int i=6;i>=1;i--) g[1][s[i][0]-'A']=s[i][1]-'A';
	f[1][0]=f[1][1]=f[1][2]=1;
	for (int i=2;i<=n;i++){
		for (int j=0;j<3;j++){
			int y=g[i-1][j],z=3-y-j;
			if (g[i-1][y]==z) g[i][j]=z,f[i][j]=f[i-1][j]+1+f[i-1][y];
			else g[i][j]=y,f[i][j]=f[i-1][j]+2+2*f[i-1][y];
		}
	}
	printf("%lld\n",f[n][0]);
	return 0;
}
