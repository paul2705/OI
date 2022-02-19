#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
int a[MAXN][MAXN];
int up[MAXN][MAXN];
int ans;
int n,m;
int st[MAXN],top,w[MAXN];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			char c=getchar(); while (c!='F'&&c!='R') c=getchar();
			a[i][j]=(c=='F');
		}
	}
	for (int i=1;i<=m;i++){
		up[1][i]=a[1][i];
		for (int j=2;j<=n;j++){
			if (a[j][i]) up[j][i]=up[j-1][i]+1;
			else up[j][i]=0;
		}
	}
	for (int i=1;i<=n;i++){
		top=0;
		for (int j=1;j<=m+1;j++){
			int W=0;
			while (top>0&&st[top]>=up[i][j]){
				W+=w[top];
				ans=max(ans,W*st[top--]);
			}
			st[++top]=up[i][j];
			w[top]=W+1;
		}
	}
	printf("%d\n",3*ans);
	return 0;
}
