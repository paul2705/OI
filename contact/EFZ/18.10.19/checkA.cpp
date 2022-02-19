#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int cnt=0;
	while (1){
		cnt++;
		system("./getinA");
		system("./dream");
		system("./main");
		if (system("diff dream.out dream1.out")) break;
		printf("%d\n",cnt);
	}
	return 0;
}
