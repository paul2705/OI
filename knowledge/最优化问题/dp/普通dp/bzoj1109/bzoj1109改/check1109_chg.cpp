#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int cnt=0;
int main(){
	while (1){
//		printf("%d\n",cnt);
		cnt++;
		system("./getin1109_chg");
		system("./bzoj1109_chg");
		system("./bzoj1109_chg_bl");
		if (system("diff bzoj1109_chg.out bzoj1109_chg_bl.out")) break;
		printf("%d\n",cnt);
	}
	return 0;
}
