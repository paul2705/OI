#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN=1e3+5;
const int MAXM=1e2+5;
int cnt[MAXN];
int n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int tmp; scanf("%d",&tmp);
		cnt[tmp]=1;
	}
	int ans=0;
	for (int i=1;i<=1000;i++) ans+=cnt[i];
	printf("%d\n",ans);
	for (int i=1;i<=1000;i++){
		if (!cnt[i]) continue;
		printf("%d ",i);
	}
	printf("\n");
	return 0;
}
