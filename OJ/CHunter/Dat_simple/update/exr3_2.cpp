#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
int a[MAXN][MAXN];
int n,m;
int up[MAXN][MAXN];
int ans;
int st[MAXN],top;
int l[MAXN][MAXN],r[MAXN][MAXN];
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
		for (int j=1;j<=m;j++){
			while (top>0&&up[i][st[top]]>=up[i][j]) top--;
			l[i][j]=st[top]+1;
			st[++top]=j;
		}
		top=0;
		for (int j=m;j>=1;j--){
			while (top>0&&up[i][st[top]]>=up[i][j]) top--;
			if (top) r[i][j]=st[top]-1;
			else r[i][j]=m;
			st[++top]=j;
		}
		for (int j=1;j<=m;j++) ans=max(ans,(r[i][j]-l[i][j]+1)*up[i][j]);
	}
	printf("%d\n",3*ans);
	return 0;
}
