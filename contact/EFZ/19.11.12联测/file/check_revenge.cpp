#include<iostream>
#include<cstdio>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++; cout<<cnt<<endl;
		system("./getin_revenge");
		system("./revenge");
		system("./revenge_bl");
		if (system("diff revenge.out revenge.ans")) break;
	}
	return 0;
}
