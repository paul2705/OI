#include<iostream>
#include<cstdio>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++;
		system("./getincdq");
		system("./cdqC");
		system("./cdq");
		if (system("diff cdq.out cdq1.out")) break;
		printf("%d\n",cnt);
	}
	return 0;
}
