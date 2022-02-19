#include<iostream>
#include<cstdio>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++;
		cout<<cnt<<endl;
		system("./getin");
		system("./A_1");
		system("./A_bl");
		if (system("diff 1.out 1_bl.out")) break;
	}
	return 0;
}
