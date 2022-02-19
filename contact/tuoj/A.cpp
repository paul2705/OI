#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
int a[MAXN][MAXN],b[MAXN][MAXN];
int n,m,mark[MAXN];
bool ff=1;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) scanf("%d",&b[i][j]);
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++) a[i][j]=a[i][j]^b[i][j];
	}
//	for (int i=1;i<
	for (int i=1;i<=n;i++){
		bool f=0;
		for (int j=1;j<=m;j++) if (mark[j]%2==1) a[i][j]^=1;
		for (int j=1;j<=m;j++) f|=(a[i][j]==1);
		if (f) for (int j=1;j<=m;j++) a[i][j]^=1;
		for (int j=1;j<=m;j++){
//			cout<<a[i][j];
			if (a[i][j]==1) mark[j]++;
			if (mark[j]>=2) ff=0;
		}
//		cout<<endl;
//		for (int j=1;j<=m;j++) cout<<mark[j]<<" "; cout<<endl;
	}
//	for (int j=1;j<=m;j++) cout<<mark[j]<<" "; cout<<endl;
//	bool f=0;
//	for (int j=1;j<=m;j++) f|=(mark[j]==1);
	if (ff) printf("Koyi\n");
	else printf("Budexing\n");
	return 0;
}
