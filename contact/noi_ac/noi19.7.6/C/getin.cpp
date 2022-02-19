#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include"sys/time.h"
using namespace std;
const int MAXN=4;
int n=4,m=4;
int a[MAXN][MAXN];
int main(){
	freopen("1.in","w",stdout);
	struct timeval tv;
	struct timezone tz;
	gettimeofday(&tv,&tz);
	srand(tv.tv_sec*1000000+tv.tv_usec);
	printf("%d %d\n",n,m);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			int x=rand()%2;
			a[i][j]=x;
			if (x==1) printf("X");
			else printf("O");
		}
		printf("\n");
	}
	int cnt=rand()%15+1;
	while (cnt--){
		int x=rand()%n+1,y=rand()%m+1;
		if (!a[x][y]) continue;
		for (int i=1;i<=m;i++) a[x][i]=1;
		for (int i=1;i<=n;i++) a[i][y]=1;
		a[x][y]=0;
	}
	int op=rand()%2;
	if (op){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				if (a[i][j]) printf("X");
				else printf("O");
			}
			printf("\n");
		}
	}
	else {
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++){
				int x=rand()%2;
				if (x) printf("X");
				else printf("O");
			}
			printf("\n");
		}
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
