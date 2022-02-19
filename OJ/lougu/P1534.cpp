#include<iostream>
#include<cstdio>
using namespace std;
int n,cnt,ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int a,b; scanf("%d%d",&a,&b);
		cnt+=a+b-8;
		ans+=cnt;
	}
	printf("%d\n",ans);
	return 0;
}
