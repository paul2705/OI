#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e3+5;
int T,n,a[MAXN],ans;
int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		ans=n;
		for (int i=1;i<=n;i++){
			char c=getchar(); while (c!='0'&&c!='1') c=getchar();
			int x=(c=='1');
			a[i]=x;
			if (x) ans=max(ans,max(i*2,max(n+1,2*(n-i+1))));
		}
		printf("%d\n",ans);
	}
	return 0;
}
