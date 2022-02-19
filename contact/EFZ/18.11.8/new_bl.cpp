#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

const int N=1e3+10;
int n,m,mx1,mx2,ans1,ans2;
int a[N],b[N],f[N][N];

int read() {
	char c=getchar();
	while (c<'0' || c>'9') c=getchar();
	int ret=c-'0';
	c=getchar();
	while (c>='0' && c<='9') {
		ret=ret*10+c-'0';
		c=getchar();
	}
	return ret;
}

int ls1() {
	memset(f,0,sizeof(f));
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (a[i]==b[j]) f[i][j]=f[i-1][j-1]+1;
			else f[i][j]=f[i-1][j]>f[i][j-1]?f[i-1][j]:f[i][j-1];
	return f[n][n];
}

int ls2() {
	memset(f,0,sizeof(f));
	int ret=0;
	for (int i=1;i<=n+1;i++)
		for (int j=1;j<=n+1;j++) {
			if (a[i-1]!=b[j-1]) f[i][j]=0;
			else if (a[i-1]==b[j-1]) f[i][j]=f[i-1][j-1]+1;
			if (f[i][j]>ret) ret=f[i][j];
		}
	return ret;
}

int main() {
	freopen("new.in","r",stdin);
	freopen("new.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) a[i]=read();
	while (m--) {
		for (int i=1;i<=n;i++) b[i]=read();
		int ans1=ls1(),ans2=ls2();
		if (ans1>mx1) mx1=ans1;
		if (ans2>mx2) mx2=ans2;
	}
	printf("%d\n%d\n",mx1,mx2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
