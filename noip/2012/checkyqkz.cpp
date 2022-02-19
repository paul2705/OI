#include<iostream>
#include<cstdio>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++;
		system("./getinyqkz");
		system("./yqkz");
		system("./yqkz_");
		if (system("diff yqkz.out yqkz1.out")) break;
		printf("%d\n",cnt);
	}
	return 0;
}
