#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n,m;
int cnt[20];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=n;i<=m;i++){
		int tmp=i;
		bool fl=1;
		while (tmp){
			cnt[tmp%10]++;
			if (cnt[tmp%10]>1) fl=0;
			tmp/=10;
		}
		tmp=i;
		while (tmp){
			cnt[tmp%10]--;
			tmp/=10;
		}
		if (fl) return printf("%d\n",i),0;
	}
	printf("%d\n",-1);
	return 0;
}
