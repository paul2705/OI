#include<iostream>
#include<cstdio>
using namespace std;
int cnt=1;
int main(){
	while (1){
		cout<<cnt<<endl;
		system("./getin_P7960");
		system("time ./P7960");
		system("time ./P7960_bl");
		if (system("diff P7960.out P7960.ans")) break;
		cnt++;
	}
	return 0;
}

