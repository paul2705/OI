#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++;
		cout<<cnt<<endl;
		system("./getin");
		system("./C_1");
		system("./C_2");
		if (system("diff 1.out 1_bl.out")) break;
	}
	return 0;
}
