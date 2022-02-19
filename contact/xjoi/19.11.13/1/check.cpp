#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int cnt=0;
int main(){
	while (1){
		cnt++; cout<<cnt<<endl;
		system("./getin");
		system("./B");
		system("./B_bl");
		if (system("diff problem2.out problem2.ans -b")) break;
	}
	return 0;
}
