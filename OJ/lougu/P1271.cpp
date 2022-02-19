#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
int cnt[MAXN];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int tmp; scanf("%d",&tmp);
		cnt[tmp]++;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=cnt[i];j++) printf("%d ",i);
	}
	printf("\n");
	return 0;
}
