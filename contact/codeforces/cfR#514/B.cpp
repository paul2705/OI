#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
int a[MAXN][MAXN],b[MAXN][MAXN];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			char c=getchar(); while (c!='#'&&c!='.') c=getchar();
			a[i][j]=(c=='#');
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			if (a[i][j]&&a[i][j+1]&&a[i][j+2]&&a[i+1][j]&&a[i+2][j]&&a[i+2][j+1]&&a[i+2][j+2]&&a[i+1][j+2]){
				b[i][j]=b[i][j+1]=b[i][j+2]=1;
				b[i+2][j]=b[i+2][j+1]=b[i+2][j+2]=1;
				b[i+1][j]=b[i+1][j+2]=1;
			}
		}
	}
	bool f=1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
//			cout<<b[i][j];
			if (a[i][j]!=b[i][j]) f=0;
		}
//		cout<<endl;
	}
	if (f) printf("YES\n");
	else printf("No\n");
	return 0;
}
