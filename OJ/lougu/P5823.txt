#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n; scanf("%d",&n);
	int all=0,cnt=0;
	for (int i=2;all<=n;i++){
		bool fg=1;
//		cout<<i<<endl;
		for (int j=2;j*j<=i;j++){
			if (i%j==0){
				fg=0;
				break;
			}
		}
		if (fg){
			all+=i;
			if (all>n) break;
			else{
				printf("%d\n",i);
				cnt++;
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}
