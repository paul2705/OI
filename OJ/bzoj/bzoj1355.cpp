#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e6+6;
char s[MAXN];
int n,fail[MAXN];
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	int j=0;
	for (int i=2;i<=n;i++){
		while (s[j+1]!=s[i]&&j) j=fail[j];
		if (s[j+1]==s[i]) j++;
		fail[i]=j;
	}
	printf("%d\n",n-fail[n]);
	return 0;
}
