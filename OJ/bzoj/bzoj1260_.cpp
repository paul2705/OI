#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=55;
char s[MAXN];
int f[MAXN][MAXN];
int n;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) f[i][j]=1e9;
	}
	for (int i=1;i<=n;i++) f[i][i]=1;
	for (int l=1;l<=n;l++){
		for (int i=1;i<=n;i++){
			int j=i+l; if (j>n) break;
			for (char c='A';c<='Z';c++){
				int las=i-1,t=0;
				for (int k=i;k<=j+1;k++){
					if (s[k]==c||k==j+1){
						if (k>las+1) t+=f[las+1][k-1];
						las=k;
					}
				}
//				cout<<i<<" "<<j<<" "<<c<<" "<<t+1<<endl;
				f[i][j]=min(f[i][j],t+1);
			}
//			cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
		}
	}
	printf("%d\n",f[1][n]);
	return 0;
}
