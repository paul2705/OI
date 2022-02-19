#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
int ans1,ans2;
int n,m;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x; scanf("%d",&x);
		ans1=max(ans1,x);
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++){
		int x; scanf("%d",&x);
		ans2=max(ans2,x);
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}
