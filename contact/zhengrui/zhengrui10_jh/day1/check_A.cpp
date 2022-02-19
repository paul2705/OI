#include<iostream>
#include<cstdio>
using namespace std;
int cnt;
int main(){
	while (1){
		cnt++; cout<<cnt<<endl;
		system("./getin_A");
		system("./A_");
		system("./A_bl");
		if (system("diff A.out A.ans")) break;
	}
	return 0;
}
