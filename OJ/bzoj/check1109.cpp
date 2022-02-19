#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int cnt=0;
int main(){
	while (1){
//		printf("%d\n",cnt);
		cnt++;
		system("./getin1109");
		system("./bzoj1109");
		system("./bzoj1109_bll");
		if (system("diff bzoj1109.out bzoj1109_bll.out")) break;
		printf("%d\n",cnt);
	}
	return 0;
}
