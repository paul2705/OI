#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=5e5+5;
int ans,s[MAXN],top;
int n;
int main(){
	scanf("%d",&n);
	for (int i=1,x;i<=n;i++){
		scanf("%d",&x); int t=1;
		while (top>0&&s[top]<=x){
			if (s[top]==x) t++;
			ans++; top--;
		}
		if (top) ans++;
		while (t--) s[++top]=x;
	}
	printf("%d\n",ans);
	return 0;
}
