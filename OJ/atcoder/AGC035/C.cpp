#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n,cnt[MAXN];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=1e5;i*=2) cnt[i]=1;
	if (cnt[n]) return printf("No\n"),0;
	else printf("Yes\n");
	
	return 0;
}
