#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int cnt[30],n,k,mn=1e9;
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		char c=getchar(); while (c<'A'||c>'Z') c=getchar();
		cnt[c-'A']++;
	}
	for (int i=0;i<k;i++) mn=min(mn,cnt[i]);
	printf("%I64d\n",(long long)mn*k);
	return 0;
}
