#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n; scanf("%d",&n);
	int cnt=0,coin=1,ans=0;
	while (cnt<n){
		for (int i=1;i<=coin;i++){
			ans+=coin;
			cnt++;
			if (cnt==n) break;
		}
		coin++;
	}
	printf("%d\n",ans);
	return 0;
}
