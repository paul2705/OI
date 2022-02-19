#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n,a[MAXN];
int st[MAXN],top;
int ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		while (top){
			if (a[st[top]]>=a[i]) top--;
			else break;
		}
		if (st[top]+1==i) ans+=a[i]-a[st[top]];
		st[++top]=i;
	}
	printf("%d\n",ans);
	return 0;
}
