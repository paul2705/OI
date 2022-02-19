#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1e4+5;
const int MAXM=1e3+5;
char a[MAXN],b[MAXM];
int n,m,x,nxt[MAXM],f[2][MAXM],ans;
inline void up(int &a,int b){ if (a<b) a=b; }
int main(){
	scanf("%s%s",a+1,b+1);
	n=strlen(a+1),m=strlen(b+1); int j=0;
	for (int i=2;i<=m;nxt[i++]=j){
		while (j&&b[j+1]!=b[i]) j=nxt[j];
		if (b[j+1]==b[i]) j++;
	}
	for (int i=1;i<m;i++) f[0][i]=-1;
	for (int i=0;i<n;i++,x^=1){
		for (int j=0;j<m;j++) f[x^1][j]=-1;
		for (int j=0;j<m;j++)
			if (~f[x][j]){
				up(f[x^1][j],f[x][j]);
				int k;
				for (k=j;k&&b[k+1]!=a[i+1];k=nxt[k]);
				if (b[k+1]==a[i+1]) k++;
				up(f[x^1][k],f[x][j]+1);
			}
	}
	for (int j=0;j<m;j++) ans=max(ans,f[x][j]);
	return printf("%d\n",n-ans),0;
}
