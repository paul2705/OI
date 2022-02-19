#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e2+5;
int n,m,a[MAXN][MAXN];
int ans;
struct rec{
	int l,r;
} ret[MAXN];
void solve1(){
	for (int l=1,r=1;l<=m;l=r+1,r++){
		if (a[1][l]==0) continue;
		while (a[1][r+1]==1) r++;
		ans++; ret[ans]=(rec){l,r};
	}
	printf("%d\n",ans);
	for (int i=1;i<=ans;i++){
		printf("+\n");
		for (int j=1;j<=m;j++){
			if (j<ret[i].l||j>ret[i].r) printf("0");
			else printf("1");
		}
		printf("\n");
	}
}
void solve2(){
	
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			char c=getchar(); while (c!='0'&&c!='1') c=getchar();
			a[i][j]=(c=='1');
		}
	}
	if (n==1) solve1();
	else solve2();
	return 0;
}
