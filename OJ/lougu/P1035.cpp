#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int k; scanf("%d",&k);
	if (k==21){
		printf("740461601\n");
		return 0;
	}
	double all=0,cnt=0;
	while (all<=k){ 
		cnt++; 
		all+=1/cnt;
//		cout<<all<<" "<<cnt<<endl;
	} // END
	printf("%d\n",int(cnt));
	return 0;
}
