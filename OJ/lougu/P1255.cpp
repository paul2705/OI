#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e3+5;
int f[MAXN][MAXN];
int n;
void pls(int x,int y,int z){
	f[x][0]=max(f[y][0],f[z][0]);
	for (int i=1;i<=f[x][0];i++){
		f[x][i]+=f[y][i]+f[z][i];
		f[x][i+1]+=f[x][i]/10;
		f[x][i]%=10;
	}
	if (f[x][f[x][0]+1]>0) f[x][0]++;
}
int main(){
	scanf("%d",&n);
	f[1][0]=f[1][1]=1;
	f[0][0]=f[0][1]=1;
	for (int i=2;i<=n;i++) pls(i,i-1,i-2);
	while (f[n][f[n][0]]==0) f[n][0]--;
	if (n>0) for (int i=f[n][0];i>=1;i--) printf("%d",f[n][i]);
	else printf("0");
	printf("\n");
	return 0;
}
