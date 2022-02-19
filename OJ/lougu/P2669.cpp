#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int k; scanf("%d",&k);
	int day=0,coin=0,ans=0;
	while (day<k){
		coin++;
		for (int i=1;i<=coin;i++){
			ans+=coin;
			day++;
//			cout<<day<<" "<<coin<<" "<<ans<<endl;
			if (day>=k) break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
