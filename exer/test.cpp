#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int ans=0;
	for (int i=1;i<=20000;i++){
		cout<<ans<<endl;
		ans+=20000/i;
	}
	printf("%d\n",ans);
	return 0;
}
