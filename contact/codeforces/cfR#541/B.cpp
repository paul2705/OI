#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e4+5;
int a[MAXN],b[MAXN];
int n,ans;
int main(){
	scanf("%d",&n);
	a[0]=-1;
	for (int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		if (a[i]==a[i-1]&&b[i]==b[i-1]) continue;
		ans+=max(0,1+min(a[i],b[i])-max(a[i-1],b[i-1]));		
		if (a[i-1]==b[i-1]) ans--;
	}
	printf("%d\n",ans);
	return 0;
}
