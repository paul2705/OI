#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
	while (1){
		system("./getin_bzoj4977");
		system("./bzoj4977");
		system("./bzoj4977_");
		if (system("diff bzoj4977.out bzoj49771.out")) break;
	}
	return 0;
}
