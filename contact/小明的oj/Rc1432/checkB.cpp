#include<iostream>
#include<cstdio>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++;
		system("./getinB");
		system("./B");
		system("./cB");
		if (system("diff B.out B1.out")) break;
		printf("%d\n",cnt);
	}
	return 0;
}
