#include<iostream>
#include<cstdio>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++; cout<<cnt<<endl;
		system("./getin2261");
		system("./P2261");
		system("./P2261_");
		if (system("diff P2261.out P2261.ans")) break;
	}
	return 0;
}
